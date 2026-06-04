/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  Timer Plugin
 * Author:   Mike Rossiter
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Mike Rossiter                                   *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#include "e_timergui_impl.h"
#include "e_timer_pi.h"
#include "e_timergui.h"
#include "icons.h"

#include "wx/dir.h"
#include <cmath>
#include <list>
#include <wx/datetime.h>
#include <wx/progdlg.h>
#include <wx/timer.h>
#include <wx/wx.h>
#include "qtstylesheet.h"
#include <iostream>
#include <iomanip>
#include <sstream>

#ifdef __ANDROID__
wxWindow* g_Window;
#endif

#define FAIL(X)  \
  do {           \
    error = X;   \
    goto failed; \
  } while (0)

Dlg::Dlg(wxWindow* parent, e_timer_pi* ppi) : m_Dialog(parent) {
  this->Fit();
  dbg = false;  // for debug output set to true

  pPlugIn = ppi;
  pParent = parent;

#ifdef __ANDROID__

  m_binResize = false;

  g_Window = this;
  GetHandle()->setStyleSheet(qtStyleSheet);
  Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(Dlg::OnMouseEvent));
  Connect(wxEVT_LEFT_UP, wxMouseEventHandler(Dlg::OnMouseEvent));

  Connect(wxEVT_MOTION, wxMouseEventHandler(Dlg::OnMouseEvent));
#endif

  wxString s = "\\";
  const char* pName = "e_timer_pi";
  wxString sound_dir = GetPluginDataDir(pName) + s + "data" + s;

  // Set reasonable defaults
  sound_dir.Append("sounds");
  sound_dir.Append(wxFileName::GetPathSeparator());

  // create sound file
  m_soundFile = sound_dir + "short-alarm.wav";
  m_empty_soundFile = sound_dir + "empty.wav";
  g_tick = 0;
  // Hide choices not selected
  m_static_text_countdown->Hide();
  m_static_text_countdown2->Hide();
  m_choice_countdown->Hide();

  m_static_text_countup->Hide();
  m_choice_countup->Hide();
  m_static_text_countup2->Hide();

  m_static_text_repeat->Hide();
  m_choice_repeat->Hide();
  m_static_text_repeat2->Hide();

  m_checkbox_countup->SetValue(false);
  m_checkbox_countdown->SetValue(false);
  m_checkbox_repeat->SetValue(false);

  m_timer_clock.Start(1000, wxTIMER_CONTINUOUS);
  NotifyClock();
}

Dlg::~Dlg() {}

#ifdef __ANDROID__
wxPoint g_startPos;
wxPoint g_startMouse;
wxPoint g_mouse_pos_screen;

void Dlg::OnPopupClick(wxCommandEvent& evt) {
  switch (evt.GetId()) {
    case ID_SOMETHING:
      m_binResize = true;
      break;
      // case ID_SOMETHING_ELSE:
      //   break;
  }
}

void Dlg::OnDLeftClick(wxMouseEvent& event) {
  wxMenu mnu;
  mnu.Append(ID_SOMETHING, "Resize...");
  // mnu.Append(ID_SOMETHING_ELSE, "Do something else");
  mnu.Connect(wxEVT_COMMAND_MENU_SELECTED,
              wxCommandEventHandler(Dlg::OnPopupClick), NULL, this);
  PopupMenu(&mnu);
}

void Dlg::OnMouseEvent(wxMouseEvent& event) {
  if (m_binResize) {
    wxSize currentSize = g_Window->GetSize();
    wxSize par_size = GetOCPNCanvasWindow()->GetClientSize();
    wxPoint par_pos = g_Window->GetPosition();
    if (event.LeftDown()) {
      m_resizeStartPoint = event.GetPosition();
      m_resizeStartSize = currentSize;
      m_binResize2 = true;
    }

    if (m_binResize2) {
      if (event.Dragging()) {
        wxPoint p = event.GetPosition();

        wxSize dragSize = m_resizeStartSize;

        dragSize.y = p.y;  //  - m_resizeStartPoint.y;
        dragSize.x = p.x;  //  - m_resizeStartPoint.x;
        ;
        /*
        if ((par_pos.y + dragSize.y) > par_size.y)
            dragSize.y = par_size.y - par_pos.y;

        if ((par_pos.x + dragSize.x) > par_size.x)
            dragSize.x = par_size.x - par_pos.x;
*/
        // not too small
        dragSize.x = wxMax(dragSize.x, 150);
        dragSize.y = wxMax(dragSize.y, 150);

        int x = wxMax(0, m_resizeStartPoint.x);
        int y = wxMax(0, m_resizeStartPoint.y);
        int xmax = ::wxGetDisplaySize().x - GetSize().x;
        x = wxMin(x, xmax);
        int ymax =
            ::wxGetDisplaySize().y - (GetSize().y);  // Some fluff at the bottom
        y = wxMin(y, ymax);

        g_Window->Move(x, y);
      }
      if (event.LeftUp()) {
        wxPoint p = event.GetPosition();

        wxSize dragSize = m_resizeStartSize;

        dragSize.y = p.y;
        dragSize.x = p.x;

        // not too small
        dragSize.x = wxMax(dragSize.x, 150);
        dragSize.y = wxMax(dragSize.y, 150);

        g_Window->SetSize(dragSize);

        m_binResize = false;
        m_binResize2 = false;
      }
    }
  } else {
    if (event.Dragging()) {
      m_resizeStartPoint = event.GetPosition();
      int x = wxMax(0, m_resizeStartPoint.x);
      int y = wxMax(0, m_resizeStartPoint.y);
      int xmax = ::wxGetDisplaySize().x - GetSize().x;
      x = wxMin(x, xmax);
      int ymax =
          ::wxGetDisplaySize().y - (GetSize().y);  // Some fluff at the bottom
      y = wxMin(y, ymax);

      g_Window->Move(x, y);
    }
  }
}

#endif  // End of Android functions for move/resize
/*
void Dlg::OnClock(wxTimerEvent& event) {
  NotifyClock();
  event.Skip();
}*/

void Dlg::OnStartTimer(wxCommandEvent& event) {
  g_tick = 0;
  if (m_checkbox_countup->IsChecked()) {
    m_timer_countup.Start(1000, wxTIMER_CONTINUOUS);
    NotifyCountUp();
  } else if (m_checkbox_countdown->IsChecked()) {
    int c = m_choice_countdown->GetSelection();
    wxString s = m_choice_countdown->GetString(c);
    int cs = atoi(s);
    g_tick = cs * 60;
    m_timer_countdown.Start(1000, wxTIMER_CONTINUOUS);
    NotifyCountDown();
  } else if (m_checkbox_repeat->IsChecked()) {
    m_timer_repeat.Start(1000, wxTIMER_CONTINUOUS);
    NotifyRepeat();
  }

  if (!m_checkbox_countup->IsChecked() && !m_checkbox_countdown->IsChecked() && !m_checkbox_repeat->IsChecked()) {
    // Do something when no checkboxes are checked
    m_timer_stopwatch.Start(1000, wxTIMER_CONTINUOUS);
    NotifyStopwatch();
  }
}

void Dlg::OnStopTimer(wxCommandEvent& event) {
  m_timer_countup.Stop();
  m_timer_countdown.Stop();
  m_timer_alarm.Stop();

  m_text_time->SetValue("   00:00");
  g_tick = 0;

  if (m_checkbox_countdown->IsChecked()) {
    m_checkbox_countdown->SetValue(false);
    // Hide choices not selected
    m_static_text_countdown->Hide();
    m_static_text_countdown2->Hide();
    m_choice_countdown->Hide();

  } else if (m_checkbox_countup->IsChecked()) {
    m_checkbox_countup->SetValue(false);
    m_static_text_countup->Hide();
    m_choice_countup->Hide();
    m_static_text_countup2->Hide();

  } else if (!m_checkbox_repeat->IsChecked()) {
    m_checkbox_repeat->SetValue(false);
    m_static_text_repeat->Hide();
    m_choice_repeat->Hide();
    m_static_text_repeat2->Hide();
    m_timer_repeat.Stop();

  } else if (m_checkbox_repeat->IsChecked()) {
    play_sound = false;
    m_text_time->SetValue("   00:00");
    g_tick = 0;
    wxMilliSleep(1000);
    m_timer_repeat.Start(1000, wxTIMER_CONTINUOUS);
  }

  if (!m_checkbox_countup->IsChecked() && !m_checkbox_countdown->IsChecked() &&
      !m_checkbox_repeat->IsChecked()) {
    // Do something when no checkboxes are checked
    m_timer_stopwatch.Stop();
    m_text_time->SetValue("   " +   stopwatch_time);
  }

}

void Dlg::OnTimerClock(wxTimerEvent& event) { NotifyClock(); }

void Dlg::OnTimerStopwatch(wxTimerEvent& event) {
  g_tick++;
  NotifyStopwatch();
}

void Dlg::OnTimerCountUp(wxTimerEvent& event) {
  g_tick++;
  NotifyCountUp();
}

void Dlg::OnTimerCountDown(wxTimerEvent& event) {
  g_tick--;
  NotifyCountDown();
}

void Dlg::OnTimerRepeat(wxTimerEvent& event) {
  g_tick++;
  NotifyRepeat();
}

void Dlg::OnTimerAlarm(wxTimerEvent& event) { NotifyAlarm(); }

void Dlg::NotifyClock() { UpdateClock(); }

void Dlg::UpdateClock() {
  wxDateTime dt = wxDateTime::Now();
  wxString s = dt.Format("%H:%M:%S");
  m_ClockTime->SetLabel(s);
}

void Dlg::NotifyStopwatch() {
  int totalSeconds = g_tick;
  int minutes = totalSeconds / 60;
  totalSeconds = totalSeconds % 60;

  int seconds = totalSeconds;

  stringstream ss;
  ss << setw(2) << setfill('0') << seconds << endl;

  stringstream mm;
  mm << setw(2) << setfill('0') << minutes << endl;

  m_text_time->SetValue("   " + mm.str() + ":" + ss.str());

  stopwatch_time = mm.str() + ":" + ss.str();

}

void Dlg::NotifyCountUp() {
  int totalSeconds = g_tick;
  int minutes = totalSeconds / 60;
  totalSeconds = totalSeconds % 60;

  int seconds = totalSeconds;

  stringstream ss;
  ss << setw(2) << setfill('0') << seconds << endl;

  stringstream mm;
  mm << setw(2) << setfill('0') << minutes << endl;

  m_text_time->SetValue("   " + mm.str() + ":" + ss.str());

  int i_interval = this->m_choice_countup->GetSelection();
  wxString s_interval = this->m_choice_countup->GetString(i_interval);
  int myInterval = wxAtoi(s_interval) * 60;

  if (g_tick >= myInterval) {
    m_timer_alarm.Start(1000, wxTIMER_CONTINUOUS);
    m_text_time->SetValue("   00:00");
  }
}

void Dlg::NotifyCountDown() {
  int totalSeconds = g_tick;
  int minutes = totalSeconds / 60;
  totalSeconds = totalSeconds % 60;

  int seconds = totalSeconds;

  stringstream ss;
  ss << setw(2) << setfill('0') << seconds << endl;

  stringstream mm;
  mm << setw(2) << setfill('0') << minutes << endl;

  m_text_time->SetValue("   " + mm.str() + ":" + ss.str());
  /*
  int i_interval = this->m_choice_countdown->GetSelection();
  wxString s_interval = this->m_choice_countdown->GetString(i_interval);
  int myInterval = wxAtoi(s_interval) * 60;*/
  if (g_tick <= 0) {
    m_timer_countdown.Stop();
    m_timer_alarm.Start(1000, wxTIMER_CONTINUOUS);
    NotifyAlarm();
    g_tick = 0;
    m_text_time->SetValue("   00:00");
  }
}

void Dlg::NotifyRepeat() {
  if (m_checkbox_repeat->IsChecked()) {
    int totalSeconds = g_tick;
    int minutes = totalSeconds / 60;
    totalSeconds = totalSeconds % 60;

    int seconds = totalSeconds;

    stringstream ss;
    ss << setw(2) << setfill('0') << seconds << endl;

    stringstream mm;
    mm << setw(2) << setfill('0') << minutes << endl;

    m_text_time->SetValue("   " + mm.str() + ":" + ss.str());

    int i_interval = this->m_choice_repeat->GetSelection();
    wxString s_interval = this->m_choice_repeat->GetString(i_interval);
    int myInterval = wxAtoi(s_interval) * 60;
    if (g_tick >= myInterval) {
      m_timer_alarm.Start(1000, wxTIMER_CONTINUOUS);
      g_tick = 0;
      m_text_time->SetValue("   00:00");
    }
  }
}

void Dlg::NotifyAlarm() {
  // wxMessageBox("Timer Alarm", "Timer", wxICON_INFORMATION | wxOK);
  PlugInPlaySound(m_soundFile);
}

void Dlg::OnCountUp(wxCommandEvent& event) {
  if (m_checkbox_countup->IsChecked()) {
    m_static_text_countup->Show();
    m_choice_countup->Show();
    m_static_text_countup2->Show();

    m_checkbox_countdown->SetValue(false);
    m_checkbox_repeat->SetValue(false);
    m_timer_repeat.Stop();
    m_timer_countup.Stop();
    m_timer_countdown.Stop();

    // Hide choices not selected
    m_static_text_countdown->Hide();
    m_static_text_countdown2->Hide();
    m_choice_countdown->Hide();

    m_static_text_repeat->Hide();
    m_choice_repeat->Hide();
    m_static_text_repeat2->Hide();

    m_text_time->SetValue("   00:00");

  } else {
    m_static_text_countup->Hide();
    m_choice_countup->Hide();
    m_static_text_countup2->Hide();
    m_text_time->SetValue("   00:00");
  }
  this->SetSizer(bSizerMain);
  this->Layout();
  bSizerMain->Fit(this);
}

void Dlg::OnCountDown(wxCommandEvent& event) {
  if (m_checkbox_countdown->IsChecked()) {
    m_static_text_countdown->Show();
    m_choice_countdown->Show();
    m_static_text_countdown2->Show();
    FillCountDown();

    m_checkbox_countup->SetValue(false);
    m_checkbox_repeat->SetValue(false);
    m_timer_repeat.Stop();
    m_timer_countup.Stop();
    m_timer_countdown.Stop();

    // Hide choices not selected
    m_static_text_countup->Hide();
    m_choice_countup->Hide();
    m_static_text_countup2->Hide();

    m_static_text_repeat->Hide();
    m_choice_repeat->Hide();
    m_static_text_repeat2->Hide();

    m_text_time->SetValue("   00:00");

  } else {
    m_static_text_countdown->Hide();
    m_choice_countdown->Hide();
    m_static_text_countdown2->Hide();
    m_text_time->SetValue("   00:00");
  }

  this->SetSizer(bSizerMain);
  this->Layout();
  bSizerMain->Fit(this);
}

void Dlg::OnRepeat(wxCommandEvent& event) {
  if (m_checkbox_repeat->IsChecked()) {
    m_static_text_repeat->Show();
    m_choice_repeat->Show();
    m_static_text_repeat2->Show();

    m_checkbox_countup->SetValue(false);
    m_checkbox_countdown->SetValue(false);
    m_timer_countup.Stop();
    m_timer_countdown.Stop();

    // Hide choices not selected
    m_static_text_countdown->Hide();
    m_static_text_countdown2->Hide();
    m_choice_countdown->Hide();

    m_static_text_countup->Hide();
    m_choice_countup->Hide();
    m_static_text_countup2->Hide();

    m_text_time->SetValue("   00:00");

  } else {
    m_static_text_repeat->Hide();
    m_choice_repeat->Hide();
    m_static_text_repeat2->Hide();
    m_text_time->SetValue("   00:00");
    m_timer_repeat.Stop();
  }

  this->SetSizer(bSizerMain);
  this->Layout();
  bSizerMain->Fit(this);
}

void Dlg::FillCountDown() {
  for (int i = 1; i <= 60; i++) {
    wxString myInt = wxString::Format("%i", i);
    m_choice_countdown->Append(myInt);
  }
}

void Dlg::OnClose(wxCloseEvent& event) { pPlugIn->OnTimerDialogClose(); }

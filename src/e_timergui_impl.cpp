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


#ifdef __OCPN__ANDROID__
wxWindow* g_Window;
#endif

#define FAIL(X)                                                                \
    do {                                                                       \
        error = X;                                                             \
        goto failed;                                                           \
    } while (0)

Dlg::Dlg(wxWindow* parent, e_timer_pi* ppi)
    : m_Dialog(parent)
{
    this->Fit();
    dbg = false; // for debug output set to true

    pPlugIn = ppi;
    pParent = parent;

    wxString s = "/";
    const char* pName = "e_timer_pi";
    wxString sound_dir = GetPluginDataDir(pName) + s + "data" + s;

    // Set reasonable defaults
    sound_dir.Append(_T("sounds"));
    sound_dir.Append(wxFileName::GetPathSeparator());
    g_anchorwatch_sound_file = sound_dir + _T("beep1.wav");
    g_tick = 0;

    // Hide choices not selected
    m_staticTextCD->Hide();
    m_staticTextCD2->Hide();
    m_choiceCD->Hide();

    m_staticTextDuration->Hide();
    m_duration->Hide();
    m_staticTextDuration2->Hide();

    m_checkBoxDuration->SetValue(false);
    m_checkBoxCountdown->SetValue(false);

    b_watchHour = false;

    //m_timer2.Start(1000, wxTIMER_CONTINUOUS);

#ifdef __OCPN__ANDROID__
    g_Window = this;
    GetHandle()->setStyleSheet(qtStyleSheet);
    Connect(wxEVT_MOTION, wxMouseEventHandler(Dlg::OnMouseEvent));
#endif
}

Dlg::~Dlg() { }

#ifdef __OCPN__ANDROID__
wxPoint g_startPos;
wxPoint g_startMouse;
wxPoint g_mouse_pos_screen;

void Dlg::OnMouseEvent(wxMouseEvent& event)
{
    g_mouse_pos_screen = ClientToScreen(event.GetPosition());

    if (event.Dragging()) {
        int x
            = wxMax(0, g_startPos.x + (g_mouse_pos_screen.x - g_startMouse.x));
        int y
            = wxMax(0, g_startPos.y + (g_mouse_pos_screen.y - g_startMouse.y));
        int xmax = ::wxGetDisplaySize().x - GetSize().x;
        x = wxMin(x, xmax);
        int ymax = ::wxGetDisplaySize().y
            - (GetSize().y * 2); // Some fluff at the bottom
        y = wxMin(y, ymax);

        g_Window->Move(x, y);
    }
}
#endif

void Dlg::OnClock(wxTimerEvent& event)
{
    Notify2();
    event.Skip();
}

void Dlg::Notify2() { UpdateClock(); }

void Dlg::OnStartTimer(wxCommandEvent& event)
{

    m_sound = new wxSound(g_anchorwatch_sound_file);

    play_sound = false;

    g_tick = 0;
    if (m_checkBoxDuration->IsChecked()) {
        m_timer1.Start(1000, wxTIMER_CONTINUOUS);
        Notify();
    }else
    if (m_checkBoxCountdown->IsChecked()) {
        int c = m_choiceCD->GetSelection();
        wxString s = m_choiceCD->GetString(c);
        int cs = atoi(s);
        g_tick = cs;
        m_timer3.Start(1000, wxTIMER_CONTINUOUS);
        Notify3();
    }
}

void Dlg::OnStopTimer(wxCommandEvent& event)
{
    if (!m_sound)
        return;

    play_sound = false;

    wxSound::Stop();
    g_tick = 0;
    wxSound* const sound = NULL;
    m_timer1.Stop();
    m_timer3.Stop();
    m_textTime->SetValue("0");

    if (m_checkBoxCountdown->IsChecked()) {
        m_checkBoxCountdown->SetValue(false);
        // Hide choices not selected
        m_staticTextCD->Hide();
        m_staticTextCD2->Hide();
        m_choiceCD->Hide();
    }else
    if (m_checkBoxDuration->IsChecked()) {
        m_checkBoxDuration->SetValue(false);
        m_staticTextDuration->Hide();
        m_duration->Hide();
        m_staticTextDuration2->Hide();
    }
    if (m_checkBoxWatch->IsChecked()) {
        b_watchHour = false;    
    }
}

void Dlg::OnTimer(wxTimerEvent& event)
{
    g_tick++;
    Notify();
}

void Dlg::OnTimer3(wxTimerEvent& event)
{
    g_tick--;
    Notify3();
}

void Dlg::UpdateClock()
{

    wxDateTime dt = wxDateTime::Now();
    int myHour = dt.GetHour();
    int myMinute = dt.GetMinute();
    int mySeconds = dt.GetSecond();
    if (m_checkBoxWatch->IsChecked()) {
        if (myHour == 0 || myHour == 4 || myHour == 8 || myHour == 12
            || myHour == 16 || myHour == 20) {
            if (myMinute == 0 && mySeconds == 0) {
                b_watchHour = true;
            }
        } else
            b_watchHour = false;

        m_sound = new wxSound(g_anchorwatch_sound_file);
        if (b_watchHour) {
            m_sound->Play(wxSOUND_ASYNC);
        }
    }

    wxString s = dt.Format(_T("%H:%M:%S"));
    m_ClockTime->SetLabel(s);

    

}

void Dlg::Notify()
{

    wxString interv = wxString::Format("%i", g_tick);
    m_textTime->SetValue(interv);
    int i_interval = this->m_duration->GetSelection();
    wxString s_interval = this->m_duration->GetString(i_interval);
    int myInterval = wxAtoi(s_interval) * 60;
    if (g_tick == 5 && m_sound != NULL) {
        // wxMessageBox("sound");
        play_sound = true;
        g_tick = 0;
        m_textTime->SetValue("0");
    }

    if (play_sound) {

        m_sound->Play(wxSOUND_ASYNC);
    }
    //      wxMessageBox(interv);
}

void Dlg::Notify3()
{

    wxString interv = wxString::Format("%i", g_tick);
    m_textTime->SetValue(interv);
    int i_interval = this->m_duration->GetSelection();
    wxString s_interval = this->m_duration->GetString(i_interval);
    int myInterval = wxAtoi(s_interval) * 60;
    if (g_tick == 0 && m_sound != NULL) {
        // wxMessageBox("sound");
        play_sound = true;
        g_tick = 0;
        m_textTime->SetValue("0");
    }

    if (play_sound) {

        m_sound->Play(wxSOUND_ASYNC);
    }
    //      wxMessageBox(interv);
}

void Dlg::OnDuration(wxCommandEvent& event) {

    if (m_checkBoxDuration->IsChecked()) {
        m_staticTextDuration->Show();
        m_duration->Show();
        m_staticTextDuration2->Show();
    } else {
        m_staticTextDuration->Hide();
        m_duration->Hide();
        m_staticTextDuration2->Hide();    
    }
    this->SetSizer(bSizerMain);
    this->Layout();
    bSizerMain->Fit(this);
}

void Dlg::OnCountdown(wxCommandEvent& event)
{

    if (m_checkBoxCountdown->IsChecked()) {
        m_staticTextCD->Show();
        m_choiceCD->Show();
        m_staticTextCD2->Show();
        FillCountdown();
    } else {
        m_staticTextCD->Hide();
        m_choiceCD->Hide();
        m_staticTextCD2->Hide();
    }

    this->SetSizer(bSizerMain);
    this->Layout();
    bSizerMain->Fit(this);

    // wxMessageBox("here");
}

void Dlg::FillCountdown()
{

    for (int i = 1; i <= 60; i++) {
        wxString myInt = wxString::Format("%i", i);
        m_choiceCD->Append(myInt);
    }
}

void Dlg::OnClose(wxCloseEvent& event) { pPlugIn->OnTimerDialogClose(); }

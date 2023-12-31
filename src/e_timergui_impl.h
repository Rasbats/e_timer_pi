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

#ifndef _CALCULATORGUI_IMPL_H_
#define _CALCULATORGUI_IMPL_H_

#ifdef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "e_timer_pi.h"
#include "e_timergui.h"
#include "wx/sound.h"
#include "wx/window.h"

#include <list>
#include <vector>

#define OCPN_SOUND_CMD                                                         \
    "PowerShell (New-Object Media.SoundPlayer \\\"%s\\\").PlaySync();"

using namespace std;

class e_timer_pi;
class Position;
class mySound;

class Dlg : public m_Dialog {
public:
    Dlg(wxWindow* parent, e_timer_pi* ppi);
    ~Dlg();

    wxWindow* pParent;
    e_timer_pi* pPlugIn;

#ifdef __OCPN__ANDROID__
    void OnMouseEvent(wxMouseEvent& event);
#endif
    void OnStartTimer(wxCommandEvent& event);
    void OnStopTimer(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnTimer3(wxTimerEvent& event);
    void OnClock(wxTimerEvent& event);
    void OnDuration(wxCommandEvent& event);
    void OnCountdown(wxCommandEvent& event);

private:
    bool b_watchHour;
    void OnClose(wxCloseEvent& event);
    void Notify();
    void Notify2();
    void Notify3();
    bool error_found;
    bool dbg;
    int g_tick;
    wxString g_anchorwatch_sound_file;

    wxSound* m_sound;
    wxString m_soundFile;
    bool play_sound;
    bool made_sound;
    wxDateTime m_dtNow;
    void UpdateClock();
    void FillCountdown();
};

#endif

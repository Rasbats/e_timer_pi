///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/gdicmn.h>
#include <wx/textctrl.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/timer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_TIMER_REPEAT 1000
#define ID_TIMER_CLOCK 1001
#define ID_TIMER_COUNTDOWN 1002
#define ID_TIMER_DURATION 1003

///////////////////////////////////////////////////////////////////////////////
/// Class m_Dialog
///////////////////////////////////////////////////////////////////////////////
class m_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText71;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticLine* m_staticline6;
		wxStaticText* m_static_text_countup;
		wxStaticText* m_static_text_countup2;
		wxStaticText* m_static_text_countdown2;
		wxStaticText* m_static_text_repeat;
		wxStaticText* m_static_text_repeat2;
		wxStaticLine* m_staticline61;
		wxStaticLine* m_staticline4;
		wxButton* m_button3111;
		wxButton* m_button31111;
		wxStaticLine* m_staticline62;
		wxTimer m_timer_countdown;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnDLeftClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnCountUp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCountDown( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRepeat( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartTimer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopTimer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimerStopwatch( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimerRepeat( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimerClock( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimerCountDown( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimerCountUp( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimerAlarm( wxTimerEvent& event ) { event.Skip(); }


	public:
		wxBoxSizer* bSizerMain;
		wxTextCtrl* m_ClockTime;
		wxCheckBox* m_checkbox_countup;
		wxCheckBox* m_checkbox_countdown;
		wxCheckBox* m_checkbox_repeat;
		wxChoice* m_choice_countup;
		wxBoxSizer* bSizerCountdown;
		wxStaticText* m_static_text_countdown;
		wxChoice* m_choice_countdown;
		wxChoice* m_choice_repeat;
		wxTextCtrl* m_text_time;
		wxBoxSizer* bSizer71;
		wxTimer m_timer_stopwatch;
		wxTimer m_timer_repeat;
		wxTimer m_timer_clock;
		wxTimer m_timer_countup;
		wxTimer m_timer_alarm;

		m_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER );

		~m_Dialog();

};


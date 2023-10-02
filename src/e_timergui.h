///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/timer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_TIMER_2 1000
#define ID_TIMER_3 1001
#define ID_TIMER_1 1002

///////////////////////////////////////////////////////////////////////////////
/// Class m_Dialog
///////////////////////////////////////////////////////////////////////////////
class m_Dialog : public wxDialog
{
	private:

	protected:
		wxCheckBox* m_checkBoxDuration;
		wxCheckBox* m_checkBoxCountdown;
		wxCheckBox* m_checkBoxWatch;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText72;
		wxStaticText* m_staticTextDuration;
		wxStaticText* m_staticTextDuration2;
		wxStaticText* m_staticTextCD2;
		wxStaticLine* m_staticline4;
		wxButton* m_button3111;
		wxButton* m_button31111;
		wxTimer m_timer2;
		wxTimer m_timer3;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnDuration( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCountdown( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWatch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartTimer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStopTimer( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClock( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimer3( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:
		wxBoxSizer* bSizerMain;
		wxBoxSizer* bSizer8;
		wxTextCtrl* m_ClockTime;
		wxTextCtrl* m_textTime;
		wxChoice* m_duration;
		wxBoxSizer* bSizerCountdown;
		wxStaticText* m_staticTextCD;
		wxChoice* m_choiceCD;
		wxBoxSizer* bSizer71;
		wxTimer m_timer1;

		m_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("   e_timer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX|wxRESIZE_BORDER );

		~m_Dialog();

};


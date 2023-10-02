///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "e_timergui.h"

///////////////////////////////////////////////////////////////////////////

m_Dialog::m_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 183, 255, 255 ) );

	bSizerMain = new wxBoxSizer( wxVERTICAL );

	bSizer8 = new wxBoxSizer( wxVERTICAL );


	bSizerMain->Add( bSizer8, 0, wxEXPAND, 5 );

	m_ClockTime = new wxTextCtrl( this, wxID_ANY, wxT("12:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ClockTime->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_ClockTime->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	bSizerMain->Add( m_ClockTime, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_checkBoxDuration = new wxCheckBox( this, wxID_ANY, wxT("Duration"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerMain->Add( m_checkBoxDuration, 0, wxALL, 5 );

	m_checkBoxCountdown = new wxCheckBox( this, wxID_ANY, wxT("Countdown"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerMain->Add( m_checkBoxCountdown, 0, wxALL, 5 );

	m_checkBoxWatch = new wxCheckBox( this, wxID_ANY, wxT("Watch"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerMain->Add( m_checkBoxWatch, 0, wxALL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerMain->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Timer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer14->Add( m_staticText7, 0, wxALL, 5 );

	m_textTime = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_textTime, 0, wxALL, 5 );

	m_staticText72 = new wxStaticText( this, wxID_ANY, wxT("Seconds"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	bSizer14->Add( m_staticText72, 0, wxALL|wxEXPAND, 5 );


	bSizerMain->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14111111;
	bSizer14111111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextDuration = new wxStaticText( this, wxID_ANY, wxT("Duration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDuration->Wrap( -1 );
	bSizer14111111->Add( m_staticTextDuration, 0, wxALL, 5 );

	wxString m_durationChoices[] = { wxT("1"), wxT("10"), wxT("15"), wxT("20"), wxT("30"), wxT("60") };
	int m_durationNChoices = sizeof( m_durationChoices ) / sizeof( wxString );
	m_duration = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_durationNChoices, m_durationChoices, 0|wxALWAYS_SHOW_SB );
	m_duration->SetSelection( 0 );
	bSizer14111111->Add( m_duration, 1, wxALL|wxEXPAND, 5 );

	m_staticTextDuration2 = new wxStaticText( this, wxID_ANY, wxT("Minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDuration2->Wrap( -1 );
	bSizer14111111->Add( m_staticTextDuration2, 0, wxALL, 5 );


	bSizerMain->Add( bSizer14111111, 0, wxEXPAND, 5 );

	bSizerCountdown = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextCD = new wxStaticText( this, wxID_ANY, wxT("Countdown"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCD->Wrap( -1 );
	bSizerCountdown->Add( m_staticTextCD, 0, wxALL, 5 );

	wxString m_choiceCDChoices[] = { wxT("0") };
	int m_choiceCDNChoices = sizeof( m_choiceCDChoices ) / sizeof( wxString );
	m_choiceCD = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCDNChoices, m_choiceCDChoices, 0|wxALWAYS_SHOW_SB );
	m_choiceCD->SetSelection( 0 );
	bSizerCountdown->Add( m_choiceCD, 1, wxALL|wxEXPAND, 5 );

	m_staticTextCD2 = new wxStaticText( this, wxID_ANY, wxT("Minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCD2->Wrap( -1 );
	bSizerCountdown->Add( m_staticTextCD2, 0, wxALL, 5 );


	bSizerMain->Add( bSizerCountdown, 0, wxEXPAND, 5 );

	bSizer71 = new wxBoxSizer( wxVERTICAL );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer71->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	m_button3111 = new wxButton( this, wxID_ANY, wxT("START"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3111->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_button3111->SetBackgroundColour( wxColour( 0, 128, 0 ) );

	bSizer71->Add( m_button3111, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );

	m_button31111 = new wxButton( this, wxID_ANY, wxT("STOP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button31111->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_button31111->SetBackgroundColour( wxColour( 255, 0, 0 ) );

	bSizer71->Add( m_button31111, 0, wxALL|wxEXPAND, 5 );


	bSizerMain->Add( bSizer71, 1, wxEXPAND, 5 );


	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	m_timer2.SetOwner( this, ID_TIMER_2 );
	m_timer3.SetOwner( this, ID_TIMER_3 );
	m_timer1.SetOwner( this, ID_TIMER_1 );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( m_Dialog::OnClose ) );
	m_checkBoxDuration->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnDuration ), NULL, this );
	m_checkBoxCountdown->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnCountdown ), NULL, this );
	m_checkBoxWatch->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnWatch ), NULL, this );
	m_button3111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStartTimer ), NULL, this );
	m_button31111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStopTimer ), NULL, this );
	this->Connect( ID_TIMER_2, wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnClock ) );
	this->Connect( ID_TIMER_3, wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimer3 ) );
	this->Connect( ID_TIMER_1, wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimer ) );
}

m_Dialog::~m_Dialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( m_Dialog::OnClose ) );
	m_checkBoxDuration->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnDuration ), NULL, this );
	m_checkBoxCountdown->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnCountdown ), NULL, this );
	m_checkBoxWatch->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnWatch ), NULL, this );
	m_button3111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStartTimer ), NULL, this );
	m_button31111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStopTimer ), NULL, this );
	this->Disconnect( ID_TIMER_2, wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnClock ) );
	this->Disconnect( ID_TIMER_3, wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimer3 ) );
	this->Disconnect( ID_TIMER_1, wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimer ) );

}

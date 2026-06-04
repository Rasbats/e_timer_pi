///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
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

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("       e_timer") ), wxVERTICAL );


	bSizerMain->Add( sbSizer1, 0, wxEXPAND, 5 );

	m_ClockTime = new wxTextCtrl( this, wxID_ANY, wxT("12:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ClockTime->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_ClockTime->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );

	bSizerMain->Add( m_ClockTime, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerMain->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	m_staticText71 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer1->Add( m_staticText71, 0, wxALL|wxEXPAND, 5 );

	m_checkbox_countup = new wxCheckBox( this, wxID_ANY, wxT("Count Up"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_checkbox_countup, 0, wxALL|wxEXPAND, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxALL|wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer1->Add( m_staticText9, 0, wxALL|wxEXPAND, 5 );

	m_checkbox_countdown = new wxCheckBox( this, wxID_ANY, wxT("Count Down"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_checkbox_countdown, 0, wxALL|wxEXPAND, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer1->Add( m_staticText10, 0, wxALL|wxEXPAND, 5 );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer1->Add( m_staticText11, 0, wxALL|wxEXPAND, 5 );

	m_checkbox_repeat = new wxCheckBox( this, wxID_ANY, wxT("Repeat"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_checkbox_repeat, 0, wxALL|wxEXPAND, 5 );


	bSizerMain->Add( fgSizer1, 0, wxEXPAND, 5 );

	m_staticline6 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerMain->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer14111111;
	bSizer14111111 = new wxBoxSizer( wxHORIZONTAL );

	m_static_text_countup = new wxStaticText( this, wxID_ANY, wxT("Count \nUp"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text_countup->Wrap( -1 );
	bSizer14111111->Add( m_static_text_countup, 0, wxALL|wxEXPAND, 5 );

	wxString m_choice_countupChoices[] = { wxT("1"), wxT("10"), wxT("15"), wxT("20"), wxT("30"), wxT("60") };
	int m_choice_countupNChoices = sizeof( m_choice_countupChoices ) / sizeof( wxString );
	m_choice_countup = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_countupNChoices, m_choice_countupChoices, 0|wxALWAYS_SHOW_SB );
	m_choice_countup->SetSelection( 0 );
	m_choice_countup->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer14111111->Add( m_choice_countup, 1, wxALL|wxEXPAND, 5 );

	m_static_text_countup2 = new wxStaticText( this, wxID_ANY, wxT("Minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text_countup2->Wrap( -1 );
	bSizer14111111->Add( m_static_text_countup2, 0, wxALL|wxEXPAND, 5 );


	bSizerMain->Add( bSizer14111111, 0, wxEXPAND, 5 );

	bSizerCountdown = new wxBoxSizer( wxHORIZONTAL );

	m_static_text_countdown = new wxStaticText( this, wxID_ANY, wxT("Count \nDown"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text_countdown->Wrap( -1 );
	bSizerCountdown->Add( m_static_text_countdown, 0, wxALL|wxEXPAND, 5 );

	wxString m_choice_countdownChoices[] = { wxT("0") };
	int m_choice_countdownNChoices = sizeof( m_choice_countdownChoices ) / sizeof( wxString );
	m_choice_countdown = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_countdownNChoices, m_choice_countdownChoices, 0|wxALWAYS_SHOW_SB );
	m_choice_countdown->SetSelection( 0 );
	m_choice_countdown->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizerCountdown->Add( m_choice_countdown, 1, wxALL|wxEXPAND, 5 );

	m_static_text_countdown2 = new wxStaticText( this, wxID_ANY, wxT("Minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text_countdown2->Wrap( -1 );
	bSizerCountdown->Add( m_static_text_countdown2, 0, wxALL|wxEXPAND, 5 );


	bSizerMain->Add( bSizerCountdown, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer141111111;
	bSizer141111111 = new wxBoxSizer( wxHORIZONTAL );

	m_static_text_repeat = new wxStaticText( this, wxID_ANY, wxT("Repeat    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text_repeat->Wrap( -1 );
	bSizer141111111->Add( m_static_text_repeat, 0, wxALL|wxEXPAND, 5 );

	wxString m_choice_repeatChoices[] = { wxT("1"), wxT("10"), wxT("15"), wxT("20"), wxT("30"), wxT("60") };
	int m_choice_repeatNChoices = sizeof( m_choice_repeatChoices ) / sizeof( wxString );
	m_choice_repeat = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_repeatNChoices, m_choice_repeatChoices, 0|wxALWAYS_SHOW_SB );
	m_choice_repeat->SetSelection( 0 );
	m_choice_repeat->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer141111111->Add( m_choice_repeat, 0, wxALL|wxEXPAND, 5 );

	m_static_text_repeat2 = new wxStaticText( this, wxID_ANY, wxT("Minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text_repeat2->Wrap( -1 );
	bSizer141111111->Add( m_static_text_repeat2, 0, wxALL|wxEXPAND, 5 );


	bSizerMain->Add( bSizer141111111, 0, wxEXPAND, 5 );

	m_staticline61 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerMain->Add( m_staticline61, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_text_time = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_text_time->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer14->Add( m_text_time, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizerMain->Add( bSizer14, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	bSizer71 = new wxBoxSizer( wxVERTICAL );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer71->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	m_button3111 = new wxButton( this, wxID_ANY, wxT("START"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3111->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_button3111->SetBackgroundColour( wxColour( 0, 128, 0 ) );

	bSizer71->Add( m_button3111, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );

	m_button31111 = new wxButton( this, wxID_ANY, wxT("STOP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button31111->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );
	m_button31111->SetBackgroundColour( wxColour( 255, 0, 0 ) );

	bSizer71->Add( m_button31111, 0, wxALL|wxEXPAND, 5 );


	bSizerMain->Add( bSizer71, 0, wxEXPAND, 5 );

	m_staticline62 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerMain->Add( m_staticline62, 0, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );
	m_timer_stopwatch.SetOwner( this, m_timer_stopwatch.GetId() );
	m_timer_repeat.SetOwner( this, m_timer_repeat.GetId() );
	m_timer_clock.SetOwner( this, m_timer_clock.GetId() );
	m_timer_countdown.SetOwner( this, m_timer_countdown.GetId() );
	m_timer_countup.SetOwner( this, m_timer_countup.GetId() );
	m_timer_alarm.SetOwner( this, m_timer_alarm.GetId() );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( m_Dialog::OnClose ) );
	this->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( m_Dialog::OnDLeftClick ) );
	m_checkbox_countup->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnCountUp ), NULL, this );
	m_checkbox_countdown->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnCountDown ), NULL, this );
	m_checkbox_repeat->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnRepeat ), NULL, this );
	m_button3111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStartTimer ), NULL, this );
	m_button31111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStopTimer ), NULL, this );
	this->Connect( m_timer_stopwatch.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerStopwatch ) );
	this->Connect( m_timer_repeat.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerRepeat ) );
	this->Connect( m_timer_clock.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerClock ) );
	this->Connect( m_timer_countdown.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerCountDown ) );
	this->Connect( m_timer_countup.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerCountUp ) );
	this->Connect( m_timer_alarm.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerAlarm ) );
}

m_Dialog::~m_Dialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( m_Dialog::OnClose ) );
	this->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( m_Dialog::OnDLeftClick ) );
	m_checkbox_countup->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnCountUp ), NULL, this );
	m_checkbox_countdown->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnCountDown ), NULL, this );
	m_checkbox_repeat->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( m_Dialog::OnRepeat ), NULL, this );
	m_button3111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStartTimer ), NULL, this );
	m_button31111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStopTimer ), NULL, this );
	this->Disconnect( m_timer_stopwatch.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerStopwatch ) );
	this->Disconnect( m_timer_repeat.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerRepeat ) );
	this->Disconnect( m_timer_clock.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerClock ) );
	this->Disconnect( m_timer_countdown.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerCountDown ) );
	this->Disconnect( m_timer_countup.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerCountUp ) );
	this->Disconnect( m_timer_alarm.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimerAlarm ) );

}

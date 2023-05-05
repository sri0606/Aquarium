/**
 * @file MainFrame.cpp
 * @author sriram
 */

#include "pch.h"
#include "MainFrame.h"
#include "AquariumView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"Aquarium", wxDefaultPosition,  wxSize( 1000,800 ));
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
	// Create a sizer that will lay out child windows vertically
	// one above each other
	auto sizer = new wxBoxSizer( wxVERTICAL );

	// Create the view class object as a child of MainFrame
	auto aquariumView = new AquariumView();
	aquariumView->Initialize(this);

	// Add it to the sizer
	sizer->Add(aquariumView,1, wxEXPAND | wxALL );

	// Set the sizer for this frame
	SetSizer( sizer );

	// Layout (place) the child windows.
	Layout();

	auto menuBar = new wxMenuBar( );

	auto fileMenu = new wxMenu();
	auto helpMenu = new wxMenu();
	auto fishMenu = new wxMenu();
	auto decorMenu = new wxMenu();

	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
	fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save aquarium as...");
	fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open aquarium file...");

	helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

	fishMenu->Append(IDM_ADDFISHBETA, L"&Beta Fish", L"Add a Beta Fish");
	fishMenu->Append(IDM_ADDFISHANGLER, L"&Angler Fish", L"Add a Angler Fish");
	fishMenu->Append(IDM_ADDBUDDHA, L"&Nemo", L"Add a Nemo");

	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append(fishMenu, L"&Add Fish");
	menuBar->Append(helpMenu, L"&Help");
	menuBar->Append(decorMenu, L"Add decor");

	decorMenu->Append(IDM_ADDDECORCASTLE,L"&DecorCastle", L"Add a decor castle");
	SetMenuBar( menuBar );
	CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(L"Welcome to the Aquarium!",
				 L"About Aquarium",
				 wxOK,
				 this);
}

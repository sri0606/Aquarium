/**
 * @file MainFrame.h
 * @author sriram
 *
 *
 */

#ifndef AQUARIUM_AQUARIUM_MAINFRAME_H
#define AQUARIUM_AQUARIUM_MAINFRAME_H

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:

public:
	 void Initialize();

	void OnExit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
};

#endif //AQUARIUM_AQUARIUM_MAINFRAME_H

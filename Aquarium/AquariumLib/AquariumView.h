/**
 * @file AquariumView.h
 * @author sriram
 *
 *
 */

#ifndef AQUARIUM_AQUARIUM_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUM_AQUARIUMVIEW_H

#include "Aquarium.h"
/**
 * Class that defines our Aquarium view
 */
class AquariumView : public wxWindow
{
private:
		/// An object that describes our aquarium
		Aquarium mAquarium;
	    void OnPaint(wxPaintEvent& event);

		/// The timer that allows for animation
		wxTimer mTimer;

		/// Stopwatch used to measure elapsed time
		wxStopWatch mStopWatch;

		/// The last stopwatch time
		long mTime = 0;

public:
		void Initialize(wxFrame* );
		void OnAddFishBetaFish(wxCommandEvent &event);
		void OnMouseMove(wxMouseEvent &event);
		void OnLeftUp(wxMouseEvent &event);
		void OnLeftDown(wxMouseEvent &event);
		void OnDoubleClick(wxMouseEvent &event);

		/// Any item we are currently dragging
		std::shared_ptr<Item> mGrabbedItem;
		void OnAddFishAnglerFish(wxCommandEvent &event);
		void OnAddBuddhaFish(wxCommandEvent &event);
	    void OnAddDecorCastle(wxCommandEvent &event);
		void OnFileSaveAs(wxCommandEvent &event);
		void OnTimer(wxTimerEvent &event);

		void OnFileOpen(wxCommandEvent &event);
};

#endif //AQUARIUM_AQUARIUM_AQUARIUMVIEW_H

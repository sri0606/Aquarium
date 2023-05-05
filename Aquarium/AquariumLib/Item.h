/**
 * @file Item.h
 * @author srira
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_ITEM_H
#define AQUARIUM_AQUARIUMLIB_ITEM_H

/**
 * Base class for any item in our aquarium.
 */

class Aquarium;

/**
 * Class that describes any item we can add to our aquarium
 */
class Item
{
private:
	/// The aquarium this item is contained in
	Aquarium   *mAquarium;

	/// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// The underlying fish image
	std::unique_ptr<wxImage> mItemImage;

	/// The bitmap we can display for this fish
	std::unique_ptr<wxBitmap> mItemBitmap;

	bool mMirror = false;   ///< True mirrors the item image
public:
	/// Destructor
	virtual ~Item();


	void Draw(wxDC *dc);

	/**
     * The X location of the item
     * @return X location in pixels
     */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
     * The height of the item
     * @return width in pixels
     */
	double GetItemHeight() const { return mItemBitmap->GetScaledHeight(); }

	/**
     * The width of the item
     * @return width in pixels
     */
	double GetItemWidth() const { return mItemBitmap->GetScaledWidth();}

		/**
		 * Set the item location
		 * @param x X location in pixels
		 * @param y Y location in pixels
		 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Default constructor (disabled)
	Item() = delete;

	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	/// Assignment operator
	void operator=(const Item &) = delete;


	 bool HitTest(int x, int y);
	 /**
	  * Function that moves fishes
	  */
	 virtual void MoveMe(){}
	 /**
	  * Updates the state the fish
	  * @param fishstate
	  */
	 virtual void FishState(bool fishstate){}
	 /**
	  * Calculates the distance between two items
	  * @param item
 	  * @return Distance in pixels
	  */
	 double DistanceTo(std::shared_ptr<Item> item);


	 /**
	 * Get the pointer to the Aquarium object
	 * @return Pointer to Aquarium object
	 */
	 Aquarium *GetAquarium() { return mAquarium;  }

	 virtual wxXmlNode *XmlSave(wxXmlNode *node);
	 virtual void XmlLoad(wxXmlNode *node);

	/**
	* Handle updates for animation
	* @param elapsed The time since the last update
	*/
	virtual void Update(double elapsed) {}



protected:
	Item(Aquarium* aquarium, const std::wstring &filename);

	void SetMirror(bool m);
};

#endif //AQUARIUM_AQUARIUMLIB_ITEM_H

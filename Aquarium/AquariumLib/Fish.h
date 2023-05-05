/**
 * @file Fish.h
 * @author srira
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISH_H
#define AQUARIUM_AQUARIUMLIB_FISH_H
#include "item.h"

/**
 * Class that defines fish
 */
class Fish : public Item
{
private:
	/// Fish speed in the X direction
	/// in pixels per second
	double mSpeedX;

	/// Fish speed in the Y direction
	/// in pixels per second
	double mSpeedY;
public:

	/// Default constructor (disabled)
	Fish() = delete;

	/// Copy constructor (disabled)
	Fish(const Fish &) = delete;

	/// Assignment operator
	void operator=(const Fish &) = delete;
	void Update(double elapsed);

	/**
	 * Sets the speed
	 * @param speedX speed value to be set
	 * @param speedY speeed value to be set
	 */

	void SetSpeed(double speedX, double speedY) {
		mSpeedX=speedX;
		mSpeedY = speedY;
	}

	/**
	 * accelerates the fish
	 * @param speedX current speed
	 * @param elapsed time elapsed
	 * @param slow whether to slow down or speed up fish
	 * @return updated speed
	 */
	virtual double AccelerateX(double speedX,double elapsed,bool slow){return mSpeedX;};

	/**
	 * accelerates the fish
	 * @param speedY current speed
	 * @param elapsed time elapsed
	 * @param slow whether to slow down or speed up fish
	 * @return updated speed
	 */
	virtual double AccelerateY(double speedY,double elapsed,bool slow){return mSpeedY ;}

	virtual  wxXmlNode *XmlSave(wxXmlNode *node);
	virtual void XmlLoad(wxXmlNode *node);


protected:
	/**
	 * Constructor
	 * @param aquarium The aquarium we are in
	 * @param filename Filename for the image we use
	 */
	 Fish(Aquarium *aquarium, const std::wstring &filename);
};

#endif //AQUARIUM_AQUARIUMLIB_FISH_H

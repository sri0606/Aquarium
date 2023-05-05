/**
 * @file FishAngler.h
 * @author srira
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHANGLER_H
#define AQUARIUM_AQUARIUMLIB_FISHANGLER_H

#include "Item.h"
#include "Fish.h"

/**
 * Class definition of Angler fish
 */
class FishAngler: public Fish
{
private:

public:
	/// Default constructor (disabled)
	FishAngler() = delete;

	/// Copy constructor (disabled)
	FishAngler(const FishAngler &) = delete;

	/// Assignment operator
	void operator=(const FishAngler &) = delete;
	FishAngler(Aquarium* aquarium);

	wxXmlNode *XmlSave(wxXmlNode *node) override;

	double AccelerateX(double speedX,double elapsed,bool slow) override;
	double AccelerateY(double speedY,double elapsed,bool slow) override;
};

#endif //AQUARIUM_AQUARIUMLIB_FISHANGLER_H

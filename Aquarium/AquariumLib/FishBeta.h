/**
 * @file FishBeta.h
 * @author srira
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHBETA_H
#define AQUARIUM_AQUARIUMLIB_FISHBETA_H

#include "Item.h"
#include "Fish.h"

/**
 * Class definition of Beta fish
 */
class FishBeta : public Fish
{
private:


public:
	/// Default constructor (disabled)
	FishBeta() = delete;

	/// Copy constructor (disabled)
	FishBeta(const FishBeta &) = delete;

	/// Assignment operator
	void operator=(const FishBeta &) = delete;
	FishBeta(Aquarium* aquarium);
	wxXmlNode* XmlSave(wxXmlNode* node) override;

	double AccelerateX(double speedX,double elapsed,bool slow) override;
	double AccelerateY(double speedY,double elapsed,bool slow) override;

};

#endif //AQUARIUM_AQUARIUMLIB_FISHBETA_H

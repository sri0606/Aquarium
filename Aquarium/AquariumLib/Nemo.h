/**
 * @file Nemo.h
 * @author sriram
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_NEMO_H
#define AQUARIUM_AQUARIUMLIB_NEMO_H

#include "Item.h"
#include "Fish.h"
/**
 * Class definition of Nemo
 */
class Nemo : public Fish
{
private:

public:

	// Default constructor (disabled)
	Nemo() = delete;

	/// Copy constructor (disabled)
	Nemo(const Nemo &) = delete;

	/// Assignment operator
	void operator=(const Nemo &) = delete;
	Nemo(Aquarium* aquarium);

	wxXmlNode *XmlSave(wxXmlNode *node) override;

	double AccelerateX(double speedX,double elapsed,bool slow) override;
	double AccelerateY(double speedY,double elapsed,bool slow) override;
};

#endif //AQUARIUM_AQUARIUMLIB_NEMO_H

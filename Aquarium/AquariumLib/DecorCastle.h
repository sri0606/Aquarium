/**
 * @file DecorCastle.h
 * @author srira
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_DECORCASTLE_H
#define AQUARIUM_AQUARIUMLIB_DECORCASTLE_H

#include "item.h"

/**
 * Class that defines decor castle
 */
class DecorCastle : public Item
{
private:

public:

	/// Default constructor (disabled)
	DecorCastle() = delete;

	/// Copy constructor (disabled)
	DecorCastle(const DecorCastle &) = delete;

	/// Assignment operator
	void operator=(const DecorCastle &) = delete;
	DecorCastle(Aquarium* aquarium);
	wxXmlNode *XmlSave(wxXmlNode *node) override;
};

#endif //AQUARIUM_AQUARIUMLIB_DECORCASTLE_H

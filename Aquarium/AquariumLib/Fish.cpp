/**
 * @file Fish.cpp
 * @author srira
 */


#include "pch.h"
#include "Fish.h"
#include <random>
#include "Aquarium.h"
#include "item.h"
#include <math.h>

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedY = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedY = 20;

Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
	Item(aquarium, filename)
{
	std::uniform_real_distribution<> distribution1(MinSpeedX, MaxSpeedX);
	std::uniform_real_distribution<> distribution2(MinSpeedY, MaxSpeedY);
	mSpeedX = distribution1(aquarium->GetRandom());
	//mSpeedY = distribution2(aquarium->GetRandom());
	mSpeedY = sqrt(pow(mSpeedX,2)+2*mSpeedX+8) +12;
}


/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{

	SetLocation(GetX() + mSpeedX * elapsed,
				GetY() + mSpeedY * elapsed);


	if (abs(mSpeedX) > MaxSpeedX || abs(mSpeedY) > MaxSpeedY)
	{
		SetSpeed(AccelerateX(mSpeedX,elapsed,true), AccelerateY(mSpeedY,elapsed,true));
	}
//	else if (abs(mSpeedX) < MinSpeedX || abs(mSpeedY) < MinSpeedY)
//	{
//		SetSpeed(AccelerateX(mSpeedX,elapsed,false), AccelerateY(mSpeedY,elapsed,false));
//	}
	else
	{
		SetSpeed(AccelerateX(mSpeedX,elapsed,false), AccelerateY(mSpeedY,elapsed,false));
	}



	double reverse_locX = GetAquarium()->GetWidth()-10-GetItemWidth()/2;
	double reverse_locY = GetAquarium()->GetHeight()-10-GetItemHeight()/2;

	if (mSpeedX > 0  && GetX() >= reverse_locX )
	{
		mSpeedX = -(mSpeedX);
		SetMirror(true);
	}
	else if (mSpeedX<0 && GetX()<=10)
	{
		mSpeedX = -(mSpeedX);
		SetMirror(true);
	}
	if (  mSpeedY >0 && GetY() >= reverse_locY)
	{
		mSpeedY = -mSpeedY;

	}
	else if ( mSpeedY<0 && GetY() <= 10 )
	{
		mSpeedY = -(mSpeedY);
	}

}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Fish::XmlSave(wxXmlNode *node)
{
	auto itemNode = Item::XmlSave(node);
	itemNode->AddAttribute(L"speedx", wxString::FromDouble(mSpeedX));
	itemNode->AddAttribute(L"speedy", wxString::FromDouble(mSpeedY));
	return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Fish::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"speedx", L"0").ToDouble(&mSpeedX);
	node->GetAttribute(L"speedy", L"0").ToDouble(&mSpeedY);
	if (mSpeedX>0)
	{
		SetMirror(false);
	}
	else
	{
		SetMirror(true);
	}
	Item::XmlLoad(node);
}
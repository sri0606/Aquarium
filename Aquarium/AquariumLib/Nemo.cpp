/**
 * @file Nemo.cpp
 * @author srira
 */

#include "pch.h"
#include "Nemo.h"
#include "Aquarium.h"
using namespace std;

/// Nemo filename
const std::wstring NemoImageName = L"images/nemo.png";

/**
 * Constructor
 * @param aquarium Aquarium this buddha is a member of
 */
Nemo::Nemo(Aquarium *aquarium) : Fish(aquarium, NemoImageName)
{

}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Nemo::XmlSave(wxXmlNode* node)
{
	auto itemNode = Fish::XmlSave(node);
	itemNode->AddAttribute(L"type", L"nemo");
	return itemNode;
}

/**
 * updates the x speed of nemo
 * @param speedX Current speed X
 * @param elapsed time elapsed since last call
 * @param slow whether to slow down or speed up
 * @return updated speed
 */
double Nemo::AccelerateX(double speedX,double elapsed, bool slow)
{

	if (slow == false)
	{
		double sign = speedX / speedX;
		double new_speed = speedX +300 * elapsed;
		return new_speed;
	}
	else{
		double new_speed = speedX - 8 * elapsed;
		return new_speed;
	}
}

/**
 * updates the y speed of nemo
 * @param speedY Current speed Y
 * @param elapsed time elapsed since last call
 * @param slow whether to slow down or speed up
 * @return updated speed
 */
double Nemo::AccelerateY(double speedY,double elapsed, bool slow)
{
	if (slow == false)
	{
		double sign = speedY / speedY;
		double new_speed = speedY+50* elapsed;
		return new_speed;
	}
	else{
		double new_speed = speedY -10 * elapsed;
		return new_speed;
	}
}



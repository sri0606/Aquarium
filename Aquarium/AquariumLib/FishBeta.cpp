/**
 * @file FishBeta.cpp
 * @author srira
 */

#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"
using namespace std;

/// Fish filename
const std::wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{


}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
	auto itemNode = Fish::XmlSave(node);
	itemNode->AddAttribute(L"type", L"beta");
	return itemNode;
}

/**
 * updates the x speed of nemo
 * @param speedX Current speed X
 * @param elapsed time elapsed since last call
 * @param slow whether to slow down or speed up
 * @return updated speed
 */
double FishBeta::AccelerateX(double speedX,double elapsed, bool slow)
{
	if (slow == false)
	{
		double sign = speedX / speedX;
		double new_speed = speedX+ 100 * elapsed;
		return new_speed;
	}
	else{
		double new_speed = speedX - 2 * elapsed;
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
double FishBeta::AccelerateY(double speedY,double elapsed, bool slow)
{
	if (slow == false)
	{
		double sign = speedY / speedY;
		double new_speed = speedY+ 200 * elapsed;
		return new_speed;
	}
	else{
		double new_speed = speedY - 7 * elapsed;
		return new_speed;
	}
}
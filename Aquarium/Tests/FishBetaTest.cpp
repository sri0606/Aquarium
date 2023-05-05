/**
 * @file FishBetaTest.cpp
 * @author srira
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <FishBeta.h>
#include <Aquarium.h>

using namespace std;

TEST(FishBetaTest, Construct){
	Aquarium aquarium;
	FishBeta fishbeta(&aquarium);
}


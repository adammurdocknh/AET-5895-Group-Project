/*
  ==============================================================================

    APF.h
    Created: 25 Mar 2021 2:38:35pm
    Author:  Tristan Ableson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "FractionalDelay.hpp"

class APF{

public:
 
    // Constructor
    APF();

    float processSample(float x, int c);
    
private:
    
    FractionalDelay fractionalDelay;
    
    float fb = 0;
    
};

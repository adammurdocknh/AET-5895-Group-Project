/*
  ==============================================================================

    FBCF.cpp
    Created: 25 Mar 2021 2:19:20pm
    Author:  Cameron Teel

  ==============================================================================
*/

#include "FBCF.h"
#include "FractionalDelay.cpp"

FBCF::FBCF(){
}

float FBCF::processSample(float x, int channel) {
    
    float y = x; //allocating memory because it needs to exist
    
    fB = 0.f;
    x += fB;
    y = delay.processSample(w,channel);
    fB = y;
    
    return y;


}




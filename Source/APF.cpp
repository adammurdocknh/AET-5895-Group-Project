/*
  ==============================================================================

    APF.cpp
    Created: 25 Mar 2021 2:38:35pm
    Author:  Tristan Ableson

  ==============================================================================
*/

#include "APF.h"

float APF::processSample(float x, int c){

    // Pre-allocate
    float fb = 0.f;
    float y = x;
        
    // 
    float w = x + fb;
    float v = fractionalDelay.processSample(w,c);
    fb = v;
    y = w + v;
    
    return y;
}

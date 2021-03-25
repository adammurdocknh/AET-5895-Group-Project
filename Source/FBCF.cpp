/*
  ==============================================================================

    FBCF.cpp
    Created: 25 Mar 2021 2:19:20pm
    Author:  Cameron Teel

  ==============================================================================
*/

#include "FBCF.h"

FBCF::FBCF(){
}

FBCF::FBCF(float delay, float fbGain, float amp, float rate){
    this->delay = delay;
    this->fbGain = fbGain;
    this->amp = amp;
    this->rate = rate;
    
    
}

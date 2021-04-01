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

float FBCF::processSample(float x, int channel) {
    
    float y = x; //allocating memory because it needs to exist
    
    fB = 0.f;
    x += fB;
    y = delay.processSample(w,channel);
    fB = y;
    
    return y;

}

void FBCF::setFs(float newFs){
    Fs = newFs;
}

void FBCF::setfbGain(float fbGain){
    this->fbGain = fbGain;
}


void FBCF::setAmp(float amp){
    this->amp = amp;
}

void FBCF::setRate(float rate){
    this->rate = rate;
}

void FBCF::setDelay(float delay){
    w = delay;
}

void FBCF::setDepth(float depth){
    delay.setDepth(depth);
}





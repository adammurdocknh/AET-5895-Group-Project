/*
  ==============================================================================

    FBCF.cpp
    Created: 25 Mar 2021 2:19:20pm
    Author:  Cameron Teel

  ==============================================================================
*/

#include "FBCF.h"

//FBCF::FBCF(){
//}

float FBCF::processSample(float x, int channel) {
	float y = x + (-fbGain) * arr[channel];
	
	arr[channel]=delay.processSample(y, channel);
	
    return arr[channel];
}

void FBCF::setFs(float newFs){
    Fs = newFs;
	delay.setFs(newFs);
}

void FBCF::setfbGain(float newfbGain){
//    this->fbGain = fbGain;
	if (newfbGain < 1.0f) {
		if (newfbGain >= 0.0f) {
			fbGain = newfbGain;
		}
	}
};
//
//
//void FBCF::setAmp(float amp){
//    this->amp = amp;
//}

void FBCF::setRate(float rate){
    this->rate = rate;
	delay.setSpeed(rate);
}

void FBCF::setDelay(float delay){
    w = delay;
}

void FBCF::setDepth(float depth){
	delay.setDepth(depth);
}

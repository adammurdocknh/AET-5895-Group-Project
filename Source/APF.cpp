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
//    float fb = 0.f;
//    float y = x;
//
//    //
//    float w = x + fb;
//    float v = fractionalDelay.processSample(w,c);
//    fb = v;
//    y = w + v;
	float input = x + (-fb * delayedSignal);
	delayedSignal = fractionalDelay.processSample(input, c);
    
    return (delayedSignal + (fb * input));
}

void APF::setFs(float Fs){
    this->Fs = Fs;
}

void APF::setFB(float fb){
    this->fb = fb;
}

void APF::setMod(float m){
    fractionalDelay.setDepth(m);
}

void APF::setDelaySamples(float delaySamples){
    this->delaySamples = delaySamples;
    fractionalDelay.setDelaySamples(delaySamples);
}

void APF::setDelayMS(float delayMS){
    this->delayMS = delayMS;
    delaySamples = delayMS * .001 * Fs;
    fractionalDelay.setDelaySamples(delaySamples);
}

void APF::setFreqLFO(float freq){
    fractionalDelay.setSpeed(freq);
}

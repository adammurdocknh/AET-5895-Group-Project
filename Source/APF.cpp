/*
  ==============================================================================

    APF.cpp
    Created: 25 Mar 2021 2:38:35pm
    Author:  Tristan Ableson

  ==============================================================================
*/

#include "APF.h"

float APF::processSample(float x, int c){
	float input = x + (-fb * delayedSignal);
	delayedSignal = fractionalDelay.processSample(input, c);
	
	float y = delayedSignal + (fb * input);
    return y;
}

void APF::setFs(float Fs){
	this->Fs = Fs;
	fractionalDelay.setFs(Fs);
}

void APF::setFB(float fb){
    this->fb = fb;
}

void APF::setModAmp(float m){
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

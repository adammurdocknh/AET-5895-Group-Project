/*
  ==============================================================================

    Moorer.cpp
    Created: 29 Mar 2021 11:27:33pm
    Author:  William Holk

  ==============================================================================
*/

#include "Moorer.h"

Moorer::Moorer() {
    
}

float Moorer::processSample(float x, int channel){
    return x;
}

void Moorer::setReverbTime(float newReverb){
    
}

void Moorer::setModulation(float newMod){
    
}

void Moorer::setDiffusion(float newDiff){
    
}

void Moorer::setSampleRate(int newFs){
    Fs = newFs;
}

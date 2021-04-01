/*
  ==============================================================================

    Moorer.h
    Created: 29 Mar 2021 11:27:33pm
    Author:  William Holk

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "TDL.h"
#include "APF.h"
#include "FBCF.h"
#include "FractionalDelay.hpp"

class Moorer{
    
public:
    
    Moorer();
    
    float processSample(float x, int channel);
    
    void setReverbTime(float newReverb);
    
    void setModulation(float newMod);
    
    void setDiffusion(float newDiff);
    
    void setSampleRate(int newFs);
    
    TDL tdl;
    
    FBCF fbcf1;
    FBCF fbcf2;
    FBCF fbcf3;
    FBCF fbcf4;
    
    APF apf1;
    APF apf2;
    
    
    
    
private:
    
    int Fs = 48000;
    
};

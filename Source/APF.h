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
    
    void setFs(float Fs);
    
    void setFB(float fb);
    
    void setMod(float m);
    
    void setDelaySamples(float delaySamples);
    void setDelayMS(float delayMS);
    void setFreqLFO(float freq);
    
private:
    
    FractionalDelay fractionalDelay;
    
    float fb = 0;
    
    int Fs = 48000;
    
    float delaySamples;
    float delayMS;
    
};

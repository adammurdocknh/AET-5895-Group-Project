/*
  ==============================================================================

    Moorer.h
    Created: 29 Mar 2021 11:27:33pm
    Author:  William Holk

  ==============================================================================
*/

#pragma once

class Moorer{
    
public:
    
    Moorer();
    
    float processSample(float x, int channel);
    
    void setReverbTime(float newReverb);
    
    void setModulation(float newMod);
    
    void setDiffusion(float newDiff);
    
    void setSampleRate(int newFs);
    
    
private:
    
    int Fs = 48000;
    
};

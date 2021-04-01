/*
  ==============================================================================

    FBCF.h
    Created: 25 Mar 2021 2:19:20pm
    Author:  Cameron Teel

  ==============================================================================
*/

#pragma once
#include <cmath>
#include "FractionalDelay.hpp"

class FBCF {
    
    
public:
    
    // Constructor
    FBCF();
    
    // What do we need to pass in here?
    FBCF(float delay, float fbGain, float amp, float rate);
    
    // Destructor
    ~FBCF();
    
    void processSignal(float * signal, const int numSamples, const int channel);

    float processSample(float x,int channel);
    
    void setFs(float newFs);
    
    void setDelay(float delay);
    void setfbGain(float fbGain);
    void setAmp(float amp);
    void setRate(float rate);
    void setDepth(float depth);
    
    
    
    
private:
    
    
    float fB = 0.0f;
    
    int Fs = 48000;
    
   // float delay = .05f; // Max delay time of 50 ms, where do we do conversion?
    
    const int MAX_BUFFERSIZE = 96000;
    float delayBuffer[96000][2] = {0.0f};
    int index[2] = {0};
    
    float fbGain = 0.25f; // <1
    float amp = 1.0f; //[0-1]
    float rate = 1.0f; // Hz, speed of LFO?
    
    // input needs to be in samples for delay
    int w = 100.f; //delay in samples
    FractionalDelay delay{static_cast<float>(w),1.1f};
    
    

};

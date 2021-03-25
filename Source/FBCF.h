/*
  ==============================================================================

    FBCF.h
    Created: 25 Mar 2021 2:19:20pm
    Author:  Cameron Teel

  ==============================================================================
*/

#pragma once
#include <cmath>

class FBCF {
    
    
public:
    
    // Constructor
    FBCF();
    
    // What do we need to pass in here?
    FBCF(float delay, float fbGain, float amp, float rate);
    
    // Destructor
    ~FBCF();
    
    float processSample(float x,int channel,int buffer);
    
    void setFs(float Fs);
    
    void setDelay(float delay);
    void setfbGain(float fbGain);
    void setAmp(float amp);
    void setRate(float rate);
    
    
    
    
private:
    
    float Fs = 48000.f;
    
    float delay = .05f; // Max delay time of 50 ms, where do we do conversion?
    
    const int MAX_BUFFERSIZE = 96000;
    float delayBuffer[96000][2] = {0.0f};
    int index[2] = {0};
    
    float fbGain = 0.25f; // <1
    float amp = 1.0f; //[0-1]
    float rate = 1.0f; // Hz, speed of LFO?
    
    

};

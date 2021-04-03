/*
  ==============================================================================

    Moorer.cpp
    Created: 29 Mar 2021 11:27:33pm
    Author:  William Holk

  ==============================================================================
*/

#include "Moorer.h"

Moorer::Moorer() {
    fbcf1.setDelay(1426);
    fbcf2.setDelay(1781);
    fbcf3.setDelay(1973);
    fbcf4.setDelay(2098);
    
    fbcf1.setfbGain(0.7f);
    fbcf2.setfbGain(0.7f);
    fbcf3.setfbGain(0.7f);
    fbcf4.setfbGain(0.7f);
    
    fbcf1.setDepth(.1);
    fbcf2.setDepth(.1);
    fbcf3.setDepth(.1);
    fbcf4.setDepth(.1);
    
    fbcf1.setRate(.99);
    fbcf2.setRate(.91);
    fbcf3.setRate(.93);
    fbcf4.setRate(.97);
    
    apf1.setModAmp(.1);
    apf2.setModAmp(.1);
    
    apf1.setFreqLFO(1.1);
    apf2.setFreqLFO(1.2);
    
    apf1.setFB(.7);
    apf2.setFB(.7);
    
    apf1.setDelaySamples(240);
    apf2.setDelaySamples(82);
    
}

float Moorer::processSample(float x, int channel){
    
    x = tdl.processSample(x, channel);
    
    float x1 = fbcf1.processSample(x, channel);
    float x2 = fbcf2.processSample(x, channel);
    float x3 = fbcf3.processSample(x, channel);
    float x4 = fbcf4.processSample(x, channel);
    
    x = (x1 + x2 + x3 + x4) * 0.5f;
    
    x = apf1.processSample(x, channel);
    x = apf2.processSample(x, channel);
    
    float y = x;
    
    return y;
}

void Moorer::setReverbTime(float newReverb){
    fbcf1.setfbGain(newReverb);
    fbcf2.setfbGain(newReverb);
    fbcf3.setfbGain(newReverb);
    fbcf4.setfbGain(newReverb);
}

void Moorer::setModulation(float newMod){
    apf1.setModAmp(newMod);
    apf2.setModAmp(newMod);
    fbcf1.setDepth(newMod);
    fbcf2.setDepth(newMod);
    fbcf3.setDepth(newMod);
    fbcf4.setDepth(newMod);
}

void Moorer::setDiffusion(float newDiff){
    if(newDiff > 0.99){
        newDiff = 0.99;
    }
    if(newDiff < 0.01){
        newDiff = 0.01;
    }
    
    apf1.setFB(newDiff-0.01);
    apf2.setFB(newDiff-0.03);
    
}

void Moorer::setSampleRate(int newFs){
    Fs = newFs;
    fbcf1.setFs(Fs);
    fbcf2.setFs(Fs);
    fbcf3.setFs(Fs);
    fbcf4.setFs(Fs);
    apf1.setFs(Fs);
    apf2.setFs(Fs);
    tdl.setFs(Fs);
    
}

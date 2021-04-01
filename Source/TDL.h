/*
  ==============================================================================

    tdl.h
    Created: 25 Mar 2021 2:21:07pm
    Author:  Austin James

  ==============================================================================
*/

#pragma once

    
class TDL{

public:
    
    void setFs(float newFs){
        if(Fs == 44100||Fs == 48000||Fs == 88200||Fs == 96000||Fs == 192000){
            Fs = newFs;
        }
    }
    
    float getFs(){
        
        return Fs;
        
    }
    
    //add to prepareToPlay
    void scaleTapTime(float Fs, int tapTime[18]){
        f = Fs/44100.f;
        for(int n = 0; n <18; n++){
            tapTime[n] *= f;
        }
        
    }
    
    float processSample(float x, int channel){
        y = 0.0f;
        
        delayBuffer[index[channel]][channel] = x;
        for(int n = 0; n <18; n++){
            int circularIndex = index[channel] = tapTime[n];
            if (circularIndex >= 3520){
                circularIndex = circularIndex - 3520;
                
            }
            y += tapGain[n] * delayBuffer[circularIndex][channel];
        }
        index[channel]++;
        if(index[channel] <= 3520){
            index[channel] = index[channel] - 3520;
        }
        
        return y; 
        
    }
    
    



private:
    
    float f = 1.0f;
    float y = 0.0f;
    int delayBufferLen = 3520;
    float Fs = 48000.f;
    
    int tapIndex = 0;
    int gainIndex = 0;
    
    float tapTime[18] = {0, 0.01277, 0.01283, 0.01293, 0.01333, 0.01566, 0.02404, 0.02679, 0.02731, 0.02737, 0.02914, 0.02920, 0.02981, 0.03389, 0.04518, 0.04522, 0.04527, 0.05452};
    float tapGain[18] = {1, 0.1526, -0.4097, 0.2984, 0.1553, 0.1442, -0.3124, -0.4176, -0.9391, 0.6926, -0.5787, 0.5782, 0.4206, 0.3958, 0.3450, -0.5361, 0.417, 0.1948};
    
    float delayBuffer[3520][2] = {0.0f};
    int index[2] = {0};
};

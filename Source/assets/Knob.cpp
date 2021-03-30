/*
  ==============================================================================

    Knob.cpp
    Created: 25 Mar 2021 2:42:46pm
    Author:  Adam Murdock

  ==============================================================================
*/

#include "Knob.h"

void LargeKnob::drawRotarySlider (Graphics& g,
                                      int x,
                                      int y,
                                      int width,
                                      int height,
                                      float sliderPos,
                                      const float rotaryStartAngle,
                                      const float rotaryEndAngle,
                                      Slider& slider)
{
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    
    AffineTransform rotator;
    g.drawImageTransformed(sprite, rotator.rotated(angle, (float)(sprite.getWidth()/2), (float)(sprite.getHeight()/2)));
}

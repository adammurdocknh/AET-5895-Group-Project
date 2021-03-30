/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessorEditor::AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(1000,700);
	bgImage = ImageCache::getFromMemory(BinaryData::gui_draft_png, BinaryData::gui_draft_pngSize);
//	timeSlider.addListener(this);
	timeSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	timeSlider.setBounds(155,417,150,150);
	timeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	timeSlider.setLookAndFeel(&knob);
	addAndMakeVisible(timeSlider);
	
	
	diffuseSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	diffuseSlider.setBounds(335,417,150,150);
	diffuseSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	diffuseSlider.setLookAndFeel(&knob);
	addAndMakeVisible(diffuseSlider);
	
	
	modSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	modSlider.setBounds(515,417,150,150);
	modSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	modSlider.setLookAndFeel(&knob);
	addAndMakeVisible(modSlider);

	mixSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	mixSlider.setBounds(695,417,150,150);
	mixSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	mixSlider.setLookAndFeel(&knob);
	addAndMakeVisible(mixSlider);

}

AlgoReverbAudioProcessorEditor::~AlgoReverbAudioProcessorEditor()
{
}

//==============================================================================
void AlgoReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.drawImageAt(bgImage, 0, 0);
}

void AlgoReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void AlgoReverbAudioProcessorEditor::sliderValueChanged(Slider *slider) {
	if (slider == &timeSlider) {
		audioProcessor.time = timeSlider.getValue();
	}
	if (slider == &diffuseSlider) {
		audioProcessor.diffuse = diffuseSlider.getValue();
	}
	if (slider == &modSlider) {
		audioProcessor.mod = modSlider.getValue();
	}
	if (slider == &mixSlider) {
		audioProcessor.mix = mixSlider.getValue();
	}
}

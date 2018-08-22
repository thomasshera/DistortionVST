/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
DistortionVstAudioProcessorEditor::DistortionVstAudioProcessorEditor (DistortionVstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	addAndMakeVisible(driveKnob = new Slider("Drive"));
	driveKnob->setSliderStyle(Slider::LinearVertical);
	driveKnob->setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
	driveKnob->setTextValueSuffix("\nDrive");

	addAndMakeVisible(rangeKnob = new Slider("Range"));
	rangeKnob->setSliderStyle(Slider::LinearVertical);
	rangeKnob->setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
	rangeKnob->setTextValueSuffix("\nRange");

	addAndMakeVisible(blendKnob = new Slider("Blend"));
	blendKnob->setSliderStyle(Slider::LinearVertical);
	blendKnob->setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
	blendKnob->setTextValueSuffix("\nBlend");

	addAndMakeVisible(volumeKnob = new Slider("Volume"));
	volumeKnob->setSliderStyle(Slider::LinearVertical);
	volumeKnob->setTextBoxStyle(Slider::TextBoxBelow, false, 100, 50);
	volumeKnob->setTextValueSuffix("\nVolume");

	driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob);
	rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
	blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob);
	volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	localWidth = 400;
	localHeight = 200;

	setSize(localWidth, localHeight);
}

DistortionVstAudioProcessorEditor::~DistortionVstAudioProcessorEditor()
{
}

//==============================================================================
void DistortionVstAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
}

void DistortionVstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	auto area = getLocalBounds();

	buttonWidth = getWidth() / 4;
	//buttonHeight = getHeight() / 2;
	
	driveKnob->setBounds(area.removeFromLeft(buttonWidth));
	rangeKnob->setBounds(area.removeFromLeft(buttonWidth));
	blendKnob->setBounds(area.removeFromLeft(buttonWidth));
	volumeKnob->setBounds(area.removeFromLeft(buttonWidth));
}
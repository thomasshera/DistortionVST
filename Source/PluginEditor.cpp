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
	driveKnob->setSliderStyle(Slider::Rotary);
	driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(rangeKnob = new Slider("Range"));
	rangeKnob->setSliderStyle(Slider::Rotary);
	rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(blendKnob = new Slider("Blend"));
	blendKnob->setSliderStyle(Slider::Rotary);
	blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(volumeKnob = new Slider("Volume"));
	volumeKnob->setSliderStyle(Slider::Rotary);
	volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob);
	rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
	blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob);
	volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	localWidth = 500;
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
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void DistortionVstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	auto area = getLocalBounds();

	buttonWidth = localWidth / 4;
	buttonHeight = localHeight / 2;
	
	driveKnob->setBounds(area.removeFromLeft(buttonWidth));
	rangeKnob->setBounds(area.removeFromLeft(buttonWidth));
	blendKnob->setBounds(area.removeFromLeft(buttonWidth));
	volumeKnob->setBounds(area.removeFromLeft(buttonWidth));
}
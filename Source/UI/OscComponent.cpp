/*
  ==============================================================================

    OscComponent.cpp
    Author:  jaymi

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String oscId, juce::String gainId, juce::String pitchId, juce::String fmFreqId, juce::String fmDepthId)
: gain    ("GAIN",     gainId,    apvts, dialWidth, dialHeight)
, pitch   ("PITCH",    pitchId,   apvts, dialWidth, dialHeight)
, fmFreq  ("FM FREQ",  fmFreqId,  apvts, dialWidth, dialHeight)
, fmDepth ("FM DEPTH", fmDepthId, apvts, dialWidth, dialHeight)
{
    juce::StringArray oscChoices { "SIN", "SAW", "SQR" };
    oscSelector.addItemList (oscChoices, 1);
    oscSelector.setSelectedItemIndex (0);
    addAndMakeVisible (oscSelector);
    
    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, oscId, oscSelector);
    
    addAndMakeVisible (gain);
    addAndMakeVisible (pitch);
    addAndMakeVisible (fmFreq);
    addAndMakeVisible (fmDepth);
}

OscComponent::~OscComponent()
{
}


void OscComponent::resized()
{
    const auto yStart = 15;
    const auto width  = 70;
    const auto height = 88;
    
    oscSelector.setBounds (27, 38, 100, 25);
    gain.setBounds    (142, yStart, width, height);
    pitch.setBounds   (190+20, yStart, width, height);
    fmFreq.setBounds  (260+16, yStart, width, height);
    fmDepth.setBounds (330+13, yStart, width, height);
}

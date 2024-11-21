/*
  ==============================================================================

    FilterComponent.cpp
    Author:  jaymi

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent (juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeId, juce::String cutoffId, juce::String resonanceId)
: cutoff    ("CUTOFF", cutoffId,    apvts, dialWidth, dialHeight)
, resonance ("RESO",   resonanceId, apvts, dialWidth, dialHeight)
{
    juce::StringArray filterTypeChoices { "LOW-PASS", "BND-PASS", "HI-PASS" };
    filterTypeSelector.addItemList (filterTypeChoices, 1);
    filterTypeSelector.setSelectedItemIndex (0);
    addAndMakeVisible (filterTypeSelector);
    
    filterTypeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, filterTypeId, filterTypeSelector);
    
    addAndMakeVisible (cutoff);
    addAndMakeVisible (resonance);
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::resized()
{
    const auto startX = 18;
    const auto startY = 80;
    const auto width  = 70;
    const auto height = 88;
    
    filterTypeSelector.setBounds (18, 40, 145, 25);
    cutoff.setBounds    (startX, startY, width, height);
    resonance.setBounds (cutoff.getRight(), startY, width, height);
}



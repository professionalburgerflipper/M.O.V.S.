/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/OscComponent.h"
#include "UI/FilterComponent.h"
#include "UI/AdsrComponent.h"
#include "UI/LfoComponent.h"
#include "UI/ReverbComponent.h"

//==============================================================================
/**
*/
class MOVSAudioProcessorEditor  : public juce::AudioProcessorEditor
, public juce::Timer
{
public:
    MOVSAudioProcessorEditor (MOVSAudioProcessor&);
    ~MOVSAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override;

private:
    MOVSAudioProcessor& audioProcessor;
    OscComponent osc1;
    OscComponent osc2;
    FilterComponent filter;
    AdsrComponent adsr;
    LfoComponent lfo1;
    AdsrComponent filterAdsr;
    ReverbComponent reverb;
    juce::Image image; //background image
    juce::JPEGImageFormat* j; //necessary to convert background image format

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MOVSAudioProcessorEditor)
};

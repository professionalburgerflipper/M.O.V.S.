/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MOVSAudioProcessorEditor::MOVSAudioProcessorEditor (MOVSAudioProcessor& p)
: AudioProcessorEditor (&p)
, audioProcessor (p)
, osc1       (audioProcessor.apvts, "OSC1", "OSC1GAIN", "OSC1PITCH", "OSC1FMFREQ", "OSC1FMDEPTH")
, osc2       (audioProcessor.apvts, "OSC2", "OSC2GAIN", "OSC2PITCH", "OSC2FMFREQ", "OSC2FMDEPTH")
, filter     (audioProcessor.apvts, "FILTERTYPE", "FILTERCUTOFF", "FILTERRESONANCE")
, adsr       (audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE")
, lfo1       (audioProcessor.apvts, "LFO1FREQ", "LFO1DEPTH")
, filterAdsr (audioProcessor.apvts, "FILTERATTACK", "FILTERDECAY", "FILTERSUSTAIN", "FILTERRELEASE")
, reverb     (audioProcessor.apvts, "REVERBSIZE", "REVERBDAMPING", "REVERBWIDTH", "REVERBDRY", "REVERBWET", "REVERBFREEZE")
{
    juce::File backgroundFile = juce::File::getCurrentWorkingDirectory().getChildFile("../../Assets/tapLogo.png");
    image = j->loadFrom(backgroundFile);


    // Add segments to GUI
    addAndMakeVisible (osc1);
    addAndMakeVisible (osc2);
    addAndMakeVisible (filter);
    addAndMakeVisible (adsr);
    addAndMakeVisible (lfo1);
    addAndMakeVisible (filterAdsr);
    addAndMakeVisible (reverb);
    
    // Set segement names
    osc1.setName       ("OSC1");
    osc2.setName       ("OSC2");
    filter.setName     ("FILTER");
    lfo1.setName       ("FILTER LFO");
    filterAdsr.setName ("FILTER ADSR");
    adsr.setName       ("ADSR");
    reverb.setName     ("REVERB");
        
    startTimerHz (30);
    // Set window size (72:35 Ratio)
    setSize (1080, 525);
}

MOVSAudioProcessorEditor::~MOVSAudioProcessorEditor()
{
    stopTimer();
}

//==============================================================================
void MOVSAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Paint background of window black
    g.fillAll (juce::Colours::black);
    g.drawImage(image, 100, 340, 2000, 2000, 100, 0, 2000, 2000);
}

void MOVSAudioProcessorEditor::resized()
{
    // Height and Width for Oscillator Segments, shared by OSC1 and OSC2 segments
    const auto oscWidth  = 420;
    const auto oscHeight = 100;

    // Set bounds for OSC segments
    osc1.setBounds       (0, 0, oscWidth, oscHeight);
    osc2.setBounds       (0, osc1.getBottom(), oscWidth, oscHeight);

    // Set bounds for filter segment
    filter.setBounds     (osc1.getRight(), 0, 180, 200);

    // Set bounds for filterADSR segment
    filterAdsr.setBounds (filter.getRight(), 0, 230, 360);

    // Set bounds for ADSR segment
    adsr.setBounds       (filterAdsr.getRight(), 0, 230, 360);

    // Set bounds for LFO segment
    lfo1.setBounds       (osc2.getRight(), filter.getBottom() - 2, 180, 160);

    // Set bounds for reverb segment
    reverb.setBounds     (0, osc2.getBottom(), oscWidth, 150);
}

void MOVSAudioProcessorEditor::timerCallback()
{
    repaint();
}

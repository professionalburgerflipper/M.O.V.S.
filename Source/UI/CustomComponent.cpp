/*
  ==============================================================================

    CustomComponent.cpp
    Author:  jaymi

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CustomComponent.h"

//==============================================================================

using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
using SliderStyle = juce::Slider::SliderStyle;

SliderWithLabel::SliderWithLabel (juce::String labelName, juce::String paramId, juce::AudioProcessorValueTreeState& apvts, const int width, const int height, SliderStyle style)
{
    sliderWidth  = width;
    sliderHeight = height;
    
    slider.setSliderStyle  (style);
    slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    addAndMakeVisible (slider);
    
    label.setFont (15);
    label.setText (labelName, juce::dontSendNotification);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
    
    attachment = std::make_unique<SliderAttachment>(apvts,  paramId,  slider);
}

void SliderWithLabel::resized()
{
    const auto dialToLabelRatio = 15;
    const auto labelHeight      = 18;
    
    jassert (sliderWidth  > 0);
    jassert (sliderHeight > 0);
    
    label.setBounds  (0, 0, sliderWidth, labelHeight);
    slider.setBounds (0, 0 + dialToLabelRatio, sliderWidth, sliderHeight);
}


CustomComponent::CustomComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

CustomComponent::~CustomComponent()
{
}

void CustomComponent::paint (juce::Graphics& g)
{
    g.setColour (juce::Colours::white);
    g.setFont   (fontHeight);
    g.setFont   (g.getCurrentFont().boldened());
    
    jassert    (name.isNotEmpty());
    g.drawText (name, 20, 15, 100, 25, juce::Justification::left);
}

void CustomComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}


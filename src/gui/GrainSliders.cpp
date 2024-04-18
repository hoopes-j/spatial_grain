//
//  GrainSliders.cpp
//  granular
//
//  Created by Jason Hoopes on 3/19/24.
//

#include "GrainSliders.hpp"


void GrainSliders::setup(int numGrains) {
    params.setName("pitch");
    
    pitches.resize(numGrains);
    this->numGrains = numGrains;
    params.add(pitchSpread.set("pitch spread", 0.0, 0.0, 1.0));
    params.add(manualPitch.set("manual pitch", false));
    for (int i = 0; i < numGrains; i++) {
        std::string sliderName = "pitch"+std::to_string(i);
        params.add(pitches[i].set(sliderName, 1.0, -2.0, 2.0));
    }
    
    params.add(pitchMultiplier.set("global multiplier", 1.0, -2.0, 2.0));
    
    
    // Warp Group
    warpGroup.setName("warping");
    warpGroup.add(numWarpPoints.set("Transient Number", 1.0, 1.0, 10.0));
    warpGroup.add(warpAmount.set("warp", 1.0, 0.0, 1.0));
    
    setupWindowTypeSelector();
}


bool GrainSliders::setupWindowTypeSelector() {
    // Windowing
    std::vector<string> windowTypes = {
        "Tukey",
        "Raised Cosine"
    };
    windowDropdown =  make_unique<ofxDropdown>("Window Function");
    for (int i = 0; i < windowTypes.size(); i++) {
        windowDropdown->add(windowTypes[i]);
    }
    windowDropdown->addListener(this, &GrainSliders::ofWindowTypeChanged);
    
    return true;
}

void GrainSliders::setPitches(float * newPitches) {
    for (int i  = 0; i < numGrains; i++) {
        pitches[i] = newPitches[i];
    
    }
    
}

void GrainSliders::ofWindowTypeChanged(string & output) {
    
    std::cout << output << std::endl;
    
}

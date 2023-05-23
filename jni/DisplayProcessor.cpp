//
//  DisplayProcess.cpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.

#include "DisplayProcessor.hpp"

DisplayProcessor::DisplayProcessor(DisplayBoard* displayBoard, int index) {
    this->displayBoard = displayBoard;
    this->index = index;
}

DisplayProcessor::~DisplayProcessor() {
    
}

void DisplayProcessor::process(Mat& frame) {
    this->displayBoard->put(frame, this->index);
}

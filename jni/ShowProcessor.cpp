//
//  ShowProcessor.cpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.
//

#include "ShowProcessor.hpp"

ShowProcessor::ShowProcessor(int cameraId, DisplayBoard* displayBoard, int index)
{
    this->cameraId = cameraId;
    this->displayBoard = displayBoard;
    this->index = index;
}

ShowProcessor::~ShowProcessor()
{
}

void ShowProcessor::process(Mat &frame)
{
    this->displayBoard->put(frame, this->index);
}
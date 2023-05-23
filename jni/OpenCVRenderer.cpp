//
//  OpenCVRenderer.cpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.
//


#include "OpenCVRenderer.hpp"

#define DISPLAY_BOARD_NAME "QView v1.0"



OpenCVRenderer::OpenCVRenderer() {
    namedWindow(DISPLAY_BOARD_NAME, cv::WINDOW_NORMAL);//VuongNQb
    this->exitPending = false;
}

OpenCVRenderer::~OpenCVRenderer() {
}

void OpenCVRenderer::prepare(const cv::Mat& frame) {
    frame.copyTo(this->frame);
}

void OpenCVRenderer::render() {
    imshow(DISPLAY_BOARD_NAME, this->frame);//VuongNQb
    this->exitPending = cv::waitKey(30) == 27;
}

bool OpenCVRenderer::running() {
    return !this->exitPending;
}

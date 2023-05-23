/*
 File name: Renderer.cpp
 Project name: QView v1.0

 Created by Luu Kien on 16/02/2023
 Copyright © Luu Kien 16/02/2023. All rights reserved.
*/

#ifndef Renderer_hpp
#define Renderer_hpp

#include <opencv2/opencv.hpp>

class Renderer {
public:
    Renderer();
    virtual ~Renderer();
    virtual void prepare(const cv::Mat& frame) = 0;
    virtual void render() = 0;
    virtual bool running() = 0;
};

#endif /* Renderer_hpp */

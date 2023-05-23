//
//  DisplayBoard.cpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.

#ifndef DisplayBoard_hpp
#define DisplayBoard_hpp

#include <mutex>
#include <opencv2/opencv.hpp>

#include "Renderer.hpp"

using namespace cv;

class DisplayBoard {
public:
    DisplayBoard();
    ~DisplayBoard();
    void loop();
    void setRenderer(Renderer* renderer);
    void setClientSize(int width, int height);
    void setGridSize(int rows, int cols);
    void put(Mat& image, int index);
    void print(const char* text, int index);
    
private:
    int rows;
    int cols;
    Mat frame;
    Renderer* renderer;
    
    pthread_mutex_t mutex;
};

#endif /* DisplayBoard_hpp */

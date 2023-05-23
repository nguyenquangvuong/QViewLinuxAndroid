//
//  DisplayBoard.cpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.
//

#include "DisplayBoard.hpp"



DisplayBoard::DisplayBoard() {
    this->rows = 1;
    this->cols = 1;
    this->frame = Mat(720, 1280, CV_8UC3, Scalar(0, 0, 0));
    pthread_mutex_init(&this->mutex, NULL);
}

DisplayBoard::~DisplayBoard() {
    pthread_mutex_destroy(&this->mutex);
}

void DisplayBoard::loop() {
    pthread_mutex_lock(&this->mutex);
    this->renderer->prepare(this->frame);
    
    pthread_mutex_unlock(&this->mutex);
    this->renderer->render();
}

void DisplayBoard::setRenderer(Renderer *renderer) {
    this->renderer = renderer;
}

void DisplayBoard::setClientSize(int width, int height) {
    this->frame = Mat(height, width, CV_8UC3, Scalar(0, 0, 0));
}

void DisplayBoard::setGridSize(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
}

void DisplayBoard::put(Mat& image, int index) {
    if (image.data == NULL) {
        return;
    }
    
    if (index >= this->rows * this->cols) {
        return;
    }
    
    int row = index / this->cols;
    int col = index % this->cols;
    
    int rowHeight = this->frame.rows / this->rows;
    int colWidth = this->frame.cols / this->cols;
    
    Rect roi(col * colWidth, row * rowHeight, colWidth, rowHeight);
    Mat small;
    resize(image, small, Size(colWidth, rowHeight), 0.0, 0.0, INTER_NEAREST);

    pthread_mutex_lock(&this->mutex);
    Mat dst = this->frame(roi);
    small.copyTo(dst);
    pthread_mutex_unlock(&this->mutex);
}
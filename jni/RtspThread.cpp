//
//  RtspThread.cpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.
//
#include "RtspThread.hpp"

RtspThread::RtspThread(const String& url, Processor* processor) {
    this->url = url;
    this->processor = processor;
}

RtspThread::~RtspThread() {
    
}

void RtspThread::start() {
    pthread_create(&this->thread, NULL, threadFunc, this);
}

void RtspThread::localThreadFunc() {
    while (true) {
        // printf("Start retrieve from %s\n", url.c_str());
        Mat image;
        VideoCapture cap(this->url, cv::CAP_FFMPEG);
        while (true) {
            cap >> image;
            if (image.empty()) {
                // printf("Imge getted empty ! %s\n", url.c_str());
                break;
            }
            this->processor->process(image);
        }
        // printf("RTSP stream ended.\n");
        sleep(1);
    }
}

void* RtspThread::threadFunc(void* arg) {
    RtspThread* thread = (RtspThread*)arg;
    thread->localThreadFunc();
    pthread_exit(NULL);
}

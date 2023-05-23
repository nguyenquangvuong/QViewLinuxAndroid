/*
 RtspThread.hpp
 QView v1.0

 Created by Luu Kien on 16/02/2023
 Copyright © 2020 16/02/2023. All rights reserved.
*/

#ifndef RtspThread_hpp
#define RtspThread_hpp

#include <unistd.h>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Processor.hpp"

using namespace std;
using namespace cv;

class RtspThread {
public:
    RtspThread(const String& url, Processor* processor);
    ~RtspThread();
    void start();
    
private:
    String url;
    Processor* processor;
    pthread_t thread;
    
    void localThreadFunc();
    static void* threadFunc(void* arg);
};

#endif /* RtspThread_hpp */

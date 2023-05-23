//
//  main.cpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <thread>
#include <deque>
#include <mutex>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "config.h"

#include "Processor.hpp"
#include "RtspThread.hpp"
#include "DisplayBoard.hpp"
#include "DisplayProcessor.hpp"

#include "ShowProcessor.hpp" //LuuKien

#include "OpenCVRenderer.hpp"

using namespace cv;
using namespace std;

Renderer* renderer = NULL;
DisplayBoard* displayBoard = NULL;

ShowProcessor* processor0 = NULL;
ShowProcessor* processor1 = NULL;
ShowProcessor* processor2 = NULL;
ShowProcessor* processor3 = NULL;
ShowProcessor* processor4 = NULL;
ShowProcessor* processor5 = NULL;
ShowProcessor* processor6 = NULL;
ShowProcessor* processor7 = NULL;

RtspThread* thread0 = NULL;
RtspThread* thread1 = NULL;
RtspThread* thread2 = NULL;
RtspThread* thread3 = NULL;
RtspThread* thread4 = NULL;
RtspThread* thread5 = NULL;
RtspThread* thread6 = NULL;
RtspThread* thread7 = NULL;


int main(int argc, char** argv) {

    renderer = new OpenCVRenderer();
    
    displayBoard = new DisplayBoard();
    displayBoard->setClientSize(1000 * RESOLUTION, 500*RESOLUTION);//1920X1080
    displayBoard->setGridSize(3, 3);
    displayBoard->setRenderer(renderer);

    processor0 = new ShowProcessor(0, displayBoard, 0);
    thread0 = new RtspThread(CAM_LINK_1, processor0);
    thread0->start();
    
    processor1 = new ShowProcessor(1, displayBoard, 1);
    thread1 = new RtspThread(CAM_LINK_2, processor1);
    thread1->start();

    processor2 = new ShowProcessor(2, displayBoard, 2);
    thread2 = new RtspThread(CAM_LINK_3, processor2);
    thread2->start();

    processor3 = new ShowProcessor(3, displayBoard, 3);
    thread3 = new RtspThread(CAM_LINK_4, processor3);
    thread3->start();

    processor4 = new ShowProcessor(4, displayBoard, 4);
    thread4 = new RtspThread(CAM_LINK_5, processor4);
    thread4->start();

    processor5 = new ShowProcessor(5, displayBoard, 5);
    thread5 = new RtspThread(CAM_LINK_6, processor5);
    thread5->start();

    processor6 = new ShowProcessor(6, displayBoard, 6);
    thread6 = new RtspThread(CAM_LINK_7, processor6);
    thread6->start();

    processor7 = new ShowProcessor(7, displayBoard, 7);
    thread7 = new RtspThread(CAM_LINK_8, processor7);
    thread7->start();

    while (renderer->running()) {
        displayBoard->loop();
    }

    return 0;
}

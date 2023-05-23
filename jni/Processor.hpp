//
//  Processor.hpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.

#ifndef Processor_hpp
#define Processor_hpp

#include <opencv2/opencv.hpp>

using namespace cv;

class Processor {
public:
    Processor();
    virtual ~Processor();
    virtual void process(Mat& frame) = 0;
};

#endif /* Processor_hpp */

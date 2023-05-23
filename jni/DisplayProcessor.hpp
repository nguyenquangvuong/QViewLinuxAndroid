//
//  DisplayProcess.Hpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.

#ifndef DisplayProcessor_hpp
#define DisplayProcessor_hpp

#include "Processor.hpp"
#include "DisplayBoard.hpp"

class DisplayProcessor: public Processor {
public:
    DisplayProcessor(DisplayBoard* displayBoard, int index);
    virtual ~DisplayProcessor();
    virtual void process(Mat& frame);
    
    DisplayBoard* displayBoard;
    int index;
};

#endif /* DisplayProcessor_hpp */

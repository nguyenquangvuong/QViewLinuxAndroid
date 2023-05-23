//
//  ShowProcessor.hpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.
//

#ifndef ShowProcessor_hpp
#define ShowProcessor_hpp

#include <string>
#include <vector>

#include "Processor.hpp"
#include "DisplayBoard.hpp"

class ShowProcessor : public Processor{
public:
    ShowProcessor(int cameraId, DisplayBoard* displayBoard, int index);
    virtual ~ShowProcessor();
    virtual void process(Mat& frame);

    int cameraId;
    DisplayBoard* displayBoard;
    int index;
};

#endif /*ShowProcessor_hpp*/


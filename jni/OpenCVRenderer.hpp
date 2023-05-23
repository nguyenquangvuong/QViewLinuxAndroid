//
//  OpenCVRenderer.hpp
//  QView v1.0
//
//  Created by Luu Kien on 16/02/2023
//  Copyright © 2020 16/02/2023. All rights reserved.
//

#ifndef OpenCVRenderer_hpp
#define OpenCVRenderer_hpp

#include "Renderer.hpp"

class OpenCVRenderer: public Renderer {
public:
    OpenCVRenderer();
    ~OpenCVRenderer();
    
    virtual void prepare(const cv::Mat& frame);
    virtual void render();
    virtual bool running();
    
private:
    cv::Mat frame;
    bool exitPending;
};

#endif /* OpenCVRenderer_hpp */

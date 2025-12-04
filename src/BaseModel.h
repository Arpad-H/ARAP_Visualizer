//
// Created by Arpad on 12/4/2025.
//

#ifndef ARAP_VISUALIZER_BASEMODEL_H
#define ARAP_VISUALIZER_BASEMODEL_H

#include <stdio.h>
#include "camera.h"
#include "matrix.h"
#include "baseshader.h"

class BaseModel
{
public:
    BaseModel();
    virtual ~BaseModel();
    virtual void draw(const BaseCamera& Cam);
    const Matrix& transform() const { return Transform; }
    void transform( const Matrix& m) { Transform = m; }
    virtual void shader( BaseShader* shader, bool deleteOnDestruction=false );
    virtual BaseShader* shader() const { return pShader; }
protected:
    Matrix Transform;
    BaseShader* pShader;
    bool DeleteShader;

};


#endif //ARAP_VISUALIZER_BASEMODEL_H
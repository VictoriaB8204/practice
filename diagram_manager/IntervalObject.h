/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "IntervalSample.h"
#include "Diagram.h"

#ifdef __cplusplus
extern "C"{
#endif

class IIntervalObject
{
public:
    enum ECurveStyle {
        NO_CURVE = -1, LINES,
        STICKS, STEPS,
        DOTS, USER_CURVE = 100
    };

    virtual void SetTitle( QString title ) = 0;
    virtual void SetSamples( QVector< CIntervalSample > points ) = 0;
    virtual void SetPen( const QPen &pen ) = 0;
    virtual void SetBrush( const QBrush &brush ) = 0;
    virtual void SetStyle( ECurveStyle style ) = 0;
    virtual void Attach( IDiagram *diagram ) = 0;
    virtual ~IIntervalObject(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

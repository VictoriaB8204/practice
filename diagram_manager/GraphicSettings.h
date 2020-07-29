/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "Object.h"

enum ECurveStyle {
  NoCurve = -1, Lines, Sticks, Steps,
  Dots, UserCurve = 100
};

#ifdef __cplusplus
extern "C"{
#endif

class IGraphicSettings : public IObject
{
    virtual void SetPen (const QPen &pen) = 0;
    virtual void SetBrush (const QBrush &) = 0;
    virtual void SetStyle (ECurveStyle style) = 0;
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

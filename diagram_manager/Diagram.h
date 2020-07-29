/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

#ifndef DIAGRAM_H
#define DIAGRAM_H

/////////////////////////////////////////////////////////////

#include "Symbol.cpp"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

enum EAxis { X_TOP, X_BOTTOM, Y_LEFT, Y_RIGHT };

#ifdef __cplusplus
extern "C"{
#endif

class IDiagram
{
public:
    virtual void AddCurve( QVector<QPointF> , QPen, CSymbol ) = 0;
    virtual void AddPoint( QPointF, QPen, CSymbol ) = 0;
    virtual void SetAxisTitle( EAxis, QString ) = 0;
    virtual void AttachGrid( QPen ) = 0;
    virtual void SetMagnifier( Qt::MouseButton ) = 0;
    virtual void SetPanner( Qt::MouseButton ) = 0;
    virtual ~IDiagram();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif // DIAGRAM_H

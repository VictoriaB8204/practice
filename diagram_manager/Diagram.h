/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include <qwt_plot.h>

#ifdef __cplusplus
extern "C"{
#endif

class IDiagram
{
public:
    enum EAxis
    {
        Y_LEFT, Y_RIGHT,
        X_BOTTOM, X_TOP
    };

    enum ELegendPosition
    {
        LEFT_LEGEND, RIGHT_LEGEND,
        BOTTOM_LEGEND, TOP_LEGEND
    };

    virtual void SetAxisTitle( EAxis, QString ) = 0;
    virtual void SetAxisScale( EAxis, double, double, double ) = 0;
    virtual void SetTitle( QString ) = 0;
    virtual void SetFooter( QString ) = 0;
    virtual void SetBackground( Qt::GlobalColor ) = 0;
    virtual void SetAxisMaxMinor( EAxis, int ) = 0;
    virtual void SetAxisMaxMajor( EAxis, int ) = 0;
    virtual void SetGrid( QPen ) = 0;
    virtual void SetLegend( ELegendPosition ) = 0;
    virtual void SetMagnifier( Qt::MouseButton ) = 0;
    virtual void SetPanner( Qt::MouseButton ) = 0;
    virtual QwtPlot* SetWidget() = 0;
    virtual QwtPlot* SetParent() = 0;
    virtual ~IDiagram(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

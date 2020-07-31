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

    virtual void SetAxisTitle( EAxis axis, QString string ) = 0;
    virtual void SetAxisScale( EAxis axis, double min, double max, double step ) = 0;
    virtual void SetTitle( QString title ) = 0;
    virtual void SetFooter( QString string ) = 0;
    virtual void SetBackground( Qt::GlobalColor color ) = 0;
    virtual void SetAxisMaxMinor( EAxis axis, int maxMinor ) = 0;
    virtual void SetAxisMaxMajor( EAxis, int maxMajor ) = 0;
    virtual void SetGrid( QPen pen ) = 0;
    virtual void SetLegend( ELegendPosition position ) = 0;
    virtual void SetMagnifier( Qt::MouseButton button ) = 0;
    virtual void SetPanner( Qt::MouseButton button ) = 0;
    virtual QwtPlot* SetWidget() = 0;
    virtual QwtPlot* SetParent() = 0;
    virtual ~IDiagram(){};
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

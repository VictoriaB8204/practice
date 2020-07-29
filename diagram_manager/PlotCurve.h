/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "GraphicSettings.h"
#include <qwt_plot_curve.h>

enum EPaintAttribute
{
    ClipPolygons, FilterPoints, MinimizeMemory, ImageBuffer
};

enum ECurveAttribute { Inverted, Fitted  };

enum ELegendAttribute
{
    NoAttribute, ShowLine, ShowSymbol, ShowBrush
};

#ifdef __cplusplus
extern "C"{
#endif

class CPlotCurve : public IGraphicSettings
{
    QwtPlotCurve *m_curve;
public:
    CPlotCurve();
    void SetPaintAttribute( EPaintAttribute attribute, bool on = true );
    void SetLegendAttribute( ELegendAttribute attribute, bool on = true );
    void SetSamples( double *xData, double *yData, int size );
    void SetCurveAttribute( ECurveAttribute attribute, bool on = true );
    void SetPen( const QPen &pen ) override;
    void SetBrush( const QBrush &brush ) override;
    void SetBaseLine( double baseline );
    void SetStyle( ECurveStyle style ) override;
    void SetSymbol( CSymbol symbol );
    void Attach( CPlot *plot ) override;
    ~CPlotCurve();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
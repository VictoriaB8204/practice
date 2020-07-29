/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "GraphicSettings.h"
#include "ColumnSymbol.h"
#include "IntervalSample.h"
#include <qwt_plot_histogram.h>

#ifdef __cplusplus
extern "C"{
#endif

class CPlotHistogram : public IGraphicSettings
{
    QwtPlotHistogram *m_histogram;
public:
    CPlotHistogram();
    void SetSamples ( QVector< CIntervalSample > samples);
    void SetPen (const QPen &pen) override;
    void SetBrush (const QBrush &brush ) override;
    void SetStyle (ECurveStyle style ) override;
    void SetSymbol ( CColumnSymbol symbol );
    void SetBaseline (double baseline );
    void Attach( CPlot *plot ) override;
    ~CPlotHistogram();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include "IntervalObject.h"
#include <qwt_plot_histogram.h>

#ifdef __cplusplus
extern "C"{
#endif

class CPlotHistogram : public IIntervalObject
{
    QwtPlotHistogram *m_histogram;
public:
    CPlotHistogram();
    void SetTitle( QString title ) override;
    void SetSamples( QVector< CIntervalSample > points ) override;
    void SetPen( const QPen &pen ) override;
    void SetBrush( const QBrush &brush ) override;
    void SetStyle( ECurveStyle style ) override;
    void Attach( IDiagram *diagram ) override;
    ~CPlotHistogram();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

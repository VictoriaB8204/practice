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
    void SetTitle ( QString ) override;
    void SetSamples ( QVector< CIntervalSample > ) override;
    void SetPen ( const QPen & ) override;
    void SetBrush ( const QBrush & ) override;
    void SetStyle ( ECurveStyle ) override;
    void Attach( IDiagram * ) override;
    ~CPlotHistogram();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

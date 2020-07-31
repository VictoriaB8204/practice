/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include <qwt_plot_histogram.h>

#ifdef __cplusplus
extern "C"{
#endif

class CIntervalSample
{
    double m_value;
    double m_min;
    double m_max;
public:
    CIntervalSample( double, double, double );
    QwtIntervalSample* ToQwtIntervalSample() const;
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

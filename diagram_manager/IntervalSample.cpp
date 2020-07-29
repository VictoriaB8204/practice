/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#include "IntervalSample.h"

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

CIntervalSample::CIntervalSample( double value, double min, double max )
{
    m_value = value;
    m_min = min;
    m_max = max;
}

/////////////////////////////////////////////////////////////

QwtIntervalSample* CIntervalSample::ToQwtIntervalSample() const
{
    return new QwtIntervalSample( m_value, m_min, m_max );
}

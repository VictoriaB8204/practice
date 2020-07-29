/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#include "Diagram.h"
#include <qwt_legend.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


class CPlot : public IDiagram
{
    QwtPlot *m_plot;

public:
    CPlot();
    void SetAxisTitle( EAxis axis, QString string ) override;
    void SetAxisScale( EAxis axis, double min, double max, double step ) override;
    void SetTitle( QString string ) override;
    void SetFooter( QString string ) override;
    void SetAxisMaxMinor( EAxis axis , int maxMinor ) override;
    void SetAxisMaxMajor( EAxis axis, int maxMajor ) override;
    void InsertLegend( ELegendPosition position ) override;
    void SetMagnifier( Qt::MouseButton button ) override;
    void SetPanner( Qt::MouseButton button ) override;
    QwtPlot* ToQwtPlot();
    ~CPlot();
};

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

CPlot::CPlot()
{
    m_plot = new QwtPlot();
}

/////////////////////////////////////////////////////////////

void CPlot::SetAxisTitle( EAxis axis, QString string )
{
    m_plot->setAxisTitle( axis, string );
}

/////////////////////////////////////////////////////////////

void CPlot::SetAxisScale( EAxis axis, double min, double max, double step )
{
    m_plot->setAxisScale( axis, min, max, step );
}

/////////////////////////////////////////////////////////////

void CPlot::SetTitle( QString string )
{
    m_plot->setTitle( string );
}

/////////////////////////////////////////////////////////////

void CPlot::SetFooter( QString string )
{
    m_plot->setFooter( string );
}

/////////////////////////////////////////////////////////////

void CPlot::SetAxisMaxMinor( EAxis axis , int maxMinor )
{
    m_plot->setAxisMaxMinor( axis, maxMinor );
}

/////////////////////////////////////////////////////////////

void CPlot::SetAxisMaxMajor( EAxis axis, int maxMajor )
{
    m_plot->setAxisMaxMajor( axis, maxMajor );
}

/////////////////////////////////////////////////////////////

void CPlot::InsertLegend( ELegendPosition position )
{
    m_plot->insertLegend( new QwtLegend(), QwtPlot::LegendPosition(position) );
}

/////////////////////////////////////////////////////////////

void CPlot::SetMagnifier( Qt::MouseButton button )
{
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( m_plot->canvas() );
    magnifier->setMouseButton( button );
}

/////////////////////////////////////////////////////////////

void CPlot::SetPanner( Qt::MouseButton button )
{
    QwtPlotPanner *d_panner = new QwtPlotPanner( m_plot->canvas() );
    d_panner->setMouseButton( button );
}

/////////////////////////////////////////////////////////////

QwtPlot* CPlot::ToQwtPlot()
{
    return m_plot;
}

/////////////////////////////////////////////////////////////

CPlot::~CPlot()
{
    delete [] m_plot;
}

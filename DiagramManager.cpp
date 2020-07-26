/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_symbol.h>

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//Необходимо уточнить список диаграмм
//Возможно, есть необходимость определить метод Diagram::SetWidget
//Спросить нужно ли сглаживание и имя для кривой в методе Diagram::AddCurve
//QwtCurveDiagram::AddPoint уточнить должна ли точка добавляться на кривую или просто на график
//      (на текущий момент реализовано добавление на график)
//На текущий момент, так как не утвержден список диаграмм, не все классы реализованы.
//      После получения замечаний по текущему коду и утверждения списка диаграмм, это будет доделано.

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//Типы Axis, Style, Symbol были введены для того,
//чтобы в интерфейсе Diagram абстрагироваться от библиотеки Qwt.
//На текущий момент Axis и Style повторяют аналогичные типы данных в Qwt

enum EAxis { X_TOP, X_BOTTOM, Y_LEFT, Y_RIGHT };

enum EStyle
{
    NO_SYMBOL = -1, ELLIPSE, RECT, DIAMOND,
    TRIANGLE, D_TRIANGLE, U_TRIANGLE, L_TRIANGLE,
    R_TRIANGLE, CROSS, X_CROSS, H_LINE,
    V_LINE, STAR1, STAR2, HEXAGON,
    PATH, PIXMAP, GRAPHIC, SVG_DOCUMENT
};

class CSymbol
{
    EStyle m_style;
    QBrush m_brush;
    QPen m_pen;
    QSize m_size;

public:
    CSymbol( EStyle style, QBrush brush, QPen pen, QSize size );
    QwtSymbol* ToQwtSymbol();
};

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

//Есть необходимость добавить метод SetWidget
//(На текущий момент виджет передается в конструкторе и там инициализируется)
class CCurveDiagram : public IDiagram
{
private:
    QwtPlot *m_plot;

public:
    CCurveDiagram( QWidget *widget );
    void AddCurve( QVector<QPointF> points, QPen pen, CSymbol symbol ) override;
    void AddPoint( QPointF point, QPen pen, CSymbol symbol ) override;
    void SetAxisTitle( EAxis axis, QString string ) override;
    void AttachGrid( QPen pen ) override;
    void SetMagnifier( Qt::MouseButton button ) override;
    void SetPanner( Qt::MouseButton button ) override;
    ~CCurveDiagram() override;
};

//Возможный список диаграмм {
class CScatterDiagram;
class CCountourPlot;
class CHistogram;
//}

class CCreator
{
public:
    virtual IDiagram* FactoryMethod() const = 0;
    IDiagram* CreateDiagram() const;
    virtual ~CCreator();
};

class CCurveDiagramCreator : public CCreator
{
public:
    IDiagram* FactoryMethod() const override;
};

//Список creator-ов для диаграмм {
class CScatterDiagramCreator;
class CCountourPlotCreator;
class CHistogramCreator;
//}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

CSymbol::CSymbol( EStyle style, QBrush brush, QPen pen, QSize size )
{
    m_style = style;
    m_brush = brush;
    m_pen = pen;
    m_size = size;
}

/////////////////////////////////////////////////////////////

QwtSymbol* CSymbol::ToQwtSymbol()
{
    return new QwtSymbol( QwtSymbol::Style( m_style ), m_brush, m_pen, m_size );
}

/////////////////////////////////////////////////////////////

CCurveDiagram::CCurveDiagram( QWidget *widget )
{
    m_plot = new QwtPlot( widget );
}

/////////////////////////////////////////////////////////////

void CCurveDiagram::AddCurve( QVector<QPointF> points, QPen pen, CSymbol symbol )
{
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setSamples( points );
    curve->setPen( pen );
    curve->setSymbol( symbol.ToQwtSymbol() );
    curve->attach( m_plot );
}

/////////////////////////////////////////////////////////////

//По данному методу есть вопросы: он должен добавлять точку на график или на кривую на графике?
void CCurveDiagram::AddPoint( QPointF point, QPen pen, CSymbol symbol )
{
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setPen( pen );
    curve->setSymbol( symbol.ToQwtSymbol() );

    QPolygonF points;
    points << point;
    curve->setSamples( points );

    curve->attach( m_plot );
}

/////////////////////////////////////////////////////////////

void CCurveDiagram::SetAxisTitle( EAxis axis, QString string )
{
    m_plot->setAxisTitle( axis, string );
}

/////////////////////////////////////////////////////////////

void CCurveDiagram::AttachGrid( QPen pen )
{
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen( pen );
    grid->attach( m_plot );
}

/////////////////////////////////////////////////////////////

void CCurveDiagram::SetMagnifier( Qt::MouseButton button )
{
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( m_plot->canvas() );
    magnifier->setMouseButton( button );
}

/////////////////////////////////////////////////////////////

void CCurveDiagram::SetPanner( Qt::MouseButton button )
{
    QwtPlotPanner *panner = new QwtPlotPanner( m_plot->canvas() );
    panner->setMouseButton( button );
}

/////////////////////////////////////////////////////////////

CCurveDiagram::~CCurveDiagram()
{
    delete [] m_plot;
}

/////////////////////////////////////////////////////////////

IDiagram* CCreator::CreateDiagram() const
{
    return this->FactoryMethod();
}

/////////////////////////////////////////////////////////////

//Возможно необходимо будет передавать widget в параметрах.
//Пока widget = nullptr
IDiagram * CCurveDiagramCreator::FactoryMethod() const
{
    return new CCurveDiagram( nullptr );
}



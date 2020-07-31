#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "diagram_manager/PlotCreator.h"
#include "diagram_manager/PlotCurveCreator.h"
#include "diagram_manager/PlotMarkerCreator.h"
#include "diagram_manager/PlotHistogramCreator.h"
#include "diagram_manager/PlotIntervalCurveCreator.h"

IDiagram* test_curves( IDiagram *curves_plot )
{
    curves_plot->SetTitle( "Curve plot" ); // заголовок

    // Настройка отображения
    curves_plot->SetAxisTitle( IDiagram::Y_LEFT, "Y" );
    curves_plot->SetAxisTitle( IDiagram::X_BOTTOM, "X" );
    curves_plot->SetBackground( Qt::white );
    curves_plot->SetPanner( Qt::LeftButton );
    curves_plot->SetMagnifier( Qt::RightButton );
    curves_plot->SetLegend( IDiagram::RIGHT_LEGEND );
    curves_plot->SetGrid( QPen( Qt::gray, 2 ) );

    //Построение первой кривой

    CCurveCreator *curveCreator = new CPlotCurveCreator();
    ICurve *curve = curveCreator->CreateObject();
    curve->SetTitle( "My first Curve" );
    curve->SetPen( QPen( Qt::blue, 3 ) );// цвет и толщина кривой

    CSymbol *symbol = new CSymbol( EStyle(0),
        QBrush( Qt::yellow ), QPen( Qt::blue, 2 ), QSize( 15, 15 ) );
    curve->SetSymbol( *symbol ); // маркеры кривой

    QPolygonF points;

    points << QPointF( 1.0, 1.0 )
           << QPointF( 2.0, 2.5 )
           << QPointF( 3.0, 3.0 )
           << QPointF( 4.0, 3.5 )
           << QPointF( 5.0, 5.0 );

    curve->SetSamples( points ); // добавить точки на кривую

    curve->Attach( curves_plot ); // отобразить кривую на графике

    //Построение второй кривой

    ICurve *secondCurve = curveCreator->CreateObject();
    secondCurve->SetTitle( "My second Curve" );
    secondCurve->SetPen( QPen( Qt::red, 3 ) ); // цвет и толщина кривой
    secondCurve->SetSymbol( *symbol );

    points.clear();

    points << QPointF( 1.0, 5.0 )
           << QPointF( 2.0, 3.5 )
           << QPointF( 3.0, 3.0 )
           << QPointF( 4.0, 2.5 )
           << QPointF( 5.0, 1.0 );

    secondCurve->SetSamples( points ); // добавить точки на кривую

    secondCurve->Attach( curves_plot ); // отобразить кривую на графике

    return curves_plot;
}

IDiagram* test_markers( IDiagram *marker_plot )
{
    marker_plot->SetTitle( "Marker plot" ); // заголовок

    // Настройка отображения
    marker_plot->SetAxisTitle( IDiagram::Y_LEFT, "Y" );
    marker_plot->SetAxisTitle( IDiagram::X_BOTTOM, "X" );
    marker_plot->SetBackground( Qt::white );
    marker_plot->SetPanner( Qt::LeftButton );
    marker_plot->SetMagnifier( Qt::RightButton );
    marker_plot->SetGrid( QPen( Qt::gray, 2 ) );

    CSymbol *marker_symbol = new CSymbol( DIAMOND, QBrush( Qt::yellow ), QPen( Qt::blue, 2 ), QSize( 50, 50 ) );

    CMarkerCreator *markerCreator = new CPlotMarkerCreator();
    IMarker *marker = markerCreator->CreateObject();

    marker->SetTitle( "Demo Marker" );
    marker->SetSymbol( *marker_symbol );
    marker->SetValue( 300.0, 300.0 );

    marker->Attach( marker_plot );

    IMarker *second_marker = markerCreator->CreateObject();

    second_marker->SetTitle( "Demo Marker" );
    second_marker->SetSymbol( *marker_symbol );
    second_marker->SetValue( 500.0, 500.0 );

    second_marker->Attach( marker_plot );

    return marker_plot;
}

IDiagram* test_histogram( IDiagram *histogram_plot )
{
    histogram_plot->SetTitle( "Histogram plot" ); // заголовок

    // Настройка отображения
    histogram_plot->SetAxisTitle( IDiagram::Y_LEFT, "Y" );
    histogram_plot->SetAxisTitle( IDiagram::X_BOTTOM, "X" );
    histogram_plot->SetBackground( Qt::white );
    histogram_plot->SetLegend( IDiagram::RIGHT_LEGEND );
    histogram_plot->SetPanner( Qt::LeftButton );
    histogram_plot->SetMagnifier( Qt::RightButton );
    histogram_plot->SetGrid( QPen( Qt::gray, 2 ) );

    CIntervalObjectCreator *histogramCreator = new CPlotHistogramCreator();
    IIntervalObject *histogram = histogramCreator->CreateObject();

    histogram->SetTitle( "Demo first Histogram" );
    histogram->SetPen( QPen( Qt::black, 1.0 ) );
    histogram->SetBrush( QBrush( Qt::yellow ) );

    QVector<CIntervalSample> *intervals = new QVector<CIntervalSample>;
    float di = 0.1;
    for (float i = 0; i <= 5; i += di)
        intervals->append( CIntervalSample( qAbs(qCos(i)), i, i + di ) );

    histogram->SetSamples( *intervals );

    histogram->Attach( histogram_plot );

    IIntervalObject *second_histogram = histogramCreator->CreateObject();

    second_histogram->SetTitle( "Demo second Histogram" );
    second_histogram->SetPen( QPen( Qt::black, 1.0 ) );
    second_histogram->SetBrush( QBrush( Qt::green ) );
    second_histogram->SetStyle( IIntervalObject::STICKS );

    intervals->clear();
    di = 0.1;
    for (float i = 0; i <=5; i += di)
        intervals->append( CIntervalSample( qAbs(qSin(i)), i, i+di ) );

    second_histogram->SetSamples( *intervals );

    second_histogram->Attach( histogram_plot  );

    return histogram_plot;
}

IDiagram* test_interval_curve(IDiagram *interval_curve_plot)
{
    interval_curve_plot->SetTitle( "Interval curve plot" ); // заголовок

    // Настройка отображения
    interval_curve_plot->SetAxisTitle( IDiagram::Y_LEFT, "Y" );
    interval_curve_plot->SetAxisTitle( IDiagram::X_BOTTOM, "X" );
    interval_curve_plot->SetBackground( Qt::white );
    interval_curve_plot->SetLegend( IDiagram::RIGHT_LEGEND );
    interval_curve_plot->SetPanner( Qt::LeftButton );
    interval_curve_plot->SetMagnifier( Qt::RightButton );
    interval_curve_plot->SetGrid( QPen( Qt::gray, 2 ) );

    CIntervalObjectCreator *intervalCurveCreator = new CPlotIntervalCurveCreator();
    IIntervalObject *intervalCurve = intervalCurveCreator->CreateObject();

    intervalCurve->SetTitle( "Demo first Interval curve" );
    intervalCurve->SetPen( QPen( Qt::black, 1.0 ) );
    intervalCurve->SetBrush( QBrush( Qt::yellow ) );

    QVector<CIntervalSample> *intervals = new QVector<CIntervalSample>;
    float di = 0.1;
    for (float i = 0; i <= 5; i += di)
        intervals->append( CIntervalSample( qAbs(qCos(i)), i, i + di ) );

    intervalCurve->SetSamples( *intervals );

    intervalCurve->Attach( interval_curve_plot );

    IIntervalObject *second_intervalCurve = intervalCurveCreator->CreateObject();

    second_intervalCurve->SetTitle( "Demo second Interval curve" );
    second_intervalCurve->SetPen( QPen( Qt::black, 1.0 ) );
    second_intervalCurve->SetBrush( QBrush( Qt::green ) );
    second_intervalCurve->SetStyle( IIntervalObject::STICKS );

    intervals->clear();
    di = 0.1;
    for (float i = 0; i <= 5; i += di)
        intervals->append( CIntervalSample( qAbs(qSin(i)), i, i + di ) );

    second_intervalCurve->SetSamples( *intervals );

    second_intervalCurve->Attach( interval_curve_plot );

    return interval_curve_plot;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CDiagramCreator *creator = new CPlotCreator();

    //////////////////////////////////////////////
    //Построение графика с двумя кривыми
    //////////////////////////////////////////////

//    IDiagram *curves_plot = creator->CreateDiagram();
//    setCentralWidget( curves_plot->SetWidget() );
//    curves_plot = test_curves( curves_plot );

    //////////////////////////////////////////////
    //Построение графика с маркерами
    //////////////////////////////////////////////

//    IDiagram *marker_plot = creator->CreateDiagram();
//    setCentralWidget( marker_plot->SetWidget() );
//    marker_plot = test_markers( marker_plot );

    //////////////////////////////////////////////
    //Построение графика с гистограммой
    //////////////////////////////////////////////

//    IDiagram *histogram_plot = creator->CreateDiagram();
//    setCentralWidget( histogram_plot->SetWidget() );
//    histogram_plot = test_histogram( histogram_plot );

    //////////////////////////////////////////////
    //Построение графика с интервальной кривой
    //////////////////////////////////////////////

    IDiagram *interval_curve_plot = creator->CreateDiagram();
    setCentralWidget( interval_curve_plot->SetWidget() );
    interval_curve_plot = test_interval_curve( interval_curve_plot );

}

MainWindow::~MainWindow()
{
    delete ui;
}


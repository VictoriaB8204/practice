#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "diagram_manager/PlotCreator.h"
#include "diagram_manager/PlotCurveCreator.h"
#include "diagram_manager/PlotMarkerCreator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CDiagramCreator *creator = new CPlotCreator();
    IDiagram *d_plot = creator->CreateDiagram();
    setCentralWidget(d_plot->SetWidget());

    d_plot->SetTitle( "Qwt demonstration" ); // заголовок

    // Параметры осей координат
    d_plot->SetAxisTitle(Y_LEFT, "Y");
    d_plot->SetAxisTitle(X_BOTTOM, "X");
    d_plot->InsertLegend(RIGHT_LEGEND);

    CObjectCreator *curveCreator = new CPlotCurveCreator();
    IObject *curve = curveCreator->CreateObject();
    curve->SetTitle( "Demo Curve" );
    QPen *pen = new QPen( Qt::blue, 3 );
    curve->SetPen( *pen ); // цвет и толщина кривой

    CObjectCreator *markerCreator = new CPlotMarkerCreator();
    IObject *marker = markerCreator->CreateObject();
    marker->SetTitle( "Demo Marker" );
    marker->SetPen( *pen ); // цвет и толщина кривой

    // Маркеры кривой
    // #include <qwt_symbol.h>
    CSymbol *symbol = new CSymbol( EStyle(0),
        QBrush( Qt::yellow ), QPen( Qt::blue, 2 ), QSize( 15, 15 ) );
    curve->SetSymbol( symbol );

    // Добавить точки на ранее созданную кривую
    QPolygonF points;

       points << QPointF( 1.0, 1.0 ) // координаты x, y
    << QPointF( 1.5, 2.0 ) << QPointF( 3.0, 2.0 )
    << QPointF( 3.5, 3.0 ) << QPointF( 5.0, 3.0 )
    << QPointF( 2.5, 1.0 ) << QPointF( 5.0, 2.5 );

     curve->SetSamples( points ); // ассоциировать набор точек с кривой

     curve->Attach( d_plot ); // отобразить кривую на графике

     // Включить возможность приближения/удаления графика
      // #include <qwt_plot_magnifier.h>
//      QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(d_plot->canvas());
//      // клавиша, активирующая приближение/удаление
//      magnifier->setMouseButton(Qt::LeftButton);


//      // Включить возможность перемещения по графику
//      // #include <qwt_plot_panner.h>
//      QwtPlotPanner *d_panner = new QwtPlotPanner( d_plot->canvas() );
//      // клавиша, активирующая перемещение
//      d_panner->setMouseButton( Qt::RightButton );

//      // Включить отображение координат курсора и двух перпендикулярных
//      // линий в месте его отображения
//      // #include <qwt_plot_picker.h>

//       // настройка функций
//      QwtPlotPicker *d_picker =
//              new QwtPlotPicker(
//                  QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
//      QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
//      QwtPicker::ActiveOnly, // включение/выключение
//      d_plot->canvas() ); // ассоциация с полем

//      // Цвет перпендикулярных линий
//      d_picker->setRubberBandPen( QColor( Qt::red ) );

//      // цвет координат положения указателя
//      d_picker->setTrackerPen( QColor( Qt::black ) );

//      // непосредственное включение вышеописанных функций
//      d_picker->setStateMachine( new QwtPickerDragPointMachine() );
}

MainWindow::~MainWindow()
{
    delete ui;
}


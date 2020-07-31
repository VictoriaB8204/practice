/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////

#include <qwt_plot.h>
#include <qwt_symbol.h>

enum EStyle
{
    NO_SYMBOL = -1, ELLIPSE, RECT, DIAMOND,
    TRIANGLE, D_TRIANGLE, U_TRIANGLE, L_TRIANGLE,
    R_TRIANGLE, CROSS, X_CROSS, H_LINE,
    V_LINE, STAR1, STAR2, HEXAGON,
    PATH, PIXMAP, GRAPHIC, SVG_DOCUMENT
};

#ifdef __cplusplus
extern "C"{
#endif

class CSymbol
{
    EStyle m_style;
    QBrush m_brush;
    QPen m_pen;
    QSize m_size;

public:
    CSymbol( EStyle, QBrush, QPen, QSize );
    QwtSymbol* ToQwtSymbol();
};

/////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

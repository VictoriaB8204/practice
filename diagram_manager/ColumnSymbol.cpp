/*
 * Copyright (C) 2020 Rhonda Software.
 * All rights reserved.
 */

/////////////////////////////////////////////////////////////

#include "ColumnSymbol.h"

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

//Класс, необходимый для PlotHistogram

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

CColumnSymbol::CColumnSymbol(EColumnSymbolStyle style)
{
    m_symbol = new QwtColumnSymbol( QwtColumnSymbol::Style(style) );
}

/////////////////////////////////////////////////////////////

QwtColumnSymbol* CColumnSymbol::ToQwtColumnSymbol()
{
    return m_symbol;
}

/////////////////////////////////////////////////////////////

CColumnSymbol::~CColumnSymbol()
{
    delete [] m_symbol;
}

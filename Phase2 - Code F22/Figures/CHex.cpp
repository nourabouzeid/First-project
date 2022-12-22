#include "CHex.h"

CHex::CHex(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	midd = P1;
}


void CHex::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHexagon(midd, FigGfxInfo, Selected);
}

bool CHex::isinside(Point p)
{
	return false;
}

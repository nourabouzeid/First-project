#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point p3 , GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = p3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawtriangle(Corner1, Corner2, Corner3 , FigGfxInfo, Selected);
}

bool CTriangle::isinside(Point p)
{
	return false;
}

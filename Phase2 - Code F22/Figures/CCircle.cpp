#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	midd = P1;
	radius = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawcircle(midd, radius, FigGfxInfo, Selected);
}

bool CCircle::isinside(Point p)
{
	long long int d1, d2;
	d1 = sqrt(pow((midd.x - radius.x), 2) + pow((midd.y - radius.y), 2));
	d2 = sqrt(pow((midd.x - p.x), 2) + pow((midd.y - p.y), 2));
	if (d1 >= d2)
		return true;
	else
		return false;
}

void CCircle::move(Point p1)
{
	midd = p1;
}

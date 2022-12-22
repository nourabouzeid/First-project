#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	midd = P1;
	
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawsqr(midd , FigGfxInfo, Selected);
}

bool CSquare::isinside(Point p)
{
	Point Corner1, Corner2;
	Corner1.x = midd.x - 125;
	Corner1.y = midd.y - 125;
	Corner2.x = midd.x + 125;
	Corner2.y = midd.y + 125;
	if (p.x <= (Corner1.x > Corner2.x ? Corner1.x : Corner2.x) && p.x >= (Corner1.x < Corner2.x ? Corner1.x : Corner2.x))
	{
		if (p.y <= (Corner1.y > Corner2.y ? Corner1.y : Corner2.y) && p.y >= (Corner1.y < Corner2.y ? Corner1.y : Corner2.y))
		{
			return true;
		}
		else return false;
	}
	else return false;
}

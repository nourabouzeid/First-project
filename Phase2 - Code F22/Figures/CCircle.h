#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point midd;
	Point radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
};
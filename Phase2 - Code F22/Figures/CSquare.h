#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point midd;
	
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
};
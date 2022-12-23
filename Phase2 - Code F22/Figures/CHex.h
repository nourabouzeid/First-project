#include "CFigure.h"

class CHex : public CFigure
{
private:
	Point midd;
public:
	CHex(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool isinside(Point p);
	void move(Point p1);
};
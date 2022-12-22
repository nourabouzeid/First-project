#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please Click inside a figure");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p.x, p.y);

	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{

	ReadActionParameters();
	pManager->setselectedfigure(p);

}

#include "FillCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillCAction::FillCAction(ApplicationManager* pApp) :Action(pApp)
{}


void FillCAction::ReadActionParameters()
{
	c = pManager->getcolor();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("please Click inside a figure");
}

void FillCAction::Execute()
{
	ReadActionParameters();
	pManager->changeFC(c);
}

#include "DrawCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawCAction::DrawCAction(ApplicationManager* pApp) :Action(pApp)
{}


void DrawCAction::ReadActionParameters()
{
	c=pManager->getcolor();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("please Click inside a figure");
}

void DrawCAction::Execute()
{
	ReadActionParameters();
	pManager->changeDC(c);
}
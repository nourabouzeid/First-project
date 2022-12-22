#include "ClearAllAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}



void ClearAllAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("you choose clear all");
	pOut->ClearDrawArea();
}




void ClearAllAction::Execute()
{
	ReadActionParameters();
	pManager->deleteallfigure();
}

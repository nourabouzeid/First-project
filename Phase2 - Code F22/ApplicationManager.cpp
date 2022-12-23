#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DrawCAction.h"
#include "Actions\FillCAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\CreatDAction.h"
#include "Actions\CreatFAction.h"
#include "Actions\CreateDToolbarAction.h"
#include "Actions\CreatePToolbarAction.h"
#include "Actions\CreatFigureAction.h"
#include "Actions\DeleteFigureAction.h"
#include "Actions\MoveAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	FigCount = 0;
	f = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	   case FIG:
		   pAct = new CreatFigureAction(this);  
		   break;
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriangleAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case TO_DRAW:
			pAct = new CreateDToolbarAction(this);
			break;
		case DRAW_COLOR:
			pAct = new CreatDAction(this);
			f = 1;
			break;
		case FILL_COLOR:
			pAct = new CreatFAction(this);
			f = 2;
			break;
		case BLACK_COLOR:
			c1 = BLACK;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if(f==2)
				pAct = new FillCAction(this);
			break;
		case YELLOW_COLOR:
			c1 = YELLOW;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case ORANGE_COLOR:
			c1 = ORANGE;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case RED_COLOR:
			c1 = RED;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case GREEN_COLOR:
			c1 = GREEN;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case BLUE_COLOR:
			c1 = BLUE;
			if (f == 1)
				pAct = new DrawCAction(this);
			else if (f == 2)
				pAct = new FillCAction(this);
			break;
		case TO_PLAY:
			pAct = new CreatePToolbarAction(this);
			break;
		case MOVE:
			pAct = new MoveAction(this);
			break;
		case CLEAR:
			pAct = new ClearAllAction(this);
			break;
		case DELET:
			pAct = new DeleteFigureAction(this);
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

void ApplicationManager::deleteallfigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	SelectedFig = NULL;
}

void ApplicationManager::deletefigure(CFigure* cf1)
{
	CFigure* temp;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == cf1 && i < (FigCount-1))
		{
			temp = FigList[i];
			FigList[i] = FigList[i + 1];
			FigList[i + 1] = temp;
		}
		if (FigList[i] == cf1 && i == (FigCount - 1))
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount = FigCount - 1;
			SelectedFig = NULL;
		}
	}
}

color ApplicationManager::getcolor()
{
	return c1;
}

void ApplicationManager::MOVEE(Point p) const
{
	if(SelectedFig!=NULL)
	SelectedFig->move(p);
}

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::setselectedfigure(CFigure* cf)
{
	SelectedFig = cf;
}

CFigure* ApplicationManager::getselectedfigure()
{
	return SelectedFig;
}

CFigure* ApplicationManager::GetFigure(Point p) const
{
	for (int i = FigCount-1; i>=0; i--)
	{
		if (FigList[i]->isinside(p))
		{
			return FigList[i];
		}
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

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


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
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
		   pOut->CreateFigureToolBar();     //need to change
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
			pOut->CreateDrawToolBar();    //need to change
			break;
		case DRAW_COLOR:
			pOut->CreateDrawColorToolBar();     //need to change
			f = 1;
			break;
		case FILL_COLOR:
			pOut->CreateFillColorToolBar();   //need to change
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
			pOut->CreatePlayToolBar();
			break;

		case CLEAR:
			pAct = new ClearAllAction(this);
			break;
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
		FigList[i]->SetSelected(false);
		FigList[i] = NULL;
	}
	FigCount = 0;
}

color ApplicationManager::getcolor()
{
	return c1;
}

void ApplicationManager::changeDC(color c)
{
	SelectedFig->ChngDrawClr(c);
}

void ApplicationManager::changeFC(color c)
{
	SelectedFig->ChngFillClr(c);
}

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::setselectedfigure(Point p)
{
	SelectedFig = GetFigure(p);
}

CFigure* ApplicationManager::GetFigure(Point p) const
{
	for (int i = FigCount-1; i>=0; i--)
	{
		if (FigList[i]->isinside(p))
		{
			if (FigList[i]->IsSelected())
			{
				FigList[i]->SetSelected(false);
				break;
			}
			else
			{
				for(int j=0;j< FigCount; j++)
					FigList[j]->SetSelected(false);
				FigList[i]->SetSelected(true);
				return FigList[i];
			}
		}
	}

	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

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

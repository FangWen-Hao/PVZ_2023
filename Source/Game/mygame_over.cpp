#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// ?�個class?��??��?結�??�??Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g): CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState()
{
}

void CGameStateOver::OnInit()
{
	//
	// ?��?很�??��?OnInit載入?�?��??��??��?多�??�。為?��??��??��?�?
	//     等�?不耐煩，�??��??�現?�Loading ...?��?顯示Loading?�進度??
	//
	ShowInitProgress(66, "Initialize...");	// ?�個�?一?��??��??�度，此?�進度視為66%
	//
	// ?��?載入資�?
	//
	Sleep(1000);				// ?�慢，以便�?清�??�度，實?��??��??�除此Sleep
	//
	// ?�終進度??00%
	//
	ShowInitProgress(100, "OK!");

	Sleep(1000);
}

void CGameStateOver::OnShow()
{

}

void CGameStateOver::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}


void CGameStateOver::load_background() {
	background.LoadBitmapByString({ "resources/practice/over_background.bmp" });
	background.SetTopLeft(0, 0);
}

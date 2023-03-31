#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "GameMode/Main_Menu.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
	mode = new MainMenu();
}

CGameStateRun::~CGameStateRun()
{
	delete mode;
}

void CGameStateRun::OnBeginState()
{
	mode->init();
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	mode->move();
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	mode->OnHover(point);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	int res = mode->OnClick(point);
	if (!isLoading
		&& (res != MENU_NO_BTN_ACTION_REJECTED
			&& res != MENU_NO_BTN_ACTION_ACCEPTED)
		)
	{
		NextMode = res;
		isLoading = true;
		changeGameMode(mode, LOADING);
	}
	else if(isLoading
			&& res == MENU_NO_BTN_ACTION_ACCEPTED)
	{
		changeGameMode(mode, NextMode);
		NextMode = MENU_NO_BTN_ACTION_REJECTED;
		isLoading = false;
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	mode->show();
}

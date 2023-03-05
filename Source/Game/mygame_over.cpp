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
// ?™å€‹class?ºé??²ç?çµæ??€??Game Over)
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
	// ?¶å?å¾ˆå??‚ï?OnInitè¼‰å…¥?€?‰ç??–è??±å?å¤šæ??“ã€‚ç‚º?¿å??©é??²ç?äº?
	//     ç­‰ç?ä¸è€ç…©ï¼Œé??²æ??ºç¾?ŒLoading ...?ï?é¡¯ç¤ºLoading?„é€²åº¦??
	//
	ShowInitProgress(66, "Initialize...");	// ?¥å€‹å?ä¸€?‹ç??‹ç??²åº¦ï¼Œæ­¤?•é€²åº¦è¦–ç‚º66%
	//
	// ?‹å?è¼‰å…¥è³‡æ?
	//
	Sleep(1000);				// ?¾æ…¢ï¼Œä»¥ä¾¿ç?æ¸…æ??²åº¦ï¼Œå¯¦?›é??²è??ªé™¤æ­¤Sleep
	//
	// ?€çµ‚é€²åº¦??00%
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

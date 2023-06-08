#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "Utils/Soundboard.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//

	for (int i = 0; i < 101; i++)
	{
		ShowInitProgress(i, "Start Initialize...");
		Sleep(1); // 10s sleep in total
	}

	// TODO: find a BMP file of the init_screen that can be used. 
	// I tried converting the JPG to BMP with Gimp but it doesnt work,
	// regardless of the bit depth or bit depth type.
	init_screen.init("Resources/Background/MAIN MENU/BMP/init_screen_v4.bmp");

	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//


	// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}


void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	SoundBoard::initSoundboard();
	GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	init_screen.show();
	draw_text();
}

void CGameStateInit::draw_text() {
	CDC *pDC = CDDraw::GetBackCDC();

	/* Print title */
	CTextDraw::ChangeFontLog(pDC, 36, "微軟正黑體", RGB(0, 0, 0), 800);
	CTextDraw::Print(pDC, 250, 120, "By 方文昊 and 鄭琳玲");

	CDDraw::ReleaseBackCDC();
}
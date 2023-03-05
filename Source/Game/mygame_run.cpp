#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

#include "./My_VK_Consts.h"

#define MOVE_INCREMENT        100

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	if (character.Top() + character.Height() >= chest_and_key.Top()
		&& character.Left() + character.Width() >= chest_and_key.Left()
		&& chest_and_key.GetSelectShowBitmap() == 0
		&& chest_and_key.IsVisible())
	{
		chest_and_key.SelectShowBitmap(1);
		chest_and_key.SetFilterColor(RGB(255, 255, 255));
		return;
	}

	if (character.Top() + character.Height() >= bee.Top()
		&& character.Left() + character.Width() >= bee.Left()
		&& bee.IsVisible()
		&& !bee.IsAnimation())
	{
		bee.SetAnimation(2, false);
		return;
	}


	if (character.Top() + character.Height() >= door[0].Top()
		&& character.Left() + character.Width() >= door[0].Left()
		&& door[0].GetSelectShowBitmap() == 0
		&& door[0].IsVisible())
	{
		door[0].SelectShowBitmap(1);
		return;
	}

	if (character.Top() + character.Height() >= door[1].Top()
		&& character.Left() + character.Width() >= door[1].Left()
		&& door[1].GetSelectShowBitmap() == 0
		&& door[1].IsVisible())
	{
		door[1].SelectShowBitmap(1);
		return;
	}

	if (character.Top() + character.Height() >= door[2].Top()
		&& character.Left() + character.Width() >= door[2].Left()
		&& door[2].GetSelectShowBitmap() == 0
		&& door[2].IsVisible())
	{
		door[2].SelectShowBitmap(1);
		return;
	}

	if (character.Top() + character.Height() >= ball.Top()
		&& character.Left() + character.Width() >= ball.Left()
		&& ball.IsVisible()
		&& ball.GetSelectShowBitmap() == 0
		&& !ball.IsAnimation())
	{
		ball.SetAnimation(300, true);
		ball.ToggleAnimation();
		return;
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({ 
		"resources/practice/phase11_background.bmp", 
		"resources/practice/phase12_background.bmp", 
		"resources/practice/phase21_background.bmp", 
		"resources/practice/phase22_background.bmp", 
		"resources/practice/phase31_background.bmp", 
		"resources/practice/phase32_background.bmp",
		"resources/practice/phase41_background.bmp",
		"resources/practice/phase42_background.bmp",
		"resources/practice/phase51_background.bmp",
		"resources/practice/phase52_background.bmp",
		"resources/practice/phase61_background.bmp",
		"resources/practice/phase62_background.bmp",
	});
	background.SetTopLeft(0, 0);

	character.LoadBitmapByString({ "resources/practice/giraffe.bmp" });
	character.SetTopLeft(150, 265);

	chest_and_key.LoadBitmapByString({ "resources/practice/chest.bmp", "resources/practice/chest_ignore.bmp" }, RGB(255, 255, 255));
	chest_and_key.SetTopLeft(150, 430);

	bee.LoadBitmapByString({ "resources/practice/bee_1.bmp", "resources/practice/bee_2.bmp" });
	bee.SetTopLeft(462, 265);

	ball.LoadBitmapByString({ "resources/practice/ball-3.bmp", "resources/practice/ball-2.bmp", "resources/practice/ball-1.bmp", "resources/practice/ball-ok.bmp" });
	ball.SetTopLeft(150, 430);

	for (int i = 0; i < 3; i++) {
		door[i].LoadBitmapByString({ "resources/practice/door_close.bmp", "resources/practice/door_open.bmp" }, RGB(255, 255, 255));
		door[i].SetTopLeft(462 - 100 * i, 265);
	}
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar) {
	case VK_RETURN:
		switch (phase) {
		case 1:
			if (sub_phase == 1) {
				sub_phase += validate_phase_1();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
			return;

		case 2:
			if (sub_phase == 1) {
				sub_phase += validate_phase_2();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
			return;

		case 3:
			if (sub_phase == 1) {
				sub_phase += validate_phase_3();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
			return;

		case 4:
			if (sub_phase == 1) {
				sub_phase += validate_phase_4();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
			return;

		case 5:
			if (sub_phase == 1) {
				sub_phase += validate_phase_5();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
			return;

		case 6:
			if (sub_phase == 1) {
				sub_phase += validate_phase_6();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
				GotoGameState(GAME_STATE_OVER);
			}
			return;

		default:
			return;
		}
		return;

	case VK_UP:
	case VK_W:
		character.SetTopLeft(character.Left(), (character.Top() - MOVE_INCREMENT));
		return;

	case VK_DOWN:
	case VK_S:
		character.SetTopLeft(character.Left(), (character.Top() + MOVE_INCREMENT));
		return;

	case VK_LEFT:
	case VK_A:
		character.SetTopLeft((character.Left() - MOVE_INCREMENT), character.Top());
		return;

	case VK_RIGHT:
	case VK_D:
		character.SetTopLeft((character.Left() + MOVE_INCREMENT), character.Top());
		return;
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
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
	show_image_by_phase();
	show_text_by_phase();
}

void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		background.SelectShowBitmap((phase - 1) * 2 + (sub_phase - 1));
		background.ShowBitmap();
		character.ShowBitmap();
		if (phase == 3 && sub_phase == 1) {
			chest_and_key.ShowBitmap();
		}
		if (phase == 4 && sub_phase == 1) {
			bee.ShowBitmap();
		}
		if (phase == 5 && sub_phase == 1) {
			for (int i = 0; i < 3; i++) {
				door[i].ShowBitmap();
			}
		}
		if (phase == 6 && sub_phase == 1) {
			ball.ShowBitmap();
		}
	}
}

void CGameStateRun::show_text_by_phase() {
	CDC *pDC = CDDraw::GetBackCDC();
	CFont* fp;

	CTextDraw::ChangeFontLog(pDC, fp, 21, "微軟正黑體", RGB(0, 0, 0), 800);

	if (phase == 1 && sub_phase == 1) {
		CTextDraw::Print(pDC, 237, 128, "修改你的主角！");
		CTextDraw::Print(pDC, 55, 163, "將灰色方格換成 resources/practice 內的 giraffe.bmp 圖樣！");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 2 && sub_phase == 1) {
		CTextDraw::Print(pDC, 26, 128, "下一個階段，讓長頸鹿能夠透過上下左右移動到這個位置！");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 3 && sub_phase == 1) {
		CTextDraw::Print(pDC, 205, 128, "幫你準備了一個寶箱");
		CTextDraw::Print(pDC, 68, 162, "設計程式讓長頸鹿摸到寶箱後，將寶箱消失！");
		CTextDraw::Print(pDC, 68, 196, "記得寶箱要去背，使用 RGB(255, 255, 255)");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 4 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "幫你準備了一個蜜蜂好朋友");
		CTextDraw::Print(pDC, 89, 162, "已經幫它做了兩幀的動畫，讓它可以上下移動");
		CTextDraw::Print(pDC, 110, 196, "寫個程式來讓你的蜜蜂好朋友擁有動畫！");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 5 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "幫你準備了三扇門");
		CTextDraw::Print(pDC, 89, 162, "設計程式讓長頸鹿摸到門之後，門會打開");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 6 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "幫你準備了一顆會倒數的球");
		CTextDraw::Print(pDC, 89, 162, "設計程式讓球倒數，然後顯示 OK 後停止動畫");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (sub_phase == 2) {
		CTextDraw::Print(pDC, 268, 128, "完成！");
	}

	CDDraw::ReleaseBackCDC();
}

bool CGameStateRun::validate_phase_1() {
	return character.GetImageFilename() == "resources/practice/giraffe.bmp";
}

bool CGameStateRun::validate_phase_2() {
	return character.Top() > 204 && character.Top() < 325 && character.Left() > 339 && character.Left() < 459;
}

bool CGameStateRun::validate_phase_3() {
	return (
		character.Top() + character.Height() >= chest_and_key.Top()
		&& character.Left() + character.Width() >= chest_and_key.Left()
		&& chest_and_key.GetSelectShowBitmap() == 1
		&& chest_and_key.GetFilterColor() == RGB(255, 255, 255)
	);
}

bool CGameStateRun::validate_phase_4() {
	return bee.IsAnimation() && bee.GetMovingBitmapFrame() == 2;
}

bool CGameStateRun::validate_phase_5() {
	bool check_all_door_is_open = true;
	for (int i = 0; i < 3; i++) {
		check_all_door_is_open &= (door[i].GetSelectShowBitmap() == 1);
	}
	return check_all_door_is_open;
}

bool CGameStateRun::validate_phase_6() {
	return ball.IsAnimationDone() && !ball.IsAnimation();
}
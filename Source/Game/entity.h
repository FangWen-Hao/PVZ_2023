
namespace game_framework {

	class Entity : public CMovingBitmap {
	public: 
		Entity();
		void UnshowBitmap();
		void ShowBitmap();
		bool IsVisible();
		void SetFilterColor(COLORREF color);

	protected:
		bool visible = false;
		COLORREF filter_color;
	};
}
//#include "MenuItem.h"
//#include "MenuScreen.h"
//#include "MathHelper.h""
//
//#pragma region cdtor
//
//MenuItem::MenuItem(std::string text)
//{
//	this->text = text;
//}
//
//
//MenuItem::~MenuItem(void)
//{
//
//}
//
//#pragma endregion
//
//#pragma region Properties
//
//void MenuItem::Text(std::string text)
//{
//	this->text = text;
//}
//
//std::string MenuItem::Text()
//{
//	return text;
//}
//
//Point MenuItem::Position()
//{
//	return position;
//}
//
//void MenuItem::Position(Point point)
//{
//	this->position = point;
//}
//
//#pragma endregion
//
//	void MenuItem::Update(MenuScreen screen, bool isSelected, unsigned int elapsed_gameTime)
//	{
//
//		// When the menu selection changes,
//		// items gradually fade between their selected and deselected appearance,
//		// rather than instantly popping to the new state.
//		float fadeSpeed = elapsed_gameTime;
//
//		//if (isSelected)
//		//	selectionFade = MathHelper::min<float>(selectionFade + fadeSpeed, 1);
//		//else
//		//	selectionFade = MathHelper::max<float>(selectionFade - fadeSpeed, 0);
//	}
//
//
//	void MenuItem::Draw(MenuScreen screen, bool isSelected, unsigned int elapsed_gameTime)
//	{
//
//		// Draw the selected item in yellow, otherwise white.
//		Color color = isSelected ? Color::Yellow() : Color::White();
//
//		// Pulsate the size of the selected menu item.
//		double time = elapsed_gameTime;//.TotalGameTime.TotalSeconds;
//
//		float pulsate = (float)sin(time * 6) + 1;
//
//		float scale = 1 + pulsate * 0.05f * selectionFade;
//
//		//float scale = 1 + 0.1f * selectionFade;
//
//		//float scale = 1;
//
//		//// Modify the alpha to fade text out during transitions.
//		//color *= screen.TransitionAlpha;
//
//		//// Draw text, centered on the middle of each line.
//		//ScreenManager* screenManager = screen->screenManager;
//		//SpriteBatch spriteBatch = screenManager.SpriteBatch;
//		//SpriteFont font = screenManager.Font;
//
//		//Vector2 origin = new Vector2(0, font.LineSpacing / 2);
//
//		//spriteBatch.DrawString(font, text, position, color, 0, origin, scale, SpriteEffects.None, 0);
//	}
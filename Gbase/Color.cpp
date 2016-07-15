#include "Color.h"
#include "MathHelper.h"

Color::Color(unsigned int R, unsigned int G, unsigned int B, unsigned int A)
{
	this->_R = R;
	this->_G = G;
	this->_B = B;
	this->_A = A;
}

#pragma region GettersSetters

void Color::R(unsigned int A)
{
	_R = MathHelper::clamp<unsigned int>(A,static_cast<unsigned int>(0),static_cast<unsigned int>(255));
}

void Color::G(unsigned int A)
{
	_G = MathHelper::clamp<unsigned int>(A,static_cast<unsigned int>(0),static_cast<unsigned int>(255));
}

void Color::B(unsigned int A)
{
	_B = MathHelper::clamp<unsigned int>(A,static_cast<unsigned int>(0),static_cast<unsigned int>(255));
}

void Color::A(unsigned int A)
{
	_A = MathHelper::clamp<unsigned int>(A,static_cast<unsigned int>(0),static_cast<unsigned int>(255));
}

unsigned int Color::R()
{
	return _R;
}

unsigned int Color::G()
{
	return _G;
}

unsigned int Color::B()
{
	return _B;
}

unsigned int Color::A()
{
	return _A;
}

#pragma endregion

#pragma region operators

Color::operator SDL_Color ()
{
	SDL_Color xyz;
	xyz.r = _R;
	xyz.g = _G;
	xyz.b = _B;
	xyz.unused = _A;
	return xyz;
}

#pragma endregion

#pragma region StaticProperties
Color Color::AliceBlue()
{
	return Color(240,248,255);
}//	Gets a system-defined color with the value R:240 G:248 B:255 A:255.

Color Color::AntiqueWhite()
{
	return Color(250,235,215);
}//	Gets a system-defined color with the value R:250 G:235 B:215 A:255.


Color Color::Aqua()
{
	return Color(0,255,255);
}//	Gets a system-defined color with the value R:0 G:255 B:255 A:255.


Color Color::Aquamarine()
{
	return Color(127,255,212);
}//	Gets a system-defined color with the value R:127 G:255 B:212 A:255.


Color Color::Azure()
{
	return Color(240,255,255);
}//	Gets a system-defined color with the value R:240 G:255 B:255 A:255.


Color Color::Beige()
{
	return Color(245,245,225);
}//	Gets a system-defined color with the value R:245 G:245 B:220 A:255.


Color Color::Bisque()
{
	return Color(255,228,196);
}//	Gets a system-defined color with the value R:255 G:228 B:196 A:255.


Color Color::Black()
{
	return Color(0,0,0);
}//	Gets a system-defined color with the value R:0 G:0 B:0 A:255.


Color Color::BlanchedAlmond()
{
	return Color(255,235,205);
}//	Gets a system-defined color with the value R:255 G:235 B:205 A:255.

// --------------------------------------------------------------------------------
Color Color::Blue()//	Gets a system-defined color with the value R:0 G:0 B:255 A:255.
{
	return Color(0,0,255);
}


Color Color::BlueViolet()
{
	return Color(138,43,226);
}//	Gets a system-defined color with the value R:138 G:43 B:226 A:255.


Color Color::Brown()
{
	return Color(165,42,42);
}//	Gets a system-defined color with the value R:165 G:42 B:42 A:255.


Color Color::BurlyWood()
{
	return Color(222,184,135);
}//	Gets a system-defined color with the value R:222 G:184 B:135 A:255.


Color Color::CadetBlue()
{
	return Color(95,158,160);
}//	Gets a system-defined color with the value R:95 G:158 B:160 A:255.


Color Color::Chartreuse()
{
	return Color(127,255,0);
}//	Gets a system-defined color with the value R:127 G:255 B:0 A:255.


Color Color::Chocolate()
{
	return Color(210,105,30);
}//	Gets a system-defined color with the value R:210 G:105 B:30 A:255.


Color Color::Coral()
{
	return Color(255,127,80);
}//	Gets a system-defined color with the value R:255 G:127 B:80 A:255.


Color Color::CornflowerBlue()
{
	return Color(100,149,237);
}//	Gets a system-defined color with the value R:100 G:149 B:237 A:255.


Color Color::Cornsilk()
{
	return Color(255,248,220);
}//	Gets a system-defined color with the value R:255 G:248 B:220 A:255.


Color Color::Crimson()
{
	return Color(220,20,60);
}//	Gets a system-defined color with the value R:220 G:20 B:60 A:255.


Color Color::Cyan()
{
	return Color(0,255,255);
}//	Gets a system-defined color with the value R:0 G:255 B:255 A:255.


Color Color::DarkBlue()
{
	return Color(0,0,139);
}//	Gets a system-defined color with the value R:0 G:0 B:139 A:255.


Color Color::DarkCyan()
{
	return Color(0,139,139);
}//	Gets a system-defined color with the value R:0 G:139 B:139 A:255.


Color Color::DarkGoldenrod()
{
	return Color(184,134,11);
}//	Gets a system-defined color with the value R:184 G:134 B:11 A:255.


Color Color::DarkGray()
{
	return Color(169,169,169);
}//	Gets a system-defined color with the value R:169 G:169 B:169 A:255.


Color Color::DarkGreen()
{
	return Color(0,100,0);
}//	Gets a system-defined color with the value R:0 G:100 B:0 A:255.


Color Color::DarkKhaki()
{
	return Color(189,183,107);
}//	Gets a system-defined color with the value R:189 G:183 B:107 A:255.


Color Color::DarkMagenta()
{
	return Color(139,0,139);
}//	Gets a system-defined color with the value R:139 G:0 B:139 A:255.


Color Color::DarkOliveGreen()
{
	return Color(85,107,47);
}//	Gets a system-defined color with the value R:85 G:107 B:47 A:255.


Color Color::DarkOrange()
{
	return Color(255,140,0);
}//	Gets a system-defined color with the value R:255 G:140 B:0 A:255.


Color Color::DarkOrchid()
{
	return Color(153,50,204);
}//	Gets a system-defined color with the value R:153 G:50 B:204 A:255.

//----------------------------------------------------------------------------
Color Color::DarkRed()
{
	return Color(139,0,0);
}//	Gets a system-defined color with the value R:139 G:0 B:0 A:255.


Color Color::DarkSalmon()
{
	return Color(233,150,122);
}//	Gets a system-defined color with the value R:233 G:150 B:122 A:255.


Color Color::DarkSeaGreen()
{
	return Color(143,188,139);
}//	Gets a system-defined color with the value R:143 G:188 B:139 A:255.


Color Color::DarkSlateBlue()
{
	return Color(72,61,139);
}//	Gets a system-defined color with the value R:72 G:61 B:139 A:255.


Color Color::DarkSlateGray()
{
	return Color(47,79,79);
}//	Gets a system-defined color with the value R:47 G:79 B:79 A:255.


Color Color::DarkTurquoise()
{
	return Color(0,206,209);
}//	Gets a system-defined color with the value R:0 G:206 B:209 A:255.

Color Color::DarkViolet()
{
	return Color(148,0,211);
}//	Gets a system-defined color with the value R:148 G:0 B:211 A:255.


Color Color::DeepPink()
{
	return Color(255,20,147);
}//	Gets a system-defined color with the value R:255 G:20 B:147 A:255.


Color Color::DeepSkyBlue()
{
	return Color(0,191,255);
}//	Gets a system-defined color with the value R:0 G:191 B:255 A:255.


Color Color::DimGray()
{
	return Color(105,105,105);
}//	Gets a system-defined color with the value R:105 G:105 B:105 A:255.


Color Color::DodgerBlue()
{
	return Color(30,144,255);
}//	Gets a system-defined color with the value R:30 G:144 B:255 A:255.

////////////////////////////////////////////////////////////////////////
Color Color::Firebrick()
{
	return Color(178,34,34);
}//	Gets a system-defined color with the value R:178 G:34 B:34 A:255.

Color Color::FloralWhite()
{
	return Color(255,250,240);
}//	Gets a system-defined color with the value R:255 G:250 B:240 A:255.

Color Color::ForestGreen()
{
	return Color(34,139,34);
}//	Gets a system-defined color with the value R:34 G:139 B:34 A:255.

Color Color::Fuchsia()
{
	return Color(255,0,255);
}//	Gets a system-defined color with the value R:255 G:0 B:255 A:255.

Color Color::Gainsboro()
{
	return Color(220,220,220);
}//	Gets a system-defined color with the value R:220 G:220 B:220 A:255.

Color Color::GhostWhite()
{
	return Color(248,248,255);
}//	Gets a system-defined color with the value R:248 G:248 B:255 A:255.

Color Color::Gold()
{
	return Color(255,215,0);
}//	Gets a system-defined color with the value R:255 G:215 B:0 A:255.

Color Color::Goldenrod()
{
	return Color(218,165,32);
}//	Gets a system-defined color with the value R:218 G:165 B:32 A:255.

Color Color::Gray()
{
	return Color(128,128,128);
}//	Gets a system-defined color with the value R:128 G:128 B:128 A:255.

Color Color::Green()
{
	return Color(0,128,0);
}//	Gets a system-defined color with the value R:0 G:128 B:0 A:255.

Color Color::GreenYellow()
{
	return Color(173,255,47);
}//	Gets a system-defined color with the value R:173 G:255 B:47 A:255.

Color Color::Honeydew()
{
	return Color(240,255,240);
}//	Gets a system-defined color with the value R:240 G:255 B:240 A:255.

Color Color::HotPink()
{
	return Color(255,105,180);
}//	Gets a system-defined color with the value R:255 G:105 B:180 A:255.

Color Color::IndianRed()
{
	return Color(205,92,92);
}//	Gets a system-defined color with the value R:205 G:92 B:92 A:255.

Color Color::Indigo()
{
	return Color(75,0,130);
}//	Gets a system-defined color with the value R:75 G:0 B:130 A:255.

Color Color::Ivory()
{
	return Color(255,255,240);
}//	Gets a system-defined color with the value R:255 G:255 B:240 A:255.

Color Color::Khaki()
{
	return Color(240,230,140);
}//	Gets a system-defined color with the value R:240 G:230 B:140 A:255.
////////////////////////////////////////////////////////////////////////
Color Lavender()
{
	return Color(230,230,250);
}//	Gets a system-defined color with the value R:230 G:230 B:250 A:255.

Color LavenderBlush()
{
	return Color(255,240,245);
}//	Gets a system-defined color with the value R:255 G:240 B:245 A:255.

Color LawnGreen()
{
	return Color(124,252,0);
}//	Gets a system-defined color with the value R:124 G:252 B:0 A:255.

Color LemonChiffon()
{
	return Color(255,250,205);
}//	Gets a system-defined color with the value R:255 G:250 B:205 A:255.

Color LightBlue()
{
	return Color(173,216,230);
}//	Gets a system-defined color with the value R:173 G:216 B:230 A:255.

Color LightCoral()
{
	return Color(240,128,128);
}//	Gets a system-defined color with the value R:240 G:128 B:128 A:255.

Color LightCyan()
{
	return Color(224,255,255);
}//	Gets a system-defined color with the value R:224 G:255 B:255 A:255.

Color LightGoldenrodYellow()
{
	return Color(250,250,210);
}//	Gets a system-defined color with the value R:250 G:250 B:210 A:255.

Color LightGray()
{
	return Color(211,211,211);
}//	Gets a system-defined color with the value R:211 G:211 B:211 A:255.

Color LightGreen()
{
	return Color(144,238,144);
}//	Gets a system-defined color with the value R:144 G:238 B:144 A:255.

Color LightPink()
{
	return Color(255,182,193);
}//	Gets a system-defined color with the value R:255 G:182 B:193 A:255.

Color LightSalmon()
{
	return Color(255,160,122);
}//	Gets a system-defined color with the value R:255 G:160 B:122 A:255.

Color LightSeaGreen()
{
	return Color(32,178,170);
}//	Gets a system-defined color with the value R:32 G:178 B:170 A:255.

Color LightSkyBlue()
{
	return Color(135,206,250);
}//	Gets a system-defined color with the value R:135 G:206 B:250 A:255.

Color LightSlateGray()
{
	return Color(119,136,153);
}//	Gets a system-defined color with the value R:119 G:136 B:153 A:255.

Color LightSteelBlue()
{
	return Color(176,196,222);
}//	Gets a system-defined color with the value R:176 G:196 B:222 A:255.

Color LightYellow()
{
	return Color(255,255,224);
}//	Gets a system-defined color with the value R:255 G:255 B:224 A:255.

Color Lime()
{
	return Color(0,255,0);
}//	Gets a system-defined color with the value R:0 G:255 B:0 A:255.

Color LimeGreen()
{
	return Color(50,205,50);
}//	Gets a system-defined color with the value R:50 G:205 B:50 A:255.

Color Linen()
{
	return Color(250,240,230);
}//	Gets a system-defined color with the value R:250 G:240 B:230 A:255.

////////////////////////////////////////////////////////////////////////

Color Color::Magenta()
{
	return Color(255,0,255);
}//	Gets a system-defined color with the value R:255 G:0 B:255 A:255.

Color Color::Maroon()
{
	return Color(128,0,0);
}//	Gets a system-defined color with the value R:128 G:0 B:0 A:255.

Color Color::MediumAquamarine()
{
	return Color(102,205,170);
}//	Gets a system-defined color with the value R:102 G:205 B:170 A:255.

Color Color::MediumBlue()
{
	return Color(0,0,205);
}//	Gets a system-defined color with the value R:0 G:0 B:205 A:255.

Color Color::MediumOrchid()
{
	return Color(186,85,211);
}//	Gets a system-defined color with the value R:186 G:85 B:211 A:255.

Color Color::MediumPurple()
{
	return Color(147,112,219);
}//	Gets a system-defined color with the value R:147 G:112 B:219 A:255.

Color Color::MediumSeaGreen()
{
	return Color(60,179,113);
}//	Gets a system-defined color with the value R:60 G:179 B:113 A:255.

Color Color::MediumSlateBlue()
{
	return Color(123,104,238);
}//	Gets a system-defined color with the value R:123 G:104 B:238 A:255.

Color Color::MediumSpringGreen()
{
	return Color(0,250,154);
}//	Gets a system-defined color with the value R:0 G:250 B:154 A:255.

Color Color::MediumTurquoise()
{
	return Color(72,209,204);
}//	Gets a system-defined color with the value R:72 G:209 B:204 A:255.

Color Color::MediumVioletRed()
{
	return Color(199,21,133);
}//	Gets a system-defined color with the value R:199 G:21 B:133 A:255.

Color Color::MidnightBlue()
{
	return Color(25,25,112);
}//	Gets a system-defined color with the value R:25 G:25 B:112 A:255.

Color Color::MintCream()
{
	return Color(245,255,250);
}//	Gets a system-defined color with the value R:245 G:255 B:250 A:255.

Color Color::MistyRose()
{
	return Color(255,228,255);
}//	Gets a system-defined color with the value R:255 G:228 B:225 A:255.

////////////////////////////////////////////////////////////////////////
Color Color::White()
{
	return Color(255,255,255);
}//	Gets a system-defined color with the value R:255 G:255 B:255 A:255.

Color Color::WhiteSmoke()
{
	return Color(245,245,245);
}//	Gets a system-defined color with the value R:245 G:245 B:245 A:255.

Color Color::Yellow()
{
	return Color(255,255,0);
}//	Gets a system-defined color with the value R:255 G:255 B:0 A:255.

Color Color::YellowGreen()
{
	return Color(154,205,50);
}//	Gets a system-defined color with the value R:154 G:205 B:50 A:255.;

#pragma endregion
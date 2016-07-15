#pragma once

#include <SDL_video.h>
struct Color
{
private:
	unsigned int _R;
	unsigned int _G;
	unsigned int _B;
	unsigned int _A;
public:
	Color(unsigned int R, unsigned int G, unsigned int B, unsigned int A = 255);

	// Set the R component
	void R(unsigned int A);
	// Set the G component
	void G(unsigned int A);
	// Set the B component
	void B(unsigned int A);
	// Set the A component
	void A(unsigned int A);

	// Get the red component
	unsigned int R();
	// Get the Green Component
	unsigned int G();
	// Get the blue component
	unsigned int B();
	// Get the alpha component
	unsigned int A();

	operator SDL_Color ();

	// The RGBA for the predefined colors below were taken from Microsoft XNA 4.0's documentation
 	static Color AliceBlue();//	Gets a system-defined color with the value R:240 G:248 B:255 A:255.
 	static Color AntiqueWhite();//	Gets a system-defined color with the value R:250 G:235 B:215 A:255.
 	static Color Aqua();//	Gets a system-defined color with the value R:0 G:255 B:255 A:255.
	static Color Aquamarine();//	Gets a system-defined color with the value R:127 G:255 B:212 A:255.
 	static Color Azure();//	Gets a system-defined color with the value R:240 G:255 B:255 A:255.
 	static Color Beige();//	Gets a system-defined color with the value R:245 G:245 B:220 A:255.
 	static Color Bisque();//	Gets a system-defined color with the value R:255 G:228 B:196 A:255.
 	static Color Black();//	Gets a system-defined color with the value R:0 G:0 B:0 A:255.
 	static Color BlanchedAlmond();//	Gets a system-defined color with the value R:255 G:235 B:205 A:255.
 	static Color Blue();//	Gets a system-defined color with the value R:0 G:0 B:255 A:255.
 	static Color BlueViolet();//	Gets a system-defined color with the value R:138 G:43 B:226 A:255.
 	static Color Brown();//	Gets a system-defined color with the value R:165 G:42 B:42 A:255.
 	static Color BurlyWood();//	Gets a system-defined color with the value R:222 G:184 B:135 A:255.
 	static Color CadetBlue();//	Gets a system-defined color with the value R:95 G:158 B:160 A:255.
 	static Color Chartreuse();//	Gets a system-defined color with the value R:127 G:255 B:0 A:255.
 	static Color Chocolate();//	Gets a system-defined color with the value R:210 G:105 B:30 A:255.
 	static Color Coral();//	Gets a system-defined color with the value R:255 G:127 B:80 A:255.
 	static Color CornflowerBlue();//	Gets a system-defined color with the value R:100 G:149 B:237 A:255.
 	static Color Cornsilk();//	Gets a system-defined color with the value R:255 G:248 B:220 A:255.
 	static Color Crimson();//	Gets a system-defined color with the value R:220 G:20 B:60 A:255.
 	static Color Cyan();//	Gets a system-defined color with the value R:0 G:255 B:255 A:255.
 	static Color DarkBlue();//	Gets a system-defined color with the value R:0 G:0 B:139 A:255.
 	static Color DarkCyan();//	Gets a system-defined color with the value R:0 G:139 B:139 A:255.
 	static Color DarkGoldenrod();//	Gets a system-defined color with the value R:184 G:134 B:11 A:255.
 	static Color DarkGray();//	Gets a system-defined color with the value R:169 G:169 B:169 A:255.
 	static Color DarkGreen();//	Gets a system-defined color with the value R:0 G:100 B:0 A:255.
 	static Color DarkKhaki();//	Gets a system-defined color with the value R:189 G:183 B:107 A:255.
 	static Color DarkMagenta();//	Gets a system-defined color with the value R:139 G:0 B:139 A:255.
 	static Color DarkOliveGreen();//	Gets a system-defined color with the value R:85 G:107 B:47 A:255.
 	static Color DarkOrange();//	Gets a system-defined color with the value R:255 G:140 B:0 A:255.
 	static Color DarkOrchid();//	Gets a system-defined color with the value R:153 G:50 B:204 A:255.
 	static Color DarkRed();//	Gets a system-defined color with the value R:139 G:0 B:0 A:255.
 	static Color DarkSalmon();//	Gets a system-defined color with the value R:233 G:150 B:122 A:255.
 	static Color DarkSeaGreen();//	Gets a system-defined color with the value R:143 G:188 B:139 A:255.
 	static Color DarkSlateBlue();//	Gets a system-defined color with the value R:72 G:61 B:139 A:255.
 	static Color DarkSlateGray();//	Gets a system-defined color with the value R:47 G:79 B:79 A:255.
 	static Color DarkTurquoise();//	Gets a system-defined color with the value R:0 G:206 B:209 A:255.
 	static Color DarkViolet();//	Gets a system-defined color with the value R:148 G:0 B:211 A:255.
 	static Color DeepPink();//	Gets a system-defined color with the value R:255 G:20 B:147 A:255.
 	static Color DeepSkyBlue();//	Gets a system-defined color with the value R:0 G:191 B:255 A:255.
 	static Color DimGray();//	Gets a system-defined color with the value R:105 G:105 B:105 A:255.
 	static Color DodgerBlue();//	Gets a system-defined color with the value R:30 G:144 B:255 A:255.
 	static Color Firebrick();//	Gets a system-defined color with the value R:178 G:34 B:34 A:255.
 	static Color FloralWhite();//	Gets a system-defined color with the value R:255 G:250 B:240 A:255.
 	static Color ForestGreen();//	Gets a system-defined color with the value R:34 G:139 B:34 A:255.
 	static Color Fuchsia();//	Gets a system-defined color with the value R:255 G:0 B:255 A:255.
 	static Color Gainsboro();//	Gets a system-defined color with the value R:220 G:220 B:220 A:255.
 	static Color GhostWhite();//	Gets a system-defined color with the value R:248 G:248 B:255 A:255.
 	static Color Gold();//	Gets a system-defined color with the value R:255 G:215 B:0 A:255.
 	static Color Goldenrod();//	Gets a system-defined color with the value R:218 G:165 B:32 A:255.
 	static Color Gray();//	Gets a system-defined color with the value R:128 G:128 B:128 A:255.
 	static Color Green();//	Gets a system-defined color with the value R:0 G:128 B:0 A:255.
 	static Color GreenYellow();//	Gets a system-defined color with the value R:173 G:255 B:47 A:255.
 	static Color Honeydew();//	Gets a system-defined color with the value R:240 G:255 B:240 A:255.
 	static Color HotPink();//	Gets a system-defined color with the value R:255 G:105 B:180 A:255.
 	static Color IndianRed();//	Gets a system-defined color with the value R:205 G:92 B:92 A:255.
 	static Color Indigo();// Gets a system-defined color with the value R:75 G:0 B:130 A:255.
 	static Color Ivory();//	Gets a system-defined color with the value R:255 G:255 B:240 A:255.
 	static Color Khaki();//	Gets a system-defined color with the value R:240 G:230 B:140 A:255.
 	static Color Lavender();//	Gets a system-defined color with the value R:230 G:230 B:250 A:255.
 	static Color LavenderBlush();//	Gets a system-defined color with the value R:255 G:240 B:245 A:255.
 	static Color LawnGreen();//	Gets a system-defined color with the value R:124 G:252 B:0 A:255.
 	static Color LemonChiffon();//	Gets a system-defined color with the value R:255 G:250 B:205 A:255.
 	static Color LightBlue();//	Gets a system-defined color with the value R:173 G:216 B:230 A:255.
 	static Color LightCoral();//	Gets a system-defined color with the value R:240 G:128 B:128 A:255.
 	static Color LightCyan();//	Gets a system-defined color with the value R:224 G:255 B:255 A:255.
 	static Color LightGoldenrodYellow();//	Gets a system-defined color with the value R:250 G:250 B:210 A:255.
 	static Color LightGray();//	Gets a system-defined color with the value R:211 G:211 B:211 A:255.
 	static Color LightGreen();//	Gets a system-defined color with the value R:144 G:238 B:144 A:255.
 	static Color LightPink();//	Gets a system-defined color with the value R:255 G:182 B:193 A:255.
 	static Color LightSalmon();//	Gets a system-defined color with the value R:255 G:160 B:122 A:255.
 	static Color LightSeaGreen();//	Gets a system-defined color with the value R:32 G:178 B:170 A:255.
 	static Color LightSkyBlue();//	Gets a system-defined color with the value R:135 G:206 B:250 A:255.
 	static Color LightSlateGray();//	Gets a system-defined color with the value R:119 G:136 B:153 A:255.
 	static Color LightSteelBlue();//	Gets a system-defined color with the value R:176 G:196 B:222 A:255.
 	static Color LightYellow();//	Gets a system-defined color with the value R:255 G:255 B:224 A:255.
 	static Color Lime();//	Gets a system-defined color with the value R:0 G:255 B:0 A:255.
 	static Color LimeGreen();//	Gets a system-defined color with the value R:50 G:205 B:50 A:255.
 	static Color Linen();//	Gets a system-defined color with the value R:250 G:240 B:230 A:255.
 	
	static Color Magenta();//	Gets a system-defined color with the value R:255 G:0 B:255 A:255.
 	static Color Maroon();//	Gets a system-defined color with the value R:128 G:0 B:0 A:255.
 	static Color MediumAquamarine();//	Gets a system-defined color with the value R:102 G:205 B:170 A:255.
 	static Color MediumBlue();//	Gets a system-defined color with the value R:0 G:0 B:205 A:255.
 	static Color MediumOrchid();//	Gets a system-defined color with the value R:186 G:85 B:211 A:255.
 	static Color MediumPurple();//	Gets a system-defined color with the value R:147 G:112 B:219 A:255.
 	static Color MediumSeaGreen();//	Gets a system-defined color with the value R:60 G:179 B:113 A:255.
 	static Color MediumSlateBlue();//	Gets a system-defined color with the value R:123 G:104 B:238 A:255.
 	static Color MediumSpringGreen();//	Gets a system-defined color with the value R:0 G:250 B:154 A:255.
 	static Color MediumTurquoise();//	Gets a system-defined color with the value R:72 G:209 B:204 A:255.
 	static Color MediumVioletRed();//	Gets a system-defined color with the value R:199 G:21 B:133 A:255.
 	static Color MidnightBlue();//	Gets a system-defined color with the value R:25 G:25 B:112 A:255.
 	static Color MintCream();//	Gets a system-defined color with the value R:245 G:255 B:250 A:255.
 	static Color MistyRose();//	Gets a system-defined color with the value R:255 G:228 B:225 A:255.

 	/*Moccasin	Gets a system-defined color with the value R:255 G:228 B:181 A:255.
 	NavajoWhite	Gets a system-defined color with the value R:255 G:222 B:173 A:255.
 	Navy	Gets a system-defined color R:0 G:0 B:128 A:255.
 	OldLace	Gets a system-defined color with the value R:253 G:245 B:230 A:255.
 	Olive	Gets a system-defined color with the value R:128 G:128 B:0 A:255.
 	OliveDrab	Gets a system-defined color with the value R:107 G:142 B:35 A:255.
 	Orange	Gets a system-defined color with the value R:255 G:165 B:0 A:255.
 	OrangeRed	Gets a system-defined color with the value R:255 G:69 B:0 A:255.
 	Orchid	Gets a system-defined color with the value R:218 G:112 B:214 A:255.
	PackedValue	Gets the current color as a packed value.
 	PaleGoldenrod	Gets a system-defined color with the value R:238 G:232 B:170 A:255.
 	PaleGreen	Gets a system-defined color with the value R:152 G:251 B:152 A:255.
 	PaleTurquoise	Gets a system-defined color with the value R:175 G:238 B:238 A:255.
 	PaleVioletRed	Gets a system-defined color with the value R:219 G:112 B:147 A:255.
 	PapayaWhip	Gets a system-defined color with the value R:255 G:239 B:213 A:255.
 	PeachPuff	Gets a system-defined color with the value R:255 G:218 B:185 A:255.
 	Peru	Gets a system-defined color with the value R:205 G:133 B:63 A:255.
 	Pink	Gets a system-defined color with the value R:255 G:192 B:203 A:255.
 	Plum	Gets a system-defined color with the value R:221 G:160 B:221 A:255.
 	PowderBlue	Gets a system-defined color with the value R:176 G:224 B:230 A:255.
 	Purple	Gets a system-defined color with the value R:128 G:0 B:128 A:255.
	R	Gets or sets the red component value of this Color.
 	Red	Gets a system-defined color with the value R:255 G:0 B:0 A:255.
 	RosyBrown	Gets a system-defined color with the value R:188 G:143 B:143 A:255.
 	RoyalBlue	Gets a system-defined color with the value R:65 G:105 B:225 A:255.
 	SaddleBrown	Gets a system-defined color with the value R:139 G:69 B:19 A:255.
 	Salmon	Gets a system-defined color with the value R:250 G:128 B:114 A:255.
 	SandyBrown	Gets a system-defined color with the value R:244 G:164 B:96 A:255.
 	SeaGreen	Gets a system-defined color with the value R:46 G:139 B:87 A:255.
 	SeaShell	Gets a system-defined color with the value R:255 G:245 B:238 A:255.
 	Sienna	Gets a system-defined color with the value R:160 G:82 B:45 A:255.
 	Silver	Gets a system-defined color with the value R:192 G:192 B:192 A:255.
 	SkyBlue	Gets a system-defined color with the value R:135 G:206 B:235 A:255.
 	SlateBlue	Gets a system-defined color with the value R:106 G:90 B:205 A:255.
 	SlateGray	Gets a system-defined color with the value R:112 G:128 B:144 A:255.
 	Snow	Gets a system-defined color with the value R:255 G:250 B:250 A:255.
 	SpringGreen	Gets a system-defined color with the value R:0 G:255 B:127 A:255.
 	SteelBlue	Gets a system-defined color with the value R:70 G:130 B:180 A:255.
 	Tan	Gets a system-defined color with the value R:210 G:180 B:140 A:255.
 	Teal	Gets a system-defined color with the value R:0 G:128 B:128 A:255.
 	Thistle	Gets a system-defined color with the value R:216 G:191 B:216 A:255.
 	Tomato	Gets a system-defined color with the value R:255 G:99 B:71 A:255.
 	TransparentBlack	Gets a system-defined color with the value R:0 G:0 B:0 A:0.
 	TransparentWhite	Gets a system-defined color with the value R:255 G:255 B:255 A:0.
 	Turquoise	Gets a system-defined color with the value R:64 G:224 B:208 A:255.
 	Violet	Gets a system-defined color with the value R:238 G:130 B:238 A:255.
 	Wheat	Gets a system-defined color with the value R:245 G:222 B:179 A:255.*/

 	static Color White();//	Gets a system-defined color with the value R:255 G:255 B:255 A:255.
 	static Color WhiteSmoke();//	Gets a system-defined color with the value R:245 G:245 B:245 A:255.
 	static Color Yellow();//	Gets a system-defined color with the value R:255 G:255 B:0 A:255.
 	static Color YellowGreen();//	Gets a system-defined color with the value R:154 G:205 B:50 A:255.;
};

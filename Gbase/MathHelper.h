#pragma once

//namespace GameBase
//{
class MathHelper
{
public:
	template<typename T> static T max (T t1, T t2);
	template<typename T> static T min (T t1, T t2);
	template<typename T> static T clamp (T number, T min, T max);
};

template<typename T> static T MathHelper::max (T t1, T t2)
{
	return (t1>t2)?t1:t2;
}

template<typename T> static T MathHelper::min (T t1, T t2)
{
	return (t1<t2)?t1:t2;
}

template<typename T> static T MathHelper::clamp (T number, T min, T max)
{
	// if min <= number <= max
	if(number>=min && number <= max)
		return number;
	else 
		return (number<min)? min: max;
}

//}
#pragma once


#if !defined(MATH_LIB_EX_EXPORT)
#define MATH_LIB_EX_EXPORT
#endif

namespace math_lib_ex
{

class MATH_LIB_EX_EXPORT CustomMath {
public:
	CustomMath();
	~CustomMath();
	virtual int sumar(const int& x, const int& y);
};


}
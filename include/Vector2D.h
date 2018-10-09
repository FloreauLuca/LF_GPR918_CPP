
#include "pch.h"

#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2D {
	Vector2D(int x, int y) :x(x), y(y) {

  	}
	Vector2D() {
		x = 0;
		y = 0;
	}
	int x;
	int y;
};

#endif

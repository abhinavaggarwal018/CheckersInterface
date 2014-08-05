#include "Output.h"
#include<Windows.h>
#pragma once

Output_param Player_1(Board(*Arr)[8], bool Continued, int Iter, int Remaining, int Wrong, int XCont, int YCont)
{
	Output_param move;

	Sleep(500000);

	move._xNew = 0;
	move._xOld = 0;
	move._yNew = 0;
	move._yOld = 0;

	return move;
}


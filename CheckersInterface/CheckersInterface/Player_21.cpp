#include "Output.h"
#include <time.h>
#include<Windows.h>
#include<iostream>
#include<random>

#pragma once

Output_param validMoves2[300];
int			n2;



void getMoves2(Board(*Arr)[8], bool Continued, int Iter, int Remaining, int Wrong, int XCont, int YCont, int Player)
{
	validMoves[0]._xOld = 1;
	n2 = 0;
	if (Continued == false)
	{
		if (Player == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (Arr[i][j]._status == 1)
					{
						if (Arr[i + 1][j + 1]._status == 0 && (i + 1) < 8 && (j + 1) < 8)
						{
							validMoves2[n2]._xNew = i + 1;
							validMoves2[n2]._yNew = j + 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i + 1][j + 1]._status == 2 && Arr[i + 2][j + 2]._status == 0 && (i + 2) < 8 && (j + 2) < 8)
						{
							validMoves2[n2]._xNew = i + 2;
							validMoves2[n2]._yNew = j + 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i + 1][j - 1]._status == 0 && (i + 1) < 8 && (j - 1) >= 0)
						{
							validMoves2[n2]._xNew = i + 1;
							validMoves2[n2]._yNew = j - 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i + 1][j - 1]._status == 2 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0)
						{
							validMoves2[n2]._xNew = i + 2;
							validMoves2[n2]._yNew = j - 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j + 1]._status == 0 && Arr[i][j]._flag && (i - 1) >= 0 && (j + 1) < 8)
						{
							validMoves2[n2]._xNew = i - 1;
							validMoves2[n2]._yNew = j + 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j + 1]._status == 2 && Arr[i - 2][j + 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j + 2) < 8)
						{
							validMoves2[n2]._xNew = i - 2;
							validMoves2[n2]._yNew = j + 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j - 1]._status == 0 && Arr[i][j]._flag && (i - 1) >= 0 && (j - 1) >= 0)
						{
							validMoves2[n2]._xNew = i - 1;
							validMoves2[n2]._yNew = j - 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j - 1]._status == 2 && Arr[i - 2][j - 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j - 2) >= 0)
						{
							validMoves2[n2]._xNew = i - 2;
							validMoves2[n2]._yNew = j - 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

					}
				}
			}
		}

		if (Player == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (Arr[i][j]._status == 2)
					{
						if (Arr[i + 1][j + 1]._status == 0 && Arr[i][j]._flag && (i + 1) < 8 && (j + 1) < 8)
						{
							validMoves2[n2]._xNew = i + 1;
							validMoves2[n2]._yNew = j + 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i + 1][j + 1]._status == 1 && Arr[i + 2][j + 2]._status == 0 && Arr[i][j]._flag && (i + 2) < 8 && (j + 2) < 8)
						{
							validMoves2[n2]._xNew = i + 2;
							validMoves2[n2]._yNew = j + 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i + 1][j - 1]._status == 0 && (i + 1) < 8 && (j - 1) >= 0 && Arr[i][j]._flag)
						{
							validMoves2[n2]._xNew = i + 1;
							validMoves2[n2]._yNew = j - 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i + 1][j - 1]._status == 1 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0 && Arr[i][j]._flag)
						{
							validMoves2[n2]._xNew = i + 2;
							validMoves2[n2]._yNew = j - 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j + 1]._status == 0 && (i - 1) >= 0 && (j + 1) < 8)
						{
							validMoves2[n2]._xNew = i - 1;
							validMoves2[n2]._yNew = j + 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j + 1]._status == 1 && Arr[i - 2][j + 2]._status == 0 && (i - 2) >= 0 && (j + 2) < 8)
						{
							validMoves2[n2]._xNew = i - 2;
							validMoves2[n2]._yNew = j + 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j - 1]._status == 0 && (i - 1) >= 0 && (j - 1) >= 0)
						{
							validMoves2[n2]._xNew = i - 1;
							validMoves2[n2]._yNew = j - 1;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

						if (Arr[i - 1][j - 1]._status == 1 && Arr[i - 2][j - 2]._status == 0 && (i - 2) >= 0 && (j - 2) >= 0)
						{
							validMoves2[n2]._xNew = i - 2;
							validMoves2[n2]._yNew = j - 2;
							validMoves2[n2]._xOld = i;
							validMoves2[n2]._yOld = j;
							n2++;
						}

					}
				}
			}
		}
	}

	else
	{
		if (Player == 1)
		{

			int i = XCont, j = YCont;

			validMoves2[n2]._xNew = i;
			validMoves2[n2]._xOld = i;
			validMoves2[n2]._yNew = j;
			validMoves2[n2]._yOld = j;
			n2++;
			if (Arr[i][j]._status == 1)
			{

				if (Arr[i + 1][j + 1]._status == 2 && Arr[i + 2][j + 2]._status == 0 && (i + 2) < 8 && (j + 2) < 8)
				{
					validMoves2[n2]._xNew = i + 2;
					validMoves2[n2]._yNew = j + 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}

				if (Arr[i + 1][j - 1]._status == 2 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0)
				{
					validMoves2[n2]._xNew = i + 2;
					validMoves2[n2]._yNew = j - 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}

				if (Arr[i - 1][j + 1]._status == 2 && Arr[i - 2][j + 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j + 2) < 8)
				{
					validMoves2[n2]._xNew = i - 2;
					validMoves2[n2]._yNew = j + 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}

				if (Arr[i - 1][j - 1]._status == 2 && Arr[i - 2][j - 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j - 2) >= 0)
				{
					validMoves2[n2]._xNew = i - 2;
					validMoves2[n2]._yNew = j - 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}
			}
		}

		if (Player == 2)
		{
			int i = XCont, j = YCont;

			validMoves2[n2]._xNew = i;
			validMoves2[n2]._xOld = i;
			validMoves2[n2]._yNew = j;
			validMoves2[n2]._yOld = j;
			n2++;

			if (Arr[i][j]._status == 2)
			{
				if (Arr[i + 1][j + 1]._status == 1 && Arr[i + 2][j + 2]._status == 0 && Arr[i][j]._flag && (i + 2) < 8 && (j + 2) < 8)
				{
					validMoves2[n2]._xNew = i + 2;
					validMoves2[n2]._yNew = j + 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}

				if (Arr[i + 1][j - 1]._status == 1 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0 && Arr[i][j]._flag)
				{
					validMoves2[n2]._xNew = i + 2;
					validMoves2[n2]._yNew = j - 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}

				if (Arr[i - 1][j + 1]._status == 1 && Arr[i - 2][j + 2]._status == 0 && (i - 2) >= 0 && (j + 2) < 8)
				{
					validMoves2[n2]._xNew = i - 2;
					validMoves2[n2]._yNew = j + 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}

				if (Arr[i - 1][j - 1]._status == 1 && Arr[i - 2][j - 2]._status == 0 && (i - 2) >= 0 && (j - 2) >= 0)
				{
					validMoves2[n2]._xNew = i - 2;
					validMoves2[n2]._yNew = j - 2;
					validMoves2[n2]._xOld = i;
					validMoves2[n2]._yOld = j;
					n2++;
				}

			}
		}
		else
			assert(0);
	}

}

Output_param Player_21(Board(*Arr)[8], bool Continued, int Iter, int Remaining, int Wrong, int XCont, int YCont, int Player)
{
	srand(time(NULL));
	getMoves2(Arr, Continued, Iter, Remaining, Wrong, XCont, YCont, Player);
	int val = rand() % n2;
	cout << "\n n2:" << n2<<"  val"<<val;;
	for (int i = 0; i < n2; i++)
		cout << "(" << validMoves2[i]._xOld << "," << validMoves2[i]._yOld << ") to (" << validMoves2[i]._xNew << "," << validMoves2[i]._yNew << "\n";
	return validMoves2[val];

}


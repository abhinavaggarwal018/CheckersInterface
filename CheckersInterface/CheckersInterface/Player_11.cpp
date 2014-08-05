#include "Output.h"
#include<Windows.h>
#include<iostream>
#include<random>
#include<time.h>
using namespace std;

Output_param validMoves[300];
int			 n;


void getMoves(Board(*Arr)[8], bool Continued, int Iter, int Remaining, int Wrong, int XCont, int YCont, int Player)
{
	n = 0;
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
							validMoves[n]._xNew = i + 1;
							validMoves[n]._yNew = j + 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i + 1][j + 1]._status == 2 && Arr[i + 2][j + 2]._status == 0 && (i + 2) < 8 && (j + 2) < 8)
						{
							validMoves[n]._xNew = i + 2;
							validMoves[n]._yNew = j + 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i + 1][j - 1]._status == 0 && (i + 1) < 8 && (j - 1) >= 0)
						{
							validMoves[n]._xNew = i + 1;
							validMoves[n]._yNew = j - 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i + 1][j - 1]._status == 2 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0)
						{
							validMoves[n]._xNew = i + 2;
							validMoves[n]._yNew = j - 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j + 1]._status == 0 && Arr[i][j]._flag && (i - 1) >= 0 && (j + 1) < 8)
						{
							validMoves[n]._xNew = i - 1;
							validMoves[n]._yNew = j + 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j + 1]._status == 2 && Arr[i - 2][j + 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j + 2) < 8)
						{
							validMoves[n]._xNew = i - 2;
							validMoves[n]._yNew = j + 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j - 1]._status == 0 && Arr[i][j]._flag && (i - 1) >= 0 && (j - 1) >= 0)
						{
							validMoves[n]._xNew = i - 1;
							validMoves[n]._yNew = j - 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j - 1]._status == 2 && Arr[i - 2][j - 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j - 2) >= 0)
						{
							validMoves[n]._xNew = i - 2;
							validMoves[n]._yNew = j - 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
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
							validMoves[n]._xNew = i + 1;
							validMoves[n]._yNew = j + 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i + 1][j + 1]._status == 1 && Arr[i + 2][j + 2]._status == 0 && Arr[i][j]._flag && (i + 2) < 8 && (j + 2) < 8)
						{
							validMoves[n]._xNew = i + 2;
							validMoves[n]._yNew = j + 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i + 1][j - 1]._status == 0 && (i + 1) < 8 && (j - 1) >= 0 && Arr[i][j]._flag)
						{
							validMoves[n]._xNew = i + 1;
							validMoves[n]._yNew = j - 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i + 1][j - 1]._status == 1 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0 && Arr[i][j]._flag)
						{
							validMoves[n]._xNew = i + 2;
							validMoves[n]._yNew = j - 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j + 1]._status == 0 && (i - 1) >= 0 && (j + 1) < 8)
						{
							validMoves[n]._xNew = i - 1;
							validMoves[n]._yNew = j + 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j + 1]._status == 1 && Arr[i - 2][j + 2]._status == 0 && (i - 2) >= 0 && (j + 2) < 8)
						{
							validMoves[n]._xNew = i - 2;
							validMoves[n]._yNew = j + 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j - 1]._status == 0 && (i - 1) >= 0 && (j - 1) >= 0)
						{
							validMoves[n]._xNew = i - 1;
							validMoves[n]._yNew = j - 1;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
						}

						if (Arr[i - 1][j - 1]._status == 1 && Arr[i - 2][j - 2]._status == 0 && (i - 2) >= 0 && (j - 2) >= 0)
						{
							validMoves[n]._xNew = i - 2;
							validMoves[n]._yNew = j - 2;
							validMoves[n]._xOld = i;
							validMoves[n]._yOld = j;
							n++;
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

			validMoves[n]._xNew = i;
			validMoves[n]._xOld = i;
			validMoves[n]._yNew = j;
			validMoves[n]._yOld = j;
			n++;
			if (Arr[i][j]._status == 1)
			{

				if (Arr[i + 1][j + 1]._status == 2 && Arr[i + 2][j + 2]._status == 0 && (i + 2) < 8 && (j + 2) < 8)
				{
					validMoves[n]._xNew = i + 2;
					validMoves[n]._yNew = j + 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}

				if (Arr[i + 1][j - 1]._status == 2 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0)
				{
					validMoves[n]._xNew = i + 2;
					validMoves[n]._yNew = j - 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}

				if (Arr[i - 1][j + 1]._status == 2 && Arr[i - 2][j + 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j + 2) < 8)
				{
					validMoves[n]._xNew = i - 2;
					validMoves[n]._yNew = j + 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}

				if (Arr[i - 1][j - 1]._status == 2 && Arr[i - 2][j - 2]._status == 0 && Arr[i][j]._flag && (i - 2) >= 0 && (j - 2) >= 0)
				{
					validMoves[n]._xNew = i - 2;
					validMoves[n]._yNew = j - 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}
			}
			else
				assert(0);
		}


		if (Player == 2)
		{
			int i = XCont, j = YCont;

			validMoves[n]._xNew = i;
			validMoves[n]._xOld = i;
			validMoves[n]._yNew = j;
			validMoves[n]._yOld = j;
			n++;

			if (Arr[i][j]._status == 2)
			{
				if (Arr[i + 1][j + 1]._status == 1 && Arr[i + 2][j + 2]._status == 0 && Arr[i][j]._flag && (i + 2) < 8 && (j + 2) < 8)
				{
					validMoves[n]._xNew = i + 2;
					validMoves[n]._yNew = j + 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}

				if (Arr[i + 1][j - 1]._status == 1 && Arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0 && Arr[i][j]._flag)
				{
					validMoves[n]._xNew = i + 2;
					validMoves[n]._yNew = j - 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}

				if (Arr[i - 1][j + 1]._status == 1 && Arr[i - 2][j + 2]._status == 0 && (i - 2) >= 0 && (j + 2) < 8)
				{
					validMoves[n]._xNew = i - 2;
					validMoves[n]._yNew = j + 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}

				if (Arr[i - 1][j - 1]._status == 1 && Arr[i - 2][j - 2]._status == 0 && (i - 2) >= 0 && (j - 2) >= 0)
				{
					validMoves[n]._xNew = i - 2;
					validMoves[n]._yNew = j - 2;
					validMoves[n]._xOld = i;
					validMoves[n]._yOld = j;
					n++;
				}

			}
			else
				assert(0);
		}
	}

}


#pragma once
Output_param Player_11(Board(*Arr)[8], bool Continued, int Iter, int Remaining, int Wrong, int XCont, int YCont, int Player)
{
	srand(time(NULL));
	getMoves(Arr, Continued, Iter, Remaining, Wrong, XCont, YCont, Player);
	int val = rand() % n;
	cout << "\n n:" << n << "  val" << val;
	for (int i = 0; i < n; i++)
		cout << "(" << validMoves[i]._xOld << "," << validMoves[i]._yOld << ") to (" << validMoves[i]._xNew << "," << validMoves[i]._yNew << ")\n";
	return validMoves[val];

}
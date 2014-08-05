#pragma once

#include<cstdio>
#include<string>
#include "iostream"
#include<cassert>
#include "Output.h"
#include<Windows.h>
#include<process.h>
#include<ctime>

using namespace std;

#define INVALID_MOVES_MAX 3
// 0 for unoccupied 1 for player 1 and 2 for player 2
#define ITERATION_MAX 200
#define TIME_MAX 1000 // 1000 ms for each code to run

class Driver
{
	Board	_board[8][8];
	int 	_lost;
	int		_iter;
	int		_player1Remaining;
	int		_player2Remaining;
	int		_wrong1;  // player 1 wrong
	int		_wrong2;  // player 2 wrong
	int		_player;
	bool	_isContinued;  // if it is continued chance or not
	int		_xCont; // if continued then value of x
	int		_yCont; // if continued then value of y


	int		flipPlayer(int _playerId);
	void	initBoard();
	void	penalise();
	void	reduceRemaining(int);

public:

	Driver();

	// These are mutator functions
	int		getWrong();
	int		getWrong1();
	int		getWrong2();
	int		getRemaining();
	int		getRemaining1();
	int		getRemaining2();
	int		getIter();
	int		getPlayer();
	bool	getContinued();
	void	getBoard(Board [][8]);
	int		getXCont();
	int		getYCont();
	int		getLost();


	void	setLost(int _val);

	bool	validateMove(int _xNew, int _yNew, int _xOld, int _yOld);

}Checkers;

Board			_arr[8][8];
int 			_flag;
HANDLE			hThread;
Param			*arg = new Param;
Output_param	_move;
bool			_deleted;
int				_xDel, _yDel;
char			_path[MAX_PATH];
char			_pathTemp[MAX_PATH];

void Driver::initBoard()
{
	printf("void Driver::initBoard()");

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_board[i][j]._status = 0;
			_board[i][j]._flag = 0;
		}
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				_board[i][j]._status = 1;
				_board[i][j]._flag = 0;
			}
		}
	}


	for (int i = 5; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				_board[i][j]._status = 2;
				_board[i][j]._flag = 0;
			}
		}
	}

}

Driver::Driver()
{
	printf("Driver::Driver()\n");
	initBoard();

	_wrong1 = INVALID_MOVES_MAX;
	_wrong2 = INVALID_MOVES_MAX;
	_lost = 0;
	_player = 1;
	_isContinued = false;
	_iter = ITERATION_MAX;
	_player1Remaining = 12;
	_player2Remaining = 12;
}

int Driver::flipPlayer(int _playerId)
{
	printf("int Driver::flipPlayer(int _playerId)");
	if (_playerId == 1)
		return 2;

	else if (_playerId == 2)
		return 1;
	
	else
		assert(0);

	return -1;
}

void Driver::penalise()
{
	printf("void Driver::penalise()");

	if (_player == 1)
	{
		--_wrong1;
		if (_wrong1 == 0)
			_lost = 1;
	}

	if (_player == 2)
	{
		--_wrong2;
		if (_wrong2 == 0)
			_lost = 2;
	}

}

bool Driver::validateMove(int _xNew, int _yNew, int _xOld, int _yOld)
{
	printf("bool Driver::validateMove(int _xNew, int _yNew, int _xOld, int _yOld)");
	int _oppositePlayer = flipPlayer(_player);

	cout << "Player:" << _player << "OppositePlayer:" << _oppositePlayer << "Continued?" << _isContinued << "\n";

	if (!_isContinued)
	{
		_iter--;

		if (_xOld<0 || _yOld<0 || _xNew<0 || _yNew<0 || _xOld>7 || _yOld>7 || _xNew>7 || _yNew>7 || _board[_xOld][_yOld]._status != _player || (_xNew + _yNew) % 2 != 0 || _board[_xNew][_yNew]._status != 0)
		{
			penalise();
			_player = _oppositePlayer;
			return false;
		}

		if (_xNew > _xOld && (_player == 1 || _board[_xOld][_yOld]._flag))
		{
			if (_yNew > _yOld)
			{
				if (_yNew == _yOld + 1 && _xNew == _xOld + 1)
				{
		
					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;
					
					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					_player = _oppositePlayer;

					return true;
				}

				if (_board[_xOld + 1][_yOld + 1]._status == _oppositePlayer && (_yNew == _yOld + 2 && _xNew == _xOld + 2))
				{
					_isContinued = true;

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;
					
					_board[_xOld + 1][_yOld + 1]._flag = 0;
					_board[_xOld + 1][_yOld + 1]._status = 0;
					
					_xDel = _xOld + 1;
					_yDel = _yOld + 1;

					_deleted = true;

					reduceRemaining(_oppositePlayer);

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{
					penalise();
					_player = _oppositePlayer;
					return false;
				}

			}

			if (_yNew < _yOld)
			{
				if (_yNew == _yOld - 1 && _xNew == _xOld + 1)
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					_player = _oppositePlayer;

					return true;
				}

				if (_board[_xOld + 1][_yOld - 1]._status == _oppositePlayer && (_yNew == _yOld - 2 && _xNew == _xOld + 2))
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;

					_board[_xOld + 1][_yOld - 1]._flag = 0;
					_board[_xOld + 1][_yOld - 1]._status = 0;

					reduceRemaining(_oppositePlayer);

					_xDel = _xOld + 1;
					_yDel = _yOld - 1;

					_deleted = true;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					_isContinued = true;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{
					penalise();
					_player = _oppositePlayer;
					return false;
				}
			}

			else
			{
				penalise();
				_player = _oppositePlayer;
				return false;
			}
		}

		if (_xNew < _xOld && (_player == 2 || _board[_xOld][_yOld]._flag))
		{
			if (_yNew > _yOld)
			{
				if (_yNew == _yOld + 1 && _xNew == _xOld - 1)
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;
					
					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					_player = _oppositePlayer;

					return true;
				}

				if (_board[_xOld - 1][_yOld + 1]._status == _oppositePlayer && (_yNew == _yOld + 2 && _xNew == _xOld - 2))
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;
					
					_board[_xOld - 1][_yOld + 1]._flag = 0;
					_board[_xOld - 1][_yOld + 1]._status = 0;

					reduceRemaining(_oppositePlayer);

					_xDel = _xOld - 1;
					_yDel = _yOld + 1;

					_deleted = true;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					_isContinued = true;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{
					penalise();
					_player = _oppositePlayer;
					return false;
				}
			}

			if (_yNew < _yOld)
			{
				if (_yNew == _yOld - 1 && _xNew == _xOld - 1)
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;
				
					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					_player = _oppositePlayer;

					return true;
				}

				if (_board[_xOld - 1][_yOld - 1]._status == _oppositePlayer && (_yNew == _yOld - 2 && _xNew == _xOld - 2))
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;

					_board[_xOld - 1][_yOld - 1]._flag = 0;
					_board[_xOld - 1][_yOld - 1]._status = 0;

					reduceRemaining(_oppositePlayer);

					_xDel = _xOld - 1;
					_yDel = _yOld - 1;

					_deleted = true;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					_isContinued = true;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{
					penalise();
					_player = _oppositePlayer;
					return false;
				}
			}

			else
			{
				penalise();
				_player = _oppositePlayer;
				return false;
			}
		}

		else
		{
			penalise();
			_player = _oppositePlayer;
			return false;
		}
	}

	else
	{

		if (_xOld<0 || _yOld<0 || _xNew<0 || _yNew<0 || _xOld>7 || _yOld>7 || _xNew>7 || _yNew>7 || _board[_xOld][_yOld]._status != _player || (_xNew + _yNew) % 2 != 0 || (_board[_xNew][_yNew]._status != _player && _board[_xNew][_yNew]._status != 0)|| _xOld!=_xCont || _yOld!=_yCont)
		{

			_isContinued = false;
			penalise();
			_player = _oppositePlayer;
			return false;
		}

		if (_xNew > _xOld && (_player == 1 || _board[_xOld][_yOld]._flag))
		{
			if (_yNew > _yOld)
			{
				if (_board[_xOld + 1][_yOld + 1]._status == _oppositePlayer && (_yNew == _yOld + 2 && _xNew == _xOld + 2) && _board[_xNew][_yNew]._status == 0)
				{
					_isContinued = true;

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;

					_board[_xOld + 1][_yOld + 1]._flag = 0;
					_board[_xOld + 1][_yOld + 1]._status = 0;

					reduceRemaining(_oppositePlayer);

					_xDel = _xOld + 1;
					_yDel = _yOld + 1;

					_deleted = true;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{
					_isContinued = false;
					penalise();
					_player = _oppositePlayer;
					return false;
				}

			}

			if (_yNew < _yOld)
			{
				if (_board[_xOld + 1][_yOld - 1]._status == _oppositePlayer && (_yNew == _yOld - 2 && _xNew == _xOld + 2) && _board[_xNew][_yNew]._status==0)
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;

					_board[_xOld + 1][_yOld - 1]._flag = 0;
					_board[_xOld + 1][_yOld - 1]._status = 0;

					reduceRemaining(_oppositePlayer);

					_xDel = _xOld + 1;
					_yDel = _yOld - 1;

					_deleted = true;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					_isContinued = true;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{
					_isContinued = false;
					penalise();
					_player = _oppositePlayer;
					return false;
				}
			}

			else
			{

				_isContinued = false;
				penalise();
				_player = _oppositePlayer;
				return false;
			}
		}

		if (_xNew < _xOld && (_player == 2 || _board[_xOld][_yOld]._flag))
		{
			if (_yNew > _yOld)
			{
				if (_board[_xOld - 1][_yOld + 1]._status == _oppositePlayer && (_yNew == _yOld + 2 && _xNew == _xOld - 2) && _board[_xNew][_yNew]._status == 0)
				{
					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;

					_board[_xOld - 1][_yOld + 1]._flag = 0;
					_board[_xOld - 1][_yOld + 1]._status = 0;

					reduceRemaining(_oppositePlayer);

					_xDel = _xOld - 1;
					_yDel = _yOld + 1;

					_deleted = true;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					_isContinued = true;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{

					_isContinued = false;
					penalise();
					_player = _oppositePlayer;
					return false;
				}
			}

			if (_yNew < _yOld)
			{
				if (_board[_xOld - 1][_yOld - 1]._status == _oppositePlayer && (_yNew == _yOld - 2 && _xNew == _xOld - 2) && _board[_xNew][_yNew]._status == 0)
				{

					_board[_xNew][_yNew]._status = _player;
					_board[_xNew][_yNew]._flag = _board[_xOld][_yOld]._flag;

					_board[_xOld - 1][_yOld - 1]._flag = 0;
					_board[_xOld - 1][_yOld - 1]._status = 0;

					reduceRemaining(_oppositePlayer);

					_xDel = _xOld - 1;
					_yDel = _yOld - 1;

					_deleted = true;

					_board[_xOld][_yOld]._flag = 0;
					_board[_xOld][_yOld]._status = 0;

					_xCont = _xNew;
					_yCont = _yNew;

					_isContinued = true;

					if (_player == 1 && _xNew == 7)
						_board[_xNew][_yNew]._flag = true;

					if (_player == 2 && _xNew == 0)
						_board[_xNew][_yNew]._flag = true;

					return true;
					// Did not flip player as chance of current player now if possible
				}

				else
				{
					_isContinued = false;
					penalise();
					_player = _oppositePlayer;
					return false;
				}
			}

			else
			{
				_isContinued = false;
				penalise();
				_player = _oppositePlayer;
				return false;
			}
		}

		else
		{
			if (_xNew == _xOld && _yNew == _yOld)
			{
				_isContinued = false;
				_player = _oppositePlayer;
				return true;
			}

			else
			{
				_isContinued = false;
				penalise();
				_player = _oppositePlayer;
				return false;
			}

		}
	}
}

void Driver::reduceRemaining(int _playerid)
{
	if (_playerid == 1)
	{
		--_player1Remaining;
		if (_player1Remaining == 0)
			_lost = 1;
	}

	else if (_playerid == 2)
	{
		--_player2Remaining;
		if (_player2Remaining == 0)
			_lost = 2;
	}

	else
		assert(0);
}

int Driver::getWrong()
{

	if (_player == 1)
		return _wrong1;
	
	if (_player == 2)
		return _wrong2;

	else
		assert(0);

	return -1;
}

int Driver::getRemaining()
{
	if (_player == 1)
		return _player1Remaining;

	if (_player == 2)
		return _player2Remaining;

	else
		assert(0);

	return -1;
}

int Driver::getIter()
{
	return _iter;
}

void Driver::getBoard(Board _arr[][8])
{
	printf("");

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_arr[i][j]._status = _board[i][j]._status;
			_arr[i][j]._flag = _board[i][j]._flag;
		}
	}
}

int Driver::getPlayer()
{
	return _player;
}

bool Driver::getContinued()
{

	return _isContinued;
}

int Driver::getXCont()
{
	return _xCont;
}

int Driver::getYCont()
{
	return _yCont;
}

int Driver::getLost()
{
	return _lost;
}

int Driver::getRemaining1()
{
	return _player1Remaining;
}

int Driver::getRemaining2()
{
	return _player2Remaining;
}

int Driver::getWrong1()
{
	return _wrong1;
}

int Driver::getWrong2()
{
	return _wrong2;
}

void Driver::setLost(int _val)
{
	_lost = _val;
}


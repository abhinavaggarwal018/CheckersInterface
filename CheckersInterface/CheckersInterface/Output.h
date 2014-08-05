#pragma once

struct Board
{

public:

	int			_status;
	bool		_flag;

	Board()
	{
			_flag = 0;
	}
};

struct Output_param
{
	int			_xNew;
	int			_xOld;
	int			_yNew;
	int			_yOld;
};

struct Param
{
	Board		_pBoard[8][8];
	bool		_pContinued;
	int			_pIter;
	int			_pRemaining; 
	int			_pWrong;
	int			_pXCont;
	int			_pYCont;

	void copyBoard(Board _arr[][8] )
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				_pBoard[i][j]._status = _arr[i][j]._status;
				_pBoard[i][j]._flag = _arr[i][j]._flag;
			}
		}
	}

};
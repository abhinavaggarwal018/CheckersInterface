#pragma once
#include "CheckersMain.h"
// Just change these four properties for new file and 10^10 instructions in one sec.
#include "Player_11.cpp"
#include "Player_21.cpp"

#define Player_1 Player_11//Not working
#define Player_2 Player_21//Not working

#define ROWS 8
#define COLUMNS 8

#define DISPLAY_TIME_VALID 400
// Player 1 plays first and is black

void Player_1Wrapper(void *_args)
{
//	time
//	printf("%s: void Player_1Wrapper(void *_args)\n", ctime(&(time(0))));
	Param *_arg = (Param*)_args;
	/*	cout << (*arg)._pContinued;
	cout << (*arg)._pIter;
	cout << (*arg)._pRemaining;
	cout << (*arg)._pWrong;
	cout << (*arg)._pXCont;
	cout << (*arg)._pYCont;

	for (int i = 0; i < 8; i++)
	{
	for (int j = 0; j < 8; j++)
	{
	cout << (*arg)._pBoard[i][j]._status << "(";
	cout << (*arg)._pBoard[i][j]._flag << ") ";
	}
	cout << "\n";
	}
	*/

	_flag = 0;
	_move = Player_1((*arg)._pBoard, (*arg)._pContinued, (*arg)._pIter, (*arg)._pRemaining, (*arg)._pWrong, (*arg)._pXCont, (*arg)._pYCont,1);
	printf("Move by player 1:(%d,%d) to (%d,%d)\n", _move._xOld, _move._yOld, _move._xNew, _move._yNew);
	_flag = 1;
}

void Player_2Wrapper(void *_args)
{
	printf("void Player_2Wrapper(void *_args)\n");

	Param *_arg = (Param*)_args;

	_flag = 0;
	_move = Player_2((*arg)._pBoard, (*arg)._pContinued, (*arg)._pIter, (*arg)._pRemaining, (*arg)._pWrong, (*arg)._pXCont, (*arg)._pYCont,2);
	printf("Move by player 2:(%d,%d) to (%d,%d)\n", _move._xOld, _move._yOld, _move._xNew, _move._yNew);
	_flag = 1;
}


namespace CheckersInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Summary for MyForm
	/// </summary>


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			GetCurrentDirectoryA(sizeof(_path), _path);
			path_m = gcnew String(_path);
			//
			//Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnNextMove;
	private: System::Windows::Forms::Label^  lblCurrentPlayer;


	private: System::Windows::Forms::Label^  lblPlayer1;
	private: System::Windows::Forms::Label^  lblPlayer2;
	private: System::Windows::Forms::Label^  lblMoves;
	private: System::Windows::Forms::TextBox^  tbMoves;



	private: System::Windows::Forms::ImageList^  imgList;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  lblPlayer1Pcs;
	private: System::Windows::Forms::Label^  lblPlayer2Pcs;
	private: System::Windows::Forms::MenuStrip^  menu;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuExit;

	private: System::Windows::Forms::ToolStripMenuItem^  menuNextMove;
	private: System::Windows::Forms::Label^  lblWinner;
	private: System::Windows::Forms::ToolStripMenuItem^  internalDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  menuWrong1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuWrong2;
	private: System::Windows::Forms::ToolStripMenuItem^  menuContinued;
	private: System::Windows::Forms::ToolStripMenuItem^  menuWinner;
	private: System::Windows::Forms::Label^  lblData;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  finalsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  menuFinals;
	private: System::Windows::Forms::ToolStripMenuItem^  menuSemiFinals;
	private: System::Windows::Forms::ToolStripMenuItem^  menuKnockout;



	private: System::Windows::Forms::ToolStripMenuItem^  soundToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  menuSoundOn;
	private: System::Windows::Forms::ToolStripMenuItem^  menuSoundOff;


	private: System::Windows::Forms::Label^  lblStatus;

	private: static array< PictureBox^, 2 > ^pb = gcnew array< PictureBox^, 2 >(8, 8);
	private: bool	isNextMove;			// Check whether variable printed is next move or Start!
	private: bool	isFinal;
	private: bool	isSemiFinal;
	private: bool	isKnockout;
			 bool	soundOn;
			 bool	soundPlaying;
			 SoundPlayer ^sound;
			 SoundPlayer ^messageSound;
	private: System::Windows::Forms::Label^  tb_lblCurrentPLayer;
	private: String^ path_m;
	private: System::Windows::Forms::ImageList^  imgList2;


	private: PictureBox ^player = gcnew PictureBox();

	protected:

	private:


		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnNextMove = (gcnew System::Windows::Forms::Button());
			this->lblCurrentPlayer = (gcnew System::Windows::Forms::Label());
			this->lblPlayer1 = (gcnew System::Windows::Forms::Label());
			this->lblPlayer2 = (gcnew System::Windows::Forms::Label());
			this->lblMoves = (gcnew System::Windows::Forms::Label());
			this->tbMoves = (gcnew System::Windows::Forms::TextBox());
			this->imgList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblPlayer1Pcs = (gcnew System::Windows::Forms::Label());
			this->lblPlayer2Pcs = (gcnew System::Windows::Forms::Label());
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuNextMove = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->internalDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuWrong1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuWrong2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuContinued = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuWinner = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->finalsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFinals = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSemiFinals = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuKnockout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->soundToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSoundOn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSoundOff = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblWinner = (gcnew System::Windows::Forms::Label());
			this->lblData = (gcnew System::Windows::Forms::Label());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->tb_lblCurrentPLayer = (gcnew System::Windows::Forms::Label());
			this->imgList2 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnNextMove
			// 
			this->btnNextMove->Location = System::Drawing::Point(690, 600);
			this->btnNextMove->Name = L"btnNextMove";
			this->btnNextMove->Size = System::Drawing::Size(220, 50);
			this->btnNextMove->TabIndex = 0;
			this->btnNextMove->Text = L"&Start";
			this->btnNextMove->UseVisualStyleBackColor = true;
			this->btnNextMove->Click += gcnew System::EventHandler(this, &MyForm::btnNextMove_Click);
			// 
			// lblCurrentPlayer
			// 
			this->lblCurrentPlayer->AutoSize = true;
			this->lblCurrentPlayer->BackColor = System::Drawing::Color::Transparent;
			this->lblCurrentPlayer->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCurrentPlayer->ForeColor = System::Drawing::Color::Blue;
			this->lblCurrentPlayer->Location = System::Drawing::Point(690, 90);
			this->lblCurrentPlayer->Name = L"lblCurrentPlayer";
			this->lblCurrentPlayer->Size = System::Drawing::Size(125, 23);
			this->lblCurrentPlayer->TabIndex = 1;
			this->lblCurrentPlayer->Text = L"Current Player";
			// 
			// lblPlayer1
			// 
			this->lblPlayer1->AutoSize = true;
			this->lblPlayer1->BackColor = System::Drawing::Color::Transparent;
			this->lblPlayer1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayer1->ForeColor = System::Drawing::Color::Blue;
			this->lblPlayer1->Location = System::Drawing::Point(690, 150);
			this->lblPlayer1->Name = L"lblPlayer1";
			this->lblPlayer1->Size = System::Drawing::Size(129, 23);
			this->lblPlayer1->TabIndex = 1;
			this->lblPlayer1->Text = L"Player 1 Pieces";
			// 
			// lblPlayer2
			// 
			this->lblPlayer2->AutoSize = true;
			this->lblPlayer2->BackColor = System::Drawing::Color::Transparent;
			this->lblPlayer2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayer2->ForeColor = System::Drawing::Color::Blue;
			this->lblPlayer2->Location = System::Drawing::Point(690, 210);
			this->lblPlayer2->Name = L"lblPlayer2";
			this->lblPlayer2->Size = System::Drawing::Size(129, 23);
			this->lblPlayer2->TabIndex = 1;
			this->lblPlayer2->Text = L"Player 2 Pieces";
			// 
			// lblMoves
			// 
			this->lblMoves->AutoSize = true;
			this->lblMoves->BackColor = System::Drawing::Color::Transparent;
			this->lblMoves->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMoves->ForeColor = System::Drawing::Color::Blue;
			this->lblMoves->Location = System::Drawing::Point(690, 270);
			this->lblMoves->Name = L"lblMoves";
			this->lblMoves->Size = System::Drawing::Size(64, 23);
			this->lblMoves->TabIndex = 1;
			this->lblMoves->Text = L"Moves";
			// 
			// tbMoves
			// 
			this->tbMoves->Cursor = System::Windows::Forms::Cursors::No;
			this->tbMoves->Enabled = false;
			this->tbMoves->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbMoves->Location = System::Drawing::Point(845, 270);
			this->tbMoves->Name = L"tbMoves";
			this->tbMoves->ReadOnly = true;
			this->tbMoves->Size = System::Drawing::Size(100, 29);
			this->tbMoves->TabIndex = 2;
			// 
			// imgList
			// 
			this->imgList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imgList.ImageStream")));
			this->imgList->TransparentColor = System::Drawing::Color::Transparent;
			this->imgList->Images->SetKeyName(0, L"black_board(0).jpg");
			this->imgList->Images->SetKeyName(1, L"dark_player(1).jpg");
			this->imgList->Images->SetKeyName(2, L"dark_player_flag(2).jpg");
			this->imgList->Images->SetKeyName(3, L"white_board(3).jpg");
			this->imgList->Images->SetKeyName(4, L"light_player(4).jpg");
			this->imgList->Images->SetKeyName(5, L"light_player_flag(5).jpg");
			this->imgList->Images->SetKeyName(6, L"shaded_black_board(6).jpg");
			this->imgList->Images->SetKeyName(7, L"shaded_dark_player(7).jpg");
			this->imgList->Images->SetKeyName(8, L"shaded_dark_player_flag(8).jpg");
			this->imgList->Images->SetKeyName(9, L"shaded_white_board(9).jpg");
			this->imgList->Images->SetKeyName(10, L"shaded_light_player(10).jpg");
			this->imgList->Images->SetKeyName(11, L"shaded_light_player_flag(11).jpg");
			this->imgList->Images->SetKeyName(12, L"shaded_black_board_b(12).jpg");
			this->imgList->Images->SetKeyName(13, L"shaded_dark_player_b(13).jpg");
			this->imgList->Images->SetKeyName(14, L"shaded_dark_player_flag_b(14).jpg");
			this->imgList->Images->SetKeyName(15, L"shaded_white_board_b(15).jpg");
			this->imgList->Images->SetKeyName(16, L"shaded_light_player_b(16).jpg");
			this->imgList->Images->SetKeyName(17, L"shaded_light_player_flag_b(17).jpg");
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Black;
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				175)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(36, 36);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(606, 606);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// lblPlayer1Pcs
			// 
			this->lblPlayer1Pcs->BackColor = System::Drawing::Color::Transparent;
			this->lblPlayer1Pcs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayer1Pcs->ForeColor = System::Drawing::Color::Red;
			this->lblPlayer1Pcs->Location = System::Drawing::Point(845, 150);
			this->lblPlayer1Pcs->Name = L"lblPlayer1Pcs";
			this->lblPlayer1Pcs->Size = System::Drawing::Size(100, 30);
			this->lblPlayer1Pcs->TabIndex = 4;
			// 
			// lblPlayer2Pcs
			// 
			this->lblPlayer2Pcs->BackColor = System::Drawing::Color::Transparent;
			this->lblPlayer2Pcs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayer2Pcs->ForeColor = System::Drawing::Color::Red;
			this->lblPlayer2Pcs->Location = System::Drawing::Point(845, 210);
			this->lblPlayer2Pcs->Name = L"lblPlayer2Pcs";
			this->lblPlayer2Pcs->Size = System::Drawing::Size(100, 30);
			this->lblPlayer2Pcs->TabIndex = 4;
			// 
			// menu
			// 
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->menuNextMove, this->internalDataToolStripMenuItem, this->optionsToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(950, 24);
			this->menu->TabIndex = 5;
			this->menu->Text = L"menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->MenuExit });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// MenuExit
			// 
			this->MenuExit->Name = L"MenuExit";
			this->MenuExit->Size = System::Drawing::Size(92, 22);
			this->MenuExit->Text = L"E&xit";
			this->MenuExit->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem1_Click);
			// 
			// menuNextMove
			// 
			this->menuNextMove->Name = L"menuNextMove";
			this->menuNextMove->Size = System::Drawing::Size(76, 20);
			this->menuNextMove->Text = L"&Next Move";
			this->menuNextMove->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// internalDataToolStripMenuItem
			// 
			this->internalDataToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->menuWrong1,
					this->menuWrong2, this->menuContinued, this->menuWinner
			});
			this->internalDataToolStripMenuItem->Name = L"internalDataToolStripMenuItem";
			this->internalDataToolStripMenuItem->Size = System::Drawing::Size(86, 20);
			this->internalDataToolStripMenuItem->Text = L"Internal &Data";
			// 
			// menuWrong1
			// 
			this->menuWrong1->Name = L"menuWrong1";
			this->menuWrong1->Size = System::Drawing::Size(192, 22);
			this->menuWrong1->Text = L"Player &1 Wrong Moves";
			this->menuWrong1->MouseEnter += gcnew System::EventHandler(this, &MyForm::menuWrong1_MouseEnter);
			this->menuWrong1->MouseLeave += gcnew System::EventHandler(this, &MyForm::menuWrong1_MouseLeave);
			// 
			// menuWrong2
			// 
			this->menuWrong2->Name = L"menuWrong2";
			this->menuWrong2->Size = System::Drawing::Size(192, 22);
			this->menuWrong2->Text = L"Player &2 Wrong Moves";
			this->menuWrong2->MouseEnter += gcnew System::EventHandler(this, &MyForm::menuWrong2_MouseEnter);
			this->menuWrong2->MouseLeave += gcnew System::EventHandler(this, &MyForm::menuWrong2_MouseLeave);
			// 
			// menuContinued
			// 
			this->menuContinued->Name = L"menuContinued";
			this->menuContinued->Size = System::Drawing::Size(192, 22);
			this->menuContinued->Text = L"&Continued chance";
			this->menuContinued->MouseEnter += gcnew System::EventHandler(this, &MyForm::menuContinued_MouseEnter);
			this->menuContinued->MouseLeave += gcnew System::EventHandler(this, &MyForm::menuContinued_MouseLeave);
			// 
			// menuWinner
			// 
			this->menuWinner->Name = L"menuWinner";
			this->menuWinner->Size = System::Drawing::Size(192, 22);
			this->menuWinner->Text = L"&Winner";
			this->menuWinner->MouseEnter += gcnew System::EventHandler(this, &MyForm::menuWinner_MouseEnter);
			this->menuWinner->MouseLeave += gcnew System::EventHandler(this, &MyForm::menuWinner_MouseLeave);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->finalsToolStripMenuItem,
					this->soundToolStripMenuItem
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"&Options";
			// 
			// finalsToolStripMenuItem
			// 
			this->finalsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuFinals,
					this->menuSemiFinals, this->menuKnockout
			});
			this->finalsToolStripMenuItem->Name = L"finalsToolStripMenuItem";
			this->finalsToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->finalsToolStripMenuItem->Text = L"&Game";
			// 
			// menuFinals
			// 
			this->menuFinals->Name = L"menuFinals";
			this->menuFinals->Size = System::Drawing::Size(133, 22);
			this->menuFinals->Text = L"&Finals";
			this->menuFinals->Click += gcnew System::EventHandler(this, &MyForm::menuFinals_Click);
			// 
			// menuSemiFinals
			// 
			this->menuSemiFinals->Name = L"menuSemiFinals";
			this->menuSemiFinals->Size = System::Drawing::Size(133, 22);
			this->menuSemiFinals->Text = L"&Semi Finals";
			this->menuSemiFinals->Click += gcnew System::EventHandler(this, &MyForm::menuSemiFinals_Click);
			// 
			// menuKnockout
			// 
			this->menuKnockout->Checked = true;
			this->menuKnockout->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menuKnockout->Name = L"menuKnockout";
			this->menuKnockout->Size = System::Drawing::Size(133, 22);
			this->menuKnockout->Text = L"&Knockout";
			this->menuKnockout->Click += gcnew System::EventHandler(this, &MyForm::menuKnockout_Click);
			// 
			// soundToolStripMenuItem
			// 
			this->soundToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuSoundOn,
					this->menuSoundOff
			});
			this->soundToolStripMenuItem->Name = L"soundToolStripMenuItem";
			this->soundToolStripMenuItem->Size = System::Drawing::Size(108, 22);
			this->soundToolStripMenuItem->Text = L"&Sound";
			// 
			// menuSoundOn
			// 
			this->menuSoundOn->Checked = true;
			this->menuSoundOn->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menuSoundOn->Name = L"menuSoundOn";
			this->menuSoundOn->Size = System::Drawing::Size(91, 22);
			this->menuSoundOn->Text = L"O&n";
			this->menuSoundOn->Click += gcnew System::EventHandler(this, &MyForm::menuSoundOn_Click);
			// 
			// menuSoundOff
			// 
			this->menuSoundOff->Name = L"menuSoundOff";
			this->menuSoundOff->Size = System::Drawing::Size(91, 22);
			this->menuSoundOff->Text = L"O&ff";
			this->menuSoundOff->Click += gcnew System::EventHandler(this, &MyForm::menuSoundOff_Click);
			// 
			// lblWinner
			// 
			this->lblWinner->AutoSize = true;
			this->lblWinner->BackColor = System::Drawing::Color::Transparent;
			this->lblWinner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWinner->ForeColor = System::Drawing::Color::Blue;
			this->lblWinner->Location = System::Drawing::Point(675, 458);
			this->lblWinner->Name = L"lblWinner";
			this->lblWinner->Size = System::Drawing::Size(0, 39);
			this->lblWinner->TabIndex = 6;
			// 
			// lblData
			// 
			this->lblData->AutoSize = true;
			this->lblData->BackColor = System::Drawing::Color::Transparent;
			this->lblData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblData->ForeColor = System::Drawing::Color::Green;
			this->lblData->Location = System::Drawing::Point(690, 40);
			this->lblData->Name = L"lblData";
			this->lblData->Size = System::Drawing::Size(0, 24);
			this->lblData->TabIndex = 7;
			// 
			// lblStatus
			// 
			this->lblStatus->BackColor = System::Drawing::Color::Transparent;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->ForeColor = System::Drawing::Color::DarkGreen;
			this->lblStatus->Location = System::Drawing::Point(232, 645);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(209, 46);
			this->lblStatus->TabIndex = 8;
			this->lblStatus->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tb_lblCurrentPLayer
			// 
			this->tb_lblCurrentPLayer->BackColor = System::Drawing::Color::Transparent;
			this->tb_lblCurrentPLayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tb_lblCurrentPLayer.Image")));
			this->tb_lblCurrentPLayer->Location = System::Drawing::Point(842, 90);
			this->tb_lblCurrentPLayer->Name = L"tb_lblCurrentPLayer";
			this->tb_lblCurrentPLayer->Size = System::Drawing::Size(32, 32);
			this->tb_lblCurrentPLayer->TabIndex = 9;
			// 
			// imgList2
			// 
			this->imgList2->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imgList2.ImageStream")));
			this->imgList2->TransparentColor = System::Drawing::Color::Transparent;
			this->imgList2->Images->SetKeyName(0, L"dark_small(0).jpg");
			this->imgList2->Images->SetKeyName(1, L"light_small(1).jpg");
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(950, 700);
			this->Controls->Add(this->tb_lblCurrentPLayer);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->lblData);
			this->Controls->Add(this->lblWinner);
			this->Controls->Add(this->lblPlayer2Pcs);
			this->Controls->Add(this->lblPlayer1Pcs);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbMoves);
			this->Controls->Add(this->lblMoves);
			this->Controls->Add(this->lblPlayer2);
			this->Controls->Add(this->lblPlayer1);
			this->Controls->Add(this->lblCurrentPlayer);
			this->Controls->Add(this->btnNextMove);
			this->Controls->Add(this->menu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu;
			this->Name = L"MyForm";
			this->Text = L"Checkers";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			//LPTSTR WINAPI 
//			cout<<GetCommandLine()<<"OVER";
			printf("private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)\n");
			
			isNextMove = false;
			Checkers.getBoard(_arr);
		
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << _arr[i][j]._status;
				}

				cout << "\n";
			}

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					pb[i,j]  = gcnew PictureBox();
					pb[i,j]->Dock = DockStyle::Fill;
					pb[i,j]->SizeMode = PictureBoxSizeMode::Normal;

					if ((i + j) % 2 == 1)
					{
						pb[i,j]->Image = imgList->Images[3];
						tableLayoutPanel1->Controls->Add(pb[i,j], j, i);
					}

					else
					{
						pb[i, j]->Image = imgList->Images[0];
						tableLayoutPanel1->Controls->Add(pb[i, j], j, i);
					}
				}
			}

			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLUMNS; j++)
				{
					if ((i + j) % 2 != 0)
						continue;

					if (_arr[i][j]._status == 1)
					{
						if (_arr[i][j]._flag == false)
						{
							pb[i, j]->Image = imgList->Images[1];
							tableLayoutPanel1->Controls->Add(pb[i, j], j, i);
						}
						else
						{
							pb[i, j]->Image = imgList->Images[2];
							tableLayoutPanel1->Controls->Add(pb[i, j], j, i);
						}

					}
					else if (_arr[i][j]._status == 2)
					{
						if (_arr[i][j]._flag == false)
						{
							pb[i, j]->Image = imgList->Images[4];
							tableLayoutPanel1->Controls->Add(pb[i, j], j, i);
						}
						else
						{
							pb[i, j]->Image = imgList->Images[5];
							tableLayoutPanel1->Controls->Add(pb[i, j], j, i);
						}

					}

					else if (_arr[i][j]._status == 0)
					{
						if (_arr[i][j]._flag != 0)
							MessageBox::Show("Flag not zero", "Internal Message");

						pb[i, j]->Image = imgList->Images[0];
						tableLayoutPanel1->Controls->Add(pb[i, j], j, i);
					}

					else
					{
						MessageBox::Show("Status not zero", "Internal Message");
						printf("Status not zero", "Internal Message\n");
					}

				}
			}
	
			strcpy(_pathTemp, _path);
			path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\Message.wav"));
			messageSound = gcnew SoundPlayer(path_m);
			messageSound->Play();


			 lblPlayer1Pcs->Text = Convert::ToString(Checkers.getRemaining1());
			 lblPlayer2Pcs->Text = Convert::ToString(Checkers.getRemaining2());
			 tbMoves->Text = Convert::ToString(ITERATION_MAX - Checkers.getIter());
			 
			 if (Checkers.getPlayer()==1)
				 tb_lblCurrentPLayer->Image = imgList2->Images[0];
			 else
				 tb_lblCurrentPLayer->Image = imgList2->Images[1];

			 menuKnockout->Checked = true;
			 menuSemiFinals->Checked = false;
			 menuFinals->Checked = false;

			 isKnockout = true;
			 isSemiFinal = false;
			 isFinal = false;

			 lblStatus->Text = "Knockout!";

			 soundOn = true;
			 soundPlaying = false;

			 strcpy(_pathTemp, _path);
			 path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\KnockoutLoad.wav"));
			 sound = gcnew SoundPlayer(path_m);
			 sound->PlayLooping();
	}

	public: void updateScreen()
	{

		Checkers.getBoard(_arr);
		printf("public: void updateScreen()\n");
		// update this for updating only 3 values i.e old, curr, deleted
		
		if (!isNextMove)
		{
			btnNextMove->Text = "Next Move!";
			isNextMove = true;
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << _arr[i][j]._status;
			}

			cout << "\n";
		}

		markCells(_move._xOld, _move._yOld, 0);
		markCells(_move._xNew, _move._yNew, 0);

		if (_deleted)
		{
			_deleted = false;
			markCells(_xDel, _yDel, 0);
		}

		lblPlayer1Pcs->Text = Convert::ToString(Checkers.getRemaining1());
		lblPlayer2Pcs->Text = Convert::ToString(Checkers.getRemaining2());
		tbMoves->Text = Convert::ToString(ITERATION_MAX-Checkers.getIter());

		if (Checkers.getPlayer() == 1)
			tb_lblCurrentPLayer->Image = imgList2->Images[0];
		else
			tb_lblCurrentPLayer->Image = imgList2->Images[1];


		if (!isNextMove)
		{
			btnNextMove->Text = "Next Move!";
			isNextMove = true;
		}

	}
	
	void execute() 
	{
		
		printf("void execute()\n");

		if (Checkers.getLost() == 1)
		{
			playWinner();
			MessageBox::Show("Player 1 has no pieces remaining. \nCongratulations, Player 2 Won!", "Game over!");
			printf("Player 1 has no pieces remaining. \nCongratulations, Player 2 Won!\n");
			lblWinner->Text = "Player 2 Won!";
			btnNextMove->Enabled = false;
			return;
		}

		if (Checkers.getLost() == 2)
		{
			playWinner();
			MessageBox::Show("Player 2 has no pieces remaining. \nCongratulations, Player 1 Won!", "Game over!");
			printf("Player 2 has no pieces remaining. \nCongratulations, Player 1 Won!\n");
			lblWinner->Text = "Player 1 Won!";
			btnNextMove->Enabled = false;
			return;
		}

		if (!isNextMove)
		{
			MessageBox::Show("Game started. All the best!","Lets Start!");
			sound->Stop();
			soundPlaying = false;
		}
		
		cout << soundOn << soundPlaying;

		if (soundOn)
		{
			if (!soundPlaying)
			{
				if (isFinal)
				{
					strcpy(_pathTemp, _path);
					path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\FinalsPlay.wav"));
					sound = gcnew SoundPlayer(path_m);
					sound->PlayLooping();
				}

				else if (isSemiFinal)
				{
					strcpy(_pathTemp, _path);
					path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\SemiFinalsPlay.wav"));
					sound = gcnew SoundPlayer(path_m);
					sound->PlayLooping();
				}

				else if (isKnockout)
				{
					strcpy(_pathTemp, _path);
					path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\KnockoutPlay.wav"));
					sound = gcnew SoundPlayer(path_m);
					sound->PlayLooping();
				}

				soundPlaying = true;
			}
		}
		else
		{
			if (soundPlaying)
			{
				sound->Stop();
				soundPlaying = false;
			}
		}

		if (!isMoveAvailable())
		{
			btnNextMove->Enabled = false;
			if (Checkers.getPlayer() == 1)
			{
				playWinner();
				MessageBox::Show("Player 1 has no valid move remaining. \nCongratulations, Player 2 Won!", "Game over!");
				printf("Player 1 has no valid move remaining. \nCongratulations, Player 2 Won!\n");
				lblWinner->Text = "Player 2 Won!";
				Checkers.setLost(1);
				return;
			}

			if (Checkers.getPlayer() == 2)
			{
				playWinner();
				MessageBox::Show("Player 2 has no valid move remaining. \nCongratulations, Player 1 Won!", "Game over!");
				printf("Player 2 has no valid move remaining. \nCongratulations, Player 1 Won!\n");
				lblWinner->Text = "Player 1 Won!";
				Checkers.setLost(2);
				return;
			}

			else
				return assert(0);

		}

		if (Checkers.getIter())
		{
			Checkers.getBoard(_arr);

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << _arr[i][j]._status << " ";
				}
				cout << "\n";
			}

			(*arg).copyBoard(_arr);
			(*arg)._pContinued = Checkers.getContinued();
			(*arg)._pIter = Checkers.getIter();
			(*arg)._pRemaining = Checkers.getRemaining();
			(*arg)._pWrong = Checkers.getWrong();
			(*arg)._pXCont = Checkers.getXCont();
			(*arg)._pYCont = Checkers.getYCont();

			_flag = 0;


			if (Checkers.getPlayer() == 1)
			{
				printf("Calling thread for player1\n");

				cout <<"Thread Handle: "<< (hThread = (HANDLE)_beginthread(Player_1Wrapper, 0, (void*)arg))<<"\n";

				Sleep(TIME_MAX + 5);

				if (_flag == 0)
				{
					playWinner();
					btnNextMove->Enabled = false;
					MessageBox::Show("Time limit exceeded by Player 1.\nCongratulations, Player 2 won!!!","Game Over!!");
					printf("Time limit exceeded by Player 1.\nCongratulations, Player 2 won!!!\n");
					TerminateThread(hThread, 0);
					CloseHandle(hThread);
					Checkers.setLost(1);
					lblWinner->Text = "Player 2 Won!";
					return;
				}				

				markCells(_move._xOld, _move._yOld, 1);
				markCells(_move._xNew, _move._yNew, 2);

				if (!Checkers.validateMove(_move._xNew, _move._yNew, _move._xOld, _move._yOld))
				{

					if (Checkers.getLost() == 1)
					{
						playWinner();
						MessageBox::Show("Invalid Move by Player 1. Maximum number of invalid moves reached.\nCongratulations, Player 2 won", "Game Over!!");
						printf("Invalid Move by Player 1. Maximum number of invalid moves reached.\nCongratulations, Player 2 won\n");
						btnNextMove->Enabled = false;
						lblWinner->Text = "Player 2 Won!";
						updateScreen();
						Checkers.setLost(1);
						return;
					}
					
					MessageBox::Show("Invalid Move by Player 1.", "Warning!!");
					printf("Invalid Move by Player 1.\n");
					updateScreen();
					return;
				}
			
				cout << "Valid Move for player 1\n";
				Sleep(DISPLAY_TIME_VALID);
				updateScreen();
				return;
			
			}

			else if (Checkers.getPlayer() == 2)
			{
				printf("Calling thread for player2\n");

				cout <<"Thread handle: "<< (hThread = (HANDLE)_beginthread(Player_2Wrapper, 0, (void*)arg))<<"\n";

				Sleep(TIME_MAX + 5);

				if (_flag == 0)
				{
					playWinner();
					btnNextMove->Enabled = false;
					MessageBox::Show("Time limit exceeded by Player 2.\nCongratulations, Player 1 won!!! ", "Game Over!!");
					printf("Time limit exceeded by Player 2.\nCongratulations, Player 1 won!!! \n");
					TerminateThread(hThread, 0);
					CloseHandle(hThread);
					lblWinner->Text = "Player 1 Won!";
					Checkers.setLost(2);
					return;
				}

				markCells(_move._xOld, _move._yOld, 1);
				markCells(_move._xNew, _move._yNew, 2);

				if (!Checkers.validateMove(_move._xNew, _move._yNew, _move._xOld, _move._yOld))
				{
					if (Checkers.getLost() == 2)
					{
						playWinner();
						MessageBox::Show("Invalid Move by Player 2. Maximum number of invalid moves reached.\nCongratulations, Player 1 won", "Game Over!!");
						printf("Invalid Move by Player 2. Maximum number of invalid moves reached.\nCongratulations, Player 1 won\n");
						btnNextMove->Enabled = false;
						updateScreen();
						lblWinner->Text = "Player 1 Won!";
						return;
					}
					
					MessageBox::Show("Invalid Move by Player 2.", "Warning!!");
					printf("Invalid Move by Player 2.\n");
					updateScreen();
					return;
				}
				
				cout << "Valid Move for player 2\n";
				Sleep(DISPLAY_TIME_VALID);
				updateScreen(); 
				return;
			}

			else
				return assert(0);
		}

		btnNextMove->Enabled = false;

		if (Checkers.getRemaining1() > Checkers.getRemaining2())
		{
			playWinner();
			MessageBox::Show("Player 1 has more pieces remaining. \nCongratulations, Player 2 Won!", "Game over!");
			printf("Player 1 has more pieces remaining. \nCongratulations, Player 2 Won!\n");
			lblWinner->Text = "Player 2 Won!";
			Checkers.setLost(1);
		}

		else if (Checkers.getRemaining1()<Checkers.getRemaining2())
		{
			playWinner();
			MessageBox::Show("Player 2 has more pieces remaining. \nCongratulations, Player 1 Won!", "Game over!");
			printf("Player 2 has more pieces remaining. \nCongratulations, Player 1 Won!\n");
			lblWinner->Text = "Player 1 Won!";
			Checkers.setLost(2);
		}

		else if (Checkers.getWrong1()>Checkers.getWrong2())
		{
			playWinner();
			MessageBox::Show("Player 2 had less wrong moves. \nCongratulations, Player 2 Won!", "Game over!");
			printf("Player 2 had less wrong moves. \nCongratulations, Player 2 Won!\n");
			lblWinner->Text = "Player 2 Won!";
			Checkers.setLost(1);
		}
		
		else if (Checkers.getWrong1() < Checkers.getWrong2())
		{
			playWinner();
			MessageBox::Show("Player 1 had less wrong moves. \nCongratulations, Player 1 Won!", "Game over!");
			printf("Player 1 had less wrong moves. \nCongratulations, Player 1 Won!\n");
			lblWinner->Text = "Player 1 Won!";
			Checkers.setLost(2);
		}

		else
		{
			playDraw();
			MessageBox::Show("Maximum moves reached. \nWell Played! It's a draw!", "Game over!");
			printf("Maximum moves reached. \nWell Played! It's a draw!\n");
			lblWinner->Text = "It's a Draw!";
		}
	}

	void markCells(int _x, int _y, int _key)
	{
		Checkers.getBoard(_arr);
		printf("void markCells(int _x(%d), int _y(%d), int _key(%d))\n",_x,_y,_key);

		if (_x<0 || _y<0 || _key<0 || _x>7 || _y>7 || _key>2 )
		{
			MessageBox::Show("Indexes recieved are out of bounds","Warning");
			return;
		}

		if ((_x + _y) % 2 == 1)
		pb[_x, _y]->Image = imgList->Images[3+(_key*6)];

		else if (_arr[_x][_y]._status == 1)
		{
			if (_arr[_x][_y]._flag == false)
			{
				cout << 1 + (_key * 6);
				cout << "\na1\n";
				pb[_x, _y]->Image = imgList->Images[1 + (_key * 6)];
//				tableLayoutPanel1->Controls->Add(pb[_x, _y], _y, _x);
			}
			else
			{
				cout << 2 + (_key * 6);
				cout << "\na2\n";
				pb[_x, _y]->Image = imgList->Images[2 + (_key * 6)];
//				tableLayoutPanel1->Controls->Add(pb[_x, _y], _y, _x);
			}

		}

		else if (_arr[_x][_y]._status == 2)
		{
			if (_arr[_x][_y]._flag == false)
			{
				cout << 4 + (_key * 6);
				cout << "\na3\n";
				pb[_x, _y]->Image = imgList->Images[4 + (_key * 6)];
//				tableLayoutPanel1->Controls->Add(pb[_x, _y], _y, _x);
			}
			else
			{
				cout << 5+ (_key * 6);
				cout << "\na4\n";
				pb[_x, _y]->Image = imgList->Images[5 + (_key * 6)];
//				tableLayoutPanel1->Controls->Add(pb[_x, _y], _y, _x);
			}

		}

		else if (_arr[_x][_y]._status == 0)
		{
			cout << "\na5\n";
			if (_arr[_x][_y]._flag != 0)
				MessageBox::Show("Flag not zero", "Internal Message");

			_arr[_x][_y]._flag=0;

			cout << (_key * 6);

			pb[_x, _y]->Image = imgList->Images[(_key * 6)];
//			tableLayoutPanel1->Controls->Add(pb[_x, _y], _y, _x);
		}		

		pb[_x, _y]->Refresh();
		tb_lblCurrentPLayer->Refresh();
		lblPlayer1Pcs->Refresh();
		lblPlayer2Pcs->Refresh();
		tbMoves->Refresh();
	}

private: System::Void btnNextMove_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 printf("btnNextMove_Click(System::Object^  sender, System::EventArgs^  e)\n");

			 execute();
}

private: System::Void exitToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 printf("exitToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)\n");

			 Application::Exit();
}

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 printf("exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)\n");

			 execute();
}

private: System::Void menuWinner_MouseEnter(System::Object^  sender, System::EventArgs^  e) {

			 if (Checkers.getLost() == 1)
				 lblData->Text = "Player 2 Won!";
			 else if (Checkers.getLost() == 2)
				 lblData->Text = "Player 1 Won!";
			 else if (Checkers.getIter()>=1)
				 lblData->Text = "Game in Progress!";
			 else
				 lblData->Text = "It's a Draw!";
}

private: System::Void menuWinner_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 lblData->Text = "";
}

private: System::Void menuContinued_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 if (Checkers.getContinued() == false)
				 lblData->Text = "Not Continued!";
			 else
			 {
				 lblData->Text = "Continued from marked cell!";
				 markCells(Checkers.getXCont(), Checkers.getYCont(), 2);
			 }
}

private: System::Void menuContinued_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 lblData->Text = "";
			 markCells(Checkers.getXCont(), Checkers.getYCont(), 0);
}

private: System::Void menuWrong2_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 lblData->Text = "Player 2 Wrong Moves: " + Convert::ToString(INVALID_MOVES_MAX-Checkers.getWrong2());
}

private: System::Void menuWrong2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 lblData->Text = "";
}

private: System::Void menuWrong1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 lblData->Text = "Player 1 Wrong Moves: " + Convert::ToString(INVALID_MOVES_MAX - Checkers.getWrong1());
}

private: System::Void menuWrong1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 lblData->Text = "";
}

private: System::Void menuSoundOn_Click(System::Object^  sender, System::EventArgs^  e) {
			 soundOn = true;
			 menuSoundOn->Checked = true;
			 menuSoundOff->Checked = false;
}

private: System::Void menuSoundOff_Click(System::Object^  sender, System::EventArgs^  e) {
			 sound->Stop();
			 soundOn = false;
			 menuSoundOn->Checked = false;
			 menuSoundOff->Checked = true;
}
private: System::Void menuKnockout_Click(System::Object^  sender, System::EventArgs^  e) {
			 menuKnockout->Checked = true;
			 menuSemiFinals->Checked = false;
			 menuFinals->Checked = false;

			 isKnockout = true;
			 isSemiFinal = false;
			 isFinal = false;

			 lblStatus->Text = "Knockout!";

			 if (soundOn)
			 {
				 sound->Stop();
				 strcpy(_pathTemp, _path);
				 path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\KnockoutLoad.wav"));
				 sound = gcnew SoundPlayer(path_m);
				 sound->PlayLooping();
			 }
}

private: System::Void menuSemiFinals_Click(System::Object^  sender, System::EventArgs^  e) {
			 menuKnockout->Checked = false;
			 menuSemiFinals->Checked = true;
			 menuFinals->Checked = false;

			 isKnockout = false;
			 isSemiFinal = true;
			 isFinal = false;

			 lblStatus->Text = "Semi Finals!";
			 
			 if (soundOn)
			 {
				 sound->Stop();
				 strcpy(_pathTemp, _path);
				 path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\SemiFinalsLoad.wav"));
				 sound = gcnew SoundPlayer(path_m);
				 sound->PlayLooping();
			 }
}

private: System::Void menuFinals_Click(System::Object^  sender, System::EventArgs^  e) {
			 menuKnockout->Checked = false;
			 menuSemiFinals->Checked = false;
			 menuFinals->Checked = true;

			 isKnockout = false;
			 isSemiFinal = false;
			 isFinal = true;

			 lblStatus->Text = "Finals!";
			 
			 if (soundOn)
			 {
				 sound->Stop();
				 strcpy(_pathTemp, _path);
				 path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\FinalsLoad.wav"));
				 sound = gcnew SoundPlayer(path_m);
				 sound->PlayLooping();
				 
			 }
}

	bool isMoveAvailable()
	{
		Checkers.getBoard(_arr);

		if (Checkers.getContinued())
			return true;

		else 
		{
			if (Checkers.getPlayer() == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (_arr[i][j]._status == 1)
						{
							if (_arr[i + 1][j + 1]._status == 0 && (i + 1) < 8 && (j + 1) < 8)
								return true;

							if (_arr[i + 1][j + 1]._status == 2 && _arr[i + 2][j + 2]._status == 0 && (i + 2) < 8 && (j + 2) < 8)
								return true;

							if (_arr[i + 1][j - 1]._status == 0 && (i + 1) < 8 && (j - 1) >= 0)
								return true;

							if (_arr[i + 1][j - 1]._status == 2 && _arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0)
								return true;

							if (_arr[i - 1][j + 1]._status == 0 && _arr[i][j]._flag && (i - 1) >=0  && (j + 1) <= 8)
								return true;

							if (_arr[i - 1][j + 1]._status == 2 && _arr[i - 2][j + 2]._status == 0 && _arr[i][j]._flag && (i - 2) >= 0 && (j + 2) < 8)
								return true;

							if (_arr[i - 1][j - 1]._status == 0 && _arr[i][j]._flag && (i - 1) >= 0 && (j - 1) >= 0)
								return true;

							if (_arr[i - 1][j - 1]._status == 2 && _arr[i - 2][j - 2]._status == 0 && _arr[i][j]._flag && (i - 2) >= 0 && (j - 2) >= 0)
								return true;

						}
						
					}
				}
				return false;
		}

		if (Checkers.getPlayer() == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (_arr[i][j]._status == 2)
					{
						if (_arr[i + 1][j + 1]._status == 0 && _arr[i][j]._flag && (i + 1) < 8 && (j + 1) < 8)
							return true;

						if (_arr[i + 1][j + 1]._status == 1 && _arr[i + 2][j + 2]._status == 0 && _arr[i][j]._flag && (i + 2) < 8 && (j + 2) < 8)
							return true;

						if (_arr[i + 1][j - 1]._status == 0 && (i + 1) < 8 && (j - 1) >= 0 && _arr[i][j]._flag)
							return true;

						if (_arr[i + 1][j - 1]._status == 1 && _arr[i + 2][j - 2]._status == 0 && (i + 2) < 8 && (j - 2) >= 0 && _arr[i][j]._flag)
							return true;

						if (_arr[i - 1][j + 1]._status == 0 && (i - 1) >= 0 && (j + 1) <= 8)
							return true;

						if (_arr[i - 1][j + 1]._status == 1 && _arr[i - 2][j + 2]._status == 0 && (i - 2) >= 0 && (j + 2) < 8)
							return true;

						if (_arr[i - 1][j - 1]._status == 0 && (i - 1) >= 0 && (j - 1) >= 0)
							return true;

						if (_arr[i - 1][j - 1]._status == 1 && _arr[i - 2][j - 2]._status == 0 && (i - 2) >= 0 && (j - 2) >= 0)
							return true;

					}
				}
			}

			return false;
		}
		return false;
	}			
}

public:	 void playWinner()
	{
		if (soundOn)
		{
			if (isFinal)
			{
				sound->Stop();
				strcpy(_pathTemp, _path);
				path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\FinalsWin.wav"));
				sound = gcnew SoundPlayer(path_m);
				sound->Play();
			}

			if (isSemiFinal)
			{
				sound->Stop();
				strcpy(_pathTemp, _path);
				path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\SemiFinalsWin.wav"));
				sound = gcnew SoundPlayer(path_m);
				sound->Play();
			}

			if (isKnockout)
			{
				sound->Stop();
				strcpy(_pathTemp, _path);
				path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\KnockoutWin.wav"));
				sound = gcnew SoundPlayer(path_m);
				sound->Play();
			}
		}
}

	void playDraw()
	{
		if (soundOn)
		{
			sound->Stop();
			strcpy(_pathTemp, _path);
			path_m = gcnew String(strcat(_pathTemp, "\\media\\music\\Draw.wav"));
			sound = gcnew SoundPlayer(path_m);
			sound->Play();
		}
	}


};
}

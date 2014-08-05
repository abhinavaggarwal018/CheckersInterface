#pragma once

namespace CheckersInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Start
	/// </summary>
	public ref class Start : public System::Windows::Forms::Form
	{
	public:
		Start(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::Label^  lblDialogP1;
	private: System::Windows::Forms::Label^  lblDialogP2;
	private: System::Windows::Forms::ComboBox^  cbPlayer2Name;

	private: System::Windows::Forms::ComboBox^  cbPlayer1Name;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->lblDialogP1 = (gcnew System::Windows::Forms::Label());
			this->lblDialogP2 = (gcnew System::Windows::Forms::Label());
			this->cbPlayer2Name = (gcnew System::Windows::Forms::ComboBox());
			this->cbPlayer1Name = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(93, 197);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(75, 23);
			this->btnLoad->TabIndex = 0;
			this->btnLoad->Text = L"Begin!";
			this->btnLoad->UseVisualStyleBackColor = true;
			this->btnLoad->Click += gcnew System::EventHandler(this, &Start::btnLoad_Click);
			// 
			// lblDialogP1
			// 
			this->lblDialogP1->AutoSize = true;
			this->lblDialogP1->Location = System::Drawing::Point(37, 40);
			this->lblDialogP1->Name = L"lblDialogP1";
			this->lblDialogP1->Size = System::Drawing::Size(79, 13);
			this->lblDialogP1->TabIndex = 1;
			this->lblDialogP1->Text = L"Player 1 Name:";
			// 
			// lblDialogP2
			// 
			this->lblDialogP2->AutoSize = true;
			this->lblDialogP2->Location = System::Drawing::Point(37, 102);
			this->lblDialogP2->Name = L"lblDialogP2";
			this->lblDialogP2->Size = System::Drawing::Size(79, 13);
			this->lblDialogP2->TabIndex = 1;
			this->lblDialogP2->Text = L"Player 2 Name:";
			// 
			// cbPlayer2Name
			// 
			this->cbPlayer2Name->FormattingEnabled = true;
			this->cbPlayer2Name->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Abhinav", L"Shrajan", L"Madhav", L"Nanak" });
			this->cbPlayer2Name->Location = System::Drawing::Point(124, 94);
			this->cbPlayer2Name->Name = L"cbPlayer2Name";
			this->cbPlayer2Name->Size = System::Drawing::Size(121, 21);
			this->cbPlayer2Name->TabIndex = 2;
			// 
			// cbPlayer1Name
			// 
			this->cbPlayer1Name->FormattingEnabled = true;
			this->cbPlayer1Name->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Abhinav", L"Shrajan", L"Madhav", L"Nanak" });
			this->cbPlayer1Name->Location = System::Drawing::Point(124, 32);
			this->cbPlayer1Name->Name = L"cbPlayer1Name";
			this->cbPlayer1Name->Size = System::Drawing::Size(121, 21);
			this->cbPlayer1Name->TabIndex = 2;
			this->cbPlayer1Name->SelectedIndexChanged += gcnew System::EventHandler(this, &Start::cbPlayer1Name_SelectedIndexChanged);
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->cbPlayer1Name);
			this->Controls->Add(this->cbPlayer2Name);
			this->Controls->Add(this->lblDialogP2);
			this->Controls->Add(this->lblDialogP1);
			this->Controls->Add(this->btnLoad);
			this->Name = L"Start";
			this->Text = L"Start";
			this->Load += gcnew System::EventHandler(this, &Start::Start_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Start_Load(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) {
				 Start::Close();

	}
	private: System::Void cbPlayer1Name_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			//	 cbPlayer1Name->
	}
};
}

#pragma once
#include"Table.h"
#include <msclr/marshal_cppstd.h>


namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		TTable* tabl;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Timer^ timer5;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;

	private: System::Windows::Forms::Button^ button1;

 







		   

	public:
		MyForm(void)
		{
			InitializeComponent();
			tabl = NULL;
			//
			//TODO: Add the constructor code here
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

			}
		}
	private: System::Windows::Forms::CheckBox^ checkBox1;
	protected:
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::Timer^ timer4;





	private: System::ComponentModel::IContainer^ components;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(12, 369);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(461, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"RUN_ALL_TESTS";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Geometr706 BlkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox1->Location = System::Drawing::Point(16, 48);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(98, 24);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"ScamTable ";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Geometr706 BlkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox2->Location = System::Drawing::Point(16, 71);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(87, 24);
			this->checkBox2->TabIndex = 2;
			this->checkBox2->Text = L"SortTable";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Geometr706 BlkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox3->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox3->Location = System::Drawing::Point(16, 94);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(87, 24);
			this->checkBox3->TabIndex = 3;
			this->checkBox3->Text = L"TreeTable";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Geometr706 BlkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox4->Location = System::Drawing::Point(16, 117);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(120, 24);
			this->checkBox4->TabIndex = 4;
			this->checkBox4->Text = L"HashStepTable";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Geometr706 BlkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox5->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox5->Location = System::Drawing::Point(16, 140);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(115, 24);
			this->checkBox5->TabIndex = 5;
			this->checkBox5->Text = L"HashListTable";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 19);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Select a table type:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(260, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(179, 19);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Select the task method:";
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Geometr706 BlkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox6->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox6->Location = System::Drawing::Point(251, 61);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(80, 24);
			this->checkBox6->TabIndex = 9;
			this->checkBox6->Text = L"Random";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"Geometr706 BlkCn BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox7->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox7->Location = System::Drawing::Point(251, 117);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(86, 24);
			this->checkBox7->TabIndex = 10;
			this->checkBox7->Text = L"Manually";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button2->Location = System::Drawing::Point(12, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 27);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Find";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button3->Location = System::Drawing::Point(12, 117);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(166, 27);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Insert";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button4->Location = System::Drawing::Point(12, 150);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(166, 27);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button5->Location = System::Drawing::Point(12, 183);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(166, 37);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Save table to file";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button6->Location = System::Drawing::Point(12, 41);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(166, 37);
			this->button6->TabIndex = 15;
			this->button6->Text = L"Read table from a file";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 26);
			this->textBox1->TabIndex = 16;
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(12, 189);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 26);
			this->textBox2->TabIndex = 17;
			this->textBox2->Visible = false;
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(237, 89);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"0";
			this->textBox3->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(352, 89);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 19;
			this->textBox4->Text = L"0";
			this->textBox4->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(348, 63);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 19);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Val:";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(233, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 19);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Key:";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Geometr415 Blk BT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label5->Location = System::Drawing::Point(260, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(163, 19);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Waiting for an action";
			this->label5->Visible = false;
			// 
			// timer5
			// 
			this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Segoe Script", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button7->Location = System::Drawing::Point(12, 325);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(461, 38);
			this->button7->TabIndex = 23;
			this->button7->Text = L"Print a table";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::Window;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button8->Location = System::Drawing::Point(12, 226);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(166, 27);
			this->button8->TabIndex = 24;
			this->button8->Text = L"Change the table type";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(485, 419);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Process^ proc = Process::Start("..\\Debug\\TestTable.exe");
		proc->WaitForExit();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (this->checkBox6->Checked == true || this->checkBox7->Checked == true)
		{
			this->timer1->Enabled = false;
			this->checkBox6->Visible = false;
			this->checkBox7->Visible = false;
			if (this->checkBox6->Checked == true)
			{
				this->label2->Text = Convert::ToString("Random filling in the table");
				this->checkBox6->Checked == false;
			}
			else
			{
				this->label2->Text = Convert::ToString("Manually filling in the table");
				this->label5->Visible = true;
				this->timer5->Enabled = true;
				this->checkBox7->Checked == false;
				this->label3->Visible = true;
				this->label4->Visible = true;
				this->textBox3->Visible = true;
				this->textBox4->Visible = true;
			}
		}
	}

	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (this->checkBox1->Checked == true || this->checkBox2->Checked == true || this->checkBox3->Checked == true || this->checkBox4->Checked == true || this->checkBox5->Checked == true)
		{
			this->checkBox1->Visible = false;
			this->checkBox2->Visible = false;
			this->checkBox3->Visible = false;
			this->checkBox4->Visible = false;
			this->checkBox5->Visible = false;
			this->button2->Visible = true;
			this->button3->Visible = true;
			this->button4->Visible = true;
			this->button5->Visible = true;
			this->button6->Visible = true;
			this->button7->Visible = true;
			this->button8->Visible = true;
			while (true)
			{
				if (this->checkBox1->Checked == true)
				{
					tabl = new TScamTable;
					this->label1->Text = Convert::ToString("ScamTable");
					this->checkBox1->Checked = false;
					break;
				}
				else if (this->checkBox2->Checked == true)
				{
					tabl = new TSortTable;
					this->label1->Text = Convert::ToString("SortTable");
					this->checkBox2->Checked = false;
					break;
				}
				else if (this->checkBox3->Checked == true)
				{
					tabl = new TTreeTable;
					this->label1->Text = Convert::ToString("TreeTable");
					this->checkBox3->Checked = false;
					break;
				}
				else if (this->checkBox4->Checked == true)
				{
					tabl = new THashTableStep;
					this->label1->Text = Convert::ToString("HashTableStep");
					this->checkBox4->Checked = false;
					break;
				}
				else
				{
					tabl = new THashTableList;
					this->label1->Text = Convert::ToString("HashTableList");
					this->checkBox5->Checked == false;
					break;
				}
			}
			this->timer2->Enabled = false;
		}
	}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	this->button6->Visible = false;
	this->textBox1->Visible = true;
	this->timer3->Enabled = true;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->button5->Visible = false;
	this->textBox2->Visible = true;
	this->timer4->Enabled = true;
}
	private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
		std::string s = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		if (s.length()>4 && s[s.length()-1]=='t' && s[s.length() - 2] == 'x' && s[s.length() - 3] == 't' && s[s.length() - 4] == '.')
		{
			std::ifstream file(s);
			if (file)
				if(tabl)
					tabl->ReadFile(s);
			this->timer3->Enabled = false;
			this->textBox1->Visible = false;
			this->button6->Visible = true;
			this->textBox1->Text = "";
		}
	}
private: System::Void timer4_Tick(System::Object^ sender, System::EventArgs^ e) {
	std::string s = msclr::interop::marshal_as<std::string>(this->textBox2->Text);
	if (s.length() > 4 && s[s.length() - 1] == 't' && s[s.length() - 2] == 'x' && s[s.length() - 3] == 't' && s[s.length() - 4] == '.')
	{
		std::ofstream file(s);
		if (file)
		{
			if (tabl)
				tabl->SaveFile(s);
			this->timer4->Enabled = false;
			this->textBox2->Visible = false;
			this->button5->Visible = true;
			this->textBox1->Text = "";
		}
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	 std::string key= msclr::interop::marshal_as<std::string>(this->textBox3->Text);
	 //std::string val= msclr::interop::marshal_as<std::string>(this->textBox4->Text);
	 if (tabl)
	 {
		 bool flag = tabl->Find(stoi(key));
		 if (flag)
			 this->label5->Text = Convert::ToString("Record found");
		 else
			 this->label5->Text = Convert::ToString("Record not found");

	 }
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string key = msclr::interop::marshal_as<std::string>(this->textBox3->Text);
	std::string val= msclr::interop::marshal_as<std::string>(this->textBox4->Text);
	TRecord tmp(stoi(key), stoi(val));
	if (tabl)
	{
		bool flag = tabl->Insert(tmp);
		if (flag)
			this->label5->Text = Convert::ToString("Record added");
		else
			this->label5->Text = Convert::ToString("Record not added");

	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string key = msclr::interop::marshal_as<std::string>(this->textBox3->Text);
	std::string val = msclr::interop::marshal_as<std::string>(this->textBox4->Text);
	if (tabl)
	{
		bool flag = tabl->Delete(stoi(key));
		if (flag)
			this->label5->Text = Convert::ToString("Record deleted");
		else
			this->label5->Text = Convert::ToString("Record not deleted");

	}
}
private: System::Void timer5_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (tabl)
	{
		if (tabl->IsEmpty())
			this->button4->Enabled = false;
		else
			this->button4->Enabled = true;
		if (tabl->IsFull())
			this->button3->Enabled = false;
		else
			this->button3->Enabled = true;
		if (tabl->GetData() > 10)
			this->button7->Enabled = false;
	}
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (tabl)
		tabl->Print();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	delete tabl;
	this->checkBox1->Visible = true;
	this->checkBox2->Visible = true;
	this->checkBox3->Visible = true;
	this->checkBox4->Visible = true;
	this->checkBox5->Visible = true;
	this->button2->Visible = false;
	this->button3->Visible = false;
	this->button4->Visible = false;
	this->button5->Visible = false;
	this->button6->Visible = false;
	this->button7->Visible = false;
	this->button8->Visible = false;
	this->timer2->Enabled = true;
}
};
}

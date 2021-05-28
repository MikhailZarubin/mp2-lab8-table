#pragma once
#include <msclr/marshal_cppstd.h>
#include"../TableProject/Table.h"

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;











		   bool f1, f2, res;

		   Pen^ ErrorPoint, ^ ErrorLine;
	private: System::Windows::Forms::Button^ button1;









		   

	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 482);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(447, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"RUN_ALL_TESTS";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(485, 517);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			STARTUPINFO cif;
			ZeroMemory(&cif, sizeof(STARTUPINFO));
			PROCESS_INFORMATION pi;
			CreateProcess("..\\TableProject\\Debug\\TestTable.exe" ,NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &cif, &pi);
			WaitForSingleObject(pi.hProcess, INFINITY);
	}
	};
}

#pragma once
#include"Calculator.h"
#include<string>

//#include<marshal_cppstd.h>

namespace calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ equ;
	private: System::Windows::Forms::TextBox^ setexpr;
	protected:

	protected:

	private: System::Windows::Forms::Label^ expr;
	private: System::Windows::Forms::Label^ answ;




	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->equ = (gcnew System::Windows::Forms::Button());
			this->setexpr = (gcnew System::Windows::Forms::TextBox());
			this->expr = (gcnew System::Windows::Forms::Label());
			this->answ = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// equ
			// 
			this->equ->Location = System::Drawing::Point(165, 132);
			this->equ->Name = L"equ";
			this->equ->Size = System::Drawing::Size(27, 23);
			this->equ->TabIndex = 0;
			this->equ->Text = L"=";
			this->equ->UseVisualStyleBackColor = true;
			this->equ->Click += gcnew System::EventHandler(this, &MyForm::equ_Click);
			// 
			// setexpr
			// 
			this->setexpr->Location = System::Drawing::Point(5, 135);
			this->setexpr->Name = L"setexpr";
			this->setexpr->Size = System::Drawing::Size(154, 20);
			this->setexpr->TabIndex = 1;
			// 
			// expr
			// 
			this->expr->AutoSize = true;
			this->expr->Location = System::Drawing::Point(105, 93);
			this->expr->Name = L"expr";
			this->expr->Size = System::Drawing::Size(55, 13);
			this->expr->TabIndex = 2;
			this->expr->Text = L"Expession";
			// 
			// answ
			// 
			this->answ->AutoSize = true;
			this->answ->Location = System::Drawing::Point(198, 138);
			this->answ->Name = L"answ";
			this->answ->Size = System::Drawing::Size(13, 13);
			this->answ->TabIndex = 3;
			this->answ->Text = L"_";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->answ);
			this->Controls->Add(this->expr);
			this->Controls->Add(this->setexpr);
			this->Controls->Add(this->equ);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ s = (setexpr->Text);

	}
	void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
private: System::Void equ_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string s;
	MarshalString(setexpr->Text, s);
	TCalculator cal(s);
	double res = cal.calc();
	answ->Text = Convert::ToString(res);
}
};
}

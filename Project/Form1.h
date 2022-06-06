#pragma once

//--------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

#include <sstream> 
#include <chrono>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;

//const int C = 50;
//const string duom = "kursiokai.txt";
const string rez = "rez_manoprograma.txt";

// is System string pavertimas i paprasta string
void MarshalString(String^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

struct data {
	string vardas, pavarde;
	int egz = 0;
	vector<int> nd;
	double rez = 0, mediana = 0;

};


void veiksmaisufailu(string duom, int rikiavimas ) {
	ifstream df(duom);
	ofstream rf(rez);

	rf << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " << std::setw(15) << "Galutinis (Vid.) " << std::setw(15) << "Galutinis (Med.) " << endl;
	rf << "---------------------------------------------------------------- " << endl;

	int p_elem = 0;
	//  int n=0;
	int paz = 0;
	double vidurkis = 0;
	vector<data> sarasas;

	string sw;  // zodis
	int kiekyra = 0;  // kiek is viso  yra elementu

	while ((df.peek() != '\n') && (df >> sw)) {
		kiekyra++;
	}

	while (!df.eof()) {
		data temp;


		// cout << kiekyra;

		 //nuskaitymas
		df >> temp.vardas >> temp.pavarde;
		for (int i = 0; i < kiekyra - 3; i++) {
			df >> paz;
			temp.nd.push_back(paz);
			vidurkis += paz;
		}
		df >> temp.egz;


		if (temp.nd.size() != 0) vidurkis = vidurkis / (kiekyra - 3);
		else vidurkis = 0;

		temp.rez = vidurkis * 0.4 + temp.egz * 0.6;
		vidurkis = 0;

		//mediana


		sort(temp.nd.begin(), temp.nd.begin() + temp.nd.size());
		if (temp.nd.size() % 2 == 1) {
			temp.mediana = temp.nd[temp.nd.size() / 2] * 0.4 + temp.egz * 0.6;
		}
		else {
			temp.mediana = ((temp.nd[temp.nd.size() / 2] + temp.nd[(temp.nd.size() / 2) - 1]) / 2.0) * 0.4 + temp.egz * 0.6;
		}




		sarasas.push_back(temp);

		//temp.nd.clear();
	}



	if(rikiavimas == 1){
		//pagal varda
		std::sort(sarasas.begin(), sarasas.end(), [](data a, data b) {
			if (a.vardas == b.vardas) return a.pavarde < b.pavarde;
			return a.vardas < b.vardas;
			});
	}
	else if (rikiavimas == 2) {
		// pagal pavarde
		std::sort(sarasas.begin(), sarasas.end(), [](data a, data b) {
			if (a.pavarde == b.pavarde) return a.vardas < b.vardas;
			return a.pavarde < b.pavarde;
			});
	}
	//pagal vidurki
	else if (rikiavimas == 3){
	std::sort(sarasas.begin(), sarasas.end(), [](data a, data b) {
		if (a.rez == b.rez) return a.pavarde < b.pavarde;
		return a.rez < b.rez;
		});
	}
	//pagal mediana
	else if (rikiavimas == 4) {
		std::sort(sarasas.begin(), sarasas.end(), [](data a, data b) {
			if (a.mediana == b.mediana) return a.pavarde < b.pavarde;
			return a.mediana < b.mediana;
			});
	}

	//isvedimas
	for (const auto& el : sarasas) {
		rf << std::left << std::setw(15) << el.vardas << " " << std::setw(15) << el.pavarde;
		rf << std::setw(15) << std::fixed << std::setprecision(2) << el.rez << std::setw(15) << std::fixed << std::setprecision(2) << el.mediana << " " << endl;
	}

	df.close();
	rf.close();
	sarasas.clear();

}

//--------------------------------------------------------------------------------


namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ apieToolStripMenuItem;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::String^ failo_vardas = "";
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::ToolStripMenuItem^ save1stFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ save2ndFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ informacijaToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;












	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->save1stFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->save2ndFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->apieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informacijaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button1->Location = System::Drawing::Point(806, 430);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button2->Location = System::Drawing::Point(806, 72);
			this->button2->Name = L"button2";
			this->button2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button2->Size = System::Drawing::Size(131, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Open File";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button3->Location = System::Drawing::Point(806, 112);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(131, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Save File";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->apieToolStripMenuItem, this->informacijaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(984, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openToolStripMenuItem,
					this->saveFileToolStripMenuItem, this->saveToolStripMenuItem, this->startToolStripMenuItem, this->closeToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->fileToolStripMenuItem->Text = L"Failas";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// saveFileToolStripMenuItem
			// 
			this->saveFileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->save1stFileToolStripMenuItem,
					this->save2ndFileToolStripMenuItem
			});
			this->saveFileToolStripMenuItem->Name = L"saveFileToolStripMenuItem";
			this->saveFileToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->saveFileToolStripMenuItem->Text = L"Save File";
			this->saveFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveFileToolStripMenuItem_Click);
			// 
			// save1stFileToolStripMenuItem
			// 
			this->save1stFileToolStripMenuItem->Name = L"save1stFileToolStripMenuItem";
			this->save1stFileToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->save1stFileToolStripMenuItem->Text = L"Save 1st File";
			this->save1stFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::save1stFileToolStripMenuItem_Click);
			// 
			// save2ndFileToolStripMenuItem
			// 
			this->save2ndFileToolStripMenuItem->Name = L"save2ndFileToolStripMenuItem";
			this->save2ndFileToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->save2ndFileToolStripMenuItem->Text = L"Save 2nd File";
			this->save2ndFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::save2ndFileToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->startToolStripMenuItem->Text = L"Start";
			this->startToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::startToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->closeToolStripMenuItem->Text = L"Exit";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::closeToolStripMenuItem_Click);
			// 
			// apieToolStripMenuItem
			// 
			this->apieToolStripMenuItem->Name = L"apieToolStripMenuItem";
			this->apieToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->apieToolStripMenuItem->Text = L"Apie";
			this->apieToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::apieToolStripMenuItem_Click);
			// 
			// informacijaToolStripMenuItem
			// 
			this->informacijaToolStripMenuItem->Name = L"informacijaToolStripMenuItem";
			this->informacijaToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->informacijaToolStripMenuItem->Text = L"Informacija";
			this->informacijaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::informacijaToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(49, 72);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(659, 181);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button4->Location = System::Drawing::Point(806, 151);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(131, 34);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Save";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(49, 283);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(500, 181);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(806, 219);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(131, 34);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Start";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button6->Location = System::Drawing::Point(577, 430);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(131, 34);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Save 2nd File";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(577, 283);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(119, 17);
			this->radioButton1->TabIndex = 9;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Rikiuoti pagal vardà";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(577, 307);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(131, 17);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Rikiuoti pagal pavardæ";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(577, 331);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(123, 17);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Rikiuoti pagal vidurká";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(577, 355);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(132, 17);
			this->radioButton4->TabIndex = 12;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Rikiuoti pagal medianà";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(411, 59);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(8, 8);
			this->flowLayoutPanel1->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(49, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Duomenø failo turinys: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 260);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Rezultatø failo turinys: ";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 512);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1000, 550);
			this->MinimumSize = System::Drawing::Size(950, 500);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MantoProjektas";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form1::Close();
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->InitialDirectory = "..\\";															// parenkome darbinæ direktorijà
		openFileDialog1->Filter = "txt files (*.txt)|*.txt";												// naudojamas filtras "Text files (*.txt)|*.txt";
		openFileDialog1->InitialDirectory = "..\\";															// parenkome darbinæ direktorijà
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)						// atidarom bilu pasirinkimo atverimui langa, 
		{
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);		// susiejame skaitymo srautà su atvertu failu kurio kelias
																											// paimtas ið openFileDialog1->FileName
			textBox1->Text = (sr->ReadToEnd());																// nuskaitome á textBox1->Text tekstà ið atverto failo
			failo_vardas = openFileDialog1->FileName;														// iðsaugome failo vardà jei noresime perraðyti jo turiná po pataisymø 
			sr->Close();																					// uþdarome srautà ir failà
		}
	}
private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void kitasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void apieToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Manto programa, \nkuriai naudojamos c++/clr formos galimybës. \nGeneruoti failams programà rasite: \nhttps://github.com/Mantelisx/Pirmas-projektas2 \nVisos autoriaus teisës yra saugomos.", "Apie", MessageBoxButtons::OK);
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();											// ágaliname ákeltà SaveFileDialog objektà
	saveFileDialog1->InitialDirectory = "..\\";															// parenkome darbinæ direktorijà
	saveFileDialog1->Filter = "txt files (*.txt)|*.txt";												// parinkome galimus failø pletinius
	String^ z = textBox1->Text;																			// uþpildome objektà System::String tekstu paimtu ið textBox1 objekto
	rep:
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)						// atidarom saugojimo vietos pasirinkimo langa, 
																										// naudojamas filtras "Text files (*.txt)|*.txt";
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(saveFileDialog1->FileName);	// susiejame áraðimo srautà su atvertu failu kurio kelias
																									// paimtas ið saveFileDialog1->FileName
		sw->Write(z);																				// Áraðome textBox1->Text lauko tekstà á atvertà failà
		sw->Close();																				// uþdarome srautà ir failà 
	}
	else MessageBox::Show("Klaida saugojime (gal nenurodëte pavadinimo).", "Klaida", MessageBoxButtons::OK);						// praneðimas sapie klaidà, iðveda praneðimà, 

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ z;
	if (textBox1->Text == "") z = " ";																	// tikriname ar textBox1->Text nera tuðèias ir jei taip áraðome á já tarpà
	else z = textBox1->Text;
	if (failo_vardas != "")																				// tikriname ar prieð tai atvertas failas egzistuoja ar ne
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(failo_vardas);					// susiejame áraðimo srautà su atvertu failu kurio kelias saugomas failo_vardas 
		sw->Write(z);																					// Áraðome textBox1->Text lauko tekstà á atvertà failà
		sw->Close();																					// uþdarome srautà ir failà
		MessageBox::Show("Failas sëkmingai perraðytas",									// praneðimas apie sekmingà perraðimà, iðveda praneðimà, 
			"Informacija", MessageBoxButtons::OK);														// uþvardintà kaip "Information" su mygtuku OK
	}
	else MessageBox::Show("Nerastas atidarytas failas.", "Failo atidarymo klaida", MessageBoxButtons::OK);			// praneðimas apie klaidà, iðveda praneðimà, 
																										//uþvardintà kaip "File open Error" su mygtuku OK
}
private: System::Void labasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//textBox2->Text = textBox1->Text;

	/*
	String^ v;
	for (int i = 0; i < 5; i++) {
	v = textBox1->Lines[i+1];
	listBox1->Items->Add(v);
	}
	*/

	//String^ v = textBox1->Lines[0];
	//textBox2->Text = v;

	String^ rezas = "rez_manoprograma.txt";
	int rikiavimas=1; // 1-pagal varda, 2-pagal pavarde, 3-pagal vidurki, 4-pagal mediana

	if (radioButton1->Checked) {
		rikiavimas = 1;
	}

	if (radioButton2->Checked) {
		rikiavimas = 2;
	}

	if(radioButton3->Checked){
		rikiavimas = 3;
	}

	if (radioButton4->Checked) {
		rikiavimas = 4;
	}

	if (failo_vardas != "")																				// tikriname ar prieð tai atvertas failas egzistuoja ar ne
	{
		std:string b;
		MarshalString(failo_vardas, b);	// system string pavertiams i std:string
		veiksmaisufailu(b, rikiavimas);

		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(rezas);		// susiejame skaitymo srautà su atvertu failu kurio kelias
																											// paimtas ið openFileDialog1->FileName
		textBox2->Text = (sr->ReadToEnd());																// nuskaitome á textBox1->Text tekstà ið atverto failo
		//failo_vardas = openFileDialog1->FileName;														// iðsaugome failo vardà jei noresime perraðyti jo turiná po pataisymø 
		sr->Close();
		remove("rez_manoprograma.txt");
	}
	else MessageBox::Show("Nerastas atidarytas failas.", "Failo atidarymo klaida", MessageBoxButtons::OK);

}




private: System::Void sToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button2_Click(sender, e);
}
private: System::Void saveFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button4_Click(sender, e);
}
private: System::Void startToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button5_Click(sender, e);
}
private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button1_Click(sender, e);
	//Form1::button1_Click(sender, e);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();											// ágaliname ákeltà SaveFileDialog objektà
	saveFileDialog1->InitialDirectory = "..\\";															// parenkome darbinæ direktorijà
	saveFileDialog1->Filter = "txt files (*.txt)|*.txt";												// parinkome galimus failø pletinius
	String^ z = textBox2->Text;																			// uþpildome objektà System::String tekstu paimtu ið textBox1 objekto
rep:
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)						// atidarom saugojimo vietos pasirinkimo langa, 
																										// naudojamas filtras "Text files (*.txt)|*.txt";
	{
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(saveFileDialog1->FileName);	// susiejame áraðimo srautà su atvertu failu kurio kelias
																									// paimtas ið saveFileDialog1->FileName
		sw->Write(z);																				// Áraðome textBox1->Text lauko tekstà á atvertà failà
		sw->Close();																				// uþdarome srautà ir failà 
	}
	else MessageBox::Show("Klaida saugojime (gal nenurodëte pavadinimo).", "Klaida", MessageBoxButtons::OK);						// praneðimas sapie klaidà, iðveda praneðimà, 

}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void save1stFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button3_Click(sender, e);
}
private: System::Void save2ndFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	button6_Click(sender, e);
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void informacijaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Duomenø failo pirma eilutë turi atrodyti maþdaug taip: \nVardas Pavarde ND1 ND2 ND3 ND4 ND5 Egz. \n\nTiek ND(sk) kiek yra namø darbø paþymiø (skaièiai + egz. skaièius). \n\nKitø eiluèiu formatas turi atitikti pirmos eilutës formatà. \nVardas1 Pavarde2 10 10 10 10 10 10 ","Informacija", MessageBoxButtons::OK);
}
};
}

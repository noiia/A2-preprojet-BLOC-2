#pragma once
#include "FormUtilisateur.h"
#include "BDD.h"
#include "UserRepository.h"
#include "User.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		UserRepository^ ur;
	public:
		MyForm(BDD^ mabdd)
		{
			this->mabdd = mabdd;
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn();
			dgvtbc->Name = "ID";
			this->ClientDgv->Columns->Add(dgvtbc);
			DataGridViewTextBoxColumn^ dgvtbc2 = gcnew DataGridViewTextBoxColumn();
			dgvtbc2->Name = "Nom";
			this->ClientDgv->Columns->Add(dgvtbc2);

			ur = gcnew UserRepository(mabdd);

			this->reload();

		}

		void reload() {
			System::Collections::Generic::List<User^>^ users = ur->getUsers();

			this->ClientDgv->Rows->Clear();
			for each (User ^ u in users) {
				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvc = gcnew DataGridViewTextBoxCell();
				dgvc->Value = Convert::ToString(u->getIdUser());
				dgvr->Cells->Add(dgvc);
				DataGridViewTextBoxCell^ dgvc2 = gcnew DataGridViewTextBoxCell();
				dgvc2->Value = u->getName();
				dgvr->Cells->Add(dgvc2);
				dgvr->Tag = u;
				this->ClientDgv->Rows->Add(dgvr);
			}
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ FormBtn;
	private: System::Windows::Forms::DataGridView^ ClientDgv;
	private: System::Windows::Forms::Label^ Title;
	protected:


	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->FormBtn = (gcnew System::Windows::Forms::Button());
			this->ClientDgv = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientDgv))->BeginInit();
			this->SuspendLayout();
			// 
			// FormBtn
			// 
			this->FormBtn->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBtn->Location = System::Drawing::Point(609, 23);
			this->FormBtn->Name = L"FormBtn";
			this->FormBtn->Size = System::Drawing::Size(102, 37);
			this->FormBtn->TabIndex = 0;
			this->FormBtn->Text = L"Formulaire";
			this->FormBtn->UseVisualStyleBackColor = true;
			this->FormBtn->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// ClientDgv
			// 
			this->ClientDgv->AllowUserToAddRows = false;
			this->ClientDgv->AllowUserToDeleteRows = false;
			this->ClientDgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ClientDgv->Location = System::Drawing::Point(29, 83);
			this->ClientDgv->MultiSelect = false;
			this->ClientDgv->Name = L"ClientDgv";
			this->ClientDgv->ReadOnly = true;
			this->ClientDgv->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ClientDgv->Size = System::Drawing::Size(742, 429);
			this->ClientDgv->TabIndex = 1;
			this->ClientDgv->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->ClientDgv->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::dataGridView1_CellMouseClick);
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(66, 23);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(205, 25);
			this->Title->TabIndex = 2;
			this->Title->Text = L"Clients Bricobléreau";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(813, 535);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->ClientDgv);
			this->Controls->Add(this->FormBtn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientDgv))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		User^ u = gcnew User();
		//System::Diagnostics::Debug::WriteLine("Cliqué sur " + u->ToString());
		FormUtilisateur^ formUtilisateur = gcnew FormUtilisateur(u);
		formUtilisateur->ShowDialog();
		System::Diagnostics::Debug::WriteLine(u->ToString());
		ur->insertUser(u);
		this->reload();
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			}
	private: System::Void dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		DataGridViewRow^ dgvr = this->ClientDgv->Rows[e->RowIndex];
		User^ u = (User^)dgvr->Tag;
		//System::Diagnostics::Debug::WriteLine("Cliqué sur " + u->ToString());
		FormUtilisateur^ formUtilisateur = gcnew FormUtilisateur(u);
		formUtilisateur->ShowDialog();
		System::Diagnostics::Debug::WriteLine(u->ToString());
		ur->editUser(u);
		int selected = this->ClientDgv->SelectedRows[0]->Index;
		this->reload();
		this->ClientDgv->Rows[selected]->Selected = true;
	}
};
}

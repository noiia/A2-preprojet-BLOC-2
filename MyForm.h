#pragma once
#include "FormUtilisateur.h"
#include "BDD.h"

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
			this->dataGridView1->Columns->Add(dgvtbc);
			DataGridViewTextBoxColumn^ dgvtbc2 = gcnew DataGridViewTextBoxColumn();
			dgvtbc2->Name = "Nom";
			this->dataGridView1->Columns->Add(dgvtbc2);

			DataSet^ ds = mabdd->executeQuery("SELECT * FROM utilisateur");

			for each (DataRow^ row in ds->Tables[0]->Rows)
			{

				int id = (int)row[0];
				System::Diagnostics::Debug::WriteLine("id " + id);
				String^ nom = (String^)row[1];
				System::Diagnostics::Debug::WriteLine("nom " + nom);

				DataGridViewRow^ dgvr = gcnew DataGridViewRow();
				DataGridViewTextBoxCell^ dgvc = gcnew DataGridViewTextBoxCell();
				dgvc->Value = Convert::ToString(id);
				dgvr->Cells->Add(dgvc);
				DataGridViewTextBoxCell^ dgvc2 = gcnew DataGridViewTextBoxCell();
				dgvc2->Value = nom;
				dgvr->Cells->Add(dgvc2);
				this->dataGridView1->Rows->Add(dgvr);


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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(614, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(29, 83);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(742, 429);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::dataGridView1_CellMouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(813, 535);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		FormUtilisateur^ formUtilisateur = gcnew FormUtilisateur();
		formUtilisateur->ShowDialog();
		System::Diagnostics::Debug::WriteLine("Fenetre fermée");
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			}
	private: System::Void dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		DataGridViewRow^ dgvr = this->dataGridView1->Rows[e->RowIndex];
		DataGridViewTextBoxCell^ cell = (DataGridViewTextBoxCell^)dgvr->Cells[0];
		System::Diagnostics::Debug::WriteLine("Cliqué sur " + cell->Value);

	}
};
}

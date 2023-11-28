#pragma once
#include "User.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de FormUtilisateur
	/// </summary>
	public ref class FormUtilisateur : public System::Windows::Forms::Form
	{
		User^ u;
	public:
		FormUtilisateur(User^ u)
		{
			InitializeComponent();
			this->u = u;
			this->UsernameTbox->Text = u->getName();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FormUtilisateur()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ UsernameText;
	protected:

	private: System::Windows::Forms::Button^ ValidationBtn;

	private: System::Windows::Forms::TextBox^ UsernameTbox;
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
			this->Title = (gcnew System::Windows::Forms::Label());
			this->UsernameText = (gcnew System::Windows::Forms::Label());
			this->UsernameTbox = (gcnew System::Windows::Forms::TextBox());
			this->ValidationBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(49, 24);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(239, 25);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Formulaire d\'inscription";
			// 
			// UsernameText
			// 
			this->UsernameText->AutoSize = true;
			this->UsernameText->Font = (gcnew System::Drawing::Font(L"Orkney", 11.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UsernameText->Location = System::Drawing::Point(51, 76);
			this->UsernameText->Name = L"UsernameText";
			this->UsernameText->Size = System::Drawing::Size(85, 19);
			this->UsernameText->TabIndex = 5;
			this->UsernameText->Text = L"Username";
			// 
			// UsernameTbox
			// 
			this->UsernameTbox->Font = (gcnew System::Drawing::Font(L"Orkney", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UsernameTbox->Location = System::Drawing::Point(41, 102);
			this->UsernameTbox->Name = L"UsernameTbox";
			this->UsernameTbox->Size = System::Drawing::Size(147, 27);
			this->UsernameTbox->TabIndex = 1;
			// 
			// ValidationBtn
			// 
			this->ValidationBtn->Font = (gcnew System::Drawing::Font(L"Orkney", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ValidationBtn->Location = System::Drawing::Point(225, 236);
			this->ValidationBtn->Name = L"ValidationBtn";
			this->ValidationBtn->Size = System::Drawing::Size(75, 37);
			this->ValidationBtn->TabIndex = 3;
			this->ValidationBtn->Text = L"Valider";
			this->ValidationBtn->UseVisualStyleBackColor = true;
			this->ValidationBtn->Click += gcnew System::EventHandler(this, &FormUtilisateur::ValidationBtn_Click);
			// 
			// FormUtilisateur
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 305);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->UsernameTbox);
			this->Controls->Add(this->ValidationBtn);
			this->Controls->Add(this->UsernameText);
			this->Name = L"FormUtilisateur";
			this->Text = L"FormUtilisateur";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void ValidationBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->u->setName(this->UsernameTbox->Text);
	this->Close();
}
};
}

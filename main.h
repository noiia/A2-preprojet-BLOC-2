#include "BDD.h"
#include "MyForm.h"
#include "UserRepository.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int __clrcall WinMain(array<String^>^ args)
{
    BDD^ mabdd = gcnew BDD();

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project1::MyForm monFormulaire(mabdd);
    Application::Run(% monFormulaire);
    
}
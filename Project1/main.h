#include "BDD.h"
#include "MyForm.h"
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
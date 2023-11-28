#pragma once
#include "BDD.h"
#include "User.h"

using namespace  System::Collections::Generic;

using namespace System;
using namespace System::Data;

ref class UserRepository
{
private:
	BDD^ bdd;
public:
	UserRepository(BDD^ bdd) :bdd(bdd) {

	}

	List<User^>^ getUsers() {
		DataSet^ ds = bdd->executeQuery("SELECT * FROM [User]");

		List<User^>^ list = gcnew List<User^>();

		for each (DataRow ^ row in ds->Tables[0]->Rows)
		{
			User^ u = gcnew User();
			u->setIdUser((int)row[0]);
			u->setName((String^)row[1]);
			list->Add(u);
		}

		return list;
	}

	void editUser(User^ u) {
		bdd->executeNonQuery("UPDATE [User] SET name = '"+u->getName()+"' WHERE [idUser] = "+u->getIdUser());
	}

	void deleteUser(User^ u) {
		bdd->executeNonQuery("UPDATE [User] SET delete = true WHERE [idUser] = " + u->getIdUser());
	}

	void insertUser(User^ u) {
		int idUser = bdd->executeInsert("INSERT INTO [User](name) VALUES ('" + u->getName()+"')");
		u->setIdUser(idUser);
		//Enregistrer ses adresses
		//AdresseRepo ar=  ...
			//boucler sur les adresses a
			//ar.insert(a)
	}
};


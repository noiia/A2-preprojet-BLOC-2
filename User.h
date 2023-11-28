#pragma once

using namespace System;

ref class User
{

private:
	int idUser=0;
	String^ name;
	
public:
	void setIdUser(int idUser) {
		this->idUser = idUser;
	}

	int getIdUser() {
		return this->idUser;
	}

	void setName(String^ name) {
		this->name = name;
	}

	String^ getName() {
		return this->name;
	}

	String^ ToString() override {
		return "User id: "+this->idUser + " name: " + this->name;
	}

};


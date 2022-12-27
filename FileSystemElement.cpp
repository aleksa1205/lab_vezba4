#include "FileSystemElement.h"
#include <string>
#include <iostream>
using namespace std;

FileSystemElement::FileSystemElement(char* ime, char* ekstenzija) {
	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);
	this->ekstenzija = new char[strlen(ekstenzija) + 1];
	strcpy(this->ekstenzija, ekstenzija);
	this->roditelj = nullptr;
}

FileSystemElement::~FileSystemElement() {
	if (this->ime != nullptr) {
		delete[] this->ime;
	}
	if (this->ekstenzija != nullptr) {
		delete[] this->ekstenzija;
	}
	this->ime = nullptr;
	this->ekstenzija = nullptr;
	this->roditelj = nullptr;
}

void FileSystemElement::PostaviRoditelja(FileSystemElement* roditelj) {
	this->roditelj = roditelj;
	return;
}

char* FileSystemElement::VratiPunoIme() {
	char* punoIme = new char[strlen(this->ime) + strlen(this->ekstenzija) + 1];
	strcpy(punoIme, this->ime);
	strcat(punoIme, this->ekstenzija);
	return punoIme;
}

void FileSystemElement::PrintList() {
	cout << this->FileSystemElement::VratiPunoIme() << endl;
}
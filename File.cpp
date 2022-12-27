#include <string>
#include "File.h"
#include "Folder.h"
#include <iostream>
using namespace std;

File::File(char* ime, char* ekstenzija) :FileSystemElement(ime, ekstenzija) {}

File::~File() {}

char* File::VratiPunoIme() {
	char* punoIme = new char;
	strcpy(punoIme, "");
	if (this->roditelj != nullptr) {
		// Ovako radimo da bi prikazao samo prvog roditelja fajla
		strcat(punoIme, this->roditelj->FileSystemElement::VratiPunoIme());
	}
	strcat(punoIme, this->ime);
	strcat(punoIme, this->ekstenzija);
	return punoIme;
}

void File::PrintList() {
	FileSystemElement::PrintList();
	return;
}
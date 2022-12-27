#include "Folder.h"
#include <string>
#include <iostream>
using namespace std;

Folder::Folder(char* ime) :FileSystemElement(ime, (char*)"") {
	for (int i = 0; i < 2018; i++) {
		this->podElementi[i] = nullptr;
	}
}

Folder::~Folder() {
	if (this->podElementi != nullptr) {
		for (int i = 0; i < 2018; i++) {
			if (this->podElementi[i] != nullptr) {
				delete[] this->podElementi[i];
			}
			this->podElementi[i] = nullptr;
		}
		delete[] this->podElementi;
	}
}

char* Folder::VratiPunoIme() {
	char* punoIme = new char;
	strcpy(punoIme, "");
	int k=strlen(punoIme);
	if (this->roditelj != nullptr) {
		// Rekurzija da prikaze sve roditelje
		strcat(punoIme, this->roditelj->VratiPunoIme());
	}
	strcat(punoIme, this->ime);
	return punoIme;
}

void Folder::PrintList() {
	int i = 0;
	cout << FileSystemElement::VratiPunoIme() << endl;
	while (i < 2018) {
		if (this->podElementi[i] != nullptr) {
			this->podElementi[i]->PrintList();
		}
		i++;
	}
	return;
}

void Folder::DodajElement(FileSystemElement& element) {
	int indeks = -1, i = 0;
	while (indeks == -1 && i<2018) {
		if (this->podElementi[i] == nullptr) {
			indeks = i;
			element.PostaviRoditelja(this);
		}
		i++;
	}
	this->podElementi[indeks] = &element;
	
	return;
}

void Folder::ObrisiElement(int indeks) {
	if (this->podElementi[indeks] != nullptr) {
		delete this->podElementi[indeks];
	}
	this->podElementi[indeks] = nullptr;
	return;
}
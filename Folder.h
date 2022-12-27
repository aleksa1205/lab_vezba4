#pragma once
#include "FileSystemElement.h"

class Folder : public FileSystemElement
{
private:
	FileSystemElement* podElementi[2018];
public:
	Folder(char* ime);
	~Folder();

	char* VratiPunoIme();
	void PrintList();
	void DodajElement(FileSystemElement& element);
	void ObrisiElement(int indeks);
};
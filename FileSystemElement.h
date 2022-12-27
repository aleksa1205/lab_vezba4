#pragma once

class FileSystemElement
{
protected:
	char* ime;
	char* ekstenzija;
	FileSystemElement* roditelj;
public:
	FileSystemElement(char* ime, char* ekstenzija);
	~FileSystemElement();
	void PostaviRoditelja(FileSystemElement* roditelj);
	virtual char* VratiPunoIme() = 0;
	virtual void PrintList() = 0;
};
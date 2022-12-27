#include "FileSystemElement.h"
#include "Folder.h"
#include "File.h"
#include <iostream>
using namespace std;

void main() {
	File* f1 = new File((char*)"fajl1", (char*)".txt");
	File* f2 = new File((char*)"fajl2", (char*)".exe");
	File* f3 = new File((char*)"fajl3", (char*)".cpp");
	File* f4 = new File((char*)"fajl4", (char*)".asm");

	Folder* folR = new Folder((char*)"roditelj");
	Folder* folD = new Folder((char*)"dete");
	Folder* fol = new Folder((char*)"folder");
	folR->DodajElement(*folD);
	folD->DodajElement(*fol);
	cout << fol->VratiPunoIme() << endl;
	fol->DodajElement(*f1);
	cout << f1->VratiPunoIme() << endl;
	fol->DodajElement(*f1);
	fol->DodajElement(*f2);
	fol->DodajElement(*f3);
	fol->DodajElement(*f4);

	return;
}
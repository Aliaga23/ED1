//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaStr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaStr::PilaStr() {
	k = "";
}

bool PilaStr::vacia() {
	return k == "";
}

void PilaStr::meter(int e) {
	if (vacia())
		k = to_string(e) + ",";
	else {
		int c = 0;
		for (int i = 0; i < k.length(); i++) {
			if (k[i] == ',')
				c++;
		}
		if (c < 10)
			k = to_string(e) + "," + k;
	}
}

void PilaStr::sacar(int &e) {
	if (!vacia()) {
		int pos = k.find_first_of(",");
		string num = k.substr(0, pos);
		e = atoi(num.c_str());
		k.erase(0, pos + 1);
	}
}

int PilaStr::cima() {
	if (!vacia()) {
		int pos = k.find_first_of(",");
		if (pos == -1)
			return atoi(k.c_str());
		else {
			string num = k.substr(0, pos);
			return atoi(num.c_str());
		}
	}
}

void PilaStr::mostrar() {
	PilaStr* aux = new PilaStr();
	while (!vacia()) {
		int e;
		sacar(e);
		aux->meter(e);
		cout << e << endl;
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
}
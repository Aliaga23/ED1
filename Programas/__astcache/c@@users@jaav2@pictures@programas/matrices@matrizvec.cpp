﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizVec.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "iomanip"
MatrizV::MatrizV() {
	/* df = 0;
	 dc = 0;
	 repe = 0;
	 nt = 0; */
	df = dc = repe = nt = 0;
	vf = new int[0];
	vc = new int[0];
	vd = new int[0];
}

void MatrizV::dimensionar(int f, int c) {
	df = f;
	dc = c;
	// MAX_MV = f * c;
	// Se vacian los vectores
	/*
	 vf = new int[MAX_MV];
	 vc = new int[MAX_MV];
	 vd = new int[MAX_MV]; */
	vf = new int[df * dc];
	vc = new int[df * dc];
	vd = new int[df * dc];
}

int MatrizV::dimension_fila() {
	return df;
}

int MatrizV::dimension_columna() {
	return dc;
}

int MatrizV::posicion(int f, int c) {
	for (int i = 0; i < nt; i++) {
		if (vf[i] == f && vc[i] == c)
			return i;
	}
	return -1;
}

void MatrizV::poner(int f, int c, int valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lugar = posicion(f, c);
		if (lugar == -1 && nt < (df * dc)) // nt < MAX_MV
		{ // insertar a lo ultimo
			if (valor != repe) {
				vd[nt] = valor;
				vf[nt] = f;
				vc[nt] = c;
				nt++;
			}
		}
		else {
			vd[lugar] = valor;
			if (valor == repe) {
				for (int i = lugar; i < nt; i++) {
					vf[i] = vf[i + 1];
					vc[i] = vc[i + 1];
					vd[i] = vd[i + 1];
				}
				nt--;
			}
		}
	}
}

int MatrizV::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lugar = posicion(f, c);
		if (lugar >= 0)
			return vd[lugar];
		else
			return repe;
	}
	else
		cout << "ERROR FUERA DE RANGO\n";
}

void MatrizV::definir_valor_repetido(int valor) {
	bool hayRepe = false;
	for (int i = 0; i < nt && hayRepe == false; i++) {
		if (vd[i] == valor)
			hayRepe = true;
	}
	if (nt == 0 || hayRepe == false) {
		repe = valor;
	}
	else {
		int nRep = valor;
		int aRep = repe;
		for (int i = 1; i <= df; i++) {
			for (int j = 1; j <= dc; j++) {
				int e = elemento(i, j);
				if (e == nRep) {
					int lugar = posicion(i, j);
					for (int k = lugar; k < nt; k++) {
						vf[k] = vf[k + 1];
						vc[k] = vc[k + 1];
						vd[k] = vd[k + 1];
					}
					nt--;
				}
				else if (e == aRep) {
					vd[nt] = aRep;
					vf[nt] = i;
					vc[nt] = j;
					nt++;
				}
			}
		}
		repe = valor;
	}
}

/*
 | 3 0 5 |
 | 0 1 0 |
 | 0 0 9 | */
string MatrizV::to_str() {
	 string r = "";
	for (int i = 1; i <= df; i++) {
		r += "| ";
		for (int j = 1; j <= dc; j++) {
			int e = elemento(i, j);
			r += to_string(e);
			// Añade espacios para alinear los números
			int espacios = 6 - to_string(e).length();
			r += string(espacios, ' ');
		}
		r += "|\n";
	}
	r += "NT: " + to_string(nt) + "\n";
	/*
	 int max = df * dc;
	 r += "vf: ";
	 for (int i = 0; i < max; i++)
	 r += to_string(vf[i]) + ",";
	 r += "\nvc: ";
	 for (int i = 0; i < max; i++)
	 r += to_string(vc[i]) + ",";
	 r += "\nvd: ";
	 for (int i = 0; i < max; i++)
	 r += to_string(vd[i]) + ",";
	 */
	return r;
}
//MatrizV MatrizV::transpuesta() {
//	MatrizV transpuesta;
//	transpuesta.dimensionar(dc, df);
//
//	for (int i = 1; i <= df; i++) {
//		for (int j = 1; j <= dc; j++) {
//			int valor = elemento(i, j);
//			transpuesta.poner(j, i, valor);
//		}
//	}
//
//	return transpuesta;
//}
//
//void MatrizV::transpuesta() {
//	int* temp_vf = new int[df * dc];
//	int* temp_vc = new int[df * dc];
//	int* temp_vd = new int[df * dc];
//	int temp_df = dc;
//	int temp_dc = df;
//
//	for (int i = 1; i <= df; i++) {
//		for (int j = 1; j <= dc; j++) {
//			int lugar_original = posicion(i, j);
//			int lugar_transpuesta = (j - 1) * temp_df + (i - 1);
//
//			temp_vf[lugar_transpuesta] = j;
//			temp_vc[lugar_transpuesta] = i;
//			temp_vd[lugar_transpuesta] = vd[lugar_original];
//		}
//	}
//
//	// Liberar memoria de los vectores originales
//	delete[] vf;
//	delete[] vc;
//	delete[] vd;
//
//	vf = temp_vf;
//	vc = temp_vc;
//	vd = temp_vd;
//	df = temp_df;
//	dc = temp_dc;
//}

//bool MatrizV::esSimetrica() {
//	if (df != dc) {
//		return false;  // La matriz no es cuadrada, por lo que no puede ser simétrica.
//	}
//
//	MatrizV transpuesta = transpuesta();
//
//	for (int i = 1; i <= df; i++) {
//		for (int j = 1; j <= dc; j++) {
//			if (elemento(i, j) != transpuesta.elemento(i, j)) {
//				return false;  // La matriz y su transpuesta no son iguales, por lo que no es simétrica.
//			}
//        }
//	}
//
//	return true;  // La matriz es simétrica.
//}


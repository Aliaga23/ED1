//---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizVec_CSR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
     MatrizVC::MatrizVC() {
	df = dc = repe = nt = 0;
	vd = new int[df * dc];
	vc = new int[df * dc];
	vf = new int[df + 1];
	for (int i = 0; i < df + 1; i++)
		vf[i] = 1;
}

int MatrizVC::existe_elemento(int f, int c) {
	int lug_antes = 0;
	for (int i = 0; i < (f - 1); i++) {
		lug_antes += (vf[i + 1] - vf[i]);
	}
	int max_elem = vf[f + 1 - 1] - vf[f - 1];
	for (int i = 0; i < max_elem; i++) {
		if (vc[lug_antes + i] == c)
			return lug_antes + i;
	}
	return -1;
} // busca en vd,vc y vf si existe el elemento

int MatrizVC::donde_insertar(int f, int c) {
	int lug_antes = 0;
	for (int i = 0; i < (f - 1); i++) {
		lug_antes += (vf[i + 1] - vf[i]);
	}
	int nuevo_lugar = lug_antes;
	int lugar = lug_antes;
	int max_elem = vf[f + 1 - 1] - vf[f - 1];
	for (int i = 0; i < max_elem; i++) {
		lugar = lug_antes + i;
		if (c == vc[lugar])
			// return nuevo_lugar + 1;
				nuevo_lugar = lugar;
	}
	// return -1;
	return nuevo_lugar;
} // determina donde insertar en vd,vc y vf

void MatrizVC::dimensionar(int f, int c) {
	df = f;
	dc = c;
	vd = new int[df * dc];
	vc = new int[df * dc];
	vf = new int[df + 1];
	for (int i = 0; i < df + 1; i++)
		vf[i] = 1;
}

int MatrizVC::dimension_fila() {
	return df;
}

int MatrizVC::dimension_columna() {
	return dc;
}

void MatrizVC::poner(int f, int c, int valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lugar = existe_elemento(f, c);
		if (lugar != -1) {
			vd[lugar] = valor;
			// Analizar si valor == repe
			if (valor == repe) {
				for (int i = lugar; i < nt; i++) {
					vd[i] = vd[i + 1];
					vc[i] = vc[i + 1];
				}
				for (int i = f; i < df + 1; i++)
					vf[i]--;
				nt--;
			}
		}
		else {
			if (valor != repe) {
				int pos = donde_insertar(f, c);
				for (int i = nt; i > pos; i--) {
					vd[i] = vd[i - 1];
					vc[i] = vc[i - 1];
				}
				vd[pos] = valor;
				vc[pos] = c;
				nt++;
				for (int i = f; i < df + 1; i++)
					vf[i]++;
			}
		}
	}

}

int MatrizVC::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		int lugar = existe_elemento(f, c);
		if (lugar == -1)
			return repe;
		else
			return vd[lugar];
	}
	else
		cout << "ERROR DE RANGO\n";
}

int MatrizVC::fila(int indiceVC) {
	int c = 0;
	for (int i = 0; i < df; i++) {
		int m = vf[i + 1] - vf[i];
		int n = c + m;
		if (indiceVC >= c && indiceVC < n)
			return i + 1;
		c += m;
	}
}

void MatrizVC::definir_valor_repetido(int valor) {
	/* repe = valor;
	 int i = 0;
	 while (i < nt) {
	 if (vd[i] == valor) {
	 for (int j = i; j < nt; j++) {
	 vc[j] = vc[j + 1];
	 vd[j] = vd[j + 1];
	 }
	 int f = fila(i);
	 for (int i = f; i < df + 1; i++)
	 vf[i]--;
	 nt--;
	 }
	 else
	 i++;
	 } */
	// --------
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
					int lugar = existe_elemento(i, j);
					for (int k = lugar; k < nt; k++) {
						vd[k] = vd[k + 1];
						vc[k] = vc[k + 1];
					}
					for (int k = i; k < df + 1; k++)
						vf[k]--;
					nt--;
				}
				else if (e == aRep) {
					int pos = donde_insertar(i, j);
					for (int k = nt; k > pos; k--) {
						vd[k] = vd[k - 1];
						vc[k] = vc[k - 1];
					}
					vd[pos] = valor;
					vc[pos] = j;
					nt++;
					for (int k = i; k < df + 1; k++)
						vf[k]++;
				}
			}
		}
		repe = valor;
	}
}

string MatrizVC::to_str() {
	 string r = "";
    for (int i = 1; i <= df; i++) {
        r += "| ";
        for (int j = 1; j <= dc; j++) {
            int e = elemento(i, j);
            r += to_string(e);
            // A�ade espacios para alinear los n�meros
            int espacios = 6 - to_string(e).length();
            r += string(espacios, ' ');
        }
        r += "|\n";
    }
	int max = df * dc;
	r += "vd: ";
	for (int i = 0; i < max; i++)
		r += to_string(vd[i]) + ",";
	r += "\nvc: ";
	for (int i = 0; i < max; i++)
		r += to_string(vc[i]) + ",";
	r += "\nvf: ";
	for (int i = 0; i < df + 1; i++)
		r += to_string(vf[i]) + ",";
	return r;
}

#include <stdio.h>
#include "CSet.h"
#include "iostream"

using namespace std;

bool CSet :: Chek(int b){ //истина если нет искомого
	for(int i = 0; i < pow; i++){
		if(mass0[i] == b){
			return false;
		}
	}
	return true;
}

//статические
int CSet :: tic = 0;

int CSet :: Get_tic(){
	return tic;
}

int CSet :: GetPow(){
	return pow;
}

CSet :: CSet(int * mass0, int pow) 
{
	tic++;
	this->pow = pow;
	this->mass0 = new int [pow];
	for(int i = 0; i < pow; i++){
		this->mass0[i] = mass0[i];
	}
}

CSet :: CSet(int pow)
{
	tic++;
	this->pow = pow;
	mass0 = new int [pow];
}

CSet :: CSet(const CSet &a){
	tic++;
	pow = a.pow;
	mass0 = new int [pow];
	for(int i = 0; i < pow; i++){
		mass0[i] = a.mass0[i];
	}
}
	
CSet :: ~CSet()
{
	tic--;
	delete [] mass0;
}

void CSet :: Output () const{
	cout << endl;
	for (int i = 0; i < pow; i ++){
		cout << mass0[i] << " ";
	}
}

int* CSet :: PushBack(const CSet &a, int m){
		int * mass1 = new int [a.pow+1]; //сохран€ем старый
		for (int i = 0; i < a.pow; i ++){
			mass1[i] = a.mass0[i];
		}
		mass1[a.pow] = m;
	return mass1;
}

void CSet :: Init(const CSet &a){
	delete mass0;
	this->pow = a.pow;
	this->mass0 = new int [pow];
	for (int i = 0; i < this->pow; i ++){
		this->mass0[i] = a.mass0[i];
	}
}



void CSet :: Add (int b){
	if(Chek(b)){ //истина если нет искомого
		CSet n(mass0, pow);
		n.mass0 = PushBack(n, b);
		n.pow++;
		Init(n);
	}
//	return *this;
}

//удаление
void CSet :: Del (int a){
	if(!Chek(a)){ //истина если нет искомого
		CSet n(pow-1);
		int j = 0;
		for (int i = 0; i < pow; i ++){
			if (mass0[i] != a){
				n.mass0[j] = mass0[i];
				j++;
			}
		}
		Init(n);
	}
//	return *this;
}
//пересечение
CSet CSet :: Inter (const CSet & a){
	CSet n;
	for (int i = 0; i < pow; i ++){
		for (int j = 0; j < a.pow; j ++){
			if(mass0[i] == a.mass0[j])
			{
				n.mass0 = PushBack(n, mass0[i]);
				n.pow++;			
			}
		}	
	}
//	Init(n);	
	return n;
}

//объединение ƒ–”∆≈—“¬≈ЌЌјя
CSet Unif (const CSet & b, const CSet & a ){
	CSet n;
	int * mass3 = new int [b.pow+a.pow];
	int i, j = 0;
	for (i = 0; i < b.pow; i ++){
		mass3[i] = b.mass0[j];
		j ++;	
	}
	j = 0;
	for (i = b.pow; i < b.pow + a.pow; i ++){
		mass3[i] = a.mass0[j];
		j ++;	
	}		
//ищем одинаковые и удал€ем	
	int bb, h = 0, p;// k = 0;
	i = 0;
	while (i < b.pow+a.pow - 1*h){
		bb = mass3[i];
		for(j = i+1; j < b.pow+a.pow - 1*h; j++){
			if (mass3[j] == bb){ //нашли одинаковые a
				h++;
				n.mass0 = new int [b.pow+a.pow - 1*h];
				n.pow = 0;
				p = 0;
				for (int q = 0; q < b.pow+a.pow - 1*(h-1); q ++){ //удал€ем
					if (mass3[q] != bb || p == 0){
						n.mass0[n.pow] = mass3[q];
						n.pow++;
					}
					if (mass3[q] == bb) p ++;
				}
				for (int q = 0; q < n.pow; q++){
					mass3[q] = n.mass0[q];
				}
				i--; //после удалени€ 2х элементов все смещаетс€, поэтому нужно сделать i--
			}		
		}
		i++;
	}
//	Init(n);
	return n;
}		
//разность
CSet CSet :: Diff (const CSet & a){
	CSet n;
	int p = 0;
	for (int i = 0; i < pow; i ++){
		p = 0;
		for (int j = 0; j < a.pow; j ++ ){
			if(mass0[i] == a.mass0[j]){
				p++;
			}
		}
		if (p == 0){
			n.mass0 = PushBack(n, mass0[i]);
			n.pow ++;
		}	
	}
//	Init(n);
	return n;	
}
//симметрическа€ разность
CSet CSet :: SimDiff (const CSet & a){
	CSet n;
	//объединение
	int * mass3 = new int [pow+a.pow];
	int i, j = 0;
	for (i = 0; i < pow; i ++){
		mass3[i] = mass0[j];
		j ++;	
	}
	j = 0;
	for (i = pow; i < pow + a.pow; i ++){
		mass3[i] = a.mass0[j];
		j ++;	
	}
	//ищем одинаковые и удал€ем	
	int b, h = 0;
	i = 0;
	while (i < pow+a.pow - 2*h){
		b = mass3[i];
		for(j = i+1; j < pow+a.pow - 2*h; j++){
			if (mass3[j] == b){ //нашли одинаковые a
				h++;
				n.mass0 = new int [pow+a.pow - 2*h];
				n.pow = 0;
				for (int q = 0; q < pow+a.pow - 2*(h-1); q ++){ //удал€ем
					if (mass3[q] != b){
						n.mass0[n.pow] = mass3[q];
						n.pow++;
					}
				}
				for (int q = 0; q < n.pow; q++){
					mass3[q] = n.mass0[q];
				}
				i--; //после удалени€ 2х элементов все смещаетс€, поэтому нужно сделать i--
			}		
		}
		i++;
	}
//	Init(n);
	return n;
}
	


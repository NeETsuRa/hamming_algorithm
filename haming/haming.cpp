// haming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void izpis (vector <int> a){
for (int i=0; i<a.size(); i++)
	cout << a[i];

}


int _tmain(int argc, _TCHAR* argv[])
{

cout << "vpisi kodo binarno kodo: (0 in 1 ob vnosu druge stevlke zakljucek)" << endl;
vector <int> org;
vector <int> obdelana;
vector <int> prebrana;
vector <int> paritetni;
vector <int> resitev;
int a,par;

do{
cin >> a;
if (a!=1&&a!=0)
	break;
org.push_back(a);

}while(a==1||a==0);

for (int i=org.size()-1; i>=0; i--){
obdelana.insert(obdelana.begin(), org[i]);
}
int i=0;
par=1;
paritetni.push_back(0);

while(i<obdelana.size()){ 
	if (i==0)
		obdelana.insert(obdelana.begin()+i, 6);
	if (i==par){
		obdelana.insert(obdelana.begin()+i, 6);
		paritetni.push_back(par);
		par=par*2;

	}
	i++;
}

int st=0;
for (int i=obdelana.size()-1; i>=0; i--){
	if (obdelana[i]==6){
		if (i==0){
		for (int j=0; j<obdelana.size(); j++){
				if (j==1)
					st++;
			}
		}
		else{
		int j=i;
		st=0;
		while(j < obdelana.size()){
			int l=j+i;
			for (; j<l; j++){
				if (j==1)
					st++;
			}
			j=l+i;
		}
		}
		if (st%2==1)
			obdelana[i]=1;
		else
			obdelana[i]=0;
	}
	
}

cout << endl;
izpis(org);
cout << endl;
izpis(obdelana);
cout << endl;
izpis(paritetni);
cout << endl;

cout << "vpisi kodo binarno kodo ki jo je raèunalnik prebral: (0 in 1 ob vnosu druge stevlke zakljucek)" << endl;
do{
cin >> a;
if (a!=1&&a!=0)
	break;
prebrana.push_back(a);

}while(a==1||a==0);


for (int i=0; i<paritetni.size(); i++){
	if(prebrana[paritetni[i]]!=obdelana[paritetni[i]]){
		resitev.push_back(paritetni[i]);
	}
}
cout << endl;
if (prebrana[0]!=obdelana[0])
	cout << "napaka na veèih mestih" << endl;
else{
	if (st!=0){
	st=0;
	for (int i=0; i<resitev.size(); i++)
		st+=resitev[i];
	cout << "napaka na " << st << " mestu" << endl;
	}else
		cout << "brez napake" << endl;

}

system("pause");
return 0;
}
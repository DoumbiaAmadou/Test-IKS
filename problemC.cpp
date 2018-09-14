#include <algorithm>
#include <iostream>
#include <string>  
using namespace std;
#include <vector> 
#include <map> 
#include <fstream>

using namespace std;

/* Program realisé sous windows => vérifier avant toute utilisation les condition de gestion systeme de 'lenvironnement ciblé*/
#include <sstream>

map<int, string> mapData;

string infile = "";
string outfile;
vector<int> dataS;

// data[x] => 0  => isoate
// data[x] => 1  => Arrived
// data[x] => 2  => Departure
// data[x] => 3  => Arrived Departure
int fixa, fixb = -1;// to solve issue
int cas = 0;

// int 
bool  add(int i, int j) {
	if (i == -1 || j == -1)
		return false;
	if ((dataS[i] == 1 && fixa == -1) || (dataS[j] == 2 && fixa == -1)) {
		fixa = i;
		fixb = j;
	}
	dataS[i] += 1;
	dataS[j] += 2;


	return true;
}
void checkValid() {
	int  cpt = 0;
	for (vector<int>::iterator it = dataS.begin(); it != dataS.end(); it++) {
		// cout<<"data[*it] "<<*it<<endl; 
		if (*it != 3)
			cpt++;
	}
	if (cpt == 0)
		cout << "Case " << cas << ": valid";
	else
		if (cpt == 2)
			cout << "Case " << cas << ": " << fixa << " " << fixb;
		else
			cout << "Case " << cas << ": invalid"; 

	if (cas != 4)
	{
		cout<< endl;
	}
}
int main(/*int  argc  , char *argv[]*/)
{
	while (cas<4) {
		cas++;
		int m = 0;
		int n = 0;
		cin >> m;
		cin >> n;
		dataS.resize(m);
		// cout<<" m n "<<m<<" " <<n <<endl;  

		for (int i = 0; i<m; i++)
			dataS[i] = 0;

		int a, b = -1;
		int nbLine = n;
		while (nbLine>0)
		{
			nbLine--;
			cin >> a;
			cin >> b;
			add(a, b);
			a = b = 0;
		}
		// cout<<"---------------------------------" <<endl;  
		checkValid();
		fixa = fixb = -1;
	}
	exit(0);
}

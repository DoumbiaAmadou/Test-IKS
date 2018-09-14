#include <algorithm>
#include <iostream>
#include <string>  
using namespace std;
#include <vector> 
#include <map> 
#include <fstream>
#include<cmath>
using namespace std;

/* Program realisé sous windows => vérifier avant toute utilisation les condition de gestion systeme de 'lenvironnement ciblé*/
#include <sstream>


map<int, string> mapData;

string infile = "";
string outfile;
ofstream outfichier;
bool isPrime(int number) {
	bool rval = true; 
	int limitVerifcation = (int) sqrt(number);
	for (int cpt = 2; cpt <= limitVerifcation ; cpt++)
	{
		if (number%cpt == 0)
		{
			rval = false;
			break;
		}
	}
	return rval;
}


void  primeReduction(int reductionNumber) { //Method to check whether the given integer is prime or not

	int  compter=0, number , sum = 0, cptPrimary;
	number = reductionNumber; 

	bool stop = false;
	while (!stop) {
		vector<int>primaryFactor; 
		primaryFactor.resize(500);
		
		compter++; 
		if (number == 4) {
			stop = true; 
			cout << endl; 
		}
		else
		{
			if (isPrime(number)) {
				cout << number << " " << compter << endl;
				outfichier << number << " " << compter << endl;
				stop = true; 
			}
			else{	// main process 
				cptPrimary = 0; 
				for (int i = 2; i <= number / i; i++) {
					while (number % i == 0) {
						number = number / i; 
						primaryFactor[cptPrimary] = i; 
						cptPrimary++; 

					}
				}
				
				if (number > 1) {
					primaryFactor[cptPrimary] = number;
					cptPrimary++; 
				}
				for (vector<int>::iterator it = primaryFactor.begin(); it != primaryFactor.end(); it++)
					sum += (*it);

				number = sum; 
				sum = 0; 
			}
		
		}
	}
	

}

int main(int  argc, char **argv)
{

	if (argc != 3)
	{
		cout << "nombre of arg wrong: "<< argc << "  argv:" << argv << "   usage: ./program    filename  outfilename";
		exit(0);
	}



	infile = argv[1];
	outfile = argv[2];
	outfichier = ofstream(outfile, ios::out | ios::trunc);
	
	ifstream fichier(infile, std::ifstream::in);
	
	if (fichier)
	{
		string ligne;
		while (getline(fichier, ligne))
		{
			int value; // int size more than 10 pow 9
			value = stoi(ligne); 
			if (value == 4)
				break; 

			//cout << "Read Line" << value << endl;  //
			primeReduction(value);
			string ligne = "";
		}

		fichier.close();
		// on ferme le fichier
	}
	else  // sinon
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	outfichier.close(); 
	exit(0);
	//primeReduction(76);
	//string a; 
	//cin >> a; 

}

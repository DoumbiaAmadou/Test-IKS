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
string outfile ; 

bool is_number(const string& s)
{
    return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

bool  insert(string ligne) {
    
    vector<string>  strstokens;
    stringstream  splitedString(ligne);
    for (string each; getline(splitedString, each, ' '); strstokens.push_back(each));

    if (strstokens.size()>1) {
       // bool first = true;
        if (is_number(strstokens[0]))
        {
            mapData[stoi(strstokens[0])/2] = strstokens[1];
        }
        else
        {
            if(is_number(strstokens[1]))
                mapData[stoi(strstokens[1])] = strstokens[0];

        }
                
            
    }

    return true; 

}

void  printAns() {

   // ofstream fichier(outfile, ios::out | ios::app);
    vector<int> keys; 
    for (map<int,string>::iterator it = mapData.begin(); it != mapData.end(); ++it) 
        keys.push_back(it->first);

    sort(keys.begin(), keys.end());
    for (vector<int>::iterator it = keys.begin(); it != keys.end(); ++it)
    {
   //     fichier << mapData[*it] <<endl;
        cout << mapData[*it] << endl;
    }
    //fichier.close(); 
}


int main(/*int  argc  , char *argv[]*/)
{ 
    //infile = argv[1];
    //outfile = argv[2]; 
    // ifstream fichier(infile , std::ifstream::in);
       
        int nblines =0 ; 
        cin >> nblines ; 

        string ligne;
        while (nblines>=0)
        { 
            nblines--; 
            getline(cin, ligne); 
            insert(ligne);
             ligne = "";
           
        }
        // fichier.close(); 
        printAns();
         // on ferme le fichier
    // }
    // else  // sinon
    //     cerr << "Impossible d'ouvrir le fichier !" << endl;

    
    exit( 0);
}

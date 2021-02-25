#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream dane("dane_obrazki.txt");
	string linijka;
	string obrazki[200][20][20] = {{{0}}};

    int liczLinijki = 0;
	int liczObrazki = 0;

	int pixeliCzarnych = 0;
	int pixeliBialych = 0;
	int maxCzarnych = 0;
	int liczRewersy = 0;

    int obrazek[20][20] = { { 0 } };
    while(dane >> linijka){
		for(int a=0; a<linijka.length(); a++){
            obrazki[liczObrazki][liczLinijki][a] = linijka[a];
			
			if(linijka[a] == '0'){
				pixeliBialych++;
			}
			else {
				pixeliCzarnych++;	
				
			}
        }
    }
		liczLinijki++;
        if(pixeliCzarnych > pixeliBialych){
				liczRewersy++;
			}

        if(maxCzarnych < pixeliCzarnych){
				maxCzarnych = pixeliCzarnych;
			}
        
			liczLinijki = 0;
			liczObrazki++;
			pixeliCzarnych = 0;
			pixeliBialych = 0;

        cout << "Rewersow: " << liczRewersy << endl;
	    cout << "Najwiecej czarnych: " << maxCzarnych << endl;

        dane.close();
	    return 0;

}
			
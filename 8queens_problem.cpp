#include <iostream>
#include <sstream>
#include <cmath>
#include <array>

using namespace std;

// tablica do przechowania kombinacji ulozenia hetmanow
std::array<int, 8> output;

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

class Eightqueens{
    
    public:

	// output[i] = j oznacza, ze krolowa jest na i-tym wierszu w j-tej kolumnie
	// kolumna jest x, wiersz jest y
	// (j, movedx) , (i, movedy)
        bool isSafe(int movedx, int movedy)
        {
            bool test1= false;
    		for (int i = 0; i < movedx; i++) {
		    // czy jest w stanie ataku?
    		    test1 = (abs(i - movedx) == abs(output[i] - movedy)); 
			// Jezeli jest, zwroc falsz
    		    if (test1 || (output[i] == movedy)) {
    			return false;
    		    };
            };
	// nie jest w stanie ataku, mozna uzyc
            return true;
        };
        
        void Solution(int x)
        {
            int size = 8;
            for (int i = 0; i < size; i++) {
		// Sprawdza czy mozna wrzucic na ta pozycje
                if (isSafe(x, i)) {
		    //jezeli to dobra kombinacja, zapisuje
                    output[x] = i; 
			// Gdy to bedzie koncowa iteracja, wypisuje kombinacje
                    if (x == size - 1) {
                        string s="";

                        for(auto i=0;i<output.size(); ++i){
                            s += to_string(output[i]); 
                            s+= " ";
                        };

                        cout<<"Rozwiazanie dla 8 krolowych "+s<<endl;
				}
				// Rekurencja dla kolejnego elementu
				Solution(x + 1);
  
                };

  
            };
        };
    
    
    
};

int main()
{
	Eightqueens i;
	i.Solution(0);
    return 0;
}

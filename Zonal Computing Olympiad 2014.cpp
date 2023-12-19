#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int alpha = 0; // numarul de clienti 
int beta = 0; // preturile fiecarui client
int sum = 0; // sumele fiecarei impartiri adunate
int maximum = 0; // elementul maxim al vectorului
int imparti = 0; // numarul de impariti al unui element la altul

int main(void)
{
    cin >> alpha; // numarul de cazuri de test
    vector<int> gamma; // depozitez aici preturile clientilor
    vector<int> epsilon; // stochez aici maximul fiecarui pret ca valoare de vanzare
    for (int i = 0; i < alpha; i++)
    {
        cin >> beta; // cazurile
        if (beta >= 1 and beta <= 108)
            gamma.push_back(beta); 
        else
        {
            cout << "eroare: numarul introdus nu apartine intervalului 1,108";
            return 1;
        }
    }
    for (auto delta : gamma) // pentru fiecare element din lista de preturi , fac impartirea cu unul din fiecare
    {
        sum = 0;
        imparti = 0;
        for (auto theta : gamma) // mentionez ca delta si theta sunt vectori cu aceleasi elemente
        {
            if (theta / delta >= 1) // daca un numar se imparte la oricare din celelalte numere 
                imparti += 1; // <---- aici se aduna numarul de impartiri
                sum = imparti*delta;// <---- aici se aduna numarul de impartiri inmultit cu pretul insusi 
                epsilon.push_back(sum); // astfel am aflat maximul fiecarui element la impartirea celorlalte preturi , acum stochez
                // maximele intr-un alt vector
        }
    }
    maximum = *max_element(epsilon.begin(), epsilon.end()); // ultimul lucru de facut este sa iterez prin fiecare maxim si sa gasesc
    // cel mai convenabil pret de acceptat , multiplicat cu numarul de cazuri in care acesta se imparte 
    cout << maximum; 
    return 0;
}

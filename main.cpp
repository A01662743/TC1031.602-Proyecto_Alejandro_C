#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "avl.h"
#include "sort.h"
using namespace std;

//Merge Sort por Nombre (O(N*log(N)))
void OrdenarNom(vector<Persona> &vec){
    int size = vec.size();
    vector<Persona> vec2(size);
    mergeSplit (vec, vec2, 0, size-1);
    return;
}

int main(){

    //caso prueba o personalizado
    int acc;
    cout << endl << "Digita 1 para caso prueba: ";
    cin >> acc;
    cout << endl;

    AVL* arbol = new AVL();
    vector<Persona> personas;
    int n;

    //caso personalizado
    if (acc != 1){
        cout << "¿Cuántos individuos hay? ";
        cin >> n;
        cout << endl;
        while (n < 2 || n > 101){
            cout << "Ingrese un valor válido: ";
            cin >> n;
            cout << endl;
        }

        personas.resize(n);

        string nom;
        double inf;

        for (int i = 0; i < n; i++){
            cout << "Ingresa nombre y porcentaje de influencia de la persona no. " << i+1 << ": ";
            cin >> n >> inf;
            cout << endl;
            while (inf < 0 || inf > 100){
                cout << "Ingresar un valor válido para la influencia: ";
                cin >> inf;
                cout << endl;
            }
            personas[i].set_nombre(nom);
            personas[i].set_influencia(inf);
        }
    }
    //caso prueba
    else {
        n = 10;
        personas.resize(n);
        personas[0] = Persona("Diego");
        personas[1] = Persona("Fernanda");
        personas[2] = Persona("Sofía");
        personas[3] = Persona("Manuel");
        personas[4] = Persona("Armando");
        personas[5] = Persona("Sebastián");
        personas[6] = Persona("José");
        personas[7] = Persona("Sol");
        personas[8] = Persona("María");
        personas[9] = Persona("Esther");
        srand(time(0));
        //randomize % de influencia
        for (int i = 0; i < n; i++){
            int ent = rand()%101;
            float dec = 00;
            if (ent != 100){
                dec = (rand()%100)/100.0;
            }
            personas[i].set_influencia(ent + dec);
            arbol->add(personas[i].get_nombre(), personas[i].get_influencia());
        }
    }

    //Desplegar información
    cout << "Personas ordenadas Alfabéticamente: " << endl << endl;
    OrdenarNom(personas);
    int pos = 1;
    for (int i = 0; i < personas.size(); i++){
        cout << pos << ". ";
        personas[i].print();
        pos = pos + 1;
    }

    cout << endl << "Personas ordenadas ascendentemente por influnecia; " << endl << endl;
    cout << arbol->inorder();

    return 0;
}

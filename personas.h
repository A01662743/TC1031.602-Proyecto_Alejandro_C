#include <iostream>
using namespace std;

class Persona{
    private:
        string nombre;
        double influencia;
    public:
        Persona();
        Persona(string n, double i);
        Persona(string n);
        void print();
        string get_nombre();
        double get_influencia();
        void set_nombre(string n);
        void set_influencia(double i);
};

Persona::Persona(){
    nombre = "N/A";
    influencia = 0.00;
}

Persona::Persona(string n, double i){
    nombre = n;
    influencia = i;
}

Persona::Persona(string n){
    nombre = n;
    influencia = 0.00;
}

void Persona::print(){
    cout << nombre << " " << influencia << "%" << endl;
}

string Persona::get_nombre(){
    return nombre;
}

double Persona::get_influencia(){
    return influencia;
}

void Persona::set_nombre(string n){
    nombre = n;
}

void Persona::set_influencia(double i){
    influencia = i;
}

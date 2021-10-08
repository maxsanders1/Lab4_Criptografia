#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
/* ---------------------------------- HASH (Pendiente) ----------------------------------- */
/*
    input
    separar el input en n/2 arreglos de tamaño 2 (Que hacer con impares?)
    Convertirlo en bits o hecadecimal?
    en caso de bits XOR
    en caso de hexadecimal, sumar un hexadecimal estatico?
    concatenar resultado
*/
string hasheador(string s){
    return s;
}
/* --------------------------------------------------------------------------- */

/* ---------------------------------- Comprobacion de Largo (Pendiente) ----------------------------------- */
string lengthComp(string s){
    // relleno en caso de largo minimo no alcanzado
    if (s.length() < 10){
        int ceros = 10 - s.length();
        string relleno = "";
        for (int i = 0; i < ceros; i++){
            relleno = relleno + "0";
        }
        s = s + relleno;
        return s;
    }
    else{
        return s;
    }
}
/* ------------------------------------------------------------------------------------------------------- */

/* ----------------------------------Calcular Entropia CHECK----------------------------------------- */
int entropy(string s){
    int l = s.length();
    int w = 1; // Como identificar base?
    int r = l * log2(w);
    return r;
}


/* --------------------------------------------------------------------- */
int main(){
    int option;
    cout << "Super Hasheador-Inador" << endl;
    cout << "Perry el ornitorrinco, quieres hashear? bueno, escoge tu arma!" << endl;
    cout << "(1) Archivo" << endl;
    cout << "(2) Input por consola" << endl;
    cout << "(3) Calcular entropia" << endl;
    cin >> option;
    if (option == 1){
        string archivo;
        cout << "El camino dificil eh? pues dame el documento!" << endl;
        cin >> archivo;
        cout << "Estas loco? mira todo esto!" << endl;

        //lectura del archivo

        ifstream a;
        string line;
        a.open(archivo);
        a >> line;
        while (!a.eof()){
            cout << line << endl;
            a >> line;
        }
        
        //hashear archivo
        //hashArchivo(archivo);

        cout << "Bueno, eso fue mucho trabajo, me voy a la cama. Adios Perry" << endl;
        return 0;
    }
    if (option == 2){
        string p;
        cout << "El camino facil eh? pues dime lo que hashear!" << endl;
        cin >> p;
        cout << "Anda, pues... aqui lo tienes!" << endl;

        //Comprobacion de largo
        string r = lengthComp(p);

        //hashear string
        //hashString(r);

        cout << "Eso fue facil eh?" << endl;
        return 0;
    }
    if (option == 3){
        cout << "Ah, que quieres calcular la entropia, okey, pero, de que?" << endl;
        int option2;
        cout << "(1) Archivo" << endl;
        cout << "(2) Input por consola" << endl;
        cin >> option2;
        if (option2 == 1){
            /* calculo entropia de archivo */
        }
        if (option2 == 2){
            /* calculo entropia de string */

        }
        
    }
    
    return 0;
}
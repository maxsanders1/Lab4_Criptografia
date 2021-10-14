#include <iostream>
#include <fstream>
#include <math.h>
#include <regex>
#include <ctime>

using namespace std;
/* ---------------------------------- funciones utiles ----------------------------------- */
long long convertBinary(int n){
    long long bin = 0;
    int rem, i = 1;
    while (n!=0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

int XORfunction(int x){
    string b = to_string(x);
    string xorpilar = "0101010";
    string aux = "";
    for (int i = 0; i < b.length() ; i++){
        if (xorpilar[i] != b[i]){
            aux = aux + "1";
        }
        else{
            aux = aux + "0";
        }
    }
    int result = 0;
    result = stoi(aux);
    return result;
}

long fromBin(long n){
    long factor = 1;
    long total = 0;
    while (n != 0){
        total += (n%10) * factor;
        n /= 10;
        factor *= 2;
    }
    return total;
}

/* ---------------------------------- HASH ----------------------------------- */
string hasheador(string key){
    //recibir palabra
    int size = key.length();
    int arrNumb[size];

    //pasarlos a numero
    for (int i = 0; i < size; i++){
        arrNumb[i] = (int)key[i];
    }

    //pasarlo a binario
    for (int i = 0; i < size; i++){
        arrNumb[i] = convertBinary(arrNumb[i]);
    }

    //realizar XOR con cada variable
    for (int  i = 0; i < size; i++){
        arrNumb[i] = XORfunction(arrNumb[i]);
    }

    //devolverlo a decimal
    for (int  i = 0; i < size; i++){
        arrNumb[i] = fromBin(arrNumb[i]);
    }

    //pasar a ASCII
    char r[size];
    for (int  i = 0; i < size; i++){
        r[i] = (char)arrNumb[i];
    }

    //pasar a string
    string result = "";
    for (int  i = 0; i < size; i++){
        result = result + r[i];
    }

    return result;
}
/* --------------------------------------------------------------------------- */

/* ---------------------------------- Comprobacion de Largo ----------------------------------- */
string lengthComp(string s){
    // relleno en caso de largo minimo no alcanzado
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    if (s.length() < 25){
        while (s.length() < 25){
            if (s.length() < 25){
                s = s + to_string(year) + to_string(month);
            }
        }
        return s;
    }
    else{
        return s;
    }
}
/* ------------------------------------------------------------------------------------------------------- */

/* ----------------------------------Calcular Entropia ----------------------------------------- */
float entropy(string s){
    float l = s.length();
    float w = 0;
    regex numbers("([0-9])");
    if (regex_search(s, numbers)){
        w = w + 10;
    }
    regex lower("([a-z])");
    if (regex_search(s, lower)){
        w = w + 26;
    }
    regex upper("([A-Z])");
    if (regex_search(s, upper)){
        w = w + 26;
    }
    regex signals("([`~!@#$%^&*()_=+{}|;:',<.>/?ñÑ])");
    if (regex_search(s, upper)){
        w = w + 29;
    }
    float r = l * log2(w);
    return r;
}
/* --------------------------------------------------------------------- */
int main(){
    int option;
    cout << "Super Hasheador-Inador" << endl;
    cout << "Escoger lo que se desea hashear" << endl;
    cout << "(1) Por Archivo" << endl;
    cout << "(2) Por Input por consola" << endl;
    cout << "(3) En caso de calcular entropia" << endl;
    cin >> option;
    if (option == 1){
        string archivo;
        cout << "Ingrese nombre del documento que se quiere hashear el contenido" << endl;
        cin >> archivo;
        cout << "Output:" << endl;
        ifstream a;
        string line;
        a.open(archivo);
        a >> line;
        while (!a.eof()){
            string aux = lengthComp(line);
            cout << "Texto: " << line << " ----> Post Hash : " << hasheador(aux) << endl;
            a >> line;
        }
        cout << "Proceso finalizado" << endl;
        return 0;
    }
    if (option == 2){
        string p;
        cout << "Ingrese string para hashear" << endl;
        cin >> p;
        cout << "procesando..." << endl;
        //Comprobacion de largo
        string a = lengthComp(p);
        string r = hasheador(a);
        cout << r << endl;
        cout << "Proceso finalizado" << endl;
        return 0;
    }
    if (option == 3){
        cout << "Calculadora de entropia" << endl;
        cout << "Ingrese opcion para calcular entropia:" << endl;
        int option2;
        cout << "(1) Archivo" << endl;
        cout << "(2) Input por consola" << endl;
        cin >> option2;
        if (option2 == 1){
            string archivo;
            cout << "Ingrese nombre del documento para calcular la entropia del contenido" << endl;
            cin >> archivo;
            cout << "Output:" << endl;
            ifstream a;
            string line;
            a.open(archivo);
            a >> line;
            while (!a.eof()){
                float aux = entropy(line);
                cout << "Texto: " << line << " ----> entropia : " << aux << endl;
                a >> line;
            }
            cout << "Proceso finalizado" << endl;
            return 0;
        }
        if (option2 == 2){
            string in;
            cout << "Ingrese el string para calcular la entropia del contenido" << endl;
            cin>> in;
            cout << "Output:" << endl;
            float aux = entropy(in);
            cout << "Texto: " << in << " ----> entropia : " << aux << endl;
            cout << "Proceso finalizado" << endl;
            return 0;
        }   
    }
    return 0;
}
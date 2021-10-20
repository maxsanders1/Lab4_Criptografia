#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <regex>
#include <ctime>
#define A 895932
#define B 909525
#define C 378632
#define D 420921

using namespace std;
/* ---------------------------------- funciones utiles ----------------------------------- */

unsigned long long superHashOperations1(int in){
    unsigned long long result = 0;
    result = (in * A)^ C;
    return result;
}

unsigned long long superHashOperations2(int in){
    unsigned long long result = 0;
    result = (in * B)* D;
    return result;
}

unsigned long long superHashRandom(int in){
    srand(in);
    unsigned long long number = (rand() % 6320430) + 227832;
    return number;
}

unsigned long long superHashTime(int in){
    unsigned long long result = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    result = ((in)*month)*year;
    return result;
}

unsigned long long superHashMixed(int in){
    unsigned long long result = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    srand(in);
    int day = ltm->tm_mday;
    unsigned long long number = (rand() % 2098960) + 4053946;
    result = (in * number) + (A+B);
    return result;
}

unsigned long long superHashName(int in){
    unsigned long long result;
    result = (in * D) - C;
    result = (result^A)+B;
    return result;
}

/* ---------------------------------- HASH ----------------------------------- */
string hasheador(string input){
    //suma del string
    int n = input.length();
    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = (int)input[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }

    //operaciones matematicas locas
    unsigned long long op1 = superHashOperations1(sum);
    unsigned long long op2 = superHashOperations2(sum);
    unsigned long long random = superHashRandom(sum);
    unsigned long long time = superHashTime(sum);
    unsigned long long mixed = superHashMixed(sum);
    unsigned long long en = superHashName(sum);

    //union y comprobacion de tamaño
    string hasheado = to_string(op1) + to_string(random)+ to_string(sum) + to_string(time) + to_string(op2) + to_string(mixed) + to_string(en);
    if (hasheado.length() > 52){
        hasheado = hasheado.substr(0,52);
    }
    //Diccionario propio para el hash
    string Diccionario[62] = {
        "0","1","2","3","4","5","6","7","8","9",
        "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
        "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
    };
    //Convertir en arreglos de tamaño 2
    string div[25];
    int c = 0;
    for (int i = 0; i < 25; i++){
        div[i] = hasheado.substr(c,2);
        c = c + 2;
    }
    //Convertir en int
    int w[25];
    for (int i = 0; i < 25; i++){
        w[i] = stoi(div[i]);
    }
    //Buscar el valor segun el diccionario
    string result = "";
    for (int i = 0; i < 25; i++){   
        int index = w[i];
        if (index > 61){
            index = index - 61;
        }
        result = result + Diccionario[index];
    }
    return result;
}
/* --------------------------------------------------------------------------- */

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
            cout << "Texto: " << line << " ----> Post Hash : " << hasheador(line) << endl;
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
        string r = hasheador(p);
        cout << "Resultado: "; 
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
                string out = hasheador(line);
                float aux = entropy(out);
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
            string out = hasheador(in);
            float aux = entropy(out);
            cout << "Texto: " << in << " ----> entropia : " << aux << endl;
            cout << "Proceso finalizado" << endl;
            return 0;
        }   
    }
    return 0;
}
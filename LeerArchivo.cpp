/*
Autor: Maximiliano De La Cruz Lima

Leer el archivo de texto en C++
*/

#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>
using namespace std;

vector<string> separar(string linea);


int main(int argc, char const *argv[])
{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");
    
    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea))
    {
        //cout << (numeroLinea++) << ": " << linea << endl;
        vector<string> datos = separar(linea);

        if (datos.size() == 6)
        {
            cout << "Pelicula: ";
            // new Pelicula(datos);
        } else
        {
            cout << "Episodio: ";
            // new Episodio(datos);
        }
        cout << endl;

    }
    entrada.close();
    return 0;
}

vector<string> separar(string linea)
{
    vector<string> tokens; // Componenetes de la línea
    stringstream entrada(linea); // Flujo de datos a partir de una string / Objeto que se encarga de leer la línea
    string dato; // token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, ',')) // Lee hasta la coma
    {   
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            //cout << dato << numeroTokens << endl;
            tokens.push_back(dato); // Guarda el token en el vector
            numeroTokens++;
        }
    }
    //cout << "tokens: " << numeroTokens << endl << endl;
    return tokens;
}

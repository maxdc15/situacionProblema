/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de métodos de la clase Episodio
*/

#include "Episodio.h"

// Constructor
Episodio::Episodio(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno, string IDepisodio, string nombreEpisodio, int temporada, int numEpisodio) 
: Video(ID, nombre, genero, calificacion, minutos, fechaEstreno)
{
    this->IDepisodio = IDepisodio;
    this->nombreEpisodio = nombreEpisodio;
    this->temporada = temporada;
    this->numEpisodio = numEpisodio;
}

string Episodio::getNombreEpisodio()
{
    return nombreEpisodio;
}

// Método para modificar la calificación del episodio (sobreescribe el método virtual puro de la clase Video)
void Episodio::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}

// Método para mostrar los datos del episodio (sobreescribe el método virtual puro de la clase Video)
void Episodio::mostrarDatos()
{   
    cout << "Serie: " << nombre << endl;
    cout << "Episodio: " << endl;
    cout << "ID episodio: " << IDepisodio << endl;
    cout << "Nombre episodio: " << nombreEpisodio << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << endl;
    cout << "Duracion: " << getMinutos() << endl;
    cout << "Fecha de estreno: " << getFechaEstreno() << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Numero de episodio: " << numEpisodio << endl;
    cout << endl;
}

// Sobrecarga del operador << para mostrar los datos del episodio
ostream &operator<<(ostream &output, const Episodio &e)
{
    output << "Episodio: " << endl;
    output << "ID episodio: " << e.IDepisodio << endl;
    output << "Nombre episodio: " << e.nombreEpisodio << endl;
    output << "Genero: " << e.genero << endl;
    output << "Calificacion: " << e.calificacion << endl;
    output << "Duracion: " << e.minutos << endl;
    output << "Fecha de estreno: " << e.fechaEstreno << endl;
    output << "Temporada: " << e.temporada << endl;
    output << "Numero de episodio: " << e.numEpisodio << endl;
    return output;
}

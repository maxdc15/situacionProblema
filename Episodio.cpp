/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de métodos de la clase Episodio
*/

#include "Episodio.h"

Episodio::Episodio(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno, string IDepisodio, string nombreEpisodio, int temporada, int numEpisodio) 
: Video(ID, nombre, genero, calificacion, minutos, fechaEstreno)
{
    this->IDepisodio = IDepisodio;
    this->nombreEpisodio = nombreEpisodio;
    this->temporada = temporada;
    this->numEpisodio = numEpisodio;
}

void Episodio::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}

void Episodio::mostrarDatos()
{
    cout << "Episodio: " << endl;
    cout << "ID: " << getID() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << endl;
    cout << "Duracion: " << getMinutos() << endl;
    cout << "Fecha de estreno: " << getFechaEstreno() << endl;
    cout << "ID episodio: " << IDepisodio << endl;
    cout << "Nombre episodio: " << nombreEpisodio << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Numero de episodio: " << numEpisodio << endl;
    cout << endl;
}

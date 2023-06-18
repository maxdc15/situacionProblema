/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de Clase Episodio
*/ // ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio

#ifndef EPISODIO_H
#define EPISODIO_H
#include "Video.h"
#include<iostream>
#include<string>
using namespace std;

class Episodio : public Video // Clase Episodio hereda de la clase Video
{
private:
    string IDepisodio; 
    string nombreEpisodio;
    int temporada;
    int numEpisodio;
public:
    // Constructor con parámetros
    Episodio(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno, string IDepisodio, string nombreEpisodio, int temporada, int numEpisodio);
    string getNombreEpisodio();
    void setCalificacion(double calificacion); // Método para modificar la calificación del episodio (sobreescribe el método virtual puro de la clase Video)
    void mostrarDatos(); // Método para mostrar los datos del episodio (sobreescribe el método virtual puro de la clase Video)
    friend ostream &operator<<(ostream &output, const Episodio &e); // Sobrecarga del operador <<
};

#endif
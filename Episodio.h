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

class Episodio : public Video
{
private:
    string IDepisodio;
    string nombreEpisodio;
    int temporada;
    int numEpisodio;
public:
    Episodio(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno, string IDepisodio, string nombreEpisodio, int temporada, int numEpisodio);
    void setCalificacion(double calificacion);
    void mostrarDatos();
};

#endif
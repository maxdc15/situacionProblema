/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de clase Sistema
*/

#ifndef SISTEMA_H
#define SISTEMA_H
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

class Sistema
{
private:
        vector<Video*> videos; // Vector de apuntadores a objetos de la clase Video
        vector<string> separar(string linea); // Método para separar los datos de una línea de un archivo CSV
        void cargarArchivo(string nombreArchivo); // Método para cargar los datos de un archivo CSV 
        void mostrarVideosCalificacion(double calificacionMinima); // Método para mostrar los videos con una calificación mínima dada
        void mostrarVideosGenero(string genero); // Método para mostrar los videos de un género dado
        void mostrarEpisodiosSerie(string nombreSerie); // Método para mostrar los episodios de una serie dada 
        void mostrarPeliculasCalificacion(double calificacionMinima); // Método para mostrar las películas con una calificación mínima dada
        void calificarVideo(string nombre, double calificacionNueva); // Método para calificar un video dado
        void calcularPromedioSerie(string nombreSerie); // Método para calcular el promedio de calificación de una serie dada
public:
        // No hay constructor porque no hay atributos privados en la clase Sistema sino que hay métodos privados
        void ejecutar(); // Método para ejecutar el programa
};


#endif
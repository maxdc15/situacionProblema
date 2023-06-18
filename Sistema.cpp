#include "Sistema.h"

vector<string> Sistema::separar(string linea)
{
    vector<string> tokens; // Componenetes de la línea
    stringstream entrada(linea); // Flujo de datos a partir de una string / Objeto que se encarga de leer la línea
    string dato; // token individual
    int numeroTokens = 0; // Contador de tokens
    while (getline(entrada, dato, ',')) // Lee hasta la coma (,)
    {   
        if (dato != "" && dato != "\n" && dato != "\r") // Ignorar espacios en blanco y saltos de línea
        {
            tokens.push_back(dato); // Guarda el token en el vector
            numeroTokens++; 
        }
    }
    return tokens;
}

void Sistema::cargarArchivo(string nombreArchivo)
{
    // Abrir el archivo
    ifstream archivo;
    archivo.open(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo" << endl << endl;
        return; // Terminar la ejecución del método
    }

    

    // Leer línea por línea
    string linea;
    getline(archivo, linea); // Ignorar la primera línea
    while (getline(archivo, linea))
    {
        // Separar los datos de la línea
        vector<string> datos = separar(linea);
        //ID,Nombre,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio

        if (datos.size() == 6)
        {
            // Crear un objeto de tipo Pelicula
            string id = (datos[0]);
            string nombre = datos[1];
            int minutos = stoi(datos[2]);
            // Quitar & de la cadena de género
            string genero = datos[3];
            double calificacion = stod(datos[4]); // Convertir de string a double
            string fechaEstreno = datos[5];

            // Agregar la película al vector de videos
            videos.push_back(new Pelicula(id, nombre, genero, calificacion, minutos, fechaEstreno));

        } else if (datos.size() == 10)
        {
            // Crear un objeto de tipo Episodio
            string id = (datos[0]);
            string nombre = datos[1];
            int minutos = stoi(datos[2]);
            string genero = datos[3];
            double calificacion = stod(datos[4]); // Convertir de string a double

            string fechaEstreno = datos[5];
            string IDepisodio = datos[6];
            string nombreEpisodio = datos[7];
            int temporada = stoi(datos[8]);
            int numEpisodio = stoi(datos[9]);

            // Agregar el episodio al vector de videos
            videos.push_back(new Episodio(id, nombre, genero, calificacion, minutos, fechaEstreno, IDepisodio, nombreEpisodio, temporada, numEpisodio));

        }
    }

    // Cerrar el archivo al terminar de leerlo
    archivo.close();
    cout << "Archivo cargado exitosamente" << endl << endl;
}


void Sistema::mostrarVideosCalificacion(double calificacionMinima)
{
    cout << "Videos con calificacion mayor o igual a " << calificacionMinima << endl;

    // Recorrer el vector de videos
    for (Video *video : videos)
    {
        // Verificar si el video cumple con la condición de calificación mínima 
        if (video->getCalificacion() >= calificacionMinima)
        {
            // Mostrar el video
            video->mostrarDatos();
            cout << endl;
        }
    }
    // Terminar la ejecución del método después de mostrar los videos que cumplen con la condición
    cout << "Presione ENTER para continuar...";
    cin.get(); // Esperar a que el usuario presione ENTER
    return;
}

void Sistema::mostrarVideosGenero(string genero)
{
    cout << "Videos del genero " << genero << endl;

    // Recorrer el vector de videos
    for (Video *video : videos) 
    {
        // Verificar si el video cumple con la condición de género dentro de un string con & 
        if (video->getGenero().find(genero) != string::npos)
        {
            // Mostrar el video
            video->mostrarDatos();
            cout << endl;
        }
    }
    // Terminar la ejecución del método después de mostrar los videos que cumplen con la condición
    cout << "Presione ENTER para continuar...";
    cin.get(); // Esperar a que el usuario presione ENTER
    return;
}

void Sistema::mostrarEpisodiosSerie(string nombreSerie)
{
    cout << "Episodios de la serie " << nombreSerie << endl;

    // Recorrer el vector de videos
    for (Video *video : videos)
    {
        // Verificar si el video es de tipo Episodio
        Episodio *episodio = dynamic_cast<Episodio*>(video); // Downcasting de Video a Episodio
        if (episodio != nullptr) // Verificar si el downcasting fue exitoso
        {
            // Verificar si el episodio es de la serie deseada
            if (episodio->getNombre() == nombreSerie)
            {
                // Mostrar el episodio
                cout << episodio << endl;
                cout << endl;
            }
        } 
    }
    // Terminar la ejecución del método después de mostrar los episodios que cumplen con la condición
    cout << "Presione ENTER para continuar...";
    cin.get(); // Esperar a que el usuario presione ENTER
    return;
}

void Sistema::mostrarPeliculasCalificacion(double calificacionMinima)
{
    cout << "Peliculas con calificacion mayor a " << calificacionMinima << endl;

    // Recorrer el vector de videos
    for (Video *video : videos)
    {
        // Verificar si el video es de tipo Pelicula
        Pelicula *pelicula = dynamic_cast<Pelicula*>(video); // Downcasting de Video a Pelicula
        if (pelicula != nullptr) // Verificar si el downcasting fue exitoso
        {
            // Verificar si la película cumple con la condición de calificación mínima
            if (pelicula->getCalificacion() > calificacionMinima)
            {
                // Mostrar la película
                cout << pelicula << endl;
                cout << endl;
            }
        }
    }
    // Terminar la ejecución del método después de mostrar las películas que cumplen con la condición
    cout << "Presione ENTER para continuar...";
    cin.get(); // Esperar a que el usuario presione ENTER
    return;
}

void Sistema::calificarVideo(string nombre, double calificacionNueva)
{
    // Recorrer el vector de videos
    for (Video *video : videos)
    {
        // Verificar si el video es de tipo Pelicula
        Pelicula *pelicula = dynamic_cast<Pelicula*>(video); // Downcasting de Video a Pelicula
        if (pelicula != nullptr) // Verificar si el downcasting fue exitoso
        {
            // Verificar si la película es la deseada
            if (pelicula->getNombre() == nombre)
            {
                // Cambiar la calificación de la película
                pelicula->setCalificacion(calificacionNueva);
                cout << "La calificacion de la pelicula " << nombre << " ha sido cambiada a " << calificacionNueva << endl;
                return; // Terminar la ejecución del método
            }
        }
        else
        {
            // Verificar si el video es de tipo Episodio
            Episodio *episodio = dynamic_cast<Episodio*>(video); // Downcasting de Video a Episodio
            if (episodio != nullptr) // Verificar si el downcasting fue exitoso
            {
                // Verificar si el episodio es de la serie deseada
                if (episodio->getNombreEpisodio() == nombre)
                {
                    // Cambiar la calificación del episodio
                    episodio->setCalificacion(calificacionNueva);
                    cout << "La calificacion del episodio " << nombre << " ha sido cambiada a " << calificacionNueva << endl;
                    return; // Terminar la ejecución del método
                }
            }
        }
    }
    // Si no se encontró el video
    cout << "No se encontro el video " << nombre << endl;
    cout << "Intente escribir el nombre tal cual se muestra en el listado o un nombre válido" << endl;
}

void Sistema::calcularPromedioSerie(string nombreSerie)
{
    // Variables para almacenar el promedio de calificaciones de la serie
    double sumaCalificaciones = 0;
    int cantidadEpisodios = 0;

    // Recorrer el vector de videos
    for (Video *video : videos)
    {
        // Verificar si el video es de tipo Episodio
        Episodio *episodio = dynamic_cast<Episodio*>(video); // Downcasting de Video a Episodio
        if (episodio != nullptr) // Verificar si el downcasting fue exitoso
        {
            // Verificar si el episodio es de la serie deseada
            if (episodio->getNombre() == nombreSerie)
            {
                // Sumar la calificación del episodio a la suma de calificaciones
                sumaCalificaciones += episodio->getCalificacion();
                // Aumentar la cantidad de episodios
                cantidadEpisodios++;
            }
        }
    }

    // Verificar si la serie tiene episodios
    if (cantidadEpisodios > 0)
    {
        // Calcular el promedio de calificaciones
        double promedio = sumaCalificaciones / cantidadEpisodios;
        // Mostrar el promedio de calificaciones
        cout << "El promedio de calificaciones de la serie " << nombreSerie << " es " << promedio << endl;
    }
    else
    {
        // Mostrar un mensaje de error
        cout << "La serie " << nombreSerie << " no tiene episodios" << endl;
    }
    // Terminar la ejecución del método después de mostrar el promedio de calificaciones
    cout << "Presione ENTER para continuar...";
    cin.get(); // Esperar a que el usuario presione ENTER
    return;
}

void Sistema::ejecutar()
{
    int opcion;

    do 
    {
        // Mostrar el menú
        cout << "MENU" << endl;
        cout << "1. Cargar el archivo de videos." << endl; // Cargar el archivo de datos en formato CSV
        cout << "2. Mostrar todos los videos con: " << endl; // Mostrar todos los videos bajo ciertas condiciones
        cout << "   a) Calificacion mayor o igual a un valor dado." << endl; 
        cout << "   b) De un genero dado." << endl; 
        cout << "3. Mostrar los episodios de una determinada serie." << endl; // Mostrar los episodios de una serie
        cout << "4. Mostrar las peliculas con calificacion mayor a un valor dado." << endl; 
        cout << "5. Calificar un video." << endl; // Pedir el nombre de un video y una calificación nueva para cambiar la calificación del video
        cout << "6. Calcular el promedio de calificaciones de una serie." << endl; 
        cout << "7. Salir." << endl;
        cout << "Ingrese una opcion: "; 
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea que queda en el buffer de entrada

        // Verificar que la opción ingresada sea válida y evitar bucles infinitos
        while (!(cin >> opcion)) // Verificar que la entrada sea un número
        {
            cout << "Opcion invalida. Ingrese una de las opciones indicadas en el menu ";
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el salto de línea que queda en el buffer de entrada
        }

        // Ejecutar la opción seleccionada
        switch (opcion)
        {
            case 1: // Cargar el archivo de datos en formato CSV
            {
                string nombreArchivo;
                cout << "Ingrese el nombre del archivo: ";
                getline(cin, nombreArchivo);
                cargarArchivo(nombreArchivo);
                break;
            }

            //--------------------------------------------------------------

            case 2: // Mostrar todos los videos que cumplen ciertas condiciones
            {
                // Verificar que se cargo el archivo de videos
                if (videos.size() == 0)
                {
                    cout << "Primero debe cargar el archivo de videos" << endl;
                    cout << "Presione ENTER para continuar...";
                    cin.get(); // Esperar a que el usuario presione ENTER
                    break; // Terminar la ejecución del case
                }
                char subopcion;
                cout << "a) Calificacion mayor o igual a un valor dado." << endl;
                cout << "b) Genero." << endl;
                cout << "Ingrese una opcion: " << endl;
                cin >> subopcion;
                cin.ignore(); // Ignorar el salto de línea que queda en el buffer de entrada

                switch (subopcion)
                {
                    case 'a': // Calificacion mayor o igual a un valor dado
                    {
                        cout << "Las calificaiones estan en una escala de 1 a 7" << endl;
                        double calificacionMinima;
                        // verificar que la entrada sea un numero entre 1 y 7
                        while (true)
                        {
                            cout << "Ingrese la calificacion minima: ";
                            if (!(cin >> calificacionMinima)) 
                            {
                                cout << "La calificacion debe ser un valor numerico" << endl;
                                cin.clear(); // Restaurar el estado de cin
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                            } else if (calificacionMinima < 1 || calificacionMinima > 7) 
                            {
                                cout << "La calificacion debe ser un valor entre 1 y 7" << endl;
                            } else 
                            {
                                break; // Salir del bucle si la entrada es válida
                            }
                        }

                        cin.ignore(); // Ignorar el salto de línea que queda en el buffer de entrada
                        mostrarVideosCalificacion(calificacionMinima);
                        break;
                    }

                    case 'b': // Genero
                    {
                        cout << "Se tienen los generos: " << endl;
                        vector<string> generos;
                        // Mostrar los generos
                        for (Video *video : videos)
                        {
                            // Verificar si el genero del video ya se agregó al vector de generos
                            if (find(generos.begin(), generos.end(), video->getGenero()) == generos.end())
                            {
                                // Agregar el genero al vector de generos
                                generos.push_back(video->getGenero());
                                // Mostrar el genero
                                cout << video->getGenero() << endl;
                            }
                        }
                        // Pedir el genero
                        string genero;
                        cout << "Ingrese el genero: ";
                        getline(cin, genero);
                        mostrarVideosGenero(genero);
                        break;
                    }

                    default:
                    {
                        cout << "Opcion invalida" << endl;
                        break;
                    }
                }
                break;
            }

            //--------------------------------------------------------------

            case 3: // Mostrar los episodios de una serie
            {
                // Verificar que se cargo el archivo de videos
                if (videos.size() == 0)
                {
                    cout << "Primero debe cargar el archivo de videos" << endl;
                    cout << "Presione ENTER para continuar...";
                    cin.get(); // Esperar a que el usuario presione ENTER
                    break; // Terminar la ejecución del case
                }
                
                cout << "Se tienen las series: " << endl;
                vector<string> series;
                for (Video *video : videos)
                {
                    // Verificar si el video es de tipo Episodio
                    Episodio *episodio = dynamic_cast<Episodio*>(video); // Downcasting de Video a Episodio
                    if (episodio != nullptr) // Verificar si el downcasting fue exitoso
                    {
                        // Verificar si la serie ya se agregó al vector de series
                        // find retorna un iterador al elemento si lo encuentra, si no lo encuentra retorna un iterador al final del vector
                        if (find(series.begin(), series.end(), episodio->getNombre()) == series.end())
                        {
                            // Agregar la serie al vector de series
                            series.push_back(episodio->getNombre());
                            // Mostrar el nombre de la serie
                            cout << episodio->getNombre() << endl;
                        }
                    }
                }

                string nombreSerie;
                cout << "Ingrese el nombre de la serie como aparece listado: ";
                getline(cin, nombreSerie);
                if (find(series.begin(), series.end(), nombreSerie) == series.end())
                {
                    cout << "No se encontro la serie " << nombreSerie << endl;
                }
                else
                {
                    mostrarEpisodiosSerie(nombreSerie);
                }
                break;
            }

            //--------------------------------------------------------------

            case 4: // Mostrar las peliculas con calificacion mayor a un valor dado
            {
                // Verificar que se cargo el archivo de videos
                if (videos.size() == 0)
                {
                    cout << "Primero debe cargar el archivo de videos" << endl;
                    cout << "Presione ENTER para continuar...";
                    cin.get(); // Esperar a que el usuario presione ENTER
                    break; // Terminar la ejecución del case
                }

                cout << "Las calificaiones estan en una escala de 1 a 7" << endl;
                double calificacionMinima;
                // verificar que la entrada sea un numero entre 1 y 7
                while (true)
                {
                    cout << "Ingrese la calificacion minima: ";
                    if (!(cin >> calificacionMinima)) 
                    {
                        cout << "La calificacion debe ser un valor numerico" << endl;
                        cin.clear(); // Restaurar el estado de cin
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                    } else if (calificacionMinima < 1 || calificacionMinima > 7) 
                    {
                        cout << "La calificacion debe ser un valor entre 1 y 7" << endl;
                    } else 
                    {
                        break; // Salir del bucle si la entrada es válida
                    }
                }
                mostrarPeliculasCalificacion(calificacionMinima);
                break;
            }

            //--------------------------------------------------------------

            case 5: // Calificar un video
            {
                // Verificar que se haya cargado el archivo de videos
                if (videos.size() == 0)
                {
                    cout << "Primero debe cargar el archivo de videos" << endl;
                    cout << "Presione ENTER para continuar...";
                    cin.ignore(); // Ignorar cualquier entrada previa
                    cin.get(); // Esperar a que el usuario presione ENTER
                    break; // Terminar la ejecución del case
                }

                char subopcion;
                cout << "a) Pelicula." << endl;
                cout << "b) Episodio." << endl;
                cout << "Ingrese una opcion: ";
                cin >> subopcion;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el salto de línea y descartar la entrada adicional

                switch (subopcion)
                {
                    case 'a': // Pelicula
                    {
                        cout << "Se tienen las peliculas: " << endl;
                        vector<string> peliculas;
                        for (Video *video : videos)
                        {
                            // Verificar si el video es de tipo Pelicula
                            Pelicula *pelicula = dynamic_cast<Pelicula*>(video); // Downcasting de Video a Pelicula
                            if (pelicula != nullptr) // Verificar si el downcasting fue exitoso
                            {
                                // Verificar si la pelicula ya se agregó al vector de peliculas
                                if (find(peliculas.begin(), peliculas.end(), pelicula->getNombre()) == peliculas.end())
                                {
                                    // Agregar la pelicula al vector de peliculas
                                    peliculas.push_back(pelicula->getNombre());
                                    // Mostrar el nombre de la pelicula
                                    cout << pelicula->getNombre() << endl;
                                }
                            }
                        }
                        string nombrePelicula;
                        cout << "Ingrese el nombre de la pelicula: ";
                        getline(cin, nombrePelicula);
                        if (find(peliculas.begin(), peliculas.end(), nombrePelicula) == peliculas.end())
                        {
                            cout << "No se encontro la pelicula " << nombrePelicula << endl;
                            break;
                        }
                        double calificacionNueva;
                        // Verificar que la calificacion sea un valor numerico entre 1 y 7
                        while (true)
                        {
                            cout << "Ingrese la nueva calificacion: ";
                            if(!(cin >> calificacionNueva))
                            {
                                cout << "La calificacion debe ser un valor numerico" << endl;
                                cin.clear(); // Restaurar el estado de cin
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el salto de línea y descartar la entrada adicional
                            } else if (calificacionNueva < 1 || calificacionNueva > 7)
                            {
                                cout << "La calificacion debe ser un valor entre 1 y 7" << endl;
                            } else
                            {
                                break; // Salir del ciclo while
                            }
                        }
                        cin.ignore();
                        calificarVideo(nombrePelicula, calificacionNueva);
                        break;
                    }

                    case 'b': // Episodio
                    {
                        cout << "Se tienen los episodios: " << endl;
                        vector<string> episodios;
                        for (Video *video : videos)
                        {
                            // Verificar si el video es de tipo Episodio
                            Episodio *episodio = dynamic_cast<Episodio*>(video); // Downcasting de Video a Episodio
                            if (episodio != nullptr) // Verificar si el downcasting fue exitoso
                            {
                                // Verificar si el episodio ya se agregó al vector de episodios
                                if (find(episodios.begin(), episodios.end(), episodio->getNombreEpisodio()) == episodios.end())
                                {
                                    // Agregar el episodio al vector de episodios
                                    episodios.push_back(episodio->getNombreEpisodio());
                                    // Mostrar el nombre del episodio
                                    cout << episodio->getNombreEpisodio() << endl;
                                }
                            }
                        }
                        string nombreEpisodio;
                        cout << "Ingrese el nombre del episodio: ";
                        getline(cin, nombreEpisodio);
                        if (find(episodios.begin(), episodios.end(), nombreEpisodio) == episodios.end())
                        {
                            cout << "No se encontro el episodio " << nombreEpisodio << endl;
                            break;
                        }
                        double calificacionNueva; 
                        // Verificar que la calificacion sea un valor numerico entre 1 y 7
                        while (true)
                        {
                            cout << "Ingrese la nueva calificacion: ";
                            if(!(cin >> calificacionNueva))
                            {
                                cout << "La calificacion debe ser un valor numerico" << endl;
                                cin.clear(); // Restaurar el estado de cin
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el salto de línea y descartar la entrada adicional
                            } else if (calificacionNueva < 1 || calificacionNueva > 7)
                            {
                                cout << "La calificacion debe ser un valor entre 1 y 7" << endl;
                            } else
                            {
                                break; // Salir del ciclo while
                            }
                        }
                        cin.ignore();
                        calificarVideo(nombreEpisodio, calificacionNueva);
                        break;
                    }

                    default:
                    {
                        cout << "Opcion invalida" << endl;
                        break;
                    }
                }
                break;
            }

            //--------------------------------------------------------------

            case 6: // Calcular el promedio de calificaciones de una serie
            {
                // Verificar que se cargo el archivo de videos
                if (videos.size() == 0)
                {
                    cout << "Primero debe cargar el archivo de videos" << endl;
                    cout << "Presione ENTER para continuar...";
                    cin.get(); // Esperar a que el usuario presione ENTER
                    break; // Terminar la ejecución del case
                }

                cout << "Se tienen las series: " << endl;
                vector<string> series;
                for (Video *video : videos)
                {
                    // Verificar si el video es de tipo Episodio
                    Episodio *episodio = dynamic_cast<Episodio*>(video); // Downcasting de Video a Episodio
                    if (episodio != nullptr) // Verificar si el downcasting fue exitoso
                    {
                        // Verificar si la serie ya se agregó al vector de series
                        // find retorna un iterador al elemento si lo encuentra, si no lo encuentra retorna un iterador al final del vector
                        if (find(series.begin(), series.end(), episodio->getNombre()) == series.end())
                        {
                            // Agregar la serie al vector de series
                            series.push_back(episodio->getNombre());
                            // Mostrar el nombre de la serie
                            cout << episodio->getNombre() << endl;
                        }
                    }
                }

                string nombreSerie;
                cout << "Ingrese el nombre de la serie como aparece listado: ";
                getline(cin, nombreSerie);
                if (find(series.begin(), series.end(), nombreSerie) == series.end())
                {
                    cout << "No se encontro la serie " << nombreSerie << endl;
                }
                else
                {
                    calcularPromedioSerie(nombreSerie);
                }
                break;
            }

            //--------------------------------------------------------------

            case 7: // Salir
            {
                cout << "Saliendo..." << endl;
                break;
            }

            //--------------------------------------------------------------

            default:
            {
                cout << "Opcion invalida" << endl;
                break;
            }

        }


        // Desplegar todos los géneros
        // Opcional: desplegar todos los videos


    } while (opcion != 7);
}
#pragma once
#include <iostream>
class MaterialBibliografico { 

    protected:

        std::string nombre;
        std::string isbn;
        std::string autor;
        std::string estado = "Disponible";

    public:
    
        MaterialBibliografico(std::string nombre, std::string isbn, std::string autor); //const
        virtual ~MaterialBibliografico(); //dest
        virtual void mostrarInformacion(); //Muestra la info del objeto.
        std::string getNombre();
        std::string getAutor();
        std::string getEstado();
        void actualizarEstado(); //Actualiza el estado del material cuando está prestado o no.
};
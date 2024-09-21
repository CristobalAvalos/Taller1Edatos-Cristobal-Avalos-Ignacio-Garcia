#pragma once
#include <iostream>
class MaterialBibliografico { 

    protected:

        std::string nombre;
        std::string isbn;
        std::string autor;
        std::string estado = "Disponible";

    public:
    
        MaterialBibliografico(std::string nombre, std::string isbn, std::string autor);
        virtual ~MaterialBibliografico();
        virtual void mostrarInformacion();
        std::string getNombre();
        std::string getAutor();
        std::string getEstado();
        void actualizarEstado();
};
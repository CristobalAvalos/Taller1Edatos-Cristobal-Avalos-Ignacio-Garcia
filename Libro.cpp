#include "Libro.h"

Libro::Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPubliacion, std::string resumen) : MaterialBibliografico(nombre,isbn,autor) {

    tipo = "Libro";
    this->fechaPublicacion=fechaPubliacion;
    this->resumen=resumen;
    extra1 = fechaPubliacion;
    extra2 = resumen;
    

}

Libro::~Libro(){

    std::cout<<"Se ha destruido el libro de nombre '"<<this->nombre<<"'"<<std::endl;

}

void Libro::mostrarInformacion(){

    std::cout<<"Estado: "<<this->estado<<"\nNombre: "<<this->nombre<<"\nisbn: "<<this->isbn<<"\nAutor: "<<this->autor<<"\nFecha de publicacion: "<<this->fechaPublicacion<<"\nResumen: "<<this->resumen<<std::endl;

}
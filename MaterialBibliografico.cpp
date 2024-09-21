#include "MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string isbn, std::string autor){

    this->nombre=nombre;
    this->isbn=isbn;
    this->autor=autor;

}

MaterialBibliografico::~MaterialBibliografico(){

    std::cout<<"<<<<<<<<<<<<<<<<<<<<ELIMINAR>>>>>>>>>>>>>>>>>>>>>>"<<std::endl;

}

void MaterialBibliografico::mostrarInformacion(){

    std::cout<<"Info"<<std::endl;

}

std::string MaterialBibliografico::getNombre(){return nombre;}
std::string MaterialBibliografico::getAutor(){return autor;}
std::string MaterialBibliografico::getEstado(){return this->estado;}
void MaterialBibliografico::actualizarEstado(){

    if(estado=="Disponible"){
        estado="No Disponible";
    } else {
        estado="Disponible";
    }

}
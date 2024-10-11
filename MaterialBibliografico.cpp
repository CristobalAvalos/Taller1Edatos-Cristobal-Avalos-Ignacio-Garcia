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

std::string MaterialBibliografico::getTipo(){return tipo;}
std::string MaterialBibliografico::getNombre(){return nombre;}
std::string MaterialBibliografico::getAutor(){return autor;}
std::string MaterialBibliografico::getEstado(){return this->estado;}
std::string MaterialBibliografico::getIsbn(){return this ->isbn;}
std::string MaterialBibliografico::getExtra1(){return this -> extra1;}
std::string MaterialBibliografico::getExtra2(){return this -> extra2;}

void MaterialBibliografico::actualizarEstado(){

    if(estado=="Disponible"){
        estado="No Disponible";
    } else {
        estado="Disponible";
    }

}
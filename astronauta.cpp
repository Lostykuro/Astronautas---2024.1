#include "astronauta.h"

astronauta::astronauta(std::string cpf, std::string nome, int idade) {
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->vivo = true;
    this->disponivel = true;
}

void astronauta::matar() {
    this->vivo = false;
}

std::string astronauta::get_cpf() {
    return this->cpf;
}

std::string astronauta::get_nome() {
    return this->nome;
}

int astronauta::get_idade() {
    return this->idade;
}

bool astronauta::get_vivo() {
    return this->vivo;
}

bool astronauta::get_disponivel() {
    return this->disponivel;
}

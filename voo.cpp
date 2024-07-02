#include "voo.h"

voo::voo(int n) {
    this->codigo = n;
    this->ativo = false;
    this->finalizado = false;
    this->em_curso = false;
    this->planejado = true;
    this->explodido = false;
}

bool voo::get_em_curso() {
    return this->em_curso;
}

bool voo::get_planejado() {
    return this->planejado;
}

bool voo::get_finalizado() {
    return this->finalizado;
}

void voo::explodir() {
    this->explodido = true;
    this->ativo = false;
    this->finalizado = true;
    this->planejado = false;
    this->em_curso = false;
}

bool voo::get_explodido() {
    return this->explodido;
}

void voo::decolar(int codigo) {
    this->ativo = true;
    this->planejado = false;
    this->em_curso = true;
}

void voo::pousar(int codigo) {
    this->ativo = false;
    this->em_curso = false;
    this->finalizado = true;
}

bool voo::get_ativo() {
    return this->ativo;
}

int voo::get_codigo() {
    return this->codigo;
}

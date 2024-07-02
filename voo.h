#ifndef VOO_H
#define VOO_H

#include <vector>
#include "astronauta.h"

class voo {
private:
    int codigo;
    bool ativo;
    bool explodido;
    bool planejado;
    bool finalizado;
    bool em_curso;

public:
    voo(int n);
    bool get_em_curso();
    bool get_planejado();
    bool get_finalizado();
    void explodir();
    bool get_explodido();
    void decolar(int codigo);
    void pousar(int codigo);
    bool get_ativo();
    int get_codigo();
    std::vector<astronauta> tripulantes;
    std::vector<astronauta> esteve_no_voo;
};

#endif /* VOO_H */

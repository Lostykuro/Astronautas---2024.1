#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
#include <vector>

class astronauta {
private:
    std::string cpf;
    std::string nome;
    int idade;

public:
    bool vivo;
    bool disponivel;
    std::vector<int> missoes_concluidas;

    astronauta(std::string cpf, std::string nome, int idade);
    void matar();
    std::string get_cpf();
    std::string get_nome();
    int get_idade();
    bool get_vivo();
    bool get_disponivel();
};

#endif /* ASTRONAUTA_H */

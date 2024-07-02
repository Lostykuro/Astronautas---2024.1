#include <iostream>
#include <string>
#include <vector>
#include "astronauta.h"
#include "voo.h"
using std::string;
using std::vector;



int main() {
  vector<voo> voos;
  vector<astronauta> astronautas;
    int opcao;
  
    do {
      std::cout << "Pressione um número para executar uma ação:" << std::endl<< std::endl;
      std::cout << "1- Cadastrar astronauta" << std::endl;
      std::cout << "2- Cadastrar voo" << std::endl;
      std::cout << "3- listar astronautas" << std::endl;
      std::cout << "4- listar astronautas mortos" << std::endl;
      std::cout << "5- adicionar astronauta em um voo" << std::endl;
      std::cout << "6- remover astronauta em um voo" << std::endl;
      std::cout << "7- listar tripulação de um voo" << std::endl;
      std::cout << "8- lançar um voo" << std::endl;
      std::cout << "9- pousar um voo" << std::endl;
      std::cout << "10- explodir um voo" << std::endl;
      std::cout << "11- listar todos os voos" << std::endl;
      std::cin >> opcao;

// switch ficou bugando pela formatação, intakavelmente, então fiz um if else.
// cadastrar astronauta
      if (opcao == 1){

        string cpf;
        string nome;
        int idade;
        std::cout << "Digite o nome do astronauta:" << std::endl;
        std::getline(std::cin>>std::ws, nome);
        std::cout << "Digite o CPF do astronauta:" << std::endl;
        std::cin >> cpf;
        std::cout << "Digite a idade do astronauta:" << std::endl;
        std::cin >> idade;
        astronauta astronauta(cpf, nome, idade);
        astronautas.push_back(astronauta); 
      }
//cadastrar voo
      if (opcao == 2){
        int codigo;
        std::cout << "insira o codigo do voo" << std::endl;
        std::cin >> codigo;
        voo voo(codigo);
        voos.push_back(voo);
      }
//listar astronautas
      if (opcao == 3){
        for (int i = 0; i < astronautas.size(); i++){
          std::cout <<" - "<< astronautas[i].get_nome() << " ";
          if(astronautas[i].get_vivo()==false){
            std::cout <<std::endl << "// status quote: [morto]" <<  std::endl<< std::endl;
          }else if (astronautas[i].get_vivo()==true){
            std::cout <<std::endl << "// status quote: [vivo]"  << std::endl<< std::endl;
          }
        }
      }
//listar astronautas mortos
      if (opcao == 4){
        for (int i = 0; i < astronautas.size(); i++){
          if(astronautas[i].get_vivo()==false){
            std::cout << "nome:" << astronautas[i].get_nome()<< std::endl<<"cpf:"<< astronautas[i].get_cpf()<< std::endl << "missões concluidas:"<< std::endl;
            for(int j = 0; j < astronautas[i].missoes_concluidas.size(); j++){
              if(j==astronautas[i].missoes_concluidas.size()-1){
                std::cout << astronautas[i].missoes_concluidas[j] << " [ultimo voo participado]";
              }else{ std::cout << astronautas[i].missoes_concluidas[j] << " [com sucesso]" << std::endl;}
            }
          }
        }
      }
//adicionar astronauta a um voo por cpf
      if (opcao == 5){
        string cpf;
        std::cout << "insira o cpf do astronauta:" << std::endl;
        std::cin >> cpf;
        bool astronauta_existe = false;
        for (int i = 0; i < astronautas.size(); i++){
          if(astronautas[i].get_cpf()==cpf){
            astronauta_existe = true;
            if (astronautas[i].get_vivo()==true){
              if (astronautas[i].get_disponivel()==true){
                int codigo;
                std::cout << "insira o codigo do voo:" << std::endl;
                std::cin >> codigo;
                bool voo_encontrado = false;
                for (int j = 0; j < voos.size(); j++){
                  if(voos[j].get_codigo()==codigo){
                    voo_encontrado = true;
                    if(voos[j].get_ativo()==false){
                      voos[j].esteve_no_voo.push_back(astronautas[i]);
                      voos[j].tripulantes.push_back(astronautas[i]);
                      astronautas[i].disponivel=false;
                      std::cout << "Astronauta adicionado com sucesso ao voo." << std::endl;
                    }else{std::cout << "Voo já está ativo." << std::endl;}
                  
                }
              }
              if (!voo_encontrado) {
                std::cout << "Voo não encontrado." << std::endl;
              }
            }else {std::cout <<"Astronauta não está disponível para o voo." << std::endl;}
          }else {std::cout << "Astronauta esta morto." << std::endl;}
          }
        }
        if (!astronauta_existe) {
          std::cout << "Astronauta não encontrado." << std::endl;
        }
      }
//remover astronauta de um voo por cpf
      if (opcao == 6){
        string cpf;
        std::cout << "insira o cpf do astronauta:" << std::endl;
        std::cin >> cpf;
        for (int i = 0; i < astronautas.size(); i++){
          if(astronautas[i].get_cpf()==cpf){
            int codigo;
            std::cout << "insira o codigo do voo:" << std::endl;
            std::cin >> codigo;
            for (int j = 0; j < voos.size(); j++){
              if(voos[j].get_codigo()==codigo){
                for (int k = 0; k < voos[j].tripulantes.size(); k++){
                  if(voos[j].tripulantes[k].get_cpf()==cpf){
                    if(voos[j].get_ativo()==false){
                      voos[j].tripulantes.erase(voos[j].tripulantes.begin()+k);
                      astronautas[i].disponivel=true;
                      std::cout << "Astronauta removido com sucesso do voo." << std::endl;
                    }else {std::cout << "Voo esta ativo, seu lunatico!"<< std::endl;}
                  }
                }
              }
            }
          }
        }
      }

//listar tripulação de um voo
      if (opcao == 7){
        int codigo;
        std::cout << "insira o codigo do voo" << std::endl;
        std::cin >> codigo;
        bool found = false;
        for (int i = 0; i < voos.size(); i++){
          if(voos[i].get_codigo()==codigo){
            for(int j = 0; j < voos[i].tripulantes.size(); j++){
              std::cout << std::endl << " - " << voos[i].tripulantes[j].get_nome() << std::endl<< std::endl;
            }
            found = true;
            break;
          }
        }
        if (!found) {
          std::cout << "Voo não encontrado" << std::endl;
        }
      }
//lançar voo
      if (opcao == 8){
        int codigo;
        std::cout << "insira o codigo do voo" << std::endl;
        std::cin >> codigo;
        bool found = false;
        for (int i = 0; i < voos.size(); i++){
          if(voos[i].get_codigo()==codigo){
            if (voos[i].get_finalizado()==false){
              if(voos[i].tripulantes.size() > 0){
                if(voos[i].get_ativo()==false){
                  voos[i].decolar(codigo);
                  std::cout << "Voo decolando" << std::endl;
                }else {std::cout << "Voo já está decolando." << std::endl;}
              }else {std::cout << "Voo está vazio." << std::endl;}
            }else {std::cout << "Voo já está finalizado." << std::endl;}
            found = true;
            break;
          } 
        }
        if (!found) {
          std::cout << "DADOS EXPURGADOS" << std::endl;
        } 
      }
//pousar voo
      if (opcao == 9){
        int codigo;
        std::cout << "insira o codigo do voo" << std::endl;
        std::cin >> codigo;
        bool found = false;
        for (int i = 0; i < voos.size(); i++){
          if(voos[i].get_codigo()==codigo){
            if(voos[i].get_ativo()==true && voos[i].get_explodido()==false){
              found = true;
              for(int j = 0; j < astronautas.size(); j++){
                if (voos[i].tripulantes[j].get_cpf() == astronautas[j].get_cpf()){
                  astronautas[j].missoes_concluidas.push_back(codigo);
                }
              }
              voos[i].pousar(codigo);
              std::cout<< "Voo pousado" << std::endl;
            }else if (voos[i].get_ativo()==false && voos[i].get_explodido()==true){
              std::cout << "Voo explodido" << std::endl;
            }else { std::cout << "voo já está pousado" << std::endl;}
          }
        }
        if (!found){std::cout << "voo não encontrado" << std::endl;}
        
      }
//explodir voo
      if (opcao == 10){
        std::cout << std::endl<< "[WARNING:ONLY AUTHORIZED PEOPLE CAN HAVE ACCESS THIS FUNCTION]" << std::endl<< std::endl;
        int codigo;
        std::cout << "insira o codigo do voo" << std::endl;
        std::cin >> codigo;
        bool found = false;
        for (int i = 0; i < voos.size(); i++){
          if(voos[i].get_codigo()==codigo){
            if(voos[i].get_explodido()==false){
              voos[i].explodir();
              for(int j = 0; j < voos[i].tripulantes.size(); j++){
                for(int k = 0; k < astronautas.size(); k++){
                  if(voos[i].tripulantes[j].get_cpf()==astronautas[k].get_cpf()){
                    astronautas[k].matar();
                  }
                }
              }
              std::cout << "Voo explodido" << std::endl;
              found=true;
              break;
            }else {std::cout << "Voo já explodido" << std::endl;}
          }
        }
        if (!found){std::cout << "voo não encontrado" << std::endl;}
      }
//listar todos os voos
      if (opcao == 11){
        std::cout <<"========================================="<< std::endl;
        std::cout << "voos planejados :" << std::endl;      
         for (int i = 0; i < voos.size(); i++){
          if(voos[i].get_planejado()==true){
            std::cout <<"-----------------------------------------"<< std::endl;
            std::cout<<"codigo:" << voos[i].get_codigo() << std::endl;
            std::cout<<"astronautas:" << std::endl;
            for(int j = 0; j < voos[i].tripulantes.size(); j++){
              std::cout << " - " << voos[i].tripulantes[j].get_nome() << std::endl;
            }
          }  
        }
        std::cout <<"========================================="<< std::endl;
        std::cout  << "voos em curso :" << std::endl;  
         for (int i = 0; i < voos.size(); i++){
          if(voos[i].get_em_curso()==true){
            std::cout <<"-----------------------------------------"<< std::endl;
            std::cout<<"codigo:" << voos[i].get_codigo() << std::endl;
            std::cout<<"astronautas:" << std::endl;
            for(int j = 0; j < voos[i].tripulantes.size(); j++){
              std::cout << " - " << voos[i].tripulantes[j].get_nome() << std::endl;
            }
          }  
        }
        std::cout <<"========================================="<< std::endl;
        std::cout  << "voos finalizados :" << std::endl;
         for (int i = 0; i < voos.size(); i++){
          if(voos[i].get_finalizado()==true){
            std::cout <<"-----------------------------------------"<< std::endl;
            std::cout<<"codigo:" << voos[i].get_codigo() << std::endl;
            if (voos[i].get_explodido()==true){
              std::cout << "status :[sem sucesso]" << std::endl;
            }else{
              std::cout << "status :[sucesso]" << std::endl;
            }
            std::cout<<"astronautas:" << std::endl;
            for(int j = 0; j < voos[i].esteve_no_voo.size(); j++){
              std::cout << " - " << voos[i].esteve_no_voo[j].get_nome() << std::endl;
            }
          }  
        }
        std::cout <<"========================================="<< std::endl;
      }
        
    
      
    } while (opcao != 0);

}
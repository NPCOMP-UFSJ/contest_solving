#include <bits/stdc++.h>

/* Feito por voamorim */

/*
    Tentando
        -> Calcula um faturamento menor do que o verdadeiro em casos de teste posteriores
*/

/*
    Descrição:
        -> Preço fixo de $10,00 por carro estacionado
        -> O atendente sempre escolhe a vaga mais próxima do início de comprimento igual ou maior do que o comprimento do carro
        -> Depois que é estacionado, o veículo não é movido até o momento de sua saída do estacionamento
        -> Ele estaciona no começo do espaço encontrado

        -> O estacionamento começa sempre vazio
        -> Um veículo pode sair somente se ele realmente estiver estacionado
        -> Não chega um veículo novo de mesma placa de um já estacionado
*/

using namespace std;

//Structs
typedef struct vaga{
    bool ocupada;
    int comprimento; //Comprimento da vaga
    int placa; //Placa do carro estacionado (0 quando não existe carro estacionado)
} Vaga;
typedef struct estacionamento{
    vector<Vaga> vagas;
    int comprimento; //Comprimento total do estacionamento
} Estacionamento;

//Declaração das funções
void inicializaEstacionamento(Estacionamento *estacionamento);
void liberaVaga(Estacionamento* estacionamento, int placa);
int preencheVaga(Estacionamento* estacionamento, int placa, int comprimento);
/**
 * Retorno:
 *      - 10 (int): quando o veículo foi estacionado com sucesso
 *      - 0 (int): quando não tinha espaço para que o veículo fosse estacionado
 */



/*
void imprimeEstacionamento(Estacionamento* estacionamento){
    cout << "Estacionamento: ";
    for(int i = 0; i < estacionamento->vagas.size(); i++){
        cout << "{" << estacionamento->vagas[i].comprimento << ", " << estacionamento->vagas[i].placa << "} ";
    }
    cout << endl;
}
*/

//Variáveis
int num_eventos;
char evento; int placa, comprimento_carro;
int faturamento;

int main(){
    Estacionamento estacionamento;

    //Loop até o fim do arquivo de entrada
    while(scanf("%d %d\n", &estacionamento.comprimento, &num_eventos) != EOF){
        faturamento = 0; //Em cada instância o faturamento começa em 0
        inicializaEstacionamento(&estacionamento);
        for(int caso = 0; caso < num_eventos; caso++){
            scanf("%c %d", &evento, &placa);
            //Verifica qual evento a ser realizado
            if(evento == 'C'){
                scanf(" %d\n", &comprimento_carro);
                faturamento += preencheVaga(&estacionamento, placa, comprimento_carro); //Soma o retorno da função ao faturamento
            } else {
                scanf("\n"); //Lê a quebra de linha
                liberaVaga(&estacionamento, placa); //Retira o veículo da referida placa do estacionamento
            }
            //imprimeEstacionamento(&estacionamento);
        }
        cout << faturamento << endl;
        estacionamento.vagas.clear(); //Esvazia o vector de vagas
    }
    return 0;
}

int preencheVaga(Estacionamento* estacionamento, int placa, int comprimento){
    for(int vaga = 0; vaga < estacionamento->vagas.size(); vaga++){
        //Caso a vaga esteja vazia e seja de comprimento maior ou igual ao carro
        if(!estacionamento->vagas[vaga].ocupada && estacionamento->vagas[vaga].comprimento >= comprimento){
            //Verifica se o comprimento da vaga é maior do que o comprimento do carro (necessário passar o comprimento restante para a vaga seguinte)
            if(estacionamento->vagas[vaga].comprimento > comprimento){
                //Armazena o espaço que o carro não ocupou
                int espaco_restante = estacionamento->vagas[vaga].comprimento - comprimento;

                //Estaciona o veículo na vaga vazia
                estacionamento->vagas[vaga].comprimento = comprimento;
                estacionamento->vagas[vaga].ocupada = true;
                estacionamento->vagas[vaga].placa = placa;

                /*
                //Verifica se a vaga de trás existe
                if(vaga - 1 >= 0){
                    //Verifica se a vaga de trás está vazia
                    if(!estacionamento->vagas[vaga-1].ocupada){
                        //Caso a vaga de trás esteja vazia, ela recebe o espaço restante da vaga atual
                        estacionamento->vagas[vaga-1].comprimento += espaco_restante;

                        espaco_restante = 0; //Espaço restante 0 para sinalizar que o espaço sobrando já foi realocado
                    }
                }
                */

                //Verifica se a vaga da frente existe
                if(vaga + 1 < estacionamento->vagas.size()){
                    //Verifica se a vaga da frente está vazia
                    if(!estacionamento->vagas[vaga+1].ocupada){
                        //Caso a vaga da frente esteja vazia, ela recebe o espaço restante da vaga atual
                        estacionamento->vagas[vaga+1].comprimento += espaco_restante;

                        espaco_restante = 0; //Espaço restante==0 sinaliza que o espaço sobrando foi realocado
                    }
                }


                //Verifica se o espaço_sobrando já foi remanejado para uma das vagas ao lado
                if(espaco_restante != 0){
                    //Como as vagas adjacentes estão ocupadas, é necessário criar uma nova vaga
                    Vaga nova_vaga;
                    nova_vaga.comprimento = espaco_restante;
                    nova_vaga.ocupada = false;
                    nova_vaga.placa = 0;

                    //Insere a nova vaga atrás da vaga ocupada neste procedimento
                    estacionamento->vagas.insert(estacionamento->vagas.begin() + vaga + 1, nova_vaga);
                }
                return 10;
            }
            //Caso o comprimento da vaga é exatamente o comprimento do veículo
            else {
                estacionamento->vagas[vaga].ocupada = true;
                estacionamento->vagas[vaga].placa = placa;
                return 10;
            }
        }
    }
    return 0;
}

void liberaVaga(Estacionamento* estacionamento, int placa){
    for(int vaga = 0; vaga < estacionamento->vagas.size(); vaga++){
        //Verifica se a placa do carro estacionado na vaga é a mesma do carro que deve ser retirado
        if(estacionamento->vagas[vaga].placa == placa){
            //Caso a placa seja a mesma, o estacionamento deve ser liberado

            //Para liberar o estacionamento, deve-se verificar se as vagas adjacentes também estão vazias. Caso verdade, ela deve se fundir com elas

            //Cria variável booleana para verificar se o espaço liberado conseguiu ser realocado para uma vaga ajacente
            bool realocado = false;

            //Verifica se a vaga anterior existe
            if(vaga - 1 >= 0){
                //Verifica se a vaga anterior está vazia
                if(!estacionamento->vagas[vaga-1].ocupada){
                    //Atribui o comprimento do estacionamento atual na vaga anterior
                    estacionamento->vagas[vaga-1].comprimento += estacionamento->vagas[vaga].comprimento;

                    //Remove a vaga atual do vetor
                    estacionamento->vagas.erase(estacionamento->vagas.begin() + vaga);

                    //Reduz o índice de 'vaga' em 1
                    vaga -= 1;

                    //Indica que a realocação da vaga foi concluida
                    realocado = true;
                }
            }

            //Verifica se a vaga posterior existe
            if(vaga + 1 < estacionamento->vagas.size()){
                //Verifica se a vaga posterior está vazia
                if(!estacionamento->vagas[vaga+1].ocupada){
                    //Atribui o comprimento do estacionamento posterior na vaga atual
                    estacionamento->vagas[vaga].comprimento += estacionamento->vagas[vaga+1].comprimento;

                    //Remove a vaga posterior
                    estacionamento->vagas.erase(estacionamento->vagas.begin() + vaga + 1);

                    //Modifica a vaga atual para constar como vazia
                    estacionamento->vagas[vaga].ocupada = false;
                    estacionamento->vagas[vaga].placa = 0;

                    //Indica que a realocação da vaga foi concluida
                    realocado = true;
                }
            }

            //Verifica se a vaga não foi realocada para uma de suas adjacentes
            if(!realocado){
                //Modifica os atributos da vaga para indicar que ela agora está vazia
                estacionamento->vagas[vaga].ocupada = false;
                estacionamento->vagas[vaga].placa = 0;
            }

            //Encerra a verificação
            return;
        }
    }
}

void inicializaEstacionamento(Estacionamento *estacionamento){
    //Cria um espaço de vaga inicial com o mesmo tamanho do comprimento do estacionamento
    Vaga vaga_inicial;
    vaga_inicial.comprimento = estacionamento->comprimento;
    vaga_inicial.ocupada = false; //A vaga começa vazia
    vaga_inicial.placa = 0;

    estacionamento->vagas.insert(estacionamento->vagas.begin(), vaga_inicial);
}

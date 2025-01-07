#include <iostream>
#include <string>

using namespace std;


// Estrutura para representar uma conta bancária
struct ContaBancaria {
    string nomeTitular;
    int numeroConta;
    double saldo;
};

// Declaração das funções
void verificarSaldo(const ContaBancaria& conta);
void depositarSaldo(ContaBancaria& conta);
void sacarSaldo(ContaBancaria& conta);
void exibirMenu(ContaBancaria& conta);

// Função para exibir o menu
void exibirMenu(ContaBancaria& conta) {
    int opcao;

    do {
        cout << "\n=== MENU BANCO ===" << endl;
        cout << "1. Verificar Saldo" << endl;
        cout << "2. Depositar Saldo" << endl;
        cout << "3. Sacar Saldo" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                verificarSaldo(conta);
                break;
            case 2:
                depositarSaldo(conta);
                break;
            case 3:
                sacarSaldo(conta);
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 4);
}


// Função para verificar o saldo da conta
void verificarSaldo(const ContaBancaria& conta) {
    cout << "\nSaldo atual da conta de " << conta.nomeTitular 
              << " (Conta " << conta.numeroConta << "): R$ " 
              << conta.saldo << endl;
}

// Função para depositar saldo
void depositarSaldo(ContaBancaria& conta) {
    double valor;
    cout << "\nDigite o valor para depositar: R$ ";
    cin >> valor;

    if (valor > 0) {
        conta.saldo += valor;
        cout << "Depósito realizado com sucesso! Saldo atualizado: R$ " 
                  << conta.saldo << endl;
    } else {
        cout << "Valor inválido para depósito!" << endl;
    }
}

// Função para sacar saldo
void sacarSaldo(ContaBancaria& conta) {
    double valor;
    cout << "\nDigite o valor para sacar: R$ ";
    cin >> valor;

    if (valor > 0 && valor <= conta.saldo) {
        conta.saldo -= valor;
        cout << "Saque realizado com sucesso! Saldo atualizado: R$ " 
                  << conta.saldo << endl;
    } else if (valor > conta.saldo) {
        cout << "Saldo insuficiente!" << endl;
    } else {
        cout << "Valor inválido para saque!" << endl;
    }
}


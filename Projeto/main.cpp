# include <iostream>
# include <iomanip>
# include <math.h>

using namespace std;

// Métodos Para Cálculo de Juros Simples
class JurosSimples{
public:
         double valorInicial, taxa, montante, valorPrestacao;
         int prestacoes;
       void calcularJurosSimples(){
         receberValores();
         mostrarMontanteEPrestacao();
       }
       void receberValores(){
         cout <<"Cálculo de Juros Simples\n";
         cout <<"Digite o Valor a ser Financiado\n";
         cin >> valorInicial;
         cout <<"Digite o Número de Prestações\n";
         cin >> prestacoes;
         cout <<"Digite a Taxa de Juros do Financiamento\n";
         cin >> taxa;
       }
       double calcularMontante(){
         return valorInicial + (valorInicial * (taxa/100));
       }
       double calcularPrestacao(){
         return montante / prestacoes;
       }
       void mostrarMontanteEPrestacao(){
         montante = calcularMontante();
         valorPrestacao = calcularPrestacao();
         cout << "Valor do Montante -------------- " << montante << "\n";
         cout << "Valor da Prestação -------------- " << valorPrestacao << "\n";
       }
};

class JurosCompostos{
public:
         int prestacoes;
	     double taxa,
	            valorInicial,
                capital,
                juros,
                montante;

       void calcularJurosSimples(){
         receberValores();
         montagemTabela();
       }
       void receberValores(){
           prestacoes = 0;
           juros = 0;
           montante = 0;
         cout <<"Cálculo de Juros Compostos\n";
         cout <<"Digite o Valor a ser Financiado\n";
         cin >> valorInicial;
         cout <<"Digite a Quantidade de Prestações\n";
         cin >> prestacoes;
         cout <<"Digite a Taxa de Juros do Financiamento\n";
         cin >> taxa;
       }
       void montagemTabela(){
         capital = valorInicial;
         cout <<"Prestação -------- Capital -------- Juros --------- Montante\n";
            for (int i = 0; i < prestacoes; i++) {
			   juros = capital * (taxa / 100);
			   montante = capital + juros;
			   cout <<"---" <<(i + 1)<< " --------------" << capital
					<< "-----------" << juros << "----------- "
					<< montante <<"\n";
			   capital = montante;
		    }
       }
};

class TabelaPrice{
public:
       int prestacoes;
       double taxa,
	          valorInicial,
	          valorPrestacoes;
	   void calcularTabelaPrice(){
	     receberValores();
	     calculaValorPrestacoes();
	     montagemTabelaPrice();
	   }
       void receberValores(){
           prestacoes = 0;
         cout <<"Tabela Price\n";
         cout <<"Digite o Valor a ser Financiado\n";
         cin >> valorInicial;
         cout <<"Digite a Quantidade de Prestações\n";
         cin >> prestacoes;
         cout <<"Digite a Taxa de Juros do Financiamento\n";
         cin >> taxa;
       }
       void calculaValorPrestacoes(){
         double coeficiente = (pow((1 + (taxa / 100)),prestacoes) * (taxa / 100))
				/ (pow((1 + (taxa / 100)),prestacoes) - 1);
		valorPrestacoes = valorInicial * coeficiente;
       }
       void montagemTabelaPrice(){
        double juros, amortizacao, saldoDevedor;
        saldoDevedor = valorInicial;
		cout <<
		"Num Prestação -------- Valor Prestação ----------------- Juros ----------------- Amortização ------------ Saldo Devedor\n";
			for (int i = 0; i <= prestacoes; i++) {
			cout << "----" << i << "---------------------"
					<< valorPrestacoes
					<< "-----------------------"
					<< juros
					<< "-------------------"
                    << amortizacao
					<< "------------"
					<< saldoDevedor << "\n";

			juros = saldoDevedor* (taxa / 100);
			amortizacao = valorPrestacoes - juros;
			saldoDevedor = (saldoDevedor - amortizacao)*1;
		}
		double valorPago;
		valorPago = valorPrestacoes * prestacoes;
		cout <<
				"--------------------------------------------------------------------------------------------------------------------\n";
		cout <<
		"Valor Pago ----------------"
				<< valorPago
				<< "--------------------------------------------------------------------------------\n";
		cout <<
				"---------------------------------------------------------------------------------------------------------------------\n";

       }
};

class MetodosParaMain{
public:
   int receberOpcao(){
       int opcao;
       cout <<"Bem Vindo Ao Sistema de Cálculo de Financiamento\n";
       cout <<"Escolha uma das Funcionalidades Abaixo\n";
       cout <<"1 - Calculo de Juros Simples\n";
       cout <<"2 - Tabela de Juros Compostos\n";
       cout <<"3 - Tabela Price\n";
       cout <<"4 - Tabela SAC\n";
       cin >> opcao;
       if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4)
            return opcao;
       else {
            cerr <<"Opcao Inválida\n";
            cout <<"-\n";
            return receberOpcao();
       }
    };
};

int main(){
   int opcao;
   MetodosParaMain metodos;
   opcao = metodos.receberOpcao();
   if(opcao == 1){
    JurosSimples js;
    js.calcularJurosSimples();
   } else if(opcao == 2){
    JurosCompostos jc;
    jc.calcularJurosSimples();
   } else if(opcao == 3){
    TabelaPrice tb;
    tb.calcularTabelaPrice();
   }
}

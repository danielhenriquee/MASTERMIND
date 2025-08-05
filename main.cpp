// Daniel Henrique da Silva, Gabriel Henrique da Silva, Jorge Luiz Siemann Pereira, Lucas dos Santos Luckow

#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int main(){
  #ifdef _WIN32
    system("chcp 65001 > nul"); // Para suportar acentos no terminal do Windows
  #endif
  setlocale(LC_ALL, "pt_BR.UTF-8");
  srand(time(NULL));
  
  int menu;
  float cont;
  
  do {
    cout << "\n\n\n\n                                        :::   :::           :::        ::::::::   :::::::::::       ::::::::::       :::::::::         :::   :::       :::::::::::       ::::    :::       :::::::::\n "
            "                                    :+:+: :+:+:        :+: :+:     :+:    :+:      :+:           :+:              :+:    :+:       :+:+: :+:+:          :+:           :+:+:   :+:       :+:    :+:  \n "
            "                                 +:+ +:+:+ +:+      +:+   +:+    +:+             +:+           +:+              +:+    +:+      +:+ +:+:+ +:+         +:+           :+:+:+  +:+       +:+    +:+    \n "
            "                               +#+  +:+  +#+     +#++:++#++:   +#++:++#++      +#+           +#++:++#         +#++:++#:       +#+  +:+  +#+         +#+           +#+ +:+ +#+       +#+    +:+      \n  "
            "                             +#+       +#+     +#+     +#+          +#+      +#+           +#+              +#+    +#+      +#+       +#+         +#+           +#+  +#+#+#       +#+    +#+        \n "
            "                            #+#       #+#     #+#     #+#   #+#    #+#      #+#           #+#              #+#    #+#      #+#       #+#         #+#           #+#   #+#+#       #+#    #+#         \n "
            "                          ###       ###     ###     ###    ########       ###           ##########       ###    ###      ###       ###     ###########       ###    ####       #########\n\n\n\n\n";

    cout << "                                                                                                       1.  Jogar \n\n\n\n"
            "                                                                                                       2.  SOBRE \n\n\n\n"
            "                                                                                                       3.  SAIR  \n\n\n\n\n\n";
    cin >> menu;
    int ganhou = 0;
    
    switch (menu) {
      case 1:
        int digito1, digito2, digito3, digito4; // digitos aleaótios
        int tentativa, d1, d2, d3, d4; // tentativas
        int ce, cc; // ce = dígito certo e posição errada; cc = dígito certo

        do {
          do {
            digito1 = rand()%6+1; // gerar primeiro algarismo 'aleatório'
            digito2 = rand()%6+1; // gerar segundo algarismo 'aleatório'
            digito3 = rand()%6+1; // gerar terceiro algarismo 'aleatório'
            digito4 = rand()%6+1; // gerar quarto algarismo 'aleatório'
          } while (digito1 == digito2 || digito1 == digito3 || digito1 == digito4 || digito2 == digito3 || digito2 == digito4 || digito3 == digito4); // garantir que não hajam algarismos repetidos
          
          int contador;
          for (contador = 1; contador <= 10; contador++) {
            cc = 0;
            ce = 0;

            cout << "\n\nDigite sua " << contador << "ª tentativa: ";
            cin >> tentativa;

            d1 = tentativa / 1000;
            d2 = tentativa / 100 % 10;
            d3 = tentativa / 10 % 10;
            d4 = tentativa % 10;

            if (digito1 == d1 && digito2 == d2 && digito3 == d3 && digito4 == d4) {
              ganhou = 1;
              contador = 11;
            }

            if (contador > 0) {
              cout << "Restam " << 10 - contador << " tentativas.\n";
            } else {
              ganhou = -1;
              break;
            }

            if (digito1 == d1) {
              cc++;
            }

            if (digito2 == d2) {
              cc++;
            }

            if (digito3 == d3) {
              cc++;
            }

            if (digito4 == d4) {
              cc++;
            }

            if (digito1 == d2 || digito1 == d3 || digito1 == d4) {
              ce++;
            }

            if (digito2 == d1 || digito2 == d3 || digito2 == d4) {
              ce++;
            }

            if (digito3 == d1 || digito3 == d2 || digito3 == d4) {
              ce++;
            }

            if (digito4 == d1 || digito4 == d2 || digito4 == d3) {
              ce++;
            }

            cout << cc << " dígitos estão corretos.\n";
            cout << ce << " dígitos estão corretos, porém, na posição errada.\n";
          }

          if (ganhou == 1) {
            cout<<" █████ ████  ██████  █████ ████    █████ ███ █████ ████  ████████\n"
                  "░░███ ░███  ███░░███░░███ ░███    ░░███ ░███░░███  ░░██░ ░███░░███\n"
                  " ░███ ░███ ░███ ░███ ░███ ░███     ░███ ░███ ░███  ░███  ░███ ░███\n"
                  " ░███ ░███ ░███ ░███ ░███ ░███     ░░███████████   ░███  ░███ ░███\n"
                  " ░░███████ ░░██████  ░░████████     ░░████░████    █████ ████ █████\n"
                  "  ░░░░░███  ░░░░░░    ░░░░░░░░       ░░░░ ░░░░    ░░░░░ ░░░░░░░░░\n"
                  "  ███ ░███\n"
                  " ░░██████\n"
                  "  ░░░░░░\n\n\n";
          
            cout << "Digite qualquer número para voltar ao menu";
            cin >> cont;
            system(CLEAR);
            
          } else if (ganhou == -1 || ganhou == 0) {
            cout << endl;  
            cout << "     ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
                    "     ███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀\n"
                    "     ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼\n"
                    "     ██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀\n"
                    "     ██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼\n"
                    "     ███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄\n"
                    "     ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n"
                    "     ███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼\n"
                    "     ██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼\n"
                    "     ██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼\n"
                    "     ██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼\n"
                    "     ███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄\n"
                    "     ┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼\n\n\n";
          
              cout << "Digite qualquer número para voltar ao menu";
              cin >> cont;
              system(CLEAR);
          }
          break;
      
        case 2:
          cout << "\nDesenvolvedores:    Daniel Henrique da Silva\n"
                  "                    Gabriel Henrique da Silva\n"
                  "                    Jorge Luiz Siemann Pereira\n"
                  "                    Lucas dos Santos Luckow\n"
                  "Professor:          Prof. Rafael Ballotin Martins\n"
                  "Matéria:            Algoritmos e Programação\n"
                  "Maio/2023\n\n";
          cout << "Digite qualquer número para voltar ao menu\n";
          cin >> cont;
          system(CLEAR);
          break;

        case 3:
          break;
        } while (ganhou != 0);
    } 
  } while (menu !=3);
  return 0;
}

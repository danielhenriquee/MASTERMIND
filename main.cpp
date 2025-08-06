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
    system("chcp 65001 > nul"); // To support accents in Windows terminal
  #endif
  setlocale(LC_ALL, "pt_BR.UTF-8");
  srand(time(NULL));
  
  int menu;
  char temp;
  
  do {
    cout << "\n\n\n ██████   ██████   █████████    █████████  ███████████ ██████████ ███████████     ██████   ██████ █████ ██████   █████ ██████████  \n"
            "░░██████ ██████   ███░░░░░███  ███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ░░██████ ██████ ░░███ ░░██████ ░░███ ░░███░░░░███ \n"
            " ░███░█████░███  ░███    ░███ ░███    ░░░ ░   ░███  ░  ░███  █ ░  ░███    ░███    ░███░█████░███  ░███  ░███░███ ░███  ░███   ░░███\n"
            " ░███░░███ ░███  ░███████████ ░░█████████     ░███     ░██████    ░██████████     ░███░░███ ░███  ░███  ░███░░███░███  ░███    ░███\n"
            " ░███ ░░░  ░███  ░███░░░░░███  ░░░░░░░░███    ░███     ░███░░█    ░███░░░░░███    ░███ ░░░  ░███  ░███  ░███ ░░██████  ░███    ░███\n"
            " ░███      ░███  ░███    ░███  ███    ░███    ░███     ░███ ░   █ ░███    ░███    ░███      ░███  ░███  ░███  ░░█████  ░███    ███ \n"
            " █████     █████ █████   █████░░█████████     █████    ██████████ █████   █████    █████     █████ █████ █████  ░░█████ ██████████ \n"   
            "░░░░░     ░░░░░ ░░░░░   ░░░░░  ░░░░░░░░░     ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░     ░░░░░ ░░░░░ ░░░░░    ░░░░░ ░░░░░░░░░░  \n\n"
                                                                               
                                                                               
                                                                               


    cout << "   1.  PLAY \n"
            "   2.  ABOUT\n"
            "   3.  EXIT \n\n\n";
    cin >> menu;
    int won = 0;
    
    switch (menu) {
      case 1:
        int digit1, digit2, digit3, digit4; // Random digits
        int attempt, a1, a2, a3, a4; // Attempts
        int cc, cw; // CdCp = Correct digit && Correct position // CdWp = Correct digit && Wrong position

        do {
          do {
            digit1 = rand() % 6+1; // Generate fisrt 'random' algarism
            digit2 = rand() % 6+1; // Generate second 'random' algarism
            digit3 = rand() % 6+1; // Generate third 'random' algarism
            digit4 = rand() % 6+1; // Generate fourth 'random' algarism
          } while (digit1 == digit2 || digit1 == digit3 || digit1 == digit4 || digit2 == digit3 || digit2 == digit4 || digit3 == digit4); // Ensure there are no repeated digits
          
          int counter;
          for (counter = 1; counter <= 10; counter++) {
            cc = 0;
            cw = 0;

            cout << "\n\nDigit your " << counter << "º attempt: ";
            cin >> attempt;

            a1 = attempt / 1000;
            a2 = attempt / 100 % 10;
            a3 = attempt / 10 % 10;
            a4 = attempt % 10;

            if (digit1 == a1 && digit2 == a2 && digit3 == a3 && digit4 == a4) {
              won = 1;
              counter = 11;
            }

            if (counter > 0) {
              cout << 10 - counter << " attemps remaining.\n";
            } else {
              won = -1;
              break;
            }

            if (digit1 == a1) {
              cc++;
            }

            if (digit2 == a2) {
              cc++;
            }

            if (digit3 == a3) {
              cc++;
            }

            if (digit4 == a4) {
              cc++;
            }

            if (digit1 == a2 || digit1 == a3 || digit1 == a4) {
              cw++;
            }

            if (digit2 == a1 || digit2 == a3 || digit2 == a4) {
              cw++;
            }

            if (digit3 == a1 || digit3 == a2 || digit3 == a4) {
              cw++;
            }

            if (digit4 == a1 || digit4 == a2 || digit4 == a3) {
              cw++;
            }

            cout << cc << " digit are correct.\n";
            cout << cw << " digit are correct, but, at wrong position.\n";
          }

          if (won == 1) {
            cout <<" █████ ████  ██████  █████ ████    █████ ███ █████ ████  ████████\n"
                   "░░███ ░███  ███░░███░░███ ░███    ░░███ ░███░░███  ░░██░ ░███░░███\n"
                   " ░███ ░███ ░███ ░███ ░███ ░███     ░███ ░███ ░███  ░███  ░███ ░███\n"
                   " ░███ ░███ ░███ ░███ ░███ ░███     ░░███████████   ░███  ░███ ░███\n"
                   " ░░███████ ░░██████  ░░████████     ░░████░████    █████ ████ █████\n"
                   "  ░░░░░███  ░░░░░░    ░░░░░░░░       ░░░░ ░░░░    ░░░░░ ░░░░░░░░░\n"
                   "  ███ ░███\n"
                   " ░░██████\n"
                   "  ░░░░░░\n\n\n";
          
            cout << "Type any character to return to the menu";
            cin >> temp;
            system(CLEAR);
            
          } else if (won == -1 || won == 0) {
            cout << endl;  
            cout << "   █████████    █████████   ██████   ██████ ██████████\n"
                    "  ███░░░░░███  ███░░░░░███ ░░██████ ██████ ░░███░░░░░█\n"
                    " ███     ░░░  ░███    ░███  ░███░█████░███  ░███  █ ░ \n"
                    "░███          ░███████████  ░███░░███ ░███  ░██████   \n"
                    "░███    █████ ░███░░░░░███  ░███ ░░░  ░███  ░███░░█   \n"
                    "░░███  ░░███  ░███    ░███  ░███      ░███  ░███ ░   █\n"
                    " ░░█████████  █████   █████ █████     █████ ██████████\n"
                    "  ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░     ░░░░░ ░░░░░░░░░░ \n\n\n" 
                    "    ███████    █████   █████ ██████████ ███████████   \n"   
                    "  ███░░░░░███ ░░███   ░░███ ░░███░░░░░█░░███░░░░░███  \n"  
                    " ███     ░░███ ░███    ░███  ░███  █ ░  ░███    ░███  \n"
                    "░███      ░███ ░███    ░███  ░██████    ░██████████   \n"
                    "░███      ░███ ░░███   ███   ░███░░█    ░███░░░░░███  \n"
                    "░░███     ███   ░░░█████░    ░███ ░   █ ░███    ░███  \n"
                    " ░░░███████░      ░░███      ██████████ █████   █████ \n"
                    "  ░░░░░░░         ░░░      ░░░░░░░░░░ ░░░░░   ░░░░░   \n\n";
          
              cout << "Type any character to return to the menu";
              cin >> temp;
              system(CLEAR);
          }
          break;
      
        case 2:
          cout << "\nDevelopers:    Daniel Henrique da Silva\n"
                  "               Gabriel Henrique da Silva\n"
                  "               Jorge Luiz Siemann Pereira\n"
                  "               Lucas dos Santos Luckow\n"
                  "Professor:     Prof. Rafael Ballotin Martins\n"
                  "Course:        Algorithms and Programming I\n"
                  "May/2023\n\n";
          cout << "Type any character to return to the menu";
          cin >> temp;
          system(CLEAR);
          break;

        case 3:
          break;
        } while (won != 0);
    } 
  } while (menu !=3);
  return 0;
}

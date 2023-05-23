using namespace std;
#include <windows.h>;

#pragma comment(lib, "winmm")
#include "Personaje.h"
#include "DarthVader.h"
#include <iostream>
#include<stdio.h>
//acentos
#include <wchar.h>
#include <locale.h>
//numero aleatorio
#include <cstdlib>
#include <ctime>
#include<Windows.h>
#include <string>
#include <conio.h>
#include <vector>

const int FILAS = 12;
const int COLUMNAS = 7;
char playAgain;
char startPlay;

char choose;
bool heroIsAlive = true;
bool enemyIsAlive = true;
bool pelea = true;


void escribirLetraPorLetra(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        std::cout << texto[i];
        Sleep(10);
    }
    std::cout << std::endl;
}

void gameIntro() {
    SetConsoleOutputCP(65001);

    Sleep(500);

    std::string texto = "  \033[34m     :::         :::     :::      :::   :::::       :::::::::\n"
        "      :+:         :+:     :+:      :+:   :+:         :+:                               \n"
        "     +:+         +:+     +:+      +:+  +:+          +:+                                \n"
        "    +#+         +#+     +#+      +#+:+#            +#++#++#+                           \n"
        "   +#+         +#+     +#+      +#+ +#+           +#+                                  \n"
        "  #+#         #+#     #+#      #+#   #+#         #+#                                   \n"
        " #########    ########        #####  ######     ###########                            \n"
        " \033[0m\n";

    escribirLetraPorLetra(texto);
    system("pause");
    system("cls");
}


void turnos(Personaje& personajes) {
    cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                                       " << endl;
    cout << "   Ahora es el turno de " << personajes.getName() << "    " << endl;
    cout << "                                        " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
};

void turno(darthVader& malo) {

    cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                                       " << endl;
    cout << "   Ahora es el turno de " << malo.getName() << "    " << endl;
    cout << "                                        " << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;

}

void tablero(Personaje& Luke, Personaje& Clone) {

    char tablero[FILAS][COLUMNAS];


    for (int fila = 0; fila < FILAS; fila++) {
        for (int columna = 0; columna < COLUMNAS; columna++) {
            tablero[fila][columna] = '|';
        }
    }


    for (int columna = 0; columna < COLUMNAS; columna++) {
        tablero[0][columna] = "*inicio*"[columna];
    }


    for (int columna = 0; columna < COLUMNAS; columna++) {
        tablero[FILAS - 1][columna] = "*final*"[columna];
    }

    // Posición inicial del personaje
    int filaPersonaje = 1;  // Comenzamos después de la palabra "inicio"
    int columnaPersonaje = COLUMNAS / 2;
    tablero[filaPersonaje][columnaPersonaje] = 'L';

    // Generar las posiciones aleatorias de los clones
    std::vector<std::pair<int, int>> posicionesClone;
    for (int i = 1; i < FILAS - 1; i++) {
        int filaClone = i;
        int columnaClone = std::rand() % (COLUMNAS - 1) + 1;
        posicionesClone.emplace_back(filaClone, columnaClone);
    }

    // Bucle principal del juego
    while (true) {
        // Limpiar la pantalla
        system("cls");

        // Mostrar el tablero
        for (int fila = 0; fila < FILAS; fila++) {
            for (int columna = 0; columna < COLUMNAS; columna++) {
                std::cout << tablero[fila][columna] << " ";

            }
            std::cout << std::endl;

        }

        turnos(Luke);
        turnos(Clone);
   
        // Verificar si el personaje ha llegado al final
        if (filaPersonaje == FILAS - 2) {  // Comprobamos si el personaje está en la penúltima fila
            //system("cls");  // Limpiar la pantalla
            std::cout << "Llegaste al final" << std::endl;
            break;  // Salir del bucle
        }
        // Verificar si el personaje se encuentra con algún clone
        for (const auto& posicionClone : posicionesClone) {
            int filaClone = posicionClone.first;
            int columnaClone = posicionClone.second;

            if (filaPersonaje == filaClone && columnaPersonaje == columnaClone) {
                // Personaje se encontró con un clone
                tablero[filaClone][columnaClone] = 'C';  // Marcar posición del clone en el tablero
                std::cout << "         ¡Un Clone en el pasillo " << filaClone << "!" << std::endl;
                // Realizar las acciones correspondientes cuando se encuentra con un enemigo
                bool continueFight = true;

                cout << "    Derrotalo y Que la Fuerza te Acompañe! " << endl;
                if (enemyIsAlive) {
                    cout << "Quieres reducirlo a cenizas? (s/n)" << endl;
                    
                    do
                    {
                        Luke.battle();
                        pelea = false;
                        if (Clone.getLife() == 0) {
                            enemyIsAlive = false;
                            pelea = false;
                        }
                    } while (choose=='s');
                }

            }
        }

        // Capturar la entrada del usuario
        char tecla = _getch();

        // Actualizar la posición del personaje según la tecla presionada
        switch (tecla) {
        case 72:  // Flecha arriba
            if (filaPersonaje > 1) {  // Evitar que el personaje se mueva hacia la palabra "inicio"
                tablero[filaPersonaje][columnaPersonaje] = '*';
                filaPersonaje--;
                tablero[filaPersonaje][columnaPersonaje] = 'L';
            }
            break;
        case 80:  // Flecha abajo
            if (filaPersonaje < FILAS - 2) {  // Evitar que el personaje se mueva hacia la palabra "final"
                tablero[filaPersonaje][columnaPersonaje] = '*';
                filaPersonaje++;
                tablero[filaPersonaje][columnaPersonaje] = 'L';
            }
            break;
        case 75:  // Flecha izquierda
            if (columnaPersonaje > 0) {
                tablero[filaPersonaje][columnaPersonaje] = '*';
                columnaPersonaje--;
                tablero[filaPersonaje][columnaPersonaje] = 'L';
            }
            break;
        case 77:  // Flecha derecha
            if (columnaPersonaje < COLUMNAS - 1) {
                tablero[filaPersonaje][columnaPersonaje] = '*';
                columnaPersonaje++;
                tablero[filaPersonaje][columnaPersonaje] = 'L';
            }
            break;
        case 'q':
            // Salir del juego si se presiona 'q'
            break;
        }

    }

}

void play(Personaje& Luke, Personaje& Clone,Personaje& DarthVader) {

    do
    {

        std::vector<Personaje> Clones;
        for (int i = 1; i < FILAS - 1; i++) {
            Personaje Clone("Clone", 100, 1, 20, 0);
            Clones.push_back(Clone);
        }

        Luke.inicio();
        tablero(Luke, Clone);

        system("pause");
        system("cls");
        if (Luke.getLife() > Clone.getLife()/*>DarthVader.getLife*/) {
            cout << Luke.getName() << " ha ganado!" << endl;
            cout << "Feliciades!" << endl;
        }
        else {
            cout << Luke.getName() << " Loser!" << endl;
        }

    } while (Luke.getLife() < Clone.getLife());

}

int restart() {
    cout << "Quieres jugar de nuevo? (s/n): ";
    cin >> playAgain;
    if (playAgain == 'n') {
        cout << "Hasta luego!";
        exit(-1);
    }
    system("cls");
    return 0;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    gameIntro();
    do
    {
        Personaje Luke("\033[34mLuke\033[0m", 350, 3, 50, 75);
        Personaje Clone("\x1b[91mClone\x1b[0m", 100, 1, 20, 0);
        darthVader DarthVader("\x1b[91mDarthVader\x1b[0m", 350, 3, 50, 75, 100,100);
        
        play(Luke, Clone, DarthVader);
        restart();

    } while (playAgain == 's');

    return 0;
}

#include <conio.h>
#include <dos.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#define LENGTH 20
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

char labyrinthe[20][20] = {"####################",
 "#################  X",
 "#          #    # ##",
 "#  #####   #       #",
 "#  #    #    #######",
 "#      ######    ###",
 "###        ####  ###",
 "#      # ########  #",
 "#    ####       #  #",
 "#   ########    ####",
 "#  #####         # #",
 "#    ########  #####",
 "#     #######      #",
 "###    ########### #",
 "#      #           #",
 "#  ##  #  ##########",
 "#   #  #           #",
 "##  ## ##########  #",
 "#P                 #",
 "####################",};

int posPlayer[2] = {18,1};
int posEnd[2] = {1,18};
int posDirection[2] = {0,0};

void matrice() {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            printf("%c ", labyrinthe[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void get_position() {
    getch();
    int key = getch();
    if (key == KEY_DOWN) {
        posDirection[0] = 1;
        posDirection[1] = 0;
    }
    else if (key == KEY_UP) {
        posDirection[0] = -1;
        posDirection[1] = 0;
    }
    else if (key == KEY_LEFT) {
        posDirection[0] = 0;
        posDirection[1] = -1;
    }
    else if (key == KEY_RIGHT) {
        posDirection[0] = 0;
        posDirection[1] = 1;
    }
}

int check_direction() {
    if (labyrinthe[posPlayer[0]+posDirection[0]][posPlayer[1]+posDirection[1]] == ' ') {
        return 1;
    }
    else return 0;
}

void move() {
    labyrinthe[posPlayer[0]+posDirection[0]][posPlayer[1]+posDirection[1]] = 'P';
    labyrinthe[posPlayer[0]][posPlayer[1]] = ' ';
    posPlayer[0] += posDirection[0];
    posPlayer[1] += posDirection[1];
}

int main() {
    printf(" *****************************************************
             *                                                   * 
             *                   LABYRINTHE                      *
             *                                                   *                                                     
             *                                                   *   
             *  Objectif : Le joueur  doit atteindre la fin du   * 
             *             labyrinthe en respectant les limites  *
             *             du labyrinthe.    			                 *
             *                                                   *
             *                                                   *   
             *             The player have to go to the end of   *                                     
             *             the parkour marked by the cross "X",  *                                   
             *             you are the player "P".               *   
             *                                                   *
             *****************************************************
                :\n");
    while (posPlayer[0] != posEnd[0] || posPlayer[1] != posEnd[1]) {
        matrice();
        get_position();
        if (check_direction() == 1) move();
        else printf("Veuillez respecter les délimitations du labyrinthe - Respect the limits !\n");
    }
    matrice();
    printf("*****************************************************
             *                                                   *                                                     
             *                VOUS AVEZ GAGNE !!!                *   
             *                                                   * 
             *                    YOU WON  ! !                   *
             *                                                   *
             *                                                   *
             *                 Félicitations !                   *   
             *                                                   *
             *                    Congrats !                     *
             *                                                   *   
             *                                                   *
             *****************************************************");
    return 0;
}

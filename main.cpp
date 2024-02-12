#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <locale>

using namespace std;

void show(char map[9][9]);
bool check_if_out(int nx, int ny);
bool check_colision(char map[9][9], int nx, int ny);
#define pause system("pause>NUL");
#define clear system("cls");
#define get_key _getch();
#define matrix system("color 0A");

// main
int main() {

    matrix;

    // Vars

    char map[9][9];

    int player_x = 2;
    int player_y = 2;
    int next_player_x = 2;
    int next_player_y = 2;
    int player_r = 4;
    int player_hp = 100;
    bool player_alive = 1;

    bool quit = false;

    bool fl = 0;

    // Main

    while(!quit) {

        fl = 0;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {

            map[j][i] = '#';
        
        }
    }

    map[7][1] = 'W';
    map[7][2] = 'W';
    map[7][3] = 'W';
    map[7][4] = 'W';
    map[7][5] = 'W';
    map[7][6] = 'W';
    map[7][7] = 'W';

    cout << "Pl.x = " << player_x << " | Pl.y = " <<  player_y << " | Pl.nx = " <<  next_player_x << " | Pl.ny = " <<  next_player_y;


    map[player_x][player_y] = 'P';


    show(map);

    cout << "Enter a move: ";
    char move = get_key;

    switch (move)
    {
    case 'w':
        next_player_y -= 1;
        player_r = 1;
        break;
    case 'd':
        next_player_x += 1;
        player_r = 2;
        break;
    case 's':
        next_player_y += 1;
        player_r = 3;
        break;
    case 'a':
        next_player_x -= 1;
        player_r = 4;
        break;
    case '?':
        quit=true;
        break;
    
    default:
        break;
    }

    clear;

    if (!check_colision(map, next_player_x, next_player_y) && !check_if_out(next_player_x, next_player_y)) {
    player_x = next_player_x;
    player_y = next_player_y;
} else {
    next_player_x = player_x;
    next_player_y = player_y;
}

    }




    return 0;
}

// void declaration

void show(char map[9][9]) {

    for(int i = 0; i < 9; i++) {
        printf("\n");
        for(int j = 0; j < 9; j++) {

            cout << " " << map[j][i];
        
        }
    }
    std::cout << "\n--------------------\n";
}

bool check_colision(char map[9][9], int nx, int ny) {

    if(map[nx][ny]=='w' || map[nx][ny]=='W') {

        return 1;
        
    } else {

        return 0;

    }

}

bool check_if_out(int nx, int ny) {

    if(nx == 9 || nx == -1 || ny == -1 || ny == 9) {

        return 1;

    } else {
        return 0;
    }

}
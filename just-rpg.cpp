#include <conio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

map<int,string> objects;

struct Player
{
    int map_size=11;
    int x = floor(map_size/2)+1;
    int y = floor(map_size/2)+1;
    string prompt = "\033[42m \033[49m",bg = "\033[44m \033[49m";
    vector<int> bag;
    void show_map(void) {
        system("cls");
        for(int i = 0;i < y;i ++) {
            for(int j = 0;j<map_size*2+1;j++) cout << bg;
            cout << "\n";
        }
        for(int j = 0;j<x;j++) cout << bg;
        cout << prompt;
        for(int j = 0;j<map_size*2-x;j++) cout << bg;
        cout << "\n";
        for(int i = 0;i < map_size-y;i ++) {
            for(int j = 0;j<map_size*2+1;j++) cout << bg;
            cout << "\n";
        }
        cout << "Position: ("  << x << ", " << y << ")" << endl;
        cout << "objects: ";
        for(int i : bag) cout << objects[i] << ";" << endl;
    }
    bool move(char key) {
        switch(key) {
            case 'd':
                x += (x >= map_size*2 ? 0 : 1);
                return true;
            case 'a':
                x -= (x <= 0 ? 0 : 1);
                return true;
            case 'w':
                y -= (y <= 0 ? 0 : 1);
                return true;
            case 's':
                y += (y >= map_size ? 0 : 1);
                return true;
        }
        return false;
    }
};

Player player;
char input;

int main(void) {
    objects[0] = "Sword";
    objects[1] = "Knife";
    objects[2] = "Meat";

    for(int i =0;i<3;i++) player.bag.push_back(i);

    player.show_map();
    while (input != 27){
        if(_kbhit()) {
            input = getch();
            if(player.move(input)) player.show_map();
            _sleep((long)floor(1000/60));
        }
    }
    return 0;
}
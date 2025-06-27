#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct die { //Kostka
    char type;
    int minRoll;
    int maxRoll;
    int effectIndex;
};

struct enemy {
    char* name;
    int diceCount;
    struct die dice[];
};

enum readMode { //Tryb wczytywania danych z pliku
    enemy,
    dice
};

void stringLowercase(char* string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

void queryFileLocation(enum readMode mode, char* fileLocation) { //Pyta o lokację brakującego pliku
                                                                 //lub zamyka program
    char* input;

    puts("Enter the missing ");
    switch(mode) {
        case enemy:
            printf("enemy "); break;
        case dice:
            printf("dice "); break;
    }

    puts("data location or (E)xit program..."); //W nawiasach oznaczone sa
                                                //komendy ktore mozna wpisac
    scanf("%s", input);                                       //i ich skroty
    stringLowercase(input); //Ignoruje wielkosc liter

    if (strcmp(input, "e") || strcmp(input, "exit")) { //Sprawdza czy wpisano e
        puts("Quitting program...");                   //lub exit
        exit(0);
    }

    fileLocation = input;

}

void dataScan(enum readMode mode) { //Pobieranie danych z plików tekstowych

    FILE *gameFile = NULL;
    char* fileLocation;

    switch(mode) {
        case enemy:
            fileLocation = "enemies.txt";
            puts("Loading enemy data...");

            while (gameFile == NULL) {
                gameFile = fopen(fileLocation, "r");
                puts("Enemy data file not found...!");
                queryFileLocation(mode, fileLocation);
            }



    }
}

int main () {

    puts("Starting game...");;
    dataScan(enemy); dataScan(dice);



}

/*
 * stats:
 * speed - increase minimum damage on a die, raises accuracy by 6%
 * attack - increase maximum damage on a die, 12 attack adds an additional die
 * defence - increase maximum defence on a defence die, 12 defence adds an additional defence die
 * wellbeing - increase minimum defence on a die, raises the amount of health by 2
 *
 * piercing attack - when all dice show the same number
 * dodge - when all defence dice show the same number
 *
 * items:
 * glasses - adds 20% accuracy, lost upon receiving a certain amount of damage, always pierces when rolling at least 2 2s
 * double edged sword - increases damage, deals one damage to self
 * equalizer - raises minimal roll
 * d6 - adds a 1 to 6 die
 * d3 - adds a 1 to 3 die
 * splitter - splits 1 die into 2 dice, each only does half of max damage of the original die
 * booze - increases damage, lowers perception

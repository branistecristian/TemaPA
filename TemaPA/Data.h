#ifndef __GUARD_STRUCTS__
#define __GUARD_STRUCTS__

typedef struct{
        char* firstName;
        char* secondName;
        int points;
}Player;

typedef struct{
    int numberPlayers;
    char* Team;
    float Score;
    Player* Jucatori;
}Data;

typedef struct Elem{
    Data Echipa;
    struct Elem* next;
}Node;

typedef struct Elem2{
    Data Echipa;
    struct Elem2 *left;
    struct Elem2 *right;
}Node2;

typedef struct Elem3{
    Data Echipa;
    int height;
    struct Elem3 *left;
    struct Elem3 *right;
}Node3;

#endif
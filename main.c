#include "nbtrees.h"
#include "menu.h"

int main () {
    system("cls");
    Isi_Tree X;
    int MaxNode_X = 8;

    printf("Membuat tree dengan %d node: \n", MaxNode_X);
    Create_tree(X, MaxNode_X);

    nbTreeLobby(X, MaxNode_X);

    return 0;
}
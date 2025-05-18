#include "menu.h"

void nbTreeLobby(Isi_Tree P, int Maks_node) {
    system("cls");
    int pilihan;
    
    do {
        system("cls");
        puts("=======================================");
        puts("=   PROGRAM NON BINARY TREE ARRAY     =");
        puts("=======================================");
        printf("\n");
        PrintTree(P);
        printf("\n=======================================\n");
        puts("1. Traversal PreOrder");
        puts("2. Traversal InOrder");
        puts("3. Traversal PostOrder");
        puts("4. Traversal LevelOrder");
        puts("5. Print Tree");
        puts("6. SearchNode Tree");
        puts("7. Jumlah Daun/leaf");
        puts("8. Mencari level node tree");
        puts("9. Kedalaman tree");
        puts("10. Membandingkan 2 node Tree");
        puts("0. Exit");

        printf("\nPilih Menu : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                system("cls");
                printf("Urutan tree berdasarkan Traversal PreOrder {pr, fs, nb} :\n");
                PreOrder(P);
                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 2:
                system("cls");
                printf("Urutan tree berdasarkan Traversal InOrder {fs, pr, other child} :\n");
                InOrder(P);
                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 3:
                system("cls");
                printf("Urutan tree berdasarkan Traversal PostOrder {fs, nb, pr} :\n");
                PostOrder(P);
                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 4:
                system("cls");
                printf ("Urutan tree berdasarkan Traversal LevelOrder {level by level} :\n");
                Level_order(P, jml_maks);
                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 5:
                system("cls");
                printf ("Isi Non Binary Tree : \n");
                printAllTree(P);
                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 6:
                system("cls");
                infotype info;
                boolean hasil;

                printf("Masukan info dari node yang dicari : ");
                scanf(" %c", &info);
                hasil = Search(P, info);
                printf("\n");

                if (hasil == false) {
                    printf("Node yang anda cari tidak ditemukan!\n");
                } else {
                    printf("Node yang anda cari ditemukan: \n");
                    int i;
                    for (i=1; i<=jml_maks; i++) {
                        if (P[i].info == info) {
                            printf ("--> Indeks ke-%d : \n", i);
                            puts("--------------------------------");
                            printf("info\t\t: %c\n", P[i].info);
                            printf("first son\t: %d\n", P[i].ps_fs);
                            printf("next brother\t: %d\n", P[i].ps_nb);
                            printf("parent\t\t: %d\n", P[i].ps_pr);
                            puts("--------------------------------");
                            printf("\n");
                        }
                    }  
                }

                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 7:
                system("cls");
                int i, jumlah = nbDaun(P);

                printf("Jumlah daun dari Tree : %d\n", jumlah);
                printf("--> ");
                for (i=1;i<=jml_maks;i++) {
                    if(P[i].info != '\0' && P[i].ps_fs == nil) {
                        printf("%c ", P[i].info);
                    }
                }

                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 8:
                system("cls");
                infotype input;
                printf("Masukan info node yang dicari :");
                scanf(" %c", &input);
                printf("\n");

                if (Search(P, input) == false) {
                    printf("Node yang dicari tidak ditemukan!\n");
                } else {
                    printf("Node %c ada di level : %d\n", input, Level(P, input));
                }

                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar();
                break;
            case 9:
                system("cls");
                printf("Kedalaman (depth) dari tree ini yaitu : %d", Depth(P));
                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 10:
                system("cls");
                boolean valid = false;
                infotype data1,data2;

                while (valid == false) {
                    printf("Masukan node ke-1 yang dicari : ");
                    scanf (" %c", &data1);
                    if (Search(P,data1) == false) {
                        printf("\nnode tidak ditemukan!\n...\n");
                    } else {
                        valid = true;
                    }
                }

                valid = false;
                while (valid == false) {
                    printf("Masukan node ke-2 yang dicari : ");
                    scanf (" %c", &data2);
                    if (Search(P,data2) == false) {
                        printf("\nnode tidak ditemukan!\n...\n");
                    } else {
                        valid = true;
                    }
                }
                printf("\nNilai yang lebih besar : %c", Max(data1,data2));

                printf("\nPress ENTER untuk melanjutkan\n"); 
                getchar(); getchar();
                break;
            case 0:
                printf("\nKeluar dari program... \n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } while (pilihan != 0);
}

void printAllTree(Isi_Tree P) {
    printf("Seluruh node pada Non Binary Tree: \n");
    int i;
    for (i=1; i<=jml_maks; i++) {
        if (P[i].info != '\0') {
            printf ("--> Indeks ke-%d : \n", i);
            puts("--------------------------------");
            printf("info array ke %d\t\t: %c\n", i, P[i].info);
            printf("first son array ke %d\t: %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d\t: %d\n", i, P[i].ps_nb);
            printf("parent array ke %d\t: %d\n", i, P[i].ps_pr);
            puts("--------------------------------");
            printf("\n");
        }
    }
}


/* COP 3502C Assignment 3
This program is written by: Aaron Burgess */

/*
    PROGRAM 1 (returns a single number)
    output a total number of valid permutations for the guests
*/

#include <stdio.h>
#include <string.h>
#define LEN 20
#define MAXP 10

typedef struct guest { //struct for the people watching the game
    char name[LEN];
    int snacks;
}Guest;

//function prototypes
void countPerms(Guest *perm, int *used, int k, int numP, Guest *attendees, int conflicts[MAXP][MAXP]);
int checkSnacks(Guest *perm, int k, int numP);
int checkConflict(Guest *perm, Guest *attendees, int conflicts[MAXP][MAXP], int numP);
int binarySearchName(char *names[], char key[LEN], int numP);
int binarySearchGuest(Guest *attendees, Guest p, int numP);

//global variables
int count = 0;
int conflicts[MAXP][MAXP];

int main(void) {
    int numP, illegal; //number of people and num of illegal pairings
    scanf("%d %d", &numP, &illegal);

    Guest attendees[numP]; //array of people attending
    for (int i = 0; i < numP; i++) {
        scanf("%s %d", attendees[i].name, &attendees[i].snacks); //scan them in
    }

    char *names[numP]; //alphabetical order list of names for binSearch
    for (int i = 0; i < numP; i++) {
        names[i] = attendees[i].name;
    }

    for (int i = 0; i < numP; i++) {
        for (int j = 0; j < numP; j++) {
            conflicts[i][j] = 1; //fill up conflicts matrix
        }
    }

    for (int i = 0; i < illegal; i++) {
        char con1[LEN];
        char con2[LEN];
        scanf("%s %s", con1, con2);

        int in1 = binarySearchName(names, con1, numP);
        int in2 = binarySearchName(names, con2, numP);
        if (in1 == -1 || in2 == -1) {
             printf("No such conflict\n");
        }
        conflicts[in1][in2] = conflicts[in2][in1] = 0; //recording the conflict itself
    }

    Guest perm[numP]; //build and store the permutation
    int used[numP]; //tracking which index is used
    for (int i = 0; i < numP; i++) used[i] = 0; //make used all 0's

    countPerms(perm, used, 0, numP, attendees, conflicts); //recursive function to count the total number of valid permutations

    printf("%d\n", count); //printing updated global variable
}

void countPerms(Guest *perm, int *used, int k, int numP, Guest *attendees, int conflicts[MAXP][MAXP]) {
    //once you get a permutation, check it's validity. If valid, increase count of valid perms
    if (k==numP) { //when you get a perm
        //if (checkConflict(perm, attendees, conflicts, numP)) { //if there is no conflict, it's valid
            count++;
        //}
    }

    int i;
    for (i = 0; i<numP; i++) {
        if (!used[i]) { //if it's not used
            used[i] = 1; //use it

            //add it to the permutation
            strcpy(perm[k].name, attendees[i].name);
            perm[k].snacks = attendees[i].snacks;

            if (checkSnacks(perm, k, numP)){ //if snack is fine, run it recursively to finish the permutation
                countPerms(perm, used, k+1, numP, attendees, conflicts);
            }
            used[i] = 0; //unuse that guest in the permutation
        }
    }
}


int checkSnacks(Guest *perm, int k, int numP) { //run after added to a perm
    /*
     *  1 is someone with a snack, 0 is someone without a snack
     *  101  good, everyone has a snack
     *  1001 good, everyone has a snack
     *  10001 bad. guy in the middle has no snack
     *  001 bad, edge has no snack
     *  if k is 1, check perm[k-1] and perm[k] for double 0's (invalid)
     *  if k>1, check for three repeating 0s (invalid)
     *  else valid
    */
    if (k==1 || k == numP-1) { //if the edge is a double 0 (001... or ...001)
        if (perm[k-1].snacks == 0 && perm[k].snacks == 0) return 0;
    }
    if (k>1) { //if there are 3 repeating 0's, invalid
        if (perm[k-2].snacks == 0 && perm[k-1].snacks == 0 && perm[k].snacks == 0) return 0;
    }
    return 1;
}

int checkConflict(Guest *perm, Guest *attendees, int conflicts[MAXP][MAXP], int numP){
    //one hater hates the other hater. If two haters hate each other, they cant sit together
    int check[numP];
    for (int i = 0; i < numP; i++) {
        check[i] = binarySearchGuest(attendees, perm[i], numP); //3 1 5 4 2 (for example)
    }

    int valid = 1;
    for (int i = 0; i < numP-1; i++) { //for the permutation
        if (conflicts[check[i]][check[i+1]] == 0) { //if two haters are next to each other
            valid = 0;
            break; //it's alr invalid if it passed the if statement
        }
    }
    return valid;
}

int binarySearchName(char *names[], char key[LEN], int numP) { //look for the name itself in the alphabetized names list
    int left = 0, right = numP - 1, mid;
    while (left <= right) {
        mid = (left+right)/2;
        if (strcmp(names[mid], key) == 0) return mid;
        if (strcmp(names[mid], key) > 0) right = mid - 1;
        if (strcmp(names[mid], key) < 0) left = mid + 1;
    }
    return -1;
}

int binarySearchGuest(Guest *attendees, Guest p, int numP) { //look for the Guest in the alphabetized Guest list
    int left = 0, right = numP - 1, mid;
    while (left <= right) {
        mid = (left+right)/2;
        if (strcmp(attendees[mid].name, p.name) == 0) return mid;
        if (strcmp(attendees[mid].name, p.name) > 0) right = mid - 1;
        if (strcmp(attendees[mid].name, p.name) < 0) left = mid + 1;
    }
    return -1;
}
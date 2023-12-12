//
// Created by ansarimn on 12/11/23.
//

#ifndef TREES_AND_GRAPHS_ELLE0_H
#define TREES_AND_GRAPHS_ELLE0_H

#endif //TREES_AND_GRAPHS_ELLE0_H


#include "stack_queue_ADT.h"


#define LINKS 4




typedef struct elle {
    struct stack_ADT * fields;
    struct stack_ADT * dates;
    int data, BF, mark;

    struct elle * link [LINKS];
} elle;


typedef struct tree {
    struct elle * root;
} tree;


struct elle * init_elle (int data);
struct tree * init_tree ();
void update_BF (struct elle * parent, int r);
void make_child (struct elle * parent, struct
        elle * child, int r);
void insert_as (struct elle * parent, int r,
        int a);
int whichchild (struct elle * root, struct elle
        * child);
struct tree * generate_tree();









struct elle * init_elle (int data) {
    struct elle * te0 = (struct elle *) malloc (sizeof (struct elle));
    int i = 0;

    te0 -> data = data;
    te0 -> BF = 0;
    te0 -> mark = 0;
    te0 -> fields = init_stack ();
    te0 -> dates = init_stack ();

    while (i < LINKS) {
        te0 -> link [i] = (struct elle*) malloc (sizeof (struct elle));
        te0 -> link [i] = NULL;
        i ++;
    }

    return te0;
}


struct tree * init_tree () {
    struct tree * te0 = (struct tree *) malloc (sizeof (struct tree));

    return te0;
}





void update_BF (struct elle * parent, int r) {
    if (r == 0) {
        parent -> BF ++;
    }


    else if (r == 1) {
        parent -> BF --;
    }
}




void make_child (struct elle * parent, struct elle * child, int r) {
    if (r > 1) {
        stderror("Invalid Link;");
    }

    else {
        parent -> link [r] = child;
        child -> link [2] = parent;
        update_BF (parent, r);
    }

}


void insert_as (struct elle * parent, int r, int a) {
    struct elle *ptrnew;

    ptrnew = init_elle (a);


    if (r > 1) {
        stderror("Invalid Link;");
    }

    else {
        parent -> link [r] = ptrnew;
        ptrnew -> link [2] = parent;
    }

    update_BF (parent, r);
}


int whichchild (struct elle * root, struct elle * child) {
    // returns int as per the child;
    // returns 0 if given child is left child;
    // returns 1 if given child is right child;

    int i;
    i = 0;

    while (i < 2) {
        if (root->link[i] == child) {
            break ;
        }
        i++;
    }

    return i;
}




struct tree * generate_tree() {
    // generates arr new tree;

    struct tree* tree;
    struct elle* te0, * root;
    int i, j, k;

    root = init_elle (0);
    te0 = init_elle (0);

    tree = (struct tree *) malloc (sizeof (struct tree));
    tree -> root = root;

    insert_as (root, 0, 1);
    insert_as (root, 1, 2);

    k = 3;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            te0 = root -> link [i];
            insert_as (te0, j, k);
            k ++;
        }
    }

    k = 7;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            te0 = root -> link [i] -> link [j];
            insert_as (te0, j, k);
            k ++;
        }
    }

    return tree;
}



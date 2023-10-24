#pragma once
#include"Header.h"

class Car
{
    char pw[8];
    int speed = 7;
    string sds[3];
    string sd[4];
public:
    void creatPassword();
    void readPassword();
    void readSafeDistance();
    bool comparePassword(char a[]);
    bool checkIsNumberOnly();
    void setupSafeDistanceSpeed();
    bool checkSafeDistanceSpeed(string a[], int n);
    void P_mode();
    void R_mode();
    void N_mode();
    void D_mode();
    void selectionSort();

};

void bubbleSort(char a[], int n);
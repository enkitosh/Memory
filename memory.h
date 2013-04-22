#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ctables/Ctables.h"


typedef struct {
    int wide;
    int VPO;
    int VPN;
    int TLBI;
    int TLBT;

    /*Indexes*/
    int VPO_i;
    int VPN_i;
    int TLBI_i;
    int TLBT_i;
}virtual_addr;


typedef struct {
    int wide_p;
    int PPO;
    int PPN;
}physical_addr;


/********************TABLES****************************************/

void fill_table(virtual_addr *v, physical_addr *p, char **argm, int width, int type);
void print_table(virtual_addr *v,physical_addr *p, int width, int type);

/********************EXTRA*****************************************/
void print_ex(char *message, int value, char *color_s);

#endif

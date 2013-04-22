#include "cache.h"


void 
fill_table(virtual_addr *v, physical_addr *p, char **argm, int width, int type)
{
    int page_size           = atoi(argm[2]);
    int index_nr            = atoi(argm[3]);
    double get_PO           = log(page_size) * M_LOG2E;

    if(type == 0) {

        v -> wide = width;          /*Store virtual address bit width*/
        v -> VPO  = get_PO + 1;     /*we need + 1 for rounding*/
        v -> VPN  = width - get_PO;
        v -> TLBI = index_nr / 2;
        v -> TLBT = v -> VPN - v -> TLBI;


        /*Calculate indexes*/

        v -> VPO_i  = 0;
        v -> VPN_i  = width - v -> VPN;
        v -> TLBI_i = v -> VPN_i;   /*same*/
        v -> TLBT_i = v -> TLBI_i + v -> TLBI;

    } else {
        p -> wide_p = width;
        p -> PPO = get_PO + 1;
        p -> PPN = width - get_PO;
    }
}

void 
print_table(virtual_addr *v, physical_addr *p, int width, int type) 
{

    int i;
    int ind            = width-1;
    int ops[MAX_OPS]   = {FREELY, COLORFUL, CENTER, ENUMERATE_REVERSED};
    int ops_2[MAX_OPS] = {FREELY, COLORFUL, CENTER, ENUMERATE_REVERSED};
   
    table_t *t_vp, *t_tl;
    t_vp = initialize_table(ops, 1, width);
    t_tl = initialize_table(ops_2, 1, width);

    if(type == 0) {
    
    printf("Components of the virtual address \n"); 
        for(i = 0; i < v -> wide; i++) {
            if(i < v -> VPO) {
                color_me(t_vp, 0, ind, MAGNETA);
            } else {
                color_me(t_vp, 0, ind, BLUE);    
            }
                add_freely(t_vp, 0, ind, "O");
                ind--;   
        }

        ind = width - 1;
    
        for(i = 0; i < v -> wide; i++) {   
            if(i >= v -> TLBI_i && i < v -> TLBT_i) {
                    color_me(t_tl, 0, ind, RED);
            } else if(i >= v -> TLBT_i && i <= v -> wide) {
                    color_me(t_tl, 0, ind, GREEN);
              }
                add_freely(t_tl, 0, ind, "O");
                ind--;   
         }

    /*Print tables*/
    print(t_vp);
    printf("\n");
    print(t_tl);
    printf("\n");

    /*Print additional information*/
    print_ex("VPO", v -> VPO, MAGNETA);
    print_ex("VPN", v -> VPN, BLUE);
    print_ex("TLB index",v -> TLBI, RED);
    print_ex("TLB tag",v -> TLBT ,GREEN);
   
    printf("\n");

    } else {
        for(i = 0; i < p -> wide_p; i++) {
            if(i < p -> PPO) {
                color_me(t_vp, 0, ind, MAGNETA);
            } else {
                color_me(t_vp, 0, ind, BLUE);    
              }
                add_freely(t_vp, 0, ind, "O");
                ind--;   
        }

        
        print(t_vp);
        printf("\n");
        print_ex("PPO", p -> PPO, MAGNETA);
        print_ex("PPN", p -> PPN, BLUE);

        printf("\n");

        
    }

    free_table(t_vp);
    free_table(t_tl);
}


void 
print_ex(char *message,int value, char *color_s) 
{

        printf("%s = %s %d %s | ", message, color_s, value , DEFAULT);
}


int main(int argc, char **argv) {

    int v_width          = 0;
    virtual_addr *virt   = malloc(sizeof(virtual_addr));
    physical_addr *physc = malloc(sizeof(physical_addr));

    if(argc < 5) {
        printf("Usage: ./cache [-virtual/physical] [-Page size] [-Index] [-Width]\n");
        exit(1);
    }
    
    v_width = atoi(argv[4]);
    
    if((strcmp(argv[1], "virtual")) == 0) {

        fill_table(virt, physc, argv, v_width,0);
        print_table(virt, physc, v_width,0);

    } else if((strcmp(argv[1], "physical")) == 0) {
        
        fill_table(virt, physc, argv, v_width,1);
        print_table(virt, physc, v_width, 1);
    }


    free(virt);
    free(physc);





    


    return (0);
}

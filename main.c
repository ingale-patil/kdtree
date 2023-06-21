#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "kdtree.h"


int main()
{
    
    kdtree kd1;
    init(&kd1);
    float x,y,r;
    int i,loop_is_on=1;
    FILE *fp;
    fp=fopen("random.txt","r");
    for(int i=0;i<200;i++){
        fscanf(fp,"%f %f",&x,&y);
        insert(&kd1,x,y,0);
    }
    //insert(&kd1,8,15,0);
    //insert(&kd1,5,7,0);
    //insert(&kd1,5,10,0);
    
    //insert(&kd1,4,6,0);
    //insert(&)
    //insert(&kd1,11,12,0);
    //insert(&kd1,13,11,0);
    //insert(&kd1,9,10,0);
    //insert(&kd1,7,8,0);
    //insert(&kd1,7,6,0,"i");
    //insert(&kd1,10,21,0,"j");
    //insert(&kd1,14,11,0,"k");
    //inorder(kd1);
    //insert(&kd1,7,7,0,"l");
    //printf("%d",kd1->x);
    //printf("%d",kd1->left->left->x);
    //inorder(kd1);
    //search(kd1,7,7,0);
    //search(kd1,93,540);
    //preorder(kd1);
    while(loop_is_on){
    printf("\nYou can perform following functions on t. To select a function, enter the function number as input.\n");
        printf("Enter 0 to exit the code.\n");
        printf("1. Insert a node to the KD-Tree.\n");
        printf("2. Know the nearest points.\n");
        printf("3. To know Most nearest Node.\n");
        printf("4. Pre-order traversal of all points.\n");
        //printf("5. preorder(): Postorder traversal\n");
        printf("User input: ");
        scanf("%d", &i);

        switch (i)
        {
        case 0:
            loop_is_on = 0;
            break;
        
        case 1:
            printf("Enter X Coordinate ");
            scanf("%f",&x);
            printf("Enter Y Coordinate ");
            scanf("%f",&y);
            insert(&kd1,x,y,0);
            break;
            

        case 2:
            printf("\nEnter X Coordinate of Query Point ");
            scanf("%f", &x);
            printf("\nEnter Y Coordinate of Query Point ");
            scanf("%f", &y);
            printf("\nEnter radius R ");
            scanf("%f", &r);
            
            search(kd1,x,y,r);
            printf("\n");
            break;
        
        case 3:
            nearest_neighbour(kd1,x,y);
            printf("\n");
            break;

        case 4:
            printf("\n");
            inorder(kd1);
            printf("\n");
            break;
        
        //case 5:
        //    printf("\n");
        //   preorder(t);
         //   printf("\n");
          //  break;

        
        default:
            printf("\nInvalid Input!");
            break;
        }
    }
    return 0;
}

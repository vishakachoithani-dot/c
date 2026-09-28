#include <stdio.h>
int main(){
    int n,i;
    int current_floor = 0;
    printf("Enter the number of floor requests: ");
    scanf("%d",&n);
    for (i=0;i<n;i++) 
    {
        int requested_floor;
        printf("Enter the requested floor: ");
        scanf("%d",&requested_floor);
        if (requested_floor > current_floor){
            printf("Moving up\n");    
        }
        else if (requested_floor < current_floor){
            printf("Moving down\n");    
        }
        else{
            printf("Doors opening\n");
        }
        current_floor = requested_floor;

    }
    return 0;
}

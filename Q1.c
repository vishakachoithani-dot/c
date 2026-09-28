#include <stdio.h>
int main(){
    char season;
    printf("Enter the season(1.Peak or 2.Offpeak): ");
    scanf(" %c",&season);
    char room_type;
    printf("Enter the room type(1.Deluxe or 2.Suite or 3.Standard): ");
    scanf(" %c",&room_type);
    int nights;
    printf("Enter night stayed: ");
    scanf("%d",&nights);
    if (season == '1'){
        int rate,total;
        rate = (room_type == '1')? 8000:((room_type == '2')? 12000: 5000);
        total = rate * nights;
        if (nights > 7){
            int final_total;
            final_total = total * 0.85;
            printf("Final price: %d",final_total); 
    }
        else{
            printf("Final price: Rs.%d",total);
        }
    }
    else{
        int rate,total;
        rate = (room_type == '1')? 5000:((room_type == '2')? 8000: 3000);
        total = rate * nights;
               if (nights > 7){
            int final_total;
            final_total = total * 0.85;
            printf("Final price: %d",final_total); 
    }
        else{
            printf("Final price: %d",total);
        }       
    }
    return 0;
}


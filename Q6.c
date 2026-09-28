#include <stdio.h>
#include <string.h>
int main(){
    char vehicle,membership,disabled_priority,available;
    int required_charging_level,battery_charge,parking_duration,current_time;
    printf("enter vehicle type (E for electrical, H for hybrid): ");
    scanf(" %c",&vehicle);
    printf("Do you have a membership (Y/N): ");
    scanf(" %c",&membership);
    printf("Do you have disablility priority(Y/N): ");
    scanf(" %c",&disabled_priority);
    printf("is the battery station available(Y/N): ");
    scanf(" %c",&available);
    printf("Enter required charging percentage: ");
    scanf("%d",&required_charging_level);
    printf("Enter battery charge level: ");
    scanf("%d",&battery_charge);
    printf("Enter parking duration: ");
    scanf("%d",&parking_duration);
    printf("Enter the current time: ");
    scanf("%d",&current_time);
    if (available == 'N'){
        if (vehicle == 'H'){
            printf("Charging unavailable - Parking only");
        }
        else{
            printf("No charging slot available");
        }    
    }
    else if (!(vehicle == 'E' || (vehicle == 'H' && battery_charge<40))){
        printf("vehicle does not qualify for EV charging");
    }
    else{
        int required_charging = required_charging_level - battery_charge;
        if (required_charging_level<=battery_charge){
            printf("No charging required");
        }
        char priority;
        if (battery_charge <= 15 && required_charging_level>=80){
            priority = "E";
        }
        else if (disabled_priority == 'Y' || battery_charge <= 30){
            priority = "P";
        }
        else{
            priority = "N";
        }
        int cc,discount_c;
        char status[20];
        if (current_time > 10 || current_time < 5){
            cc = 35 * required_charging;
            strcpy(status, "off peak");
            if (membership == 'Y' && priority != 'E'){
                discount_c = cc * 0.20;
                cc = cc - discount_c;
            }}
        else{
            cc = 50 * required_charging;
            strcpy(status, "peak");
            discount_c = cc * 0.10;
            cc = cc - discount_c;
        }
        int pc, discount_p;
        if (parking_duration <= 2){
            pc = 200
        }
        else if (parking_duration>2 && parking_duration<=5){
            pc = 400;
        }
        else {
            pc = 700;
        }
        if (disabled_priority == 'Y'){
            pc = 0;
        }
        else if (membership == 'Y'){
            discount_p = pc * 0.20;
            pc = pc - discount_p;
        }
        if (parking_duration > 8){
            printf("long-stay warning: please relocate your vehicle after charging!");
        }
        else{
            printf("standard parking duration");
        }
        printf("Vehicle type: %c",vehicle);
        printf("current battery percentage: %d",battery_charge);
        printf("required charging: %d",required_charging);
        printf("priority: %c",priority);
        printf("status: %c",status);
        printf("charging cost: %d",cc);
        printf("parking cost: %d",pc);
        printf("total payable: %d",cc+pc);
        
    }
    
}

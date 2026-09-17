#include <stdio.h>
int main(){
    char city,country, area,grade[50];
    int population;
    printf("enter the city: ");
    scanf("%s",&city);
    printf("enter the country: ");
    scanf("%s",&country);
    printf("enter the area: ");
    scanf("%s",&area);
    printf("enter the grade: ");
    scanf("%s",&grade);
    printf("enter the population: ");
    scanf("%d",&population);
    printf("country: %s",country);
    printf("city: %s",city);
    printf("area: %s",area);
    printf("grade: %s",grade);
    printf("population: %d",population);
}
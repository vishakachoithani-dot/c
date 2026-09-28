#include <stdio.h>
int main(){
    int num_of_students,i;
    printf("Enter number of students: ");
    scanf("%d",&num_of_students);
    for (i=0;i<num_of_students;i++){
        int sub1,sub2,sub3,sub4,sub5,sum, avg = 0;
        printf("Enter the marks of sub1: ");
        scanf("%d",&sub1);
        printf("Enter the marks of sub2: ");
        scanf("%d",&sub2);
        printf("Enter the marks of sub3: ");
        scanf("%d",&sub3);
        printf("Enter the marks of sub4: ");
        scanf("%d",&sub4);
        printf("Enter the marks of sub5: ");
        scanf("%d",&sub5);
        if (sub1<33 || sub2<33 || sub3<33 || sub4<33 || sub5<33){
            printf("Fail-subject deficiency.\n");
        }
        sum = sub1+sub2+sub3+sub4+sub5;
        avg = sum/5;
        if (avg >= 80){
            printf("Distinction\n");
        }
        else if (avg >= 60 && avg < 80){
            printf("Pass\n");
        }
        else {
            printf("Fail\n");
        }
    }
    return 0;
}

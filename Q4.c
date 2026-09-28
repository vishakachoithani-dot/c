#include <stdio.h>
int main(){
    int quantity,price_per_item,discount,tax;
    printf("Enter the quantity: ");
    scanf("%d",&quantity);
    printf("Enter the price: ");
    scanf("%d",&price_per_item);
    printf("Enter the discount percentage: ");
    scanf("%d",&discount);
    printf("Enter the tax percentage: ");
    scanf("%d",&tax);
    if (quantity <= 0 || price_per_item <= 0 || discount<=0 || tax <= 0){
        printf("invaid input");
    }
    int sub_total = quantity * price_per_item;
    int discounted_amount = sub_total - (sub_total*discount)/100;
    int final_bill = (discounted_amount + discounted_amount*tax)/100;
    printf("Final Bill is: %d",final_bill);
    return 0;

}

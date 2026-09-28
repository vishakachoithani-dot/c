#include <stdio.h>
int main()
{
    int capA = 20;
    int capB = 40;
    int capC = 15;
    int occA = 0;
    int occB = 0;
    int occC = 0;
    int carsParked = 0;
    int bikesParked = 0;
    int vansParked = 0;
    int rejectedVehicles = 0;
    int N, i;
    char vehicle, category, permit, emergency;
    char zone;
    int assigned;
    int remA, remB, remC;
    printf("Enter number of vehicles expected to arrive: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++){
        printf("Enter vehicle type (C = Car, B = Bike, V = Van): ");
        scanf(" %c", &vehicle);
        while (vehicle != 'C' && vehicle != 'B' && vehicle != 'V')
        {
            printf("Invalid vehicle type\n");
            printf("Enter vehicle type (C = Car, B = Bike, V = Van): ");
            scanf(" %c", &vehicle);
        }

        printf("Enter user category (F = Faculty, S = Student, G = Visitor/Guest): ");
        scanf(" %c", &category);
        while (category != 'F' && category != 'S' && category != 'G')
        {
            printf("Invalid user category\n");
            printf("Enter user category (F = Faculty, S = Student, G = Visitor/Guest): ");
            scanf(" %c", &category);
        }
        printf("Enter permit status (Y = Valid Permit, N = No Valid Permit): ");
        scanf(" %c", &permit);
        while (permit != 'Y' && permit != 'N')
        {
            printf("Invalid Permit value\n");
            printf("Enter permit status (Y = Valid Permit, N = No Valid Permit): ");
            scanf(" %c", &permit);
        }
        emergency = 'N';
        if (permit == 'N')
        {
            printf("Is the vehicle an emergency vehicle? (Y/N): ");
            scanf(" %c", &emergency);

            while (emergency != 'Y' && emergency != 'N')
            {
                printf("Invalid emergency value\n");
                printf("Is the vehicle an emergency vehicle? (Y/N): ");
                scanf(" %c", &emergency);
            }
        }
        else
        {
            printf("Emergency status is not required.\n");
        }
        if (permit == 'N' && emergency == 'N')
        {
            printf("Rejected: Invalid Permit\n");
            rejectedVehicles++;
            continue;
        }

        assigned = 0;
        zone = ' ';

        if (category == 'F')
        {
            if (vehicle == 'V')
            {
                if ((capA - occA) >= 2)
                {
                    zone = 'A';
                    assigned = 1;
                }
                else
                {
                    printf("Rejected: No available Space\n");
                    rejectedVehicles++;
                }
            }
            else
            {
                if ((capA - occA) >= 1)
                {
                    zone = 'A';
                    assigned = 1;
                }
                else
                {
                    printf("Rejected: No available Space\n");
                    rejectedVehicles++;
                }
            }
        }
        else if (category == 'S')
        {
            if (vehicle == 'V')
            {
                if ((capC - occC) >= 2)
                {
                    zone = 'C';
                    assigned = 1;
                }
                else
                {
                    printf("Rejected: No Suitable Zone\n");
                    rejectedVehicles++;
                }
            }
            else 
            {
                if ((capB - occB) >= 1)
                {
                    zone = 'B';
                    assigned = 1;
                }
                else
                {
                    printf("Rejected: No available Space\n");
                    rejectedVehicles++;
                }
            }
        }
        else
        {
            if (vehicle == 'V')
            {
                if ((capC - occC) >= 2)
                {
                    zone = 'C';
                    assigned = 1;
                }
                else
                {
                    printf("Rejected: No available Space\n");
                    rejectedVehicles++;
                }
            }
            else
            {
                if ((capC - occC) >= 1)
                {
                    zone = 'C';
                    assigned = 1;
                }
                else
                {
                    printf("Rejected: No available Space\n");
                    rejectedVehicles++;
                }
            }
        }
        if (assigned)
        {
            if (vehicle == 'V')
            {
                if (zone == 'A') occA += 2;
                else if (zone == 'B') occB += 2;
                else occC += 2;
                vansParked++;
            }
            else if (vehicle == 'C')
            {
                if (zone == 'A') occA += 1;
                else if (zone == 'B') occB += 1;
                else occC += 1;
                carsParked++;
            }
            else
            {
                if (zone == 'A') occA += 1;
                else if (zone == 'B') occB += 1;
                else occC += 1;
                bikesParked++;
            }
            if (zone == 'A')
            {
                remA = capA - occA;
                printf("Vehicle assigned to Zone A. Remaining capacity: %d\n", remA);
            }
            else if (zone == 'B')
            {
                remB = capB - occB;
                printf("Vehicle assigned to Zone B. Remaining capacity: %d\n", remB);
            }
            else
            {
                remC = capC - occC;
                printf("Vehicle assigned to Zone C. Remaining capacity: %d\n", remC);
            }
        }
    }
    printf("\n========== SUMMARY ==========\n");
    printf("Total Successfully Parked Cars: %d\n", carsParked);
    printf("Total Successfully Parked Bikes: %d\n", bikesParked);
    printf("Total Successfully Parked Vans: %d\n", vansParked);
    printf("Total Rejected Vehicles: %d\n", rejectedVehicles);
    printf("Remaining Capacity of Zone A: %d\n", capA - occA);
    printf("Remaining Capacity of Zone B: %d\n", capB - occB);
    printf("Remaining Capacity of Zone C: %d\n", capC - occC);

    return 0;
}

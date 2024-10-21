#include <stdio.h>

void towerofHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    towerofHanoi(numDisks-1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", numDisks, source, destination);
    
    towerofHanoi(numDisks-1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks); 
    towerofHanoi(numDisks, 'A', 'B', 'C'); 
    return 0;
}
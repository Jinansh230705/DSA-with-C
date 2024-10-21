// Tower of Hanoi recursive way
// no id step/moves 2^n-1
// time complexity 2^n
#include <stdio.h>
// Recursive function to solve Tower of Hanoi problem
void towerofHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    // Move numDisks-1 disks from source to auxiliary using destination as auxiliary peg
    towerofHanoi(numDisks-1, source, destination, auxiliary);

    // Move the bottom disk from source to destination
    printf("Move disk %d from %c to %c\n", numDisks, source, destination);

    // Move the numDisks-1 disks from auxiliary to destination using source as the auxiliary peg
    towerofHanoi(numDisks-1, auxiliary, source, destination);
}

void do(){
	 int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks); 
    towerofHanoi(numDisks, 'A', 'B', 'C'); 
}
int main() {
    do();
    return 0;
}

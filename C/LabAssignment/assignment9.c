#include<stdio.h>

// struct Node {
//     int data;
//     struct Node * next;
// };

int main(){
    // struct Node node1;
    // struct Node node2;
    // struct Node node3;
    // struct Node node4;

    // node1.data = 11;
    // node1.next -> node2;


    int num = 10;

    int * ptr = &num;
    int* ptr2 = &num;

    printf("ptr: %d, ptr2: %d", ptr, ptr2);
}
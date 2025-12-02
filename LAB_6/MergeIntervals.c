// #include <stdio.h>

// int stack[10][2],intervel[10][2];
// int top_row = -1, count = 0, stack_count = 0;

// void push(int n1, int n2){
//     if(top_row >= 10){
//         printf("stack ovreflow");
//         return;
//     }
//     ++top_row;
//     stack[top_row][0] = n1;
//     stack[top_row][1] = n2;
// }

// // int pop(){
// //     if(top_row == -1){
// //         printf("stack underflow");
// //     }
// //     else{
// //         return stack[top--];
// //     }   
// // }
    
// void mergeInterval(){

//     int temp[1][2];

//     for(int i=0; i<count; i++){
//         for(int j=0; j<count-1; j++){
//             if(intervel[j][0] > intervel[j+1][0]){
//                 temp[0][0] = intervel[j][0];
//                 temp[0][1] = intervel[j][1];
//                 intervel[j][0] = intervel[j+1][0];
//                 intervel[j][1] = intervel[j+1][1];
//                 intervel[j+1][0] = temp[0][0];
//                 intervel[j+1][1] = temp[0][1];
//             }
//         }
//     }

//     int max_j=-1;
//     for(int i=0; i<count; i++){
//         for(int j=i+1; j<count; j++){
//             if((intervel[i][1]>=intervel[j][0]) && (intervel[i][1]>intervel[j][1] || intervel[i][1]<intervel[j][1])){
//                 max_j = j;
                
//             }
//         }
//         if(intervel[max_j][1]>intervel[i][1]){
//             if(top_row != -1 && (stack[top_row][0]<=intervel[max_j][0] && stack[top_row][1]>=intervel[max_j][1])){
//                 continue;
//             }
//             else if(max_j != -1){
//                 push(intervel[i][0],intervel[max_j][1]);
//                 stack_count++;
//                 max_j = -1;
//             }
//         }
//         else{
//             if(top_row != -1 && (stack[top_row][0]<=intervel[i][0] && stack[top_row][1]>=intervel[i][1])){
//                 continue;
//             }
//             else if(max_j != -1){
//                 push(intervel[i][0],intervel[i][1]);
//                 stack_count++;
//                 max_j = -1;
//             }
//         }
//     }
// }


// void main(){
    
//     int n1,n2;
//     printf("Enter intervals (dot(.) seprated)(-1,-1 for stop) :\n");
//     for(int i=0; i<10; i++){
//         printf(">");
//         scanf("%d.%d",&n1,&n2);
//         if(n1 == -1 && n2 == -1){
//             break;
//         }
//         intervel[i][0] = n1;
//         intervel[i][1] = n2;
//         count++;
//     }

//     mergeInterval();
//     printf("\nAnswer :\n");
//     for(int i=0; i<stack_count; i++){
//         printf("%d,%d\n",stack[i][0],stack[i][1]);
//     }
// }

#include <stdio.h>

struct Interval {
    int start;
    int end;
};

// Bubble sort based on start time
void sortIntervals(struct Interval arr[], int n) {
    struct Interval temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeIntervals(struct Interval intervals[], int n) {
    if (n == 0) return;

    // Sort intervals using bubble sort
    sortIntervals(intervals, n);

    struct Interval result[n];
    int index = 0;
    result[0] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= result[index].end) {
            // Overlap: merge
            if (intervals[i].end > result[index].end)
                result[index].end = intervals[i].end;
        } else {
            // No overlap: move to next
            index++;
            result[index] = intervals[i];
        }
    }

    // Print result
    printf("Merged intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval intervals[n];

    printf("Enter each interval as two numbers (start end):\n");
    for (int i = 0; i < n; i++) {
        printf("Interval %d: ", i + 1);
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    return 0;
}

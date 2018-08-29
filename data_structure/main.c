#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    printf("%d \n", n);
    
    if (n <= 1) {
        return 1;
    } else {
        int subSolution = factorial(n-1);
        int solution = subSolution * n;
        
        return solution;
    }
}

int main(int argc, const char * argv[]) {
    int a = factorial(5);
    printf("%d \n", a);
    
    return 0;
}

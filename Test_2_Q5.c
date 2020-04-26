#include <stdio.h>

int fun(int *k) {
	*k += 4;
	return 3* (*k) - 1;
}

void main() {
	int i = 10, j = 10, sum1, sum2;
	sum1 = i/2 + fun(&i);
	sum2 = fun(&j) + j/2;
	printf("%d\n", sum1);
	printf("%d\n", sum2);
}

//sum1 prints 46 
//This value is obtained by the following:
//sum1 = i/2 + fun(i) = 10/2 + 3*(10+4)-1 = 5 + 42-1 = 46

//sum2 prints 48
//This value is obtained by the following:
//sum2 = fun(j) + (j/2) = 3*(10+4)-1 + 14/2 = 41 + 7 = 48
//Above, j/2 results in 14/2 instead of 10/2 because the value of j
//changes due to the function call because we are passing j by reference

//Without precedence rules instead of sum1 = ((i/2) + fun(&i)) we would end up with
//(sum1 = (i/2)) + fun(&i) because + has higher precedence than =
//This would then pass 5 to fun(&i) instead of adding 5 to fun(&i) and fun(&i) still
//using the original value of i, which is 10.
//Also, we would not know how to execute the function without precedence rules.
//If i/2 were evaulated first the result is what we got of 46.
//However, if fun(&i) were evaulated first our result would change to 48 like we
//we see with j where j is passed by reference.
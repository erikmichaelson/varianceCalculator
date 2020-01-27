#include<stdio.h>
#include<stdlib.h>


double calc(int* list, double n){
	int i;
	double mean, sum, d;

//	printf("n: %f\n", n);
	// calculate the mean
	for(i = 0; i<n; i++){
		sum += list[i];
//		printf("list[i]: %d\n", list[i]);
	}
//	printf("sum: %f\n", sum);
	mean = sum/n;
//	printf("mean: %f\n", mean);

	// find the difference for each value and add them
	// reusing sum to keep track of it
	sum = 0;
	for(i = 0; i<n; i++){
		d = (list[i] - mean);
		sum += (d * d);
	}

	return sum / n;
}

int* strToArr(char* str){
//	printf("It gets here. Array: %s\n", str);
	// I'm using 10 to be safe for WA purposes. This would break if more were entered whoops
	int* arr = malloc(10 * sizeof(int));
	int i = 0;
	int j = 0;

	while(str[i] !=']' && i < 10){
		if(str[i]> 47 && str[i]<58){
			arr[j] = str[i]-48;
//			printf("%d\n", arr[i]);
			j ++;
		}
		i ++;
	}

	return arr;
}

int main(){
	char* str = malloc(25 * sizeof(char));
	int n;

	printf("Enter the list like [a,b,c] followed by a space and the number of values in the list\n");

	fscanf(stdin, "%s %d", str, &n);
//	printf("Array: %s length: %d\n", str, n);

	int* arr = strToArr(str);
	double var = calc(arr, n);

	printf("Variance of %s is %f\n", str, var);
}

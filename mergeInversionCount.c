#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long count = 0;

#define DATARANGE 100000

void printArr(long *arr, long size) {

   for (long v = 0; v < size; v++) {
      printf("%ld ", arr[v]);
   }
   printf("\n");
}

long * mergeAndCount(long arr1[], long arr2[], long arr1Length, long arr2Length) {
   long i=0, j=0, c = 0;
   long totalLength = (arr1Length + arr2Length);

   long *sortedArr = NULL;
   sortedArr = malloc(sizeof(arr1[0]) * totalLength);

   while(i < (arr1Length) && j < (arr2Length)) {
      long el1, el2;
      el1 = arr1[i];
      el2 = arr2[j];
      if (el1 < el2) {
          sortedArr[c++] = el1;
          i++;
      } else {
         sortedArr[c++] = el2;
         count += arr1Length - i;
         j++;
      }
   }


   if (i < arr1Length) {
      while (i < arr1Length) {
         sortedArr[c] = arr1[i];
         c++;
         i++;
      }
   }

   if (j < arr2Length) {
      while (j < arr2Length) {
         sortedArr[c] = arr2[j];
         c++;
         j++;
      }
   }

   return sortedArr;
}

long * mergeCountSort(long arr[], int arrLength) {

   if (arrLength < 2) {
      return arr;
   }

   long mid = arrLength / 2;
   long firstHalfLength, secondHalfLength;

   firstHalfLength = arrLength / 2;
   secondHalfLength = arrLength - firstHalfLength;

   long sub1[firstHalfLength], sub2[secondHalfLength];

   memcpy(sub1, &arr[0], (firstHalfLength) * sizeof(arr[0]));
   memcpy(sub2, &arr[mid], (secondHalfLength) * sizeof(arr[0]));

   long *newsub1 = mergeCountSort(sub1, firstHalfLength);
   long *newsub2 = mergeCountSort(sub2, secondHalfLength);

   long *ans = mergeAndCount(newsub1, newsub2, firstHalfLength, secondHalfLength);

   return ans;
}

int main(int argc, char *argv[]) {
   long data[DATARANGE];
   long k;
   long i = 0;
   while (scanf("%ld", &k) == 1) {
       data[i] = k;
       i++;
   }

   int dataLength = sizeof(data) / sizeof(data[0]);

   long *ans = mergeCountSort(data, dataLength);

   //printArr(ans, dataLength);
   printf("\nTotal number of inversions:  %ld\n\n", count);


   return 0;
}

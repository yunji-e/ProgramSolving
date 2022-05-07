#include <stdio.h>

int bin_search_loop(int key, int arr[], int low, int high){
    int middle;

    do{
        middle = (low+high)/2;
        if(arr[middle]==key)
            return middle;
        else if (arr[middle]>key)
            high = middle - 1;
        else
            low = middle + 1;

    } while (low <= high);
}

int main(void){

}
#include <iostream>
#include <vector>
#include "personas.h"
using namespace std;

#ifndef SORT
#define SORT

int mergeSort(vector<Persona>& vec, vector<Persona>& vec2, int low, int mid, int high){
    int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (vec[i].get_nombre() < vec[j].get_nombre()) {
			vec2[k] = vec[i];
			i++;
		} else {
			vec2[k] = vec[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			vec2[k] = vec[j];
            k++;
		}
	} else {
		for (; i <= mid; i++) {
			vec2[k] = vec[i];
            k++;
		}
	}
    return 1;
}

void copyarr(vector<Persona>& vec, vector<Persona>& vec2, int low, int high){
    for (int i = low; i<=high; i++){
        vec[i] = vec2[i];
    }
    return;
}

void mergeSplit (vector<Persona>& vec, vector<Persona>& vec2, int low, int high){
    if (low >= high){
        return;
    }
    int mid = (low + high)/2;
    mergeSplit (vec, vec2, low, mid);
    mergeSplit (vec, vec2, mid+1, high);
    mergeSort (vec, vec2, low, mid, high);
    copyarr(vec, vec2, low, high);
    return;
}

#endif /* SORT */

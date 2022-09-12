// =================================================================
//
// File: sort.h
// Author: Arturo Diaz
// Date: 11/09/22
//
// =================================================================

#ifndef SORT_H
#define SORT_H

#include <vector>
#include "header.h"

template <class T>
int sortDay(std::vector<T> &v) {
	int pos;
  int k;

	for(int i = v.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(v[j].day > v[pos].day){
				pos = j;
			}
		}

		if (pos != i){
			swap(v, i, pos);
      k++;
		}
	}
  return k;
}

template <class T>
int sortMonth(std::vector<T> &v) {
	int pos;
  int k;

	for(int i = v.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(v[j].month > v[pos].month){
				pos = j;
			}
		}

		if (pos != i){
			swap(v, i, pos);
      k++;
		}
	}
  return k;
}

#endif
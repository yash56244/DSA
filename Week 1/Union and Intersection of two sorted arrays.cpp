#include<bits/stdc++.h>

using namespace std;

void unionSorted(int arr1[], int arr2[], int n, int m){
	int i = 0, j = 0;
	cout<<"Union : ";
	while(i < n || j < m){
		if(i == n){
			while(j < m){
				cout<<arr2[j];
				j++;
			}
			break;
		}
		if(j == m){
			while(i < n){
				cout<<arr1[i];
				i++;
			}
			break;
		}
		if(arr1[i] < arr2[j]){
			cout<<arr1[i]<<" ";
			i++;
		}else if(arr1[i] > arr2[j]){
			cout<<arr2[j]<<" ";
			j++;
		}else{
			cout<<arr1[i]<<" ";
			i++, j++;
		}
	}
	cout<<endl;
}

void intersectionSorted(int arr1[], int arr2[], int n, int m){
	int i = 0, j = 0;
	cout<<"Intersection : ";
	while(i < n && j < m){
		if(arr1[i] < arr2[j]){
			i++;
		}else if(arr1[i] > arr2[j]){
			j++;
		}else{
			cout<<arr1[i]<<" ";
			i++, j++;
		}
	}
	cout<<endl;
}

int main(){
	int arr1[] = {1,3,4,5,7};
	int arr2[] = {2,3,5,6};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int m = sizeof(arr2)/sizeof(arr2[0]);
	unionSorted(arr1, arr2, n, m);
	intersectionSorted(arr1, arr2, n, m);
	return 0;
}

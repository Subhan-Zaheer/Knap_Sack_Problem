#include<iostream>

using namespace std;

class knapSackUnit {
public:
	int weight;
	int profit;
	int objNo;
	float PW_Ratio;
	knapSackUnit() {
		weight = profit = objNo = PW_Ratio = 0;
	}
};
void mergeSort(knapSackUnit* arr, int start, int end, int size);
void merging(knapSackUnit* arr, int start, int end, int size);
class knapSackProblem : public knapSackUnit {
public:

	int solveProblem(int capacity) {
		int noOfKnapSackUnit;float maxProfit = 0.0;
		cout << "Enter number of Knap Sack Unit u want : ";
		cin >> noOfKnapSackUnit;
		knapSackUnit* array = new knapSackUnit[noOfKnapSackUnit];

		//intialize knap sack unit and calculate Profit/Weight ratio.

		cout << "Enter values of weight and profit for these units." << endl;
		for (int i = 0; i < noOfKnapSackUnit; i++) {
			int tempweight = 0, tempprofit = 0;
			(array + i)->objNo = i + 1;
			cout << "Enter weight of Object.";
			cin >> tempweight;
			cout << "Enter profit of Object.";

			cin >> tempprofit;
			(array + i)->profit = tempprofit;
			(array + i)->weight = tempweight;
			(array + i)->PW_Ratio = (array + i)->profit / (array + i)->weight;

		}
		for (int j = 0; j < noOfKnapSackUnit; j++) {
			cout << (array + j)->PW_Ratio << " ";
		}
		cout << endl;
		// Sorting Knap Sack Units on the basis of their PW ratios.

		mergeSort(array, 0, noOfKnapSackUnit - 1, noOfKnapSackUnit);
		for (int j = 0; j < noOfKnapSackUnit; j++) {
			cout << (array + j)->PW_Ratio << " ";
		}
		for (int i = 0; i < noOfKnapSackUnit; i++) {
			if (capacity > (array + i)->weight && capacity > 0) {
				capacity -= (array + i)->weight;
				maxProfit += (array + i)->profit;
			}
			else
			if (capacity < (array + i)->weight) {
				maxProfit += ((array + i)->profit / (array + i)->weight) * (capacity);
			}
		}
		cout << "\nMax Profit will be " << maxProfit << endl;
		return 0;
	}
	void mergeSort(knapSackUnit* arr, int start, int end, int size) {
		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(arr, start, mid, size);
			mergeSort(arr, mid + 1, end, size);
			merging(arr, start, end, mid);
		}
		//return;
	}


	void merging(knapSackUnit* arr, int start, int end, int mid) {
		int i = start, j = mid + 1, k = start;
		knapSackUnit* b = new knapSackUnit[end + 1];
		while (i <= mid && j <= end) {
			if (arr[i].PW_Ratio > arr[j].PW_Ratio) {
				b[k] = arr[i];
				i++;
			}
			else {
				b[k] = arr[j];
				j++;
			}
			k++;
		}
		while (j <= end) {
			b[k] = *(arr + j);
			k++;
			j++;
		}
		while (i <= mid) {
			b[k] = *(arr + i);
			k++;
			i++;
		}
		for (int a = start; a <= end; a++) {
			*(arr + a) = *(b + a);
		}

	}

};


int main() {
	int capacity;
	cout << "Enter Capacity of Sack : ";
	cin >> capacity;
	knapSackProblem obj;
	obj.solveProblem(capacity);
	return 0;
}
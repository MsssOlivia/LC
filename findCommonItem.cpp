#include<iostream>
#include<vector>
using namespace std;
int find_least_common_number(vector<int>& arr1,vector<int>& arr2,vector<int>& arr3) {

	vector<int>::iterator n1 = arr1.begin();
	vector<int>::iterator n2 = arr2.begin();
	vector<int>::iterator n3 = arr3.begin();
	while (n1 != arr1.end() && n2 != arr2.end() && n3 != arr3.end()) {
		if (*n1 == *n2 && *n1 == *n3) {
			return *n1;
		}

		while ((*n1 < *n2 && *n1 <= *n3)|| (*n1 <= *n2 && *n1 < *n3)) {
			n1++;
		}
		while ((*n2 < *n1 && *n2 <= *n3)|| (*n2 <= *n1 && *n2 < *n3)) {
			n2++;
		}
		while ((*n3 < *n2 && *n3 <= *n1)|| (*n3 <= *n2 && *n3 < *n1)) {
			n3++;
		}

	}

	return numeric_limits<int>::min(); // Replace will actual smallest common value
}
int main() {
	vector<int> a1 = { 1,3,5,8,14,20 };
	vector<int> a2 = { 2,5,6,7,14,21 };
	vector<int> a3 = { 3,4,14,15,17,20 };
	int b=find_least_common_number(a1, a2, a3);
	cout << b << endl;
	system("pause");
	return 0;

}

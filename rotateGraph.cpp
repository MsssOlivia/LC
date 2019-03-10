#include<iostream>
#include<vector>
#include <algorithm>   
using namespace std;

/////////////////////////copied from LeetCode
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = i + 1; j < matrix[i].size(); ++j)
			swap(matrix[i][j], matrix[j][i]);
	}
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
	for (auto vi : matrix) reverse(vi.begin(), vi.end());// "auto"!
	//A good use of auto is to avoid long initializations when creating iterators for containers.
	//for (int i = 0; i < matrix.size(); i++) reverse(matrix[i].begin(), matrix[i].end());
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = i + 1; j < matrix[i].size(); ++j)
			swap(matrix[i][j], matrix[j][i]);
	}
}


int main() {
	vector<vector<int>> M = { {5, 1, 9, 11},{2, 4, 8, 10},{13, 3, 6, 7},{15, 14, 12, 16} };
	for (int i = 0; i < M.size(); ++i) {
		for (int j = 0; j < M[i].size(); ++j)
			cout << M[i][j] << '\t';
		cout << endl;
	}
	cout << "--------------------------" << endl;
	anti_rotate(M);
		for (int i = 0; i < M.size(); ++i) {
			for (int j = 0; j < M[i].size(); ++j)
				cout<<M[i][j]<<'\t';
			cout << endl;
		}
	system("pause");
	return 0;
}

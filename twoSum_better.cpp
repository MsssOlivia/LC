bool find_sum_of_two(vector<int>& A, int val) {
  unordered_set<int> found_values;
  for (int& a : A) {
    if (found_values.find(val - a) != found_values.end()) {
      return true;
    }

    found_values.insert(a);
  }

  return false;
}

void test(vector<int> v, int val, bool expected) {
  bool output = find_sum_of_two(v, val);
  cout << "exist(A, " << val << ") = " << (output ? "true" : "false") << endl;
}

int main() {
  vector<int> v = {2, 1, 8, 4, 7, 3};
  test(v, 3, true);
  test(v, 20, false);
  test(v, 1, false);
  test(v, 2, false);
  test(v, 7, true);
  
  return 0;
}

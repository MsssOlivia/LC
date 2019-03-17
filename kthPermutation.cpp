int factorial(int n) {
  if (n == 0 || n == 1) return 1;
  return n * factorial(n -1 );
}

void find_kth_permutation(
    vector<char>& v,
    int k,
    string& result) {
  if (v.empty()) {
    return;
  }
  
  int n = (int)(v.size());
  // count is number of permutations starting with each digit
  int count = factorial(n - 1);
  int selected = (k - 1) / count;

  result += v[selected];
  v.erase(v.begin() + selected);

  k = k - (count * selected);
  find_kth_permutation(v, k, result);
}

string get_permutation(int n, int k) {
    vector<char> v;
    for (char i = 1; i <= n; ++i) {
        v.push_back(i + '0');
    }
    
    string result;
    find_kth_permutation(v, k, result);
    return result;
}

int main(int argc, char* argv[]) {
    for (int i = 1; i <= factorial(4); ++i) {
        cout << i << "th permutation = " << get_permutation(4, i) << endl;
    }
}

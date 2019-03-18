#include<iostream>
#include<algorithm>
using namespace std;

void revString(char* s, int n) {
	char* start = s;
	char* end = s + n - 1;
	while (start < end) {
		swap(*start, *end);
		start++;
		end--;
	}
}


void reverse_sentence_words(char* sentence) {
	int n = strlen(sentence);
	revString(sentence, n);

	char* head = sentence;
	char* end;
	while (*head !='\0') {
		while (*head ==' ') head++;
		end = head;
		while (*end != ' ' && *end != '\0') end++;
		revString(head, end - head);
		head = end;
	}
}

int main() {

	char a[]="Hello World!";
	reverse_sentence_words(a);
	cout << a << endl;

	char b[] = "Quick brown fox jumped over the lazy dog";
	reverse_sentence_words(b);
	cout << b << endl;
	system("pause");
	return 0;
}

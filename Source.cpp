#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <conio.h>

using namespace std;

void parseString(const string &srcString, vector <set <string> > &result);
void print_vector_set_str(vector<set <string> > result);
void print_vector_str(vector<string> v);
vector<string> div_in_words(const string& str);

int main() {
	string srcString = "the quick brown fox jumps over the lazy dog";
	vector <set <string> > result;

	parseString(srcString, result);
	print_vector_set_str(result);

	_getch();
	return 0;
}

void print_vector_set_str(vector<set <string> > result) {
	for (vector<set <string> >::iterator i = result.begin(); i < result.end(); i++) {
		for (set <string>::iterator j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
}

void print_vector_str(vector<string> v) {
	for (const string& word : v) {
		cout << word << " ";
	}
}

vector<string> div_in_words(const string& str) {
	string str1 = str;
	vector<string> words;
	string word, space = " ";
	str1 += space;
	while (str1.length() > 0) {
		word = str1.substr(0, str1.find_first_of(space));
		str1.erase(0, str1.find_first_of(space)+1);
		words.push_back(word);
	}
	return words;
}

void parseString(const string &srcString, vector <set <string> > &result) {
	vector <string> words = div_in_words(srcString);
	while (!words.empty()) {	//двигаемся по result
		string ctrl_word = words[0];		//вырезаем ключевое слово
		words.erase(words.begin());			//
		set<string> words_set;
		words_set.insert(ctrl_word);//вставляем ключевое слово в сет
		vector<string>::iterator it = words.begin();
		while(it != words.end()) {
			if (ctrl_word.length() == it->length()) {
				words_set.insert(*it);//вставляем слово в сет
				it = words.erase(it);//вырезаем найденное слово
			}else { ++it; }
		}
		result.push_back(words_set);//вставляем сет в конечный вектор
	}
}
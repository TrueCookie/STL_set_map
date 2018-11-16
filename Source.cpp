#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <conio.h>

using namespace std;

void parseString(const string &srcString, vector <set <string> > &result);
void parseString(const string &srcString, map <char, vector<string> > &result);
void print_vector_set_str(vector<set <string> > result);
void print_map_vector_str(map <char, vector<string> > result);
void print_vector_str(vector<string> v);
vector<string> div_in_words(const string& str);

int main() {
	string srcString = "some quick brown foxes jump over the sleep dog joji";
	vector <set <string> > same_size;
	parseString(srcString, same_size);
	print_vector_set_str(same_size);

	map <char, vector<string> > same_frst_letter;
	parseString(srcString, same_frst_letter);
	print_map_vector_str(same_frst_letter);

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

void print_map_vector_str(map <char, vector<string> > result) {
	for (map <char, vector<string> >::iterator i = result.begin(); i != result.end(); i++) {
		cout << i->first << " - ";
		for (vector <string>::iterator j = i->second.begin(); j != i->second.end(); j++) {
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

void parseString(const string &srcString, map <char, vector<string> > &result) {
	vector <string> words = div_in_words(srcString);
	while (!words.empty()) {	//двигаемся по result
		string ctrl_word = words[0];		//вырезаем ключевое слово
		words.erase(words.begin());			//
		vector<string> words_vector;
		words_vector.push_back(ctrl_word);//вставляем ключевое слово в вектор
		vector<string>::iterator it = words.begin();
		while (it != words.end()) {
			if (ctrl_word[0] == it->at(0)) {
				words_vector.push_back(*it);//вставляем слово в вектор
				it = words.erase(it);//вырезаем найденное слово
			}
			else { ++it; }
		}
		char letter = ctrl_word[0];
		result.insert({ letter, words_vector });//вставляем вектор в конечный словарь
	}
}
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

	string srcString = "the quick brown fox jumps over the lazy dog ";
	vector <set <string> > result;

	parseString(srcString, result);
	void print(vector<set <string> > result);


	_getch();
	return 0;
}

//void parseString(const string &srcString, vector <set <string> > &result) {
//	string inp = srcString;
//	string control;
//	int size;
//
//	string::iterator it_b = inp.begin();
//	string::iterator it = inp.begin();
//	string::iterator it_global = inp.begin();
//
//	set<string> tmp_set;
//	while (distance(it_b, it_global) != inp.length()) {	//��������� �� ������
//
//		control = inp.substr(0, inp.find_first_of(" "));	//�������� ����������� �����
//		inp = inp.erase(inp.find_first_of(" ")+1);			//
//		size = control.length();	//������ ������������ �����
//
//		it = inp.begin();
//		while (it < inp.end()) {	//���� ����� ����� �� �����
//			string tmp = inp.substr(distance(it_b, it), inp.find_first_of(" ", distance(it_b, it)));	//���������� �����
//			if (tmp.length() == size) {
//				tmp_set.insert(tmp);	//��������� ������ ����� � ���
//				inp.erase();//�������� ������ ����� ������
//
//			}
//			it += tmp.length();
//		}
//
//		result.push_back(tmp_set);//��������� ��������� ��� 
//
//		//index++;
//		it_global += size;
//	}
//
//}

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

	string word;
	string space = " ";
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
	set<string> words_set;
	vector <string>::iterator it;
	vector <string>::iterator del_it;
	while (!words.empty()) {	//��������� �� result
		string ctrl_word = words[0];		//�������� �������� �����
		words.erase(words.begin());	//
		words_set.insert(ctrl_word);//��������� �������� ����� � ���
		it = words.begin();
		for (const string& word : words) {	//TODO: ������������ ������� for ��� ��������� ����� ��������� � �������
			if (ctrl_word.length() == word.length()) {
				words_set.insert(word);//��������� ����� � ���
				del_it = it;
				it++;
				words.erase(del_it);//�������� ��������� �����
			}else { it++; }
		}
		result.push_back(words_set);//��������� ��� � �������� ������
	}
}
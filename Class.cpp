#include "Class.h"

TString::TString() {
	arr = new char[1];
	arr[0] = 0;
	size = 1;
}

TString::TString(const char* s) {
	arr = 0;
	size = strlen(s) + 1;
	arr = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		arr[i] = s[i];
	}
	arr[size] = 0;
}

TString::TString(const char c) {
	if (c != 0) {
		size = 2;
		arr = new char[2];
		arr[0] = c;
		arr[1] = 0;
	}
	else {
		size = 1;
		arr = new char[2];
		arr[0] = 0;
	}
}

TString::TString(const TString& s) {
	arr = 0;
	size = s.lng();
	arr = new char[size];
	for (int i = 0; i < size; i++)
		arr[i] = s[i];
}
TString::TString(const TString& s, int f, int l) {
	arr = 0;
	size = l - f + 2;
	arr = new char[size];
	for (int i = 0; i < size; i++)
		arr[i] = s[f + i];
	arr[size - 1] = 0;
}

TString::~TString() {
	if (arr != 0) {
		delete[] arr;
		arr = 0;
	}
	size = 0;
}

int TString::lng() const {
	return size;
}

void TString::copy(const TString& s, int begin, int end) {
	TString copy(s, begin, end);
	*this = copy;
}

int TString::psn(const char c) {
	for (int i = 0; i < size; i++)
		if (this->arr[i] == c)
			return i;
	return 0;
}

int TString::psnl(const char c) {
	int last = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == c)
			last = i;
	return last;
}

int TString::pos(const char* s) {
	int sizechar = strlen(s);
	int count = 0;
	int i;
	for (i = sizechar; i < size; i++) {
		if (arr[i] == s[i])
			count++;
		else
			count = 0;
		if (count == sizechar)
			break;
	}
	if (count == sizechar)
		return i - count;
	return 0;
}
int TString::psnc(const char c) {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] == c)
			count++;
	return count;
}

TString* TString::sep(char c) {
	int count = this->psnc(c);
	TString* res = 0;
	int arraysize;
	if (size - 2 != this->psnl(c) || this->psn(c) != 0) {
		arraysize = count + 1;
		res = new TString[arraysize];
	}
	else {
		arraysize = count;
		res = new TString[arraysize];
	}
	res[0] = *this;
	for (int i = 1; i < arraysize; i++) {
		int begin = res[i - 1].psn(c);
		int end = res[i - 1].lng() - 1;
		TString copy(res[i - 1], begin + 1, end);
		res[i] = copy;
		res[i - 1].resize(begin + 1);
	}
	return res;
}

TString TString::rep(TString& s, int n) {
	if (s.lng() == 0)
		throw "lng = 0";
	TString res(s);
	for (int i = 0; i < n - 1; i++)
	{
		res = res + s;
	}
	return res;
}

TString TString::operator+(const TString& s) const {
	TString res(*this);
	res.resize(size + s.lng() - 1);
	for (int i = size - 1; i < res.lng(); i++)
		res[i] = s[i - size + 1];
	return res;
}
TString TString::operator+(const char c)const {
	TString res(*this);
	if (res.size != 1)
		res.resize(size + 1);
	else
		res.resize(size + 2);
	int ressize = res.lng();
	res[ressize - 2] = c;
	return res;
}

bool TString::operator==(const TString& s) const {
	if (size == s.lng()) {
		int i = 0;
		while (arr[i] == s[i])
			i++;
		if (i == size - 1)
			return true;
	}
	return false;
}
bool TString::operator!=(const TString& s) const {
	if (*this == s) 
		return false;
	return true;
}
TString& TString::operator=(const TString& s) {
	if (*this == s) return *this;
	if (arr != 0)
		delete[] arr;
	size = s.lng();
	arr = 0;
	arr = new char[size];
	for (int i = 0; i < size; i++)
		arr[i] = s[i];
	return *this;
}

TString& TString::operator=(const char c) {
	TString temp(c);
	*this = temp;
	return *this;
}

char& TString::operator[](int n) const {
	return arr[n];
}

bool TString::operator<(const TString& s) const {
	for (int i = 0; i < (size < s.lng() ? size : s.lng()); i++) {
		if (arr[i] < s[i]) return true;
		else if (arr[i] > s[i]) return false;
	}
	return false;
}

bool TString::operator>(const TString& s) const {
	for (int i = 0; i < (size < s.lng() ? size : s.lng()); i++)
	{
		if (arr[i] > s[i]) return true;
		else if (arr[i] < s[i]) return false;
	}
	return false;
}

void TString::resize(int n) {
	if (size != n)
	{
		int cs = size;
		char* copy = arr;
		size = n;
		arr = 0;
		arr = new char[size];
		if (n >= cs) {
			for (int i = 0; i < cs; i++)
				arr[i] = copy[i];
			arr[n - 1] = 0;
		}
		else {
			for (int i = 0; i < n; i++)
				arr[i] = copy[i];
			arr[n - 1] = 0;
		}
		delete[] copy;
	}
	else
		std::cout << "The size has not been changed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const TString& s)
{
	out << s.arr;
	return out;
}

std::istream& operator>>(std::istream& in, TString& s)
{
	char get[256];
	in.getline(get, 256);
	TString right(get);
	s = right;
	return in;
}
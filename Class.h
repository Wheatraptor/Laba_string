#include <iostream>
#include <cstring>

class TString{
	char* arr;
	int len;
public:
	TString();
	TString(const char* arr_);
	TString(const TString& string);
	~TString();

	char* get();
	int len();
	int find(const TString& s);
	int find(char c);
	TString* split(char c);
	TString dupe(int k);

	TString operator+(const TString& s);
	TString& operator=(const TString& s);
	bool operator==(const TString& s);
	bool operator>(const TString& s);
	bool operator<(const TString& s);
	char operator[](int n) const;
	char& operator[](int n);

	friend std::ostream& operator<<(std::ostream& out, const TString& s);
	friend std::istream& operator>>(std::istream& in, TString& s);
};
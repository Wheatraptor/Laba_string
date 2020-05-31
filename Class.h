#include <iostream>

class TString {
	int size;
	char* arr;
	void resize(int n);
public:
	TString();
	TString(const char* s);
	TString(const char c);
	TString(const TString& s);
	TString(const TString& s, int f, int l);
	~TString();

	int lng() const;
	void copy(const TString& s, int begin, int end);
	int psn(const char c);
	int psnl(const char c);
	int pos(const char* s);
	int psnc(const char c);
	TString* sep(char c);
	TString rep(TString& s, int n);

	TString operator+(const char c)const;
	TString operator+(const TString& s)const;
	TString& operator=(const TString& s);
	TString& operator=(const char c);
	char& operator[] (int number)const;
	bool operator<(const TString& s)const;
	bool operator>(const TString& s)const;
	bool operator==(const TString& s) const;
	bool operator!=(const TString& s)const;
	
	friend std::ostream& operator<< (std::ostream& out, const TString& s);
	friend std::istream& operator>> (std::istream& in, TString& s);
};
#pragma once
#include <cstring>
#include <iostream>

class String {
	char* mesaj;
public:
	String(const char*);
	String(const String&);
	~String();
	String& operator=(const String&);
	bool operator==(const String&) const;
	void afiseaza() const;
	unsigned lungime() const;
};


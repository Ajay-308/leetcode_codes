// C++ program to check if
// two strings are identical
#include <bits/stdc++.h>
using namespace std;

int main()
{

	char string1[100], string2[100];

	// Get the strings which
	// is to be checked
	cin >> string1;
	cout << "Enter the first string: " << string1;

	// Get the strings which
	// is to be checked
	cin >> string2;
	cout << "\nEnter the second string: " << string2;

	// Check if both strings are equal
	cout << "\nAre both strings same: ";

	if (strcmp(string1, string2) == 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}

// This code is contributed by Akanksha Rai

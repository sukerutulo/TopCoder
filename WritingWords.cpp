#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class WritingWords {
public:
	int write(string word) {
	    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	    int size = word.size(), res=0;
	    for(int i = 0; i<size; ++i)
		res += alpha.find(word[i])+1;
	    return res;
		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	WritingWords *obj;
	int answer;
	obj = new WritingWords();
	clock_t startTime = clock();
	answer = obj->write(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
		if (hasAnswer) {
			cout << "Desired answer:" << endl;
			cout << "\t" << p1 << endl;
		}
		cout << "Your answer:" << endl;
		cout << "\t" << answer << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	string p0;
	int p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = "A";
	p1 = 1;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "ABC";
	p1 = 6;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "VAMOSGIMNASIA";
	p1 = 143;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "TOPCODER";
	p1 = 96;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "SINGLEROUNDMATCH";
	p1 = 183;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	p1 = 1300;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Fox Ciel wants to type a word on her old cell phone. The cell phone has only one button. The letter A is typed by tapping the button once, B by tapping it twice in a row, and so on, in alphabetical order. Thus, the last letter Z is typed by tapping the button 26 times without a pause.
// 
// You are given a string word. Compute and return the answer to the following question: How many times will Ciel tap the button while typing this word?
// 
// DEFINITION
// Class:WritingWords
// Method:write
// Parameters:string
// Returns:int
// Method signature:int write(string word)
// 
// 
// NOTES
// -While typing a word, Ciel has to make a short pause after typing each letter, so that the phone can tell when one letter ends and another letter begins. These pauses do not matter in this problem.
// 
// 
// CONSTRAINTS
// -word will contain between 1 and 50 characters, inclusive.
// -Each character in word will be an uppercase English letter ('A'-'Z').
// 
// 
// EXAMPLES
// 
// 0)
// "A"
// 
// Returns: 1
// 
// One tap types the letter A.
// 
// 1)
// "ABC"
// 
// Returns: 6
// 
// To type ABC, Ciel will do the following:
// 
// Tap the button once to type A.
// Tap the button twice to type B.
// Tap the button three times to type C.
// 
// The total number of taps is 1+2+3 = 6.
// 
// 2)
// "VAMOSGIMNASIA"
// 
// Returns: 143
// 
// 
// 
// 3)
// "TOPCODER"
// 
// Returns: 96
// 
// 
// 
// 4)
// "SINGLEROUNDMATCH"
// 
// Returns: 183
// 
// 
// 
// 5)
// "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"
// 
// Returns: 1300
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!

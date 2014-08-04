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

char rtrn_bra(char ket){
    if(ket == ')')
	return '(';

    if(ket == ']')
	return '[';

    if(ket == '}')
	return '{';

    cout << "error error error" << endl;
    return ' ';
}

class BracketExpressions {
public:
	string ifPossible(string expression) {
	    stack<char> bracket;
	    int numX = 0;
	    bool open = true;
	    for(int i=0; i<expression.size(); ++i){
		char chr = expression[i];
		if(chr == '(' or chr == '[' or chr == '{'){
		    bracket.push(chr);
		    open = true;
		}
		else if(chr == 'X'){
		    if(open && !bracket.empty()){
			bracket.pop();
			open = false;
		    }
		    bracket.push(chr);
		    numX++;
		}
		else if(bracket.empty())
		    return "impossible";
		else{
		    char bra = rtrn_bra(chr);
		    if(bracket.top()==bra){
			bracket.pop();
			open = false;
		    }
		    else if(bracket.top()=='X'){
			bracket.pop();
			open = false;
			numX--;
		    }
		    else{
			// cout << i << endl;
			// cout << chr << endl;
			// cout << bracket.top() << endl;
			return "impossible";
		    }
		}
	    }
	    stack<char> cp = bracket;
	    while(!cp.empty()){
	     	cout << cp.top();
	     	cp.pop();
	    }
	    cout << endl;
	    cout << bracket.size() << endl;
	    cout << numX << endl;
	    if(bracket.size()%2==0 and !open)
		return  "possible";
	    return "impossible";
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	BracketExpressions *obj;
	string answer;
	obj = new BracketExpressions();
	clock_t startTime = clock();
	answer = obj->ifPossible(p0);
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
			cout << "\t" << "\"" << p1 << "\"" << endl;
		}
		cout << "Your answer:" << endl;
		cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = "([]{})";
	p1 = "possible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "(())[]";
	p1 = "possible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "({])";
	p1 = "impossible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "[]X";
	p1 = "impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "([]X()[()]XX}[])X{{}}]";
	p1 = "possible";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	disabled = false;
	p0 = "()}{[]";
	p1 = "impossible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

	disabled = false;
	p0 = "X[()X}]()[]}[{[]{()}()X[{}[]][{()}()()][X][]{}{}(X";
	p1 = "possible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;

	// ------------------
	disabled = false;
	p0 = "X{}[]()]X{X{}]X]";
	p1 = "possible";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;

	// ------------------
	disabled = false;
	p0 = "({[((X{}{}){}{X}(){}X[][]]XX{}{}}()}{}{}}{}[])[][]";
	p1 = "possible";
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
// We have three types of brackets: "()", "[]", and "{}".
// We are now interested in some special strings.
// A string is special if all the following conditions hold:
// 
// Each character of the string is one of the six bracket characters mentioned above.
// The characters of the string can be divided into disjoint pairs such that in each pair we have an opening bracket and a closing bracket of the same type.
// For each pair, the opening bracket must occur to the left of the corresponding closing bracket.
// For each pair, the substring strictly between the opening and the closing bracket must be a special string (again, according to this definition).
// 
// 
// For example, the empty string is a special string: there are 0 pairs of brackets.
// The string "[]" is also a special string: there is one pair of matching brackets, they are in the proper order, and the string between them (which is the empty string) is a special string.
// 
// The character 'X' (uppercase x) occurs in expression at most five times; all other characters in expression are brackets of the types mentioned above.
// We want to change expression into a special string by changing each 'X' into one of the brackets.
// (Different occurrences of 'X' may be changed into different brackets.)
// Return "possible" (quotes for clarity) if we can do that, and "impossible" otherwise.
// 
// DEFINITION
// Class:BracketExpressions
// Method:ifPossible
// Parameters:string
// Returns:string
// Method signature:string ifPossible(string expression)
// 
// 
// CONSTRAINTS
// -expression will have between 1 and 50 characters, inclusive.
// -Each character in expression will be '(', ')', '[', ']', '{', '}' or 'X'.
// -There will be at most 5 occurences of 'X' in expression.
// 
// 
// EXAMPLES
// 
// 0)
// "([]{})"
// 
// Returns: "possible"
// 
// This is already a special string. As there are no 'X's, we do not get to change anything.
// 
// 1)
// "(())[]"
// 
// Returns: "possible"
// 
// 
// 
// 2)
// "({])"
// 
// Returns: "impossible"
// 
// 
// 
// 3)
// "[]X"
// 
// Returns: "impossible"
// 
// Regardless of bracket type you put instead of 'X', you cannot create a special string.
// 
// 4)
// "([]X()[()]XX}[])X{{}}]"
// 
// Returns: "possible"
// 
// You can replace 'X's respectively with '{', '(', ')' and '['.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
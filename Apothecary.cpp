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
double eps = 1 >> 26;

class Apothecary {
public:
	vector <int> balance(int W) {
	    int check1 = log(W)/log(3);
	    int check2 = (int)pow(3,check1);
	    if(check2 == W ){
		return {W};
	    }
	    int target=0, now,temp,i;
	    int N = (int)floor(log(W)/log(3)) + 1;
	    int sign=1;
	    int powers[15]={0};
	    //vector<int> powers(N+1, 0);
//	    powers[N] = 1; 
//	    target = pow(3,N); --N;

	    while(0 <= N){
		if(powers[N]!=0) continue;
		if(target < W)
		    sign = 1;
		else if(W < target)
		    sign = -1;
		else
		    break;
		for(i=N; powers[i]!=0 or 0<=i; --i);
		temp = abs(W-target);
		int powN = (int)pow(3,N);
		int powi = (int)pow(3,i);
		if(abs(temp-powN) < abs(temp-powi)){
		    now = powN;
		    powers[N] = sign;
		}
		else{
		    now = powi;
		    powers[i] = sign;
		}
		target = target + sign * now;
		N--;
	    }

	    N = (int)floor(log(W)/log(3)) + 1;
	    vector<int> result;
	    for(int i=0; i<=N; ++i){
		if(powers[i]!=0)
		    result.push_back(powers[i] * pow(3,i));
	    }
	    sort(result.begin(), result.end());
	    return result;
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
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	Apothecary *obj;
	vector <int> answer;
	obj = new Apothecary();
	clock_t startTime = clock();
	answer = obj->balance(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
		if (hasAnswer) {
			cout << "Desired answer:" << endl;
			cout << "\t" << "{";
			for (int i = 0; int(p1.size()) > i; ++i) {
				if (i > 0) {
					cout << ",";
				}
				cout << p1[i];
			}
			cout << "}" << endl;
		}
		cout << "Your answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(answer.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << answer[i];
		}
		cout << "}" << endl;
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
	
	int p0;
	vector <int> p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 17;
	p1 = {-9,-1,27};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 3;
	p1 = {3};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 4;
	p1 = {1,3};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 1000000;
	p1 = {-531441,-59049,-6561,-243,-27,1,81,729,2187,1594323};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
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
// 
// An accurate scale is one of the most important tools of the apothecary (an old-time pharmacist).  
// To measure the weight of an object, the apothecary places the object on one
// pan of the scale, along with some weights of known size, and adds more weights
// of known size to the other pan until the scales balance.  For example, if an object
// weighs 17 grains, the apothecary could balance the scales by placing a 1-grain weight
// and a 9-grain weight in the pan with the object, and a 27-grain weight in the other
// pan.
// 
// 
// 
// The apothecary owns weights in a range of sizes starting at 1 grain.  In particular, he owns one weight for each
// power of 3: 1 grain, 3 grains, 9 grains, 27 grains, etc.  Determine, for an object weighing W grains, how to distribute the weights among the
// pans to balance the object.  This distribution will be unique.  Return a vector <int> of the weights used.  The sign of each weight should be
// negative if the weight goes in the same pan as the object, and positive if it goes in the other pan.  The vector <int> should be arranged in increasing order.
// 
// 
// 
// DEFINITION
// Class:Apothecary
// Method:balance
// Parameters:int
// Returns:vector <int>
// Method signature:vector <int> balance(int W)
// 
// 
// CONSTRAINTS
// -W is between 1 and 1000000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 17
// 
// Returns: { -9,  -1,  27 }
// 
// The example above.
// 
// 1)
// 1
// 
// Returns: { 1 }
// 
// A 1-grain weight is placed in the pan opposite the object being measured.
// 
// 2)
// 2016
// 
// Returns: { -243,  -9,  81,  2187 }
// 
// A 9-grain weight and a 243-grain weight are placed in the pan with the object,
// and an 81-grain weight and a 2187-grain weight are placed in the opposite pan.
// 
// 3)
// 1000000
// 
// Returns: { -531441,  -59049,  -6561,  -243,  -27,  1,  81,  729,  2187,  1594323 }
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!



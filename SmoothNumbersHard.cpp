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
#include <string>

using namespace std;

void makePrimeTable(vector<int> &table, int num){
    vector<bool> not_prime(num, false);
    not_prime[0]=not_prime[1]=true;
    for(int i=2; i <= num; i++){
	if(!not_prime[i]){
	    table.push_back(i);
	    for(int j=2*i; j<=num; j+=i)
		not_prime[j] = true;
	}
    }
}

bool checkK_smooth(int x,int &k, vector<int> &prime_table){
    for(vector<int>::iterator it=prime_table.begin(), end=prime_table.end();
	(*it) * (*it) <= x and it != end; it++){
	if(x%(*it)==0){
	    if(k < (*it)) return false;
	    while(x%(*it)==0) x /= *it;
	}
    }
    if(k < x) return false;
    return true;
}

//int fact[5000001];

class SmoothNumbersHard {
public:
	int countSmoothNumbers(int N, int k) {
	    // memset(fact, -1, sizeof(fact)); fact[0]=fact[1]=-2;
	    // for(int i=0; i<N; ++i) if(fact[i]==-1) for(int j=i; j<=N; j+=i) fact[j]=i;
	    // int ret=0; for(int i=1; i<N; ++i) if(fact[i]<=k) ++ret; return ret;

	    if(N==1 or k==1) return 1;
	    vector<int> prime_table;
	    makePrimeTable(prime_table, k);
	    int result=min(N, k-1);
	    for(int i=k; i<=N; ++i){
	    	if(checkK_smooth(i,k, prime_table))
	    	    result++;
	    }
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	SmoothNumbersHard *obj;
	int answer;
	obj = new SmoothNumbersHard();
	clock_t startTime = clock();
	answer = obj->countSmoothNumbers(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
		if (hasAnswer) {
			cout << "Desired answer:" << endl;
			cout << "\t" << p2 << endl;
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
	
	int p0;
	int p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 5000000;
//	p0 = 50;
	p1 = 123;
	p2 = 241786;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 10;
	p1 = 4;
	p2 = 7;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 15;
	p1 = 3;
	p2 = 8;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 5;
	p1 = 20;
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
//	p0 = 49;
	p0 = 4989898;
	p1 = 1000;
	p2 = 1194680;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
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
// A positive integer is said to be k-smooth if its largest prime factor is no greater than k. Compute how many positive integers less than or equal to N are k-smooth.
// 
// DEFINITION
// Class:SmoothNumbersHard
// Method:countSmoothNumbers
// Parameters:int, int
// Returns:int
// Method signature:int countSmoothNumbers(int N, int k)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 5,000,000, inclusive.
// -k will be between 1 and 1,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 10
// 3
// 
// Returns: 7
// 
// Of the first ten positive integers, only 5, 7 and 10 have prime factors greater than 3; the rest are 3-smooth.
// 
// 1)
// 10
// 4
// 
// Returns: 7
// 
// 4 is not prime, so 4-smooth numbers are the same as 3-smooth numbers.
// 
// 2)
// 15
// 3
// 
// Returns: 8
// 
// 
// 
// 3)
// 5
// 20
// 
// Returns: 5
// 
// 
// 
// 4)
// 123456
// 123
// 
// Returns: 23855
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!

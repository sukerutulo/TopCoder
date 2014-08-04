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
#include <cstring>

using namespace std;

// dp[どのフェンスか][何回目か]
int dp[51][101];

vector<vector<int> > Tracks; 
class SteeplechaseTrack {
    vector<int> Fences[3];

    int SIZE,NUM;

int solve(){
    for(int i=0; i<SIZE; i++)
	if(Fences[i][1]!=0) dp[i][0] = Fences[i][1] + Fences[i][0];
    int num;
    bool flag = NUM!=1 ? true : false;
    for(num=1; num<NUM; num++){
	flag = true;
	for(int fence=0; fence<SIZE; fence++){
	    for(int k=0; k<SIZE; k++){
		if(Tracks[k][fence]==0) continue;
		if(dp[k][num-1]==-1) continue;
		int temp = dp[k][num-1] + Tracks[k][fence] + Fences[fence][0];
		dp[fence][num] = max(temp, dp[fence][num]);
	    }
	    for(int k=0; k<SIZE; k++)
		if(dp[fence][num]!=-1 && Tracks[fence][k]!=0) flag = false;
	}
	if(flag) break;
    }
    int res=0;
    for(int num=0; num<NUM; num++){
	for(int fence=0; fence<SIZE; fence++){
	    dp[fence][num] += Fences[fence][2];
	    res = max(dp[fence][num], res);
	}
    }
    return res;
}
    
void debug()
{for(int i=0;i<=SIZE;i++){for(int j=0;j<NUM+3;j++)printf("%3d ",dp[i][j]);cout << endl;}}

public:    
	int maxComplexity(vector <string> fences, vector <string> tracks, int N) {
	    SIZE = fences.size(), NUM=N;
	    bool start_flag = true, end_flag = true;
	    for(int i=0; i<SIZE; i++){
		if(fences[i][1]!='0') start_flag = false;
		if(fences[i][2]!='0') end_flag = false;
	    }
	    if(start_flag or end_flag) return -1;
	    for(int i=0; i<SIZE; i++){
		Fences[i].resize(SIZE);
		for(int j=0; j<3; ++j)
		    Fences[i][j] = fences[i][j] - '0';
		vector<int> temp;
		for(int j=0; j<SIZE; ++j){
		    temp.push_back(tracks[i][j] - '0');
		}
		Tracks.push_back(temp);
		cout << i<<":"<<Tracks.size()<<"*"<< temp.size() << endl;
	    }
	    memset(dp, -1, sizeof(dp));
	    int res = -1;
	    res = solve();
	    for(int i=0; i<SIZE; i++)
		res = max(dp[i][NUM], res);
	    debug();
	    return res;
	}

// abort 
int rec(int fence, int num){
    if(dp[fence][num]!=-1) return dp[fence][num];
    if(num==NUM){
//	if(Fences[fence][2]==0) return dp[fence][num] = -1;
	return dp[fence][num]=Fences[fence][2];
    }
    int start = (num==0) ? Fences[fence][1] : 0;
    int maximum = 1;
//    maximum += Fences[fence][0];
    for(int i=0; i<SIZE; i++){
	if(Tracks[fence][i]==0) continue;
	int next = Tracks[i][fence];
	int add = start + Fences[fence][0] + next;
//	int add = start + Fences[fence][0] + Tracks[fence][i];
//	maximum = max(start+rec(i, num-1)+Tracks[fence][i], maximum);
	maximum = max(rec(i, num+1)+add, maximum);}
    return dp[fence][num]=maximum;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	SteeplechaseTrack *obj;
	int answer;
	obj = new SteeplechaseTrack();
	clock_t startTime = clock();
	answer = obj->maxComplexity(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
		if (hasAnswer) {
			cout << "Desired answer:" << endl;
			cout << "\t" << p3 << endl;
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"310","300","301"};
	p1 = {"010","001","000"};
	p2 = 4;
	p3 = 13;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"923"};
	p1 = {"1"};
	p2 = 100;
	p3 = 1004;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"111","222","333"};
	p1 = {"743","985","380"};
	p2 = 1;
	p3 = 9;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"101","202","303"};
	p1 = {"659","431","770"};
	p2 = 5;
	p3 = -1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

        // ----- test 4 -----
	disabled = false;
	p0 = {"693","982","236"};
	p1 = {"603","986","780"};
	p2 = 10;
	p3 = 172;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {"199", "111"};
	p1 = {"01", "00"};
	p2 = 2;
	p3 = 19;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
       
        // ----- test 6 -----
	disabled = false;
	p0 = {"192","111","111"};
	p1 = {"010","001","000"};
	p2 = 3;
	p3 = 19;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------

        // ----- test 6 -----
	disabled = false;
	p0 = {"947", "851", "878", "846"};
	p1 = {"2101", "4367", "3315", "5502"};
	p2 = 44;
	p3 = 623;
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, p2, true, p3) ) && all_right;
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
// Your company is going to sponsor a steeplechase horse race at your local racecourse.  As a sponsor, you can choose the exact route of the race, and you want it to be as hard as possible.
// 
// 
// The racecourse contains a startling line, a finish line, and several fences connected with tracks.  Horses start at the starting line, run along the tracks, jump over all fences along the way, and end at the finish line.
// 
// 
// You are given a vector <string> fences where the i-th element describes the i-th fence, and contains exactly three digits between '0' and '9', inclusive.  The first digit is the complexity of jumping over the fence.  The second digit is the complexity of running from the starting line to the fence.  If it is '0', that means there is no track between the starting line and the fence.  The third digit is the complexity of running from the fence to the finish line.  If it is '0', that means there is no track between the fence and the finish line.
// 
// 
// You are also given a vector <string> tracks describing the tracks connecting the fences.  The j-th character of the i-th element of tracks is the complexity of running from fence i to fence j.  If that character is '0', that means there is no track from fence i to fence j.  It is possible for a track to exist between a fence and itself.  Note that all tracks are one-way tracks.  If there's a track from fence i to fence j, there isn't necessarily a track from fence j to fence i.  Also, complexities are not symmetrical, so the complexity of running from fence i to fence j may be different from the complexity of running from fence j to fence i.
// 
// 
// A valid route for the race is a sequence of fences with indices i0, i1, ..., in-1 for which all of the following conditions are satisfied:
// 
// There is a track from the starting line to fence i0.
// 
// There is a track from fence ik to fence ik+1 for 0 <= k <= n-2.
// 
// There is a track from fence in-1 to the finish line.
// 
// 
// Note that the same fence may be used multiple times within a route.  Each time the horse runs along a track or jumps over a fence, the corresponding complexity is added to the total complexity for the route.  Return the maximal total complexity for a valid route containing at most N fences.  If the same fence appears multiple times within the route, each occurrence counts toward the total number of fences.  If it is impossible to hold a race which satisfies the constraints on the given racecourse, return -1 instead.
// 
// DEFINITION
// Class:SteeplechaseTrack
// Method:maxComplexity
// Parameters:vector <string>, vector <string>, int
// Returns:int
// Method signature:int maxComplexity(vector <string> fences, vector <string> tracks, int N)
// 
// 
// CONSTRAINTS
// -fences will contain between 1 and 50 elements, inclusive.
// -Each element of fences will contain exactly 3 characters.
// -tracks will contain the same number of elements as fences.
// -Each element of tracks will contain the same number of characters as the number of elements in fences.
// -Each character in fences and tracks will be between '0' and '9', inclusive.
// -Character 0 of each element of fences will not be '0'.
// -N will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"310",
//  "300",
//  "301"}
// {"010",
//  "001",
//  "000"}
// 4
// 
// Returns: 13
// 
// You are allowed to use as many as four fences, but the only valid route for this racecourse is start-0-1-2-finish.
// 
// 1)
// {"923"}
// {"1"}
// 100
// 
// Returns: 1004
// 
// This route consists of 100 jumps over the only fence and 99 runs around this fence, for a total complexity 2 + 100*9 + 99*1 + 3 = 1004.
// 
// 2)
// {"111",
//  "222",
//  "333"}
// {"743",
//  "985",
//  "380"}
// 1
// 
// Returns: 9
// 
// With only one fence allowed, the complexity of a route is the sum of the following  complexities: running from the starting line to the fence, jumping over the fence, and running from the fence to the finish line.
// 
// 3)
// {"101",
//  "202",
//  "303"}
// {"659",
//  "431",
//  "770"}
// 5
// 
// Returns: -1
// 
// There are no tracks leading from the starting line to a fence, so no valid routes can be constructed.
// 
// 4)
// {"693",
//  "982",
//  "236"}
// {"603",
//  "986",
//  "780"}
// 10
// 
// Returns: 172
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!

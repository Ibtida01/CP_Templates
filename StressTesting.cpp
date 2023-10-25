#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ll long long
struct testcase{
    int a,n,b;
};
int randomNumber(int a,int b){
    srand(time(0));
    return a + (rand() % b);
}
testcase generateTestCase(){
    testcase randomTest;
    randomTest.a = randomNumber(1,1e9);
    randomTest.b = randomNumber(1,1e9);
    randomTest.n = randomNumber(1,100);

}
int bruteForce(testcase T){
   int ret;
    //BRUTE FORCE CODE GOES HERE...


   //RETURNING ANSWER (we can return anything we need, eg vectors, sets ,int, double ,char etc.)
    return ret;
}
int optimizedSolution(testcase T){
    int ret;

    //RETURNING ANSWER (we can return anything we need, eg vectors, sets ,int, double ,char etc.)
    return ret;
}

void debugger(){
    testcase random = generateTestCase();
    int ans1 = bruteForce(random);
    int ans2 = optimizedSolution(random);
    if(ans1 != ans2) {
        cout<<"problems found"<<endl;
        cout<<random.a<<" "<<random.b<<" "<<random.n<<endl;
        return;
    }
}

void solve(){

}
int main(){
    srand(time(0));
int t;
cin>>t;
while(t--)
    debugger();
return 0;
}

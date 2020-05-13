#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>

using namespace std;



int solve(vector<int> &numbers, int n, unsigned k){
    if(n <= 20){
        sort(numbers.begin(), numbers.end());
        return numbers[k-1];
    }
    unsigned rest_of_five = n%5;
 
    vector<int> medians;
    medians.reserve((n+4)/5);

    for(unsigned i = 0; i<numbers.size(); i+=5)
    {
        vector<int> helper;
        helper.reserve(5);
        if(i != numbers.size()-rest_of_five){
            for(int j=0; j<=4; j++)
                helper.push_back(numbers[i+j]);
        }
        else
        {
            for(unsigned j=0; j<rest_of_five; j++){
                helper.push_back(numbers[i+j]);
            while(rest_of_five != 5){
                helper.push_back(INT32_MAX);
                rest_of_five++;
            }
            break;
        }         
        }
        sort(helper.begin(),helper.end());
        medians.push_back(helper[2]);
    }
    
    
    int m_5 = solve(medians, medians.size(), floor(medians.size()/2));

    vector<int> smaller, equal, bigger;

    smaller.reserve(n);
    equal.reserve(n);
    bigger.reserve(n);

    for(unsigned i=0; i< numbers.size(); i++){
        if(numbers[i] > m_5)
            bigger.push_back(numbers[i]);
        else if (numbers[i] < m_5)
            smaller.push_back(numbers[i]);
        else
            equal.push_back(numbers[i]);
    }
    if(k <= smaller.size())
        return solve(smaller, smaller.size(), k);
    else if(k <= smaller.size() + equal.size())
        return m_5;

    return solve(bigger, bigger.size(), k - smaller.size() - equal.size());
    
};

int main(){
    ios::sync_with_stdio(false);
    int n;
    unsigned k;
    cin>>n>>k;
    vector<int> numbers;
    numbers.reserve(n+4);
    int tmp;
    for(int i=0; i<n; i++){
        cin>>tmp;
        numbers.push_back(tmp);
    }
    cout<<solve(numbers, n, k);
    return 0;
    
}
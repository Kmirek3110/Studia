#include <iostream>
#include <math.h>
#include<stdio.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>


using namespace std;

struct Coin{
    int nominal;
    int waga;
    Coin( int nominala,int wagaa):nominal(nominala),waga(wagaa) {}
};

struct krok{
    long long  max;
    long long  min;
    int8_t helpermin;
    int8_t helpermax;
};

void solve(vector<Coin> &monety, int ile_waga,int n){

        
       krok dp[ile_waga+1];
       for(int i=0;i<=ile_waga;i++){
           dp[i] = {0,0,0,0};
       }
        bool moze = true;
        for(int i=0;i < ile_waga+1;i++){   
            for(int j=0;j < n;j++){
                if(monety[j].waga <=  i){    
                    if(i != monety[j].waga){
                        moze=false;    
                        if(dp[i-monety[j].waga].max != 0 )
                            moze=true;
                    }        
                    if(!moze)
                        continue;      
                    if((dp[i].min > dp[i-monety[j].waga].min + monety[j].nominal && (i-monety[j].waga + monety[j].waga == i)) || (dp[i].min ==0 && (i-monety[j].waga + monety[j].waga == i)))
                    {                    
                         dp[i].min = dp[i-monety[j].waga].min + monety[j].nominal;
                         dp[i].helpermin = j;
                                                          
                    }    
                    if(dp[i].max < dp[i-monety[j].waga].max + monety[j].nominal && (i-monety[j].waga + monety[j].waga == i)){                                         
                        dp[i].max = dp[i-monety[j].waga].max +monety[j].nominal;
                        dp[i].helpermax = j;              
                    } 
                    
                }
            }
        }
        
        if(dp[ile_waga].min == 0){
            cout<<"NIE"<<endl;
            return;
        }

        cout<<"TAK"<<endl;
           
        int test = ile_waga;
        int test1 = ile_waga;
        int x;
        int maxway[n] = {0};
        int minway[n] = {0};
        
        while(test != 0){
            x = dp[test].helpermin;
            minway[x]++;
            test -= monety[x].waga;
        }
         
       
        while(test1 != 0){
            x = dp[test1].helpermax;
            maxway[x]++;
            test1 -= monety[x].waga;
        }
        cout<<dp[ile_waga].min<<endl;
        for(int i=0; i<n;i++){
            cout<<minway[i]<<" ";
        }

        cout<<endl;
        cout<<dp[ile_waga].max<<endl;
            for(int i=0; i<n;i++){
            cout<<maxway[i]<<" ";
        }
       
        cout<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    
    int ile_waga;
    cin>>ile_waga;
    int n;
    cin>>n;
    vector<Coin> monety;
    int no,w;
    for(int i=0;i<n;i++){
        cin>>no>>w;
        monety.push_back(Coin(no,w));
    }
    solve(monety, ile_waga, n);

    return 0;
}
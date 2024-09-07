#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,b;
    vector<int> q;
    vector<int> r;
    cout<<"Linear Combination and gcd"<<endl;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    int i=a>b?a:b,j=a>b?b:a;
    r.push_back(i);
    r.push_back(j);
    int k=-1;
    cout<<"\nBy Euclidian division algorithm\n";
    do{
        k++;
        r.push_back(i%j);
        q.push_back(i/j);
        cout<<i<<"="<<j<<"*"<<q[k]<<"+"<<r[k+2]<<endl;
        i=j; j=r[k+2];
    }while(r[k+2]!=0);
    r.pop_back();
    cout<<"Reverse Substitution"<<endl;
    int x,y;
    int m=1,n=q[q.size()-2];
    j=r.size()-1;
    i=j;
    int s=0;
    x=r[j-2];
    y=r[j-1];
    while(i>1){
        cout<<r[r.size()-1]<<"="<<x<<"*"<<m<<"-"<<y<<"*"<<n<<endl;
       if(s%2==0){
            y=r[j-3];
            if(j-3<0) break;
            m=m+(n*q[j-3]);
            j--;
            s++;
       }
       else{
            x=r[j-3];
            if(j-3<0) break;
            n=n+(m*q[j-3]);
            s++; j--;
       }
       i--;
    }
    if(q.size()==1){
        cout<<"gcd("<<a<<","<<b<<") = "<<r[r.size()-1]<<"\nm = "<<0<<"\nn = "<<q[0];
    }
    else{
        cout<<"gcd("<<a<<","<<b<<") = "<<r[r.size()-1]<<"\nm = "<<m<<"\nn = "<<n*-1;
    }
    return 0;
}
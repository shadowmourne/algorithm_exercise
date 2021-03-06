#include <iostream>

using namespace std;

int main()
{
    int n, p, f, max;
    int a[20000], b[20000], c[20000];
    while(cin>>n){
        p = 0x7FFFFFFF;
        max = 0;
        for(int i = 0; i < n; ++i){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i] < p)
                p = a[i];
            if(b[i] > max)
                max = b[i];
        }
        while(p <= max){
            f = 0;
            for(int i = 0; i < n; ++i){
                if(a[i] > b[i])
                    continue;
                if(a[i] == p)
                    ++f;
                if(a[i] + c[i] <= p+1)
                    a[i] += c[i];
            }
            if(f & 1){
                cout<<p<<' '<<f<<endl;
                break;
            }
            ++p;
        }
        if(p > max)
            cout<<"DC Qiang is unhappy."<<endl;
    }
    return 0;
}


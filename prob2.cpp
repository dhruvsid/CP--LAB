#include <iostream>
#include <vector>
using namespace std;

vector<int> decrypt(vector<int>& code, int k)
{
    int n = code.size();

    vector<int> ans(n,0);

    if(k==0)
        return ans;

    for(int i=0;i<n;i++)
    {
        int sum=0;

        if(k>0)
        {
            for(int j=1;j<=k;j++)
            {
                sum += code[(i+j)%n];
            }
        }
        else
        {
            for(int j=1;j<=-k;j++)
            {
                sum += code[(i-j+n)%n];
            }
        }

        ans[i]=sum;
    }

    return ans;
}

int main()
{
    vector<int> code={5,7,1,4};

    int k=3;

    vector<int> ans=decrypt(code,k);

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int nCase,Limit,nKind,i,j,k,
        v[111],w[111],c[111],dp[111];
    //v[]存价值，w[]存尺寸，c[]存件数
    //在本题中，价值是米的重量，尺寸是米的价格

    int count,Value[1111],size[1111];
    //count存储分解完后的物品总数
    //Value存储分解完后每件物品的价值
    //size存储分解完后每件物品的尺寸

    cin>>nCase;
    while(nCase--)
    {
        count=0;
        cin>>Limit>>nKind;
        for(i=0;i<nKind;i++)
        {
            cin>>w[i]>>v[i]>>c[i];

            //对该种类的c[i]件物品进行二进制分解
            for(j=1;j<=c[i];j<<=1)
            {
                //<<右移1位，相当于乘2
                Value[count]=j*v[i];
                size[count++]=j*w[i];
                c[i] -= j;
            }
            if(c[i] > 0)
            {
                Value[count]=c[i]*v[i];
                size[count++]=c[i]*w[i];
            }
        }

        //经过上面对每一种物品的分解，
        //现在Value[]存的就是分解后的物品价值
        //size[]存的就是分解后的物品尺寸
        //count就相当于原来的n

        //下面就直接用01背包算法来解
        memset(dp,0,sizeof(dp));

        for(i=0;i<count;i++)
            for(j=Limit;j>=size[i];j--)
                if(dp[j] < dp[j-size[i]] + Value[i])
                    dp[j]=dp[j-size[i]]+Value[i];

        cout<<dp[Limit]<<endl;
    }
    return 0;
}

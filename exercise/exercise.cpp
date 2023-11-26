#include<stdio.h>

int main(void)

{
    int count=0;
    int L,R;
    scanf("%d %d",&L,&R);
    for(int x=L;x<=R;x++)
    {
        if(x%10==2)
        {
            count++;
            
        }
        if(x/10==2)
        {
            count++;
            
        }
        if(x>=100&&x<1000)
        {
            if(x%10==2)
            {
                count++;
                
            }
            
            x/=10;
        }
        if(x>=1000&&x<=10000)
        {
            if(x%10==2)
            {
                count++;
                
            }
            
            x/=10;
        }
        
    }
    printf("%d\n",count);
    return 0;
        
 }
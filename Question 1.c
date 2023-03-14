#include <stdio.h>

int main(){
    int n,j,i;
    int count=0;
    scanf("%d",&n);
    int s0[n],s1[n];
    for(i=0;i<n;i++){
        scanf("%d %d",&s0[i],&s1[i]);
    } 

    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(s0[i]<s0[j]){
                if(s1[i]>s1[j]){
                    count++;
                }
            }
        }
    }
    printf("%d",count);
}

#include<stdio.h>
int main(){
  int n,k,s;
  printf("Enter the number of people present: ");
  scanf("%d",&n);
  int mat[n][n];
  printf("Enter the number of people to skip: ");
  scanf("%d",&k);
  printf("Enter the starting  position: ");
  scanf("%d",&s);
  for(int i=0;i<n;i++){
  	mat[0][i]=i+1;
  }
  int end_ind=n;
  k--;
  for(int i=1;i<n;i++){
     int del_index = (s+k)%end_ind;
     for(int j=0;j<del_index;j++){
        mat[i][j]=mat[i-1][j];
     }
     for(int j=del_index;j<end_ind;j++){
        mat[i][j]=mat[i-1][j+1];
     }
     s=del_index;
     end_ind--;
  }

  for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
         printf("%d ",mat[i][j]);
	  }
    printf("\n");
  }


	return 0;
}



#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int n,i,j;
	printf("====Algoritma A*====\n\n");
	printf("\nMasukan Jumlah vertek : ");scanf("%d",&n);
	int cost[n],h[n],m[n][n],x[n],y[n],visited[n],prev[n];
	printf("===Hubungan vertek===\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&m[i][j]);
			if(m[i][j]==0){
				m[i][j]=9999;
			}
		}
	}
	printf("==Nilai Heuristik setiap vertek ke vertek lain ==\n");
	for(i=0;i<n;i++){
		printf("Vertek %d = ",i);scanf("%d",&h[i]);
	}

	//algoritma a*
	int start,end,temp,min,temp2;
	printf("Masukan vertek asal = ");scanf("%d",&start);

	printf("Masukan vertek tujuan = ");scanf("%d",&end);
	for(i=0;i<n;i++){
			cost[i]=999;
			visited[i]=0;
	}
	cost[start]=0;
	temp=start;
	while(temp!=end){
		min=999;
		for(i=0;i<n;i++){
			if(min > cost[i] && visited[i]==0){
				min=cost[i];
				temp2=i;
			}
		}
		temp=temp2;
		visited[temp]=1;
		for(i=0;i<n;i++){
			if(m[temp][i]!=9999 && visited[i]==0 &&temp!=end){
				if(min+h[i]+m[temp][i] < cost[i]){
					cost[i]=min+m[temp][i];
					prev[i]=temp;
				}
			}
		}
	}
	printf("\n\n Cost terpendek dari %d ke %d adalah = %d dengan rute : \n",start,end,cost[end]);
	i=end;
	while(i!=start){
		printf("%d<--",i);
		i=prev[i];
	}
	printf("%d",start);



	return 0;
}

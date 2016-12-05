#include <stdio.h>
#include <algorithm>
#include <iostream>
#include "querytree.hxx"
#include <vector>
using namespace std;
int main(){
	query_segment_tree<long long> *st;
	st = new sum_segment_tree<long long>();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		long long x;
		scanf("%lld",&x);
		st->update(1,1,n,i,x);
	}
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",st->calculate(1,1,n,x,y));
	}
}


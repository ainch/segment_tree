#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#ifndef _Q_
#define _Q_
template < typename T > 
class query_segment_tree{
public:
	vector < T > tree;
	query_segment_tree(int N=10){
		tree.resize(4*N+10);
	}
	virtual void update(int n,int ns,int ne,int p,T value)=0;
	virtual T calculate(int n,int ns,int ne,int left,int right)=0;
};

template < typename T > 
class sum_segment_tree:public query_segment_tree<T>{
public:
	virtual void update(int n,int ns,int ne,int p,T value){
		vector < T > &tree = query_segment_tree<T>::tree;
		if(p<ns || p>ne)return;
		if(ns==ne){
			tree[n]=value;
		}
		else{
			int m=(ns+ne)/2;
			update(2*n,ns,m,p,value);
			update(2*n+1,m+1,ne,p,value);
			tree[n]=tree[2*n]+tree[2*n+1];
		}
	}
	virtual T calculate(int n,int ns,int ne,int left,int right){
		vector < T > &tree = query_segment_tree<T>::tree;
		if(ne<left || ns>right)return 0;
		if(left<=ns && ne<=right){
			return tree[n];
		}
		int m=(ns+ne)/2;
		T q1,q2;
		q1=calculate(2*n,ns,m,left,right);
		q2=calculate(2*n+1,m+1,ne,left,right);
		return q1+q2;
	}
};
#endif


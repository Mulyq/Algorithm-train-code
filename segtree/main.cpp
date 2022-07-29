const int N=2e5+5;
struct SegTree{
	#define ls (rt<<1)
	#define rs (rt<<1|1)
	#define mid ((R+L)>>1)
	int tre[N<<2][4],Add[N<<2][4];
	void PushUp(int rt){for(int j=0;j<4;j++) tre[rt][j]=tre[ls][j]+tre[rs][j];}
	void CHG(int rt,int p){
		if(Add[rt][p] > 0){
			tre[ls][3]+=tre[ls][3^p];tre[ls][3^p]=0;
			tre[ls][p]+=tre[ls][0];tre[ls][0]=0;
			tre[rs][3]+=tre[rs][3^p];tre[rs][3^p]=0;
			tre[rs][p]+=tre[rs][0];tre[rs][0]=0;
			Add[ls][p]=Add[rt][p];
			Add[rs][p]=Add[rt][p];
		}
		if(Add[rt][p] < 0){
			tre[ls][0]+=tre[ls][p]; tre[ls][p]=0;
			tre[ls][3^p]+=tre[ls][3]; tre[ls][3]=0;
			tre[rs][0]+=tre[rs][p]; tre[rs][p]=0;
			tre[rs][3^p]+=tre[rs][3]; tre[rs][3]=0;
			Add[ls][p]=Add[rt][p];
			Add[rs][p]=Add[rt][p];
		}
		Add[rt][p]=0;
	}
	void PushDown(int rt){
		for(int j=1;j<=2;j++) CHG(rt,j);
	}
	void Build(int rt,int L,int R){
		tre[rt][0]=1;
        tre[rt][1]=tre[rt][2]=tre[rt][3]=0;
		if(L==R) return ;
		Build(ls,L,mid);Build(rs,mid+1,R);
		PushUp(rt);
	}
	void Insert(int rt,int L,int R,int l,int r,int p){
		if(l<=L&&R<=r){
			tre[rt][3]+=tre[rt][3^p];tre[rt][3^p]=0;
			tre[rt][p]+=tre[rt][0];tre[rt][0]=0;
			Add[rt][p]=1;
			return;
		}
		PushDown(rt);
		if(l<=mid) Insert(ls,L,mid,l,r,p);
		if(r>mid) Insert(rs,mid+1,R,l,r,p);
		PushUp(rt);
	}
	void Delete(int rt,int L,int R,int l,int r,int p){
		if(l<=L&&R<=r){
			tre[rt][0]+=tre[rt][p];tre[rt][p]=0;
			tre[rt][3^p]+=tre[rt][3];tre[rt][3]=0;
			Add[rt][p]=-1;
			return;
		}
		PushDown(rt);
		if(l<=mid) Delete(ls,L,mid,l,r,p);
		if(r>mid) Delete(rs,mid+1,R,l,r,p);
		PushUp(rt);
	}
	int Query(int rt,int L,int R,int l,int r){
		if(l<=L&&R<=r) return tre[rt][3];
		int ret=0;
		PushDown(rt);
		if(l<=mid) ret+=Query(ls,L,mid,l,r);
		if(r>mid) ret+=Query(rs,mid+1,R,l,r);
		return ret;
	}
	#undef ls
	#undef rs
	#undef mid
}Seg;
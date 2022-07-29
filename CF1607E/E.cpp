#include<bits/stdc++.h>

using namespace std;

int T,L,D,x,y,rL,lL,uD,dD,row,col;

string s;

int main(){
    scanf("%d",&T);
    while(T --){
        rL = lL = uD = dD = L = D = x = y = 0;
        scanf("%d%d",&row,&col);
        cin >> s;
        for(int i = 0;i < s.size();i ++){
            //x,y来模拟机器人的位置
            if(s[i] == 'L') y --;
            else if(s[i] == 'R')y ++;
            else if(s[i] == 'U')x --;
            else x ++;

            lL = min(lL,y);//初始位置左边走过的最远距离
            rL = max(rL,y);//初始位置右边走过的最远距离
            uD = min(uD,x);//初始位置上边走过的最远距离
            dD = max(dD,x);//初始位置下边走过的最远距离

            L = rL - lL + 1;//框住矩形的长
            D = dD - uD + 1;//框住矩形的宽

            if (D > row) {
                if (x == uD) uD++;//如果是因为最后一步向上走引起D大于row,则要返回上一步
                break;
            }
            if (L > col) {
                if (y == lL) lL++;//如果是因为最后一步向左走引起L大于col,则要返回上一步
                break;
            }
//因为最后是以框住矩形的左上角为参考点输出结果的，所以如果是向右或者向下走引起的退出循环对结果的输出没有影响
        }

        printf("%d %d\n",1 - uD,1 - lL);
    }   

}
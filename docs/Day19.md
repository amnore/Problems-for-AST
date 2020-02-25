# 算法天梯：Day 19
这个题在我看来和Day17的捣蛋鬼那题是一样的，czg大佬在Day17的题中使用的是二分图判断答案是否正确，而我是用的染色法  
这题也可以染色，我们把每支军队看成一个点，每句话都可以得到一些关系，从而确定两个点的颜色关系，将两个点连线（放到同一个数组里）  
已经连上线的一定不会是假话，但是如果某一句话涉及和之前的话（已连接出来的线）无关的东西怎么办呢？没关系，新建一条线就好了  
新线上的点是什么颜色不重要，只要保证相对关系即可。当两个之前毫无关系的线相连的时候，如果颜色恰好和那句话的表述相同就没问题，如果不同就把其中一条线上的点颜色同时向后推移某一个定值，由于相互关系并没有改变所以这并不影响之前的话的成立性。  
如果是同一根线上的两个点相连，如果颜色没有问题就是真话，否则就是假话，忽略本次连线  
理论说完了，上代码
```c++
#include<iostream>
#include<vector>
//又是一个为了好看弄的类，其实就是两个int
class army{
    public:
    int c=-1;//0胜1胜2,其中0,1,2表示三个国家（三种颜色）
    int index=-1;//表示在哪一根线上
};
int main(){
    int n,m,count=0;
    std::cin>>n>>m;
    army a[n+1];
    std::vector<std::vector<int>> v;
    int kind=0,a1,a2;//kind是两个军队的关系，a1，a2是军队编号
    int index=0;
    for(int i=0;i<m;++i){
        std::cin>>kind>>a1>>a2;
        //军队编号超过n肯定是不对的
        if(a1>n||a2>n){
            ++count;
            continue;
        }
        if(kind==1){//同一国家
            //两军队是同一个那么同国家肯定是对的，不用做任何处理
            if(a1==a2){
                continue;
            }
            //如果两个军队都没被染过色
            if(a[a1].c==-1&&a[a2].c==-1){
                //新建一条线
                v.push_back({});
                v[index].push_back(a1);
                v[index].push_back(a2);
                a[a1].index=index;
                a[a2].index=index;
                //给这两个军队随便染个相同的颜色，这里选择0
                a[a1].c=0;
                a[a2].c=0;
                ++index;
                continue;
            }
            //一个染色一个未染色，直接放同一个线上染同一个色就行
            if(a[a1].c==-1&&a[a2].c!=-1){
                a[a1].index=a[a2].index;
                v[a[a2].index].push_back(a1);
                a[a1].c=a[a2].c;
                continue;
            }
            if(a[a2].c==-1&&a[a1].c!=-1){
                a[a2].index=a[a1].index;
                v[a[a1].index].push_back(a2);
                a[a2].c=a[a1].c;
                continue;
            }
            //两个都染过色了
            if(a[a1].c!=-1&&a[a2].c!=-1){
                if(a[a1].c!=a[a2].c){
                    //颜色不一样看是不是同一条线，同线就是假话，否则改掉其中一条线全部颜色，两条线合并
                    if(a[a1].index==a[a2].index){
                        ++count;
                        continue;
                    }
                    else{
                        int temp=a[a2].c-a[a1].c;
                        int idx=a[a1].index;
                        int index1=a[a2].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            a[v[idx][j]].c=(a[v[idx][j]].c+temp+3)%3;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
                else{
                    //颜色一样同一条线不做处理，不同的线直接合并
                    if(a[a1].index==a[a2].index){
                        continue;
                    }
                    else{
                        int idx=a[a1].index;
                        int index1=a[a2].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
            }
        }
        else{//a1战胜a2
            //我杀我自己肯定是不行的
            if(a1==a2){
                ++count;
                continue;
            }
            //其实后面的和上半部分差不多，只是相同颜色变成了胜负关系要注意对3取模
            //两个未染色
            if(a[a1].c==-1&&a[a2].c==-1){
                v.push_back({});
                v[index].push_back(a1);
                v[index].push_back(a2);
                a[a1].index=index;
                a[a2].index=index;
                a[a1].c=0;
                a[a2].c=1;
                ++index;
                continue;
            }
            //一个染色一个没有
            if(a[a1].c==-1&&a[a2].c!=-1){
                a[a1].index=a[a2].index;
                v[a[a2].index].push_back(a1);
                a[a1].c=(a[a2].c+2)%3;
                continue;
            }
            if(a[a2].c==-1&&a[a1].c!=-1){
                a[a2].index=a[a1].index;
                v[a[a1].index].push_back(a2);
                a[a2].c=(a[a1].c+1)%3;
                continue;
            }
            //两个都染色
            if(a[a1].c!=-1&&a[a2].c!=-1){
                if((a[a1].c+1)%3!=a[a2].c){
                    //不符合战胜关系
                    if(a[a1].index==a[a2].index){
                        ++count;
                        continue;
                    }
                    else{
                        int temp=a[a1].c-a[a2].c;
                        int idx=a[a2].index;
                        int index1=a[a1].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            a[v[idx][j]].c=(a[v[idx][j]].c+temp+4)%3;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
                else{
                    //符合战胜关系
                    if(a[a1].index==a[a2].index){
                        continue;
                    }
                    else{
                        int idx=a[a1].index;
                        int index1=a[a2].index;
                        for(int j=0;j<v[idx].size();++j){
                            a[v[idx][j]].index=index1;
                            v[index1].push_back(v[idx][j]);
                        }
                        v[idx].clear();
                    }
                }
            }
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}
```
这个代码又臭又长，主要是上下部分基本上一样但是我又没有写成函数的原因。。。  
~~才不会告诉你们是我懒直接CTRL+C/V了~~
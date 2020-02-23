# 算法天梯：Day 16
这个题就还可以吧，就是看能保证身高体重同时上升的最大长度问题  
我们可以先按照某一要素（身高或者体重）排序，然后再看另一个要素  
现在它们已经按某一个要素排好序了（假设是升序），那么最前面的一些只能当顶部，也就是最前面那些最大长度只能是1  
之后看后面的人，如果他能上面能放人，那他当底部对应的最大长度就是他上面能放的人中长度最长的那个再加1  
由于前面的每一个我们都处理过了，那么每个人的最大长度就确定了，找到最大的那个就行了  
上代码
```c++
#include<iostream>
//定义了一个类，只是为了看起来方便，其实就是存了两个int
class people{
    public:
    int h=0;//身高
    int w=0;//体重
    //这里我定义了一个对两个人的比较用的小于号方法，其实就是身高体重均小于
    bool operator<(const people &a){
        return this->h<a.h&&this->w<a.wreturn;
    }
};
//排序，详见Day1,只是把排序的变量变成了people类型，比较的方式变成的身高而已
void sort(people a[],int b,int e){
    int i=b,j=e;
    int k=a[b].h;
    if(b>=e)
        return;
    while(i<j){
        while(a[i].h<k&&i<e){
            i++;
        }
        while(a[j].h>=k&&j>b){
            j--;
        }
        if(i<j){
            people temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    sort(a,b,j);
    sort(a,j+1,e);
    return;
}
int main(){
    int n,max=0;
    std::cin>>n;
    people p[n];
    int length[n];
    for(int i=0;i<n;++i){
        std::cin>>p[i].h>>p[i].w;
        length[i]=0;
    }
    sort(p,0,n-1);
    for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            if(p[j]<p[i]){//这个比较就是我在class people里写的小于号方法
                //这里就是对每一个小于他的去比较长度，取最大的那个
                length[i]=(length[j]>length[i]?length[j]:length[i]);
            }
        }
        //加上他自己
        ++length[i];
        //判断最大值
        max=(max>length[i]?max:length[i]);
    }
    std::cout<<max<<std::endl;
    return 0；
}
```
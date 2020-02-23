# 算法天梯：Day 10
从这个题就能看出来出题人满满的恶意啊，__不要使用递归方法解题__，多么可恶  
不用递归当然就是循环咯，找到第一个右括号，找到和它匹配的左括号，然后把里面的东西展开，重复进行直到没有右括号为止  
不说废话了上代码  
```c++
#include<iostream>
#include<string>
int main(){
    std::string str;
    std::cin>>str;
    std::string str_b="",str_m="",str_e="";//b表示前半部分，m是要重复的部分，e是后半部分
    bool count_r;
    while(true){
        str_b="";str_m="";str_e="";
        count_r=false;
        int l=0,r,num=0;
        int i;
        for(r=0;r<str.size();++r){
            //从前往后找右括号
            if(str[r]==']'){
                count_r=true;
                //从右括号往前找左括号
                for(l=r;l>0;--l){
                    if(str[l]=='['){
                        break;
                    }
                }
                break;
            }
        }
        //没找到右括号就结束了
        if(!count_r){
            break;
        }
        //算一下重复次数
        for(i=1;i<=l&&str[l-i]>='0'&&str[l-i]<='9';++i){
            int temp=1;//temp是表示位数，就是个十百千万之类的
            for(int j=1;j<i;++j){
                temp*=10;
            }
            num+=(((str[l-i])-48)*temp);
        }
        //偷懒用了分割字符串的函数
        str_b=str.substr(0,l-i+1);
        str_m=str.substr(l+1,r-l-1);
        str_e=str.substr(r+1,str.size()-r-1);
        std::string str4="";//临时用来存重复之后的被重复部分
        for(i=0;i<num;++i){
            str4=str4+str_m;
        }
        str=str_b+str4+str_e;
    }
    std::cout<<str<<std::endl;
    return 0;
}
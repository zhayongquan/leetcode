//stl list 
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

// int main()
// {
//     list<int>monkey ;
//     int m,n;
//     cout<<"enter sum monkey n:"<<endl;
//     cin>>n;
//     cout<<"enter interval m:"<<endl;
//     cin>>m;
//     while(true)
//     {
//         if(m==0 && n==0)
//             break;
//         monkey.clear();  //init the monkey list
//         for(int i = 0;i<n;++i)
//         {
//             monkey.push_back(i);  // push_back monkey number to list
//         }
//         list<int>::iterator it = monkey.begin();   //it is mark to pop,init is list head 
//         while(monkey.size()>1)   //only return 1 monkey
//         {
//             for(int k = 0; k<m;++k)
//             {
//                 ++it;
//                 if(it == monkey.end())
//                 it = monkey.begin();
//             }
//             it = monkey.erase(it);
//             if(it ==  monkey.end())
//             it = monkey.begin();
//         } 
//         cout<<"the chose monkey is:"<<endl;
//         cout<<monkey.front()<<endl;   //input first number is only monkey;
//         break;
//     }
//     return 0;


#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> monkeys;
        int n, m;
        cout<<"enter the number n:"<<endl;
        cin >> n ;
        cout<<"enter the number of interval:"<<endl;
        cin>> m;
        if (n == 0 && m == 0)
          return false;
        monkeys.clear();  //清空list容器
        for (int i = 1; i <= n; ++i)  //将猴子的编号放入list
            monkeys.push_back(i);
        list<int>::iterator it = monkeys.begin();
        while (monkeys.size() > 1) { //只要还有不止一只猴子，就要找一只猴子让其出列
            for (int i = 1; i < m; ++i) { //报数
                ++it;
                if (it == monkeys.end())
                    it = monkeys.begin();
            }
            it = monkeys.erase(it); //删除元素后，迭代器失效，
                                    //要重新让迭代器指向被删元素的后面
            if (it == monkeys.end())
                it = monkeys.begin();
        }
        cout << monkeys.front() << endl; //front返回第一个元素的引用
    
    return 0;
}
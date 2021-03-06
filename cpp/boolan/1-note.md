#类的实现
##构造函数
###实现
类在构造函数中进行数据成员的初始化,任何类的对象只要被创建,就会执行构造函数。

###设计
类可以有多个构造函数,上文中第 1 行,第 2 行的函数都是构造函数。第 1 行 的构造函数对类的成员变量进行默认的初始化,第 2 行的构造函数可以根据传 入的参数初始化成员变量。
####合成默认构造函数
* 我们已经知道构造函数是对类的成员变量进行初始化,但是当我们编写一个 类,却没有编写构造函数时,我们会发现成员变量已经被初始化(虽然初始 化的值可能不那么可爱),这是因为这个时候类通过一个特殊的构造函数来 控制默认初始化过程,这个函数称之为默认构造函数。默认构造函数无需任 何参数(就是上文第 1 行的代码)。* 此时我们没有显式的定义构造函数或者默认构造函数,编译器就为我们隐式 的创建了一个默认构造函数。这种编译器创建的构造函数又叫做合成的默认 构造函数。


##操作符重载
###成员函数的操作符重载
![image](https://cloud.githubusercontent.com/assets/6140508/22282367/d849d8c8-e316-11e6-8964-ebde2380908b.png)

```
bool Date::operator < (const Date& rhs) const
```

###非成员函数的操作符重载
![image](https://cloud.githubusercontent.com/assets/6140508/22282444/5acfa8f4-e317-11e6-9617-44a4def29aba.png)
# CS50

<!--ts-->
* [CS50](#cs50)
   * [<strong>week2_Arrays</strong>](#week2_arrays)
   * [<strong>week3_Algorithms</strong>](#week3_algorithms)
   * [<strong>week4_Memory</strong>](#week4_memory)
   * [<strong>week5_Data_Structures</strong>](#week5_data_structures)
      * [<strong>malloc()和calloc()</strong>](#malloc和calloc)
   * [<strong>week6_Python</strong>](#week6_python)
   * [<strong>week7_SQL</strong>](#week7_sql)
   * [<strong>week8_HTML, CSS, JavaScript</strong>](#week8_html-css-javascript)
   * [<strong>week9_Flask</strong>](#week9_flask)
   * [<strong>week10_Ethics</strong>](#week10_ethics)

<!-- Added by: light, at: Fri Jul 23 20:50:56 CST 2021 -->

<!--te-->

## **week2_Arrays**

* it turns out that a string ends with a special character, ‘\0’, or a byte with all bits set to 0. This character is called the null character, or null terminating character. So we actually need four bytes to store our string “HI!”:

![](https://cdn.jsdelivr.net/gh/light266/pic@main/study/memory_with_string.png)

<br/>

-----------------
<br/>

## **week3_Algorithms**

* Merge sort

![](https://cdn.jsdelivr.net/gh/light266/pic@main/study/Merge_sort.jpg)

* 注意**递归算法**

<br/>

-----------------
<br/>

## **week4_Memory**
```
typedef char *string;
```

C 库函数 void *malloc(size_t size) 分配所需的内存空间，并返回一个指向它的指针。

valgrind ./copy2   可以用来检查程序使用和释放的内存

程序的内存分布
![程序的内存](https://cdn.jsdelivr.net/gh/light266/pic@main/study/20201215202633.png)

所有JPG图的开头3个字节都是 FF D8 FF

<br/>

-----------------
<br/>

## **week5_Data_Structures**

`int *y` 这样的初始化实际并没有赋值
没有给y赋值，y没有具体指向的位置，所以`*y=13`那里是错的
![](https://cdn.jsdelivr.net/gh/light266/pic@main/study/20201221143029.png)

### **malloc()和calloc()**

    malloc()函数有一个参数,即要分配的内存空间的大小:
    void *malloc(size_t size);

    calloc()函数有两个参数,分别为元素的数目和每个元素的大小,这两个参数的乘积就是要分配的内存空间的大小。
    void *calloc(size_t numElements,size_t sizeOfElement);

    如果调用成功,函数malloc()和函数calloc()都将返回所分配的内存空间的首地址。

    函数calloc()会将所分配的内存空间中的每一位都初始化为零，而malloc()不会

<br/>

nul是\0   null是0x0

<br/>

a linked list struct in C
![](https://cdn.jsdelivr.net/gh/light266/pic@main/study/20201221160933.png)

`(*n).number = 2;` 和 `n->number = 2;` 等价

```
// Print list
for (node *tmp = list; tmp != NULL; tmp = tmp->next)
{
    printf("%i\n", tmp->number);
}
```

二分法搜索  在tree结构里
```
bool search(node *tree)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (50 < tree->number)
    {
        return search(tree->left);
    }
    else if (50 > tree->number)
    {
        return search(tree->right);
    }
    else
    {
        return true;
    }
}
```

<br/>

* hash tables  按前几个字母的顺序，把东西扔进不同的盒子，从而近似得到O(1)

* tries   真正的O(1)，但是消耗大量存储空间
![](https://cdn.jsdelivr.net/gh/light266/pic@main/study/20201221203942.png)

* queue  一个FIFO(first in, first out)的数据结构
* stack  LIFO

<br/>

-----------------
<br/>

## **week6_Python**

* 在循环或者条件语句里面被定义的变量可以在外面后面使用（Python可以，C不行）

    Python和C 在函数里面定义的变量都不能跨函数使用

* 可以用这种形式写Python，有内容的主函数在前面，然后是一堆子函数，最后放个`main()`
```
def main():
    cough(3)

def cough(n):
    for i in range(n):
        print("cough")

main()
```

python可以用这种类似 `%s` 的 `print(f"Average: {scores}")` 注意里面有个 `f`

`print(c, end="")` 普通的print末尾自带'\n'

dictionary in python
```
# dictionary in python

people = {
    "EMMA": "617-555-0100",
    "RODRIGO": "617-555-0101",
    "BRIAN": "617-555-0102",
    "DAVID": "617-555-0103"
}

# Search for EMMA
if "EMMA" in people:
    print(f"Found {people['EMMA']}")
```

python 里没有char，所以用 `"` 和 `'` 都可以，除非在 `" "` 里套 `' '` 用作区分

`s[i:j]` 取字符串的第i个至第j个（不包括j的那个）

<br/>

-----------------
<br/>

## **week7_SQL**

可以直接用 `sorted` 来排序；`lambda item: item[1]` 定义了一个一行的函数，输入是item，输出是item[1]
```
for title, count in sorted(counts.items(), key=lambda item: item[1], reverse=True):
    print(title, count, sep=" | ")
```

**SQL**: Structured Query Language

<br/>

-----------------
<br/>

## **week8_HTML, CSS, JavaScript**

<br/>

-----------------
<br/>

## **week9_Flask**

在python里，`__name__` 表示当前文件的文件名

永远不要相信你的用户，他们总是会整出各种骚操作233

<br/>

-----------------
<br/>

## **week10_Ethics**


-----------------

![](https://cdn.jsdelivr.net/gh/light266/pic@main/study/%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20201221162358.png)
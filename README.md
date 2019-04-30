# ByteDance
## 字节跳动算法岗位笔试题目

**求取最少找零**

* 题目内容：
  有一个人用一张1024元的纸币购买价值n元的商品，卖家用四种硬币找零，分别是1、4、16、64，问卖家找零最少需要多少个硬币。
* 解题思路：
  将硬币从大到小排序，依次序找零即可
* 代码指路：
  change.cpp
* 代码解析：
  在change.cpp文件中提供了两种形式的解答，分别为change_solution1()（自己写的）和change_solution2()（别人写的）。

**字符串自动处理**

* 题目内容：
  有一个程序员写了个自动处理字符串的代码，规则有两条：①如果有aabb型子串，改为aab；②如果有ccc型子串，改为cc。让我们复现程序员的代码。
* 解题思路：
  我的解题思路是刚开始设置大小为2的滑动窗口检测aa型或cc型（就是有两个相邻一样的字符），如果有，就开始检测以下情况：如果第3个字符还是一样的，就符合ccc型字符串；如果第3个字符不一样，但第3个字符和第4个字符一样，则符合aabb型字符串；
> P.S.>>这里需要注意一点，例如，对于ccc型来说，如果第4个、第5个字符...第m个字符还是c，就需要顺便一次性全删除，不然处理完还会存在ccc型字符的。对于aabb型也是一样的。
* 代码指路：
  auto_process_str.cpp
* 代码解析：
  在change.cpp文件中提供了两种形式的解答，分别为auto_str()（自己写的）和auto_str2()（别人写的，这个解题思路就不详写了，大致是把存在ccc型和aabb型字符串的地方用@字符来替换，后面打印的时候跳过@不打印就好）。


**分发奖品问题**

* 题目内容：
  老师要给一群学生根据他们的成绩发奖品，学生们围在一个圆桌周围，每个人都有自己的成绩。发奖品的规则是：①每个学生都至少有一个奖品；②如果某学生比左右邻座的学生成绩好，那他应收到比他们更多的奖品。问：老师至少需要准备多少个奖品。
* 解题思路：
  如果涉及到这种圆桌的同桌问题，我一般考虑用双向链表实现的。这样在计算某个同学的奖品数时使用*next和*previous指针比较方便跟同桌进行“成绩交流”～hhhh。至于如何获得最少奖品数的问题，只要把成绩从低到高进行排序，然后从成绩最低的开始计算即可。左或右同桌成绩比自己高，但他/她的奖品数不大于自己时，则他/她的奖品数等于自身奖品数再+1.(反正就是要比自己多一个就对了，没办法成绩高的就是硬气～～)。
* 代码指路：
  group_prize.cpp
* 代码解析：
  这里我在实现的时候是想顺便复习一下双向链表的实现的，所以这个代码实现在某些地方有可能有一丢丢滴冗余，如果嫌弃就只看看👆的解题思路就好～


**绳子等长分割问题**

* 题目内容：
  有n根绳子，给出每根的长度。现在要求从这n根绳子中剪出m根等l长的绳子（注：不能拼接），问等长绳子最长多长。
* 解题思路：
  这里我的解题思路比较粗暴，就是设置l的最大值为所有n根绳子长度里的最小值，梯度为-0.01，然后试！！！没错，粗暴地直到得到m根等长的绳子。
* 代码指路：
  rope.cpp
* 代码解析：
  粗暴地不想说啥了

**补充：堆排序的实现**

* 在做题的过程中老要我排序，好烦啊，所以我就干脆温习一下数据结构里的排序了，用数组实现的，说实话，在计算各种各样的下标时让我有点崩溃。。。哼！这是我最后一次用数组实现树结构了😠！（悄悄的立个flag～🤫）



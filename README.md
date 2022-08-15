# Algorithm-Notes

记录一下会的算法(虽然可能明天就忘了).

`main.cpp` 没什么用(), 用到哪个就把哪个单独拎出来吧.

---

目前的收录如下

---

`NumberTheory` - 数论类算法

函数名                  | 文件           |作用                            | 说明
------------------------|----------------|--------------------------------|------------
fastpow                 | fastpow.cpp    | 快速幂                         |
gcd                     | gcd.cpp        | 最大公因数                     |
exgcd                   | gcd.cpp        | 拓展欧几里得                   | 求解方程 `ax + by = k`
inv                     | inv.cpp        | 求乘法逆元                     |

---

`Signal` - 信号处理类算法

函数名                  | 文件           |作用                            | 说明
------------------------|----------------|--------------------------------|------------
dft                     | transform.cpp  | 离散傅里叶变换                 |
idft                    | transform.cpp  | 离散傅里叶逆变换               |
fft                     | transform.cpp  | 快速傅里叶变换                 | 
ifft                    | transform.cpp  | 快速傅里叶逆变换               |
hilbert                 | transform.cpp  | 离散希尔伯特变换               |
hilbert_fft             | transform.cpp  | 离散希尔伯特变换	              | 需要先fft

---
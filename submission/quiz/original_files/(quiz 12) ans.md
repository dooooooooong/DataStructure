Tree가 모양을 **바꿀 때마다** AVL tree들을 그리고, 각 단계별로 LL, RR, LR, RL을 표시하여 제출하십시오. 



1. **Insert the sequence of elements (10, 20, 15, 25, 30, 16, 18, 19) into an AVL tree. **
    **Delete 30 in the AVL tree that you got above and rebalance it.** 

```
Insert 10
Insert 20
```

![image-20220109003141147](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109003141147.png) 



```
Insert 15
[RL] case 10 ( [LL]case 20, [RR]case 10) 
```

![image-20220109003539415](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109003539415.png) 



```
Insert 25
```

![image-20220109003652137](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109003652137.png) 

```
Insert 30
[RR]case 20
```

![image-20220109003737216](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109003737216.png) 

```
Insert 16
[RL]case 15 ([LL]case 25, [RR]case 15)
```

![image-20220109003854625](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109003854625.png)



```
Insert 18
```

 ![image-20220109003936088](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109003936088.png) 

```
Insert 19
[RR]case 16
```

![image-20220109004034585](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109004034585.png) 



```
Delete 30
[LR]case 20 ([RR]case 15, [LL]case 20)
```

![image-20220109004204617](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109004204617.png) 









**2. Delete 32 in the AVL tree**

![image-20220109000207560](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109000207560.png) 



Answer:

    [LL]case at 78

![image-20220109002430652](C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109002430652.png)







```
[RR]case at 44
```



<img src="C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20220109000229285.png" alt="image-20220109000229285" style="zoom:50%;" /> 
![](http://train.usaco.org/usaco/cow1.jpg)

<center>**<font size="7">Beef McNuggets</font>**  
**Hubert Chen**</center>

Farmer Brown's cows are up in arms, having heard that McDonalds is considering the introduction of a new product: Beef McNuggets. The cows are trying to find any possible way to put such a product in a negative light.

One strategy the cows are pursuing is that of 'inferior packaging'. ''Look,'' say the cows, ''if you have Beef McNuggets in boxes of 3, 6, and 10, you can not satisfy a customer who wants 1, 2, 4, 5, 7, 8, 11, 14, or 17 McNuggets. Bad packaging: bad product.''

Help the cows. Given N (the number of packaging options, 1 <= N <= 10), and a set of N positive integers (1 <= i <= 256) that represent the number of nuggets in the various packages, output the largest number of nuggets that can not be purchased by buying nuggets in the given sizes. Print 0 if all possible purchases can be made or if there is no bound to the largest number.

The largest impossible number (if it exists) will be no larger than 2,000,000,000.

### PROGRAM NAME: nuggets

### INPUT FORMAT

<table border="1">

<tbody>

<tr>

<td>Line 1:</td>

<td>N, the number of packaging options</td>

</tr>

<tr>

<td>Line 2..N+1:</td>

<td>The number of nuggets in one kind of box</td>

</tr>

</tbody>

</table>

### SAMPLE INPUT (file nuggets.in)

<pre>3
3
6
10
</pre>

### OUTPUT FORMAT

The output file should contain a single line containing a single integer that represents the largest number of nuggets that can not be represented or 0 if all possible purchases can be made or if there is no bound to the largest number.

### SAMPLE OUTPUT (file nuggets.out)

<pre>17
</pre>

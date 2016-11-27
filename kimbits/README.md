<html><head> <title>Problem 69: Stringsobits</title> </head>
<img src="http://train.usaco.org/usaco/cow1.jpg" width="742" height="118">
<center>
<b><font size="7">Stringsobits</font></b><br>
<b>Kim Schrijvers</b>
</center>

<p> Consider an ordered set S of strings of N (1 &lt;= N &lt;= 31)
bits.  Bits, of course, are either 0 or 1.

</p><p> This set of strings is interesting because it is ordered and
contains all possible strings of length N that have L (1 &lt;= L
&lt;= N) or fewer bits that are `1'.

</p><p> Your task is to read a number I (1 &lt;= I &lt;= sizeof(S))
from the input and print the Ith element of the ordered set for N
bits with no more than L bits that are `1'.

</p><h3>PROGRAM NAME: kimbits</h3>

<h3>INPUT FORMAT</h3>

A single line with three space separated integers: N, L, and I.

<h3>SAMPLE INPUT (file kimbits.in) </h3>

<pre>5 3 19
</pre>

<h3>OUTPUT FORMAT</h3>

A single line containing the integer that represents the Ith element
from the order set, as described.

<h3>SAMPLE OUTPUT (file kimbits.out)</h3>

<pre>10011
</pre>

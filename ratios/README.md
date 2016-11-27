<img src="http://train.usaco.org/usaco/cow1.jpg" width="742" height="118">
<center>
<b><font size="7">Feed Ratios</font></b><br>
<b>1998 ACM Finals, Dan Adkins</b>
</center>

<p> Farmer John feeds his cows only the finest mixture of cow food,
which has three components:  Barley, Oats, and Wheat.  While he knows
the precise mixture of these easily mixable grains, he can not buy that
mixture!  He buys three other mixtures of the three grains and then
combines them to form the perfect mixture.

</p><p> Given a set of integer ratios barley:oats:wheat, find a way to
combine them IN INTEGER MULTIPLES to form a mix with some goal ratio
x:y:z.

</p><p>
For example, given the goal <tt>3:4:5</tt> and the ratios of three mixtures:
</p><pre>        1:2:3
        3:7:1
        2:1:2
</pre>
your program should find some minimum number of integer units (the
`mixture') of the first, second, and third mixture that should be mixed
together to achieve the goal ratio or print `NONE'.   `Minimum number'
means the sum of the three non-negative mixture integers is minimized.

<p> For this example, you can combine eight units of mixture 1, one
unit of mixture 2, and five units of mixture 3 to get seven units of
the goal ratio:
</p><pre>    8*(1:2:3) + 1*(3:7:1) + 5*(2:1:2) = (21:28:35) = 7*(3:4:5)
</pre>

<p> Integers in the goal ratio and mixture ratios are all non-negative
and smaller than 100 in magnitude.  The number of units of each type of
feed in the mixture must be less than 100.  The mixture ratios are not
linear combinations of each other.

</p><h3>PROGRAM NAME: ratios</h3>

<h3>INPUT FORMAT</h3>

<table border="1">
<tbody><tr> <td> Line 1: </td> <td> Three space separated integers that
represent the goal ratios</td> </tr>
<tr> <td> Line 2..4: </td> <td>Each contain three space
separated integers that represent the ratios of the three mixtures
purchased.</td> </tr>
</tbody></table>

<h3>SAMPLE INPUT (file ratios.in) </h3>

<pre>3 4 5
1 2 3
3 7 1
2 1 2
</pre>

<h3>OUTPUT FORMAT</h3>

<p>The output file should contain one line containing four integers or
the word `NONE'.  The first three integers should represent the number
of units of each mixture to use to obtain the goal ratio.  The fourth
number should be the multiple of the goal ratio obtained by mixing the
initial feed using the first three integers as mixing ratios.

</p><h3>SAMPLE OUTPUT (file ratios.out)</h3>

<pre>8 1 5 7
</pre>

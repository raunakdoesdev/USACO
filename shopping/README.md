<html><head> <title>Problem 32: Shopping Offers</title> </head>
<img src="http://train.usaco.org/usaco/cow1.jpg" width="742" height="118">
<center>
<b><font size="7">Shopping Offers</font></b><br>
<b>IOI'95</b>
</center>

<p> In a certain shop, each kind of product has an integer price.  For
example, the price of a flower is 2 zorkmids (z) and the price of a vase
is 5z.  In order to attract more customers, the shop introduces some
special offers.

</p><p> A special offer consists of one or more product items together for
a reduced price, also an integer.  Examples:
</p><ul>
<li>three flowers for 5z instead of 6z, or
</li><li>two vases together with one flower for 10z instead of 12z.
</li></ul>

<p> Write a program that calculates the price a customer has to pay for
a purchase, making optimal use of the special offers to make the price
as low as possible.  You are not allowed to add items, even if that
would lower the price.

</p><p> For the prices and offers given above, the (lowest) price for three
flowers and two vases is 14z:  two vases and one flower for the reduced
price of 10z and two flowers for the regular price of 4z.

</p><h3>PROGRAM NAME: shopping</h3>

<h3>INPUT FORMAT</h3>

<p>The input file has a set of offers followed by a purchase.
<table border="1">
<tbody><tr> <td> Line 1: </td> <td>s, the number of special offers, (0 &lt;=
          s &lt;= 99).  </td> </tr>
<tr> <td> Line 2..s+1: </td> <td> Each line describes an offer using
several integers.  The first integer is n (1 &lt;= n &lt;= 5), the number
of products that are offered.  The subsequent n pairs of integers c and
k indicate that k items (1 &lt;= k &lt;= 5) with product code c (1 &lt;=
c &lt;= 999) are part of the offer.  The last number p on the line stands
for the reduced price (1 &lt;= p &lt;= 9999).  The reduced price of an
offer is less than the sum of the regular prices.  </td> </tr>
<tr> <td> Line s+2: </td> <td>
The first line contains the number b (0 &lt;= b &lt;= 5) of different
kinds of products to be purchased. </td></tr>
<tr> <td> Line s+3..s+b+2: </td> <td> Each of the subsequent b lines
contains three values: c, k, and p.  The value c is the (unique) product
code (1 &lt;= c &lt;= 999).  The value k indicates how many items of
this product are to be purchased (1 &lt;= k &lt;= 5).  The value p is
the regular price per item (1 &lt;= p &lt;= 999).  At most 5*5=25 items
can be in the basket.  </td> </tr>

</tbody></table>

</p><h3>SAMPLE INPUT (file shopping.in) </h3>

<pre>2
1 7 3 5
2 7 1 8 2 10
2
7 3 2
8 2 5
</pre>

<h3>OUTPUT FORMAT</h3>

A single line with one integer: the lowest possible price to be paid
for the purchases.

<h3>SAMPLE OUTPUT (file shopping.out)</h3>

<pre>14
</pre>

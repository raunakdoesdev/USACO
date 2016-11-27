<html><head> <title>Problem 2: Home on the Range</title> </head>
<img src="http://train.usaco.org/usaco/cow1.jpg" width="742" height="118">
<center>
<b><font size="7">Home on the Range</font></b><br>
</center>

<p> Farmer John grazes his cows on a large, square field N (2 &lt;= N
&lt;= 250) miles on a side (because, for some reason, his cows will only
graze on precisely square land segments).  Regrettably, the cows have
ravaged some of the land (always in 1 mile square increments). FJ needs
to map the remaining squares (at least 2x2 on a side) on which his cows
can graze (in these larger squares, no 1x1 mile segments are ravaged).

</p><p> Your task is to count up all the various square grazing areas within
the supplied dataset and report the number of square grazing areas (of
sizes &gt;= 2x2) remaining. Of course, grazing areas may overlap for
purposes of this report.


</p><h3>PROGRAM NAME: range</h3>

<h3>INPUT FORMAT</h3>

<table border="1">
<tbody><tr> <td> Line 1: </td> <td> N, the number of miles on each side of
the field.</td> </tr>
<tr> <td> Line 2..N+1: </td> <td> N characters with no spaces.  0
	  represents "ravaged for that block; 1 represents "ready to
	  eat".  </td>
</tr>
</tbody></table>

<h3>SAMPLE INPUT (file range.in) </h3>

<pre>6
101111
001111
111111
001111
101101
111001
</pre>

<h3>OUTPUT FORMAT</h3>

<p>Potentially several lines with the size of the square and the
number of such squares that exist.  Order them in ascending order from
smallest to largest size.


</p><h3>SAMPLE OUTPUT (file range.out)</h3>

<pre>2 10
3 4
4 1  
</pre>

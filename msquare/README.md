![](http://train.usaco.org/usaco/cow1.jpg)

<center>**<font size="7">Magic Squares</font>**  
**IOI'96**</center>

Following the success of the magic cube, Mr. Rubik invented its planar version, called magic squares. This is a sheet composed of 8 equal-sized squares:

<center>

<table border="all">

<tbody>

<tr>

<td>1</td>

<td>2</td>

<td>3</td>

<td>4</td>

</tr>

<tr>

<td>8</td>

<td>7</td>

<td>6</td>

<td>5</td>

</tr>

</tbody>

</table>

</center>

In this task we consider the version where each square has a different color. Colors are denoted by the first 8 positive integers. A sheet configuration is given by the sequence of colors obtained by reading the colors of the squares starting at the upper left corner and going in clockwise direction. For instance, the configuration of _Figure 3_ is given by the sequence (1,2,3,4,5,6,7,8). This configuration is the initial configuration.

Three basic transformations, identified by the letters 'A', 'B' and 'C', can be applied to a sheet:

*   'A': exchange the top and bottom row,
*   'B': single right circular shifting of the rectangle,
*   'C': single clockwise rotation of the middle four squares.

Below is a demonstration of applying the transformations to the initial squares given above:

<center>

<table>

<tbody>

<tr>

<td>**A:**</td>

<td>

<table border="all">

<tbody>

<tr>

<td>8</td>

<td>7</td>

<td>6</td>

<td>5</td>

</tr>

<tr>

<td>1</td>

<td>2</td>

<td>3</td>

<td>4</td>

</tr>

</tbody>

</table>

</td>

<td>**B:**</td>

<td>

<table border="all">

<tbody>

<tr>

<td>4</td>

<td>1</td>

<td>2</td>

<td>3</td>

</tr>

<tr>

<td>5</td>

<td>8</td>

<td>7</td>

<td>6</td>

</tr>

</tbody>

</table>

</td>

<td>**C:**</td>

<td>

<table border="all">

<tbody>

<tr>

<td>1</td>

<td>7</td>

<td>2</td>

<td>4</td>

</tr>

<tr>

<td>8</td>

<td>6</td>

<td>3</td>

<td>5</td>

</tr>

</tbody>

</table>

</td>

</tr>

</tbody>

</table>

</center>

All possible configurations are available using the three basic transformations.

You are to write a program that computes a minimal sequence of basic transformations that transforms the initial configuration above to a specific target configuration.

### PROGRAM NAME: msquare

### INPUT FORMAT

A single line with eight space-separated integers (a permutation of (1..8)) that are the target configuration.

### SAMPLE INPUT (file msquare.in)

<pre>2 6 8 4 5 7 3 1 
</pre>

### OUTPUT FORMAT

<table border="1">

<tbody>

<tr>

<td>Line 1:</td>

<td>A single integer that is the length of the shortest transformation sequence.</td>

</tr>

<tr>

<td>Line 2:</td>

<td>The lexically earliest string of transformations expressed as a string of characters, 60 per line except possibly the last line.</td>

</tr>

</tbody>

</table>

### SAMPLE OUTPUT (file msquare.out)

<pre>7
BCABCCB
</pre>

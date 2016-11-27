
<html>

<head>
<title>Sweet Butter</title>
</head>

<img src=http://train.usaco.org/usaco/cow1.jpg width=742 height=118>

<center> <h1>Sweet Butter</h1> </center>
<center>Greg Galperin -- 2001</center>


<p>Farmer John has discovered the secret to making the sweetest butter
in all of Wisconsin: sugar.  By placing a sugar cube out in the
pastures, he knows the N (1 &lt;= N &lt;= 500) cows will lick it and thus
will produce super-sweet butter which can be marketed at better
prices.  Of course, he spends the extra money on luxuries for the
cows.

<p>FJ is a sly farmer.  Like Pavlov of old, he knows he can train the
cows to go to a certain pasture when they hear a bell.  He intends to
put the sugar there and then ring the bell in the middle of the
afternoon so that the evening's milking produces perfect milk.

<p>FJ knows each cow spends her time in a given pasture (not necessarily
alone).  Given the pasture location of the cows and a description of
the paths that connect the pastures, find the pasture in which to place
the sugar cube so that the total distance walked by the cows when FJ
rings the bell is minimized. FJ knows the fields are connected well enough
that some solution is always possible.

<h3>PROGRAM NAME: butter</h3>

<h3>INPUT FORMAT</h3>

<ul><li> Line 1: Three space-separated integers: N, the number of pastures: P (2 &lt;= P &lt;=
800), and the number of connecting paths: C (1 &lt;= C &lt;= 1,450).  Cows
are uniquely numbered 1..N. Pastures are uniquely numbered 1..P.
<li> Lines 2..N+1: Each line contains a single integer that is the pasture number in which
a cow is grazing.  Cow i's pasture is listed on line i+1.
<li> Lines N+2..N+C+1: Each line contains three space-separated integers that describe a single
path that connects a pair of pastures and its length.  Paths may be
traversed in either direction.  No pair of pastures is directly connected
by more than one path.  The first two integers are in the range 1..P; the
third integer is in the range (1..225).
</ul>

<h3>SAMPLE INPUT (file butter.in)</h3>

<pre>
3 4 5
2
3
4
1 2 1
1 3 5
2 3 7
2 4 3
3 4 5

</pre>


<h3>INPUT DETAILS</h3>
This diagram shows the connections geometrically:
<pre>
          P2  
 P1 @--1--@ C1
     \    |\
      \   | \
       5  7  3
        \ |   \
         \|    \ C3
       C2 @--5--@
          P3    P4
</pre>

<h3>OUTPUT FORMAT</h3>

<ul><li> Line 1: A single integer that is the minimum distance the cows must walk to
a pasture with a sugar cube.
</ul>

<h3>SAMPLE OUTPUT (file butter.out) </h3>

<pre>
8

OUTPUT DETAILS:

Putting the cube in pasture 4 means: cow 1 walks 3 units; cow 2 walks 5
units; cow 3 walks 0 units -- a total of 8.

</pre>

</html>

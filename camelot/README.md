![](http://train.usaco.org/usaco/cow1.jpg)

<center>**<font size="7">Camelot</font>**  
**IOI 98**</center>

Centuries ago, King Arthur and the Knights of the Round Table used to meet every year on New Year's Day to celebrate their fellowship. In remembrance of these events, we consider a board game for one player, on which one chesspiece king and several knight pieces are placed on squares, no two knights on the same square.

This example board is the standard 8x8 array of squares:  

<center>![](http://train.usaco.org/usaco/probs/camelot-1.gif)</center>

The King can move to any adjacent square from ![](http://train.usaco.org/usaco/probs/camelot-b.gif) to ![](http://train.usaco.org/usaco/probs/camelot-w.gif) as long as it does not fall off the board:  

<center>![](http://train.usaco.org/usaco/probs/camelot-2.gif)</center>

A Knight can jump from ![](http://train.usaco.org/usaco/probs/camelot-b.gif) to ![](http://train.usaco.org/usaco/probs/camelot-w.gif), as long as it does not fall off the board:

<center>![](http://train.usaco.org/usaco/probs/camelot-3.gif)</center>

During the play, the player can place more than one piece in the same square. The board squares are assumed big enough so that a piece is never an obstacle for any other piece to move freely.

The player's goal is to move the pieces so as to gather them all in the same square - in the minimal number of moves. To achieve this, he must move the pieces as prescribed above. Additionally, whenever the king and one or more knights are placed in the same square, the player may choose to move the king and one of the knights together from that point on, as a single knight, up to the final gathering point. Moving the knight together with the king counts as a single move.

Write a program to compute the minimum number of moves the player must perform to produce the gathering. The pieces can gather on any square, of course.

### PROGRAM NAME: camelot

### INPUT FORMAT

<table border="1">

<tbody>

<tr>

<td>Line 1:</td>

<td>Two space-separated integers: R,C, the number of rows and columns on the board. There will be no more than 26 columns and no more than 30 rows.</td>

</tr>

<tr>

<td>Line 2..end:</td>

<td>The input file contains a sequence of space-separated letter/digit pairs, 1 or more per line. The first pair represents the board position of the king; subsequent pairs represent positions of knights. There might be 0 knights or the knights might fill the board. Rows are numbered starting at 1; columns are specified as upper case characters starting with `A'.</td>

</tr>

</tbody>

</table>

### SAMPLE INPUT (file camelot.in)

<pre>8 8
D 4
A 3 A 8
H 1 H 8
</pre>

The king is positioned at D4\. There are four knights, positioned at A3, A8, H1, and H8.

### OUTPUT FORMAT

A single line with the number of moves to aggregate the pieces.

### SAMPLE OUTPUT (file camelot.out)

<pre>10
</pre>

### SAMPLE OUTPUT ELABORATION

They gather at B5.  
Knight 1: A3 - B5 (1 move)  
Knight 2: A8 - C7 - B5 (2 moves)  
Knight 3: H1 - G3 - F5 - D4 (picking up king) - B5 (4 moves)  
Knight 4: H8 - F7 - D6 - B5 (3 moves)  
1 + 2 + 4 + 3 = 10 moves.  

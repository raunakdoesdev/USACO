![](http://train.usaco.org/usaco/cow1.jpg)

<center>**<font size="7">A Game</font>**  
**IOI'96 - Day 1**</center>

Consider the following two-player game played with a sequence of N positive integers (2 <= N <= 100) laid onto a 1 x N game board. Player 1 starts the game. The players move alternately by selecting a number from either the left or the right end of the gameboar. That number is then deleted from the board, and its value is added to the score of the player who selected it. A player wins if his sum is greater than his opponents.

Write a program that implements the optimal strategy. The optimal strategy yields maximum points when playing against the "best possible" opponent. Your program must further implement an optimal strategy for player 2.

### PROGRAM NAME: game1

### INPUT FORMAT

<table border="1">

<tbody>

<tr>

<td>Line 1:</td>

<td>N, the size of the board</td>

</tr>

<tr>

<td>Line 2-etc:</td>

<td>N integers in the range (1..200) that are the contents of the game board, from left to right</td>

</tr>

</tbody>

</table>

### SAMPLE INPUT (file game1.in)

<pre>6
4 7 2 9
5 2
</pre>

### OUTPUT FORMAT

Two space-separated integers on a line: the score of Player 1 followed by the score of Player 2.

### SAMPLE OUTPUT (file game1.out)

<pre>18 11
</pre>

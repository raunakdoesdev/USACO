![](http://train.usaco.org/usaco/cow1.jpg)

<center>**<font size="7">Letter Game</font>**  
IOI 1995</center>

<center>![](http://train.usaco.org/usaco/lgame.gif)  
Figure 1: Each of the 26 lowercase letters and its value</center>

Letter games are popular at home and on television. In one version of the game, every letter has a value, and you collect letters to form one or more words giving the highest possible score. Unless you have 'a way with words', you will try all the words you know, sometimes looking up the spelling, and then compute the scores. Obviously, this can be done more accurately by computer.

Given the values in Figure 1, a list of words, and the letters collected: find the highest scoring words or pairs of words that can be formed.

### PROGRAM NAME: lgame

### INPUT FORMAT

One line with a string of lowercase letters (from '<tt>a</tt>' to '<tt>z</tt>'). The string consists of at least 3 and at most 7 letters in arbitrary order.

### SAMPLE INPUT (file lgame.in)

<pre>prmgroa
</pre>

### DICTIONARY FORMAT

At most 40,000 lines, each containing a string of at least 3 and at most 7 lowercase letters. At the end of this file is a line with a single period ('<tt>.</tt>'). The file is sorted alphabetically and contains no duplicates.

### SAMPLE DICTIONARY (file [lgame.dict](http://train.usaco.org/usaco/lgame.dict))

<pre>profile
program
prom
rag
ram
rom
.
</pre>

### OUTPUT FORMAT

On the first line, your program should write the highest possible score, and on each of the following lines, all the words and/or word pairs from file <tt>lgame.dict</tt> with this score. Sort the output alphabetically by first word, and if tied, by second word. A letter must not occur more often in an output line than in the input line. Use the letter values given in Figure 1.

When a combination of two words can be formed with the given letters, the words should be printed on the same line separated by a space. The two words should be in alphabetical order; for example, do not write '<tt>rag prom</tt>', only write '<tt>prom rag</tt>'. A pair in an output line may consist of two identical words.

### SAMPLE OUTPUT (file lgame.out)

This output uses the tiny dictionary above, not the <tt>lgame.dict</tt> dictionary.

<pre>24
program
prom rag
</pre>

<autoscroll></autoscroll>

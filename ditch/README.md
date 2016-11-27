![](http://train.usaco.org/usaco/cow1.jpg)

<center>**<font size="7">Drainage Ditches</font>** **Hal Burch**</center>

Every time it rains on Farmer John's fields, a pond forms over Bessie's favorite clover patch. This means that the clover is covered by water for awhile and takes quite a long time to regrow. Thus, Farmer John has built a set of drainage ditches so that Bessie's clover patch is never covered in water. Instead, the water is drained to a nearby stream. Being an ace engineer, Farmer John has also installed regulators at the beginning of each ditch, so he can control at what rate water flows into that ditch. Farmer John knows not only how many gallons of water each ditch can transport per minute but also the exact layout of the ditches, which feed out of the pond and into each other and stream in a potentially complex network. Note however, that there can be more than one ditch between two intersections. Given all this information, determine the maximum rate at which water can be transported out of the pond and into the stream. For any given ditch, water flows in only one direction, but there might be a way that water can flow in a circle. ### PROGRAM NAME: ditch ### INPUT FORMAT

<table border="1">

<tbody>

<tr>

<td>Line 1:</td>

<td>Two space-separated integers, N (0 <= N <= 200) and M (2 <= M <= 200). N is the number of ditches that Farmer John has dug. M is the number of intersections points for those ditches. Intersection 1 is the pond. Intersection point M is the stream.</td>

</tr>

<tr>

<td>Line 2..N+1:</td>

<td>Each of N lines contains three integers, S<sub>i</sub>, E<sub>i</sub>, and C<sub>i</sub>. S<sub>i</sub> and E<sub>i</sub> (1 <= S<sub>i</sub>, E<sub>i</sub> <= M) designate the intersections between which this ditch flows. Water will flow through this ditch from S<sub>i</sub> to E<sub>i</sub>. C<sub>i</sub> (0 <= C<sub>i</sub> <= 10,000,000) is the maximum rate at which water will flow through the ditch.</td>

</tr>

</tbody>

</table>

### SAMPLE INPUT (file ditch.in)

<pre>5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
</pre>

### OUTPUT FORMAT One line with a single integer, the maximum rate at which water may emptied from the pond.
### SAMPLE OUTPUT (file ditch.out)

<pre>50
</pre>

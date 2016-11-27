![](http://train.usaco.org/usaco/cow1.jpg)

<center>**<font size="7">Job Processing</font>**  
**IOI'96**</center>

A factory is running a production line that requires two operations to be performed on each job: first operation "A" then operation "B". Only a certain number of machines are capable of performing each operation.

<center>![](http://train.usaco.org/usaco/probs/ioi96d1.gif)</center>

Figure 1 shows the organization of the production line that works as follows. A type "A" machine takes a job from the input container, performs operation "A" and puts the job into the intermediate container. A type "B" machine takes a job from the intermediate container, performs operation "B" and puts the job into the output container. All machines can work in parallel and independently of each other, and the size of each container is unlimited. The machines have different performance characteristics, a given machine requires a given processing time for its operation.

Give the earliest time operation "A" can be completed for all N jobs provided that the jobs are available at time 0\. Compute the minimal amount of time that is necessary to perform both operations (successively, of course) on all N jobs.

### PROGRAM NAME: job

### INPUT FORMAT

<table border="1">

<tbody>

<tr>

<td>Line 1:</td>

<td>Three space-separated integers:

*   N, the number of jobs (1<=N<=1000).
*   M1, the number of type "A" machines (1<=M1<=30)
*   M2, the number of type "B" machines (1<=M2<=30)

</td>

</tr>

<tr>

<td>Line 2..etc:</td>

<td>M1 integers that are the job processing times of each type "A" machine (1..20) followed by M2 integers, the job processing times of each type "B" machine (1..20).</td>

</tr>

</tbody>

</table>

### SAMPLE INPUT (file job.in)

<pre>5 2 3
1 1 3 1 4
</pre>

### OUTPUT FORMAT

A single line containing two integers: the minimum time to perform all "A" tasks and the minimum time to perform all "B" tasks (which require "A" tasks, of course).

### SAMPLE OUTPUT (file job.out)

<pre>3 5
</pre>

# <h1 align="center">PHILOSOPHERS</h1>

<div align="center">
  <img src="https://miro.medium.com/v2/resize:fit:1100/format:webp/1*kTNv4zAJfdhvM9l0LiwUaA.png" />
</div>

### Introduction
---
In the realm of computer science, particularly in the study of concurrent programming and synchronization, the 'Dining Philosophers Problem' stands as a classic illustration of the challenges inherent in resource allocation and deadlock avoidance. Originating from a simple thought experiment involving philosophers seated around a dining table, this problem serves as a poignant metaphor for the complexities encountered in designing robust, multi-threaded software systems. In this introduction, we delve into the essence of the Dining Philosophers Problem, exploring its significance, theoretical underpinnings, and practical implications in modern computing.

### Overview
---
<p>Here are the things you need to know if you want to succeed in this assignment:</p>
<ul>
  <li>One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.</li>
  <li>The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.</li>
  <li>There are also forks on the table. There are as many forks as philosophers.</li>
  <li>Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.</li>
  <li>When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.</li>
  <li>Every philosopher needs to eat and should never starve.</li>
  <li>Philosophers don’t speak with each other.</li>
  <li>Philosophers don’t know if another philosopher is about to die.</li>
  <li>No need to say that philosophers should avoid dying!</li>
</ul>

### Rules to Follow
---
<p>Below are the program arguments required for the simulation:</p>
<pre>
<code>
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
</code>
</pre>

<ul>
  <li><strong>number_of_philosophers:</strong> The number of philosophers and also the number of forks.</li>
  <li><strong>time_to_die (in milliseconds):</strong> If a philosopher doesn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.</li>
  <li><strong>time_to_eat (in milliseconds):</strong> The time it takes for a philosopher to eat. During that time, they will need to hold two forks.</li>
  <li><strong>time_to_sleep (in milliseconds):</strong> The time a philosopher will spend sleeping.</li>
  <li><strong>number_of_times_each_philosopher_must_eat (optional argument):</strong> If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.</li>
</ul>
</pre>

<ul>
  <li>Each philosopher has a number ranging from 1 to number_of_philosophers.</li>
  <li>Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.</li>
  <li>Any state change of a philosopher must be formatted as follows:</li>
<pre>
<code>
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
</code>
</pre>
  <li>A displayed state message should not be mixed up with another message.</li>
  <li>A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.</li>
  <li>Again, philosophers should avoid dying!</li>
</ul>
<h2>Mandatory Part</h2>
<ul>
  <li>Each philosopher should be a thread.</li>
  <li>There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.</li>
  <li>To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.</li>
</ul>

<h2>Bonus Part</h2>
<ul>
  <li>The program of the bonus part takes the same arguments as the mandatory program. It has to comply with the requirements of the Global rules chapter.</li>
  <li>Specific rules for the bonus part:</li>
  <ul>
    <li>All the forks are put in the middle of the table.</li>
    <li>They have no states in memory but the number of available forks is represented by a semaphore.</li>
    <li>Each philosopher should be a process. But the main process should not be a philosopher.</li>
  </ul>
</ul>

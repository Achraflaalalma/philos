# <h1 align="center">PHILOSOPHERS</h1>

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

# Philosophers

## About

In computer science, the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.<br />
The goal of this project was to learn to avoid deadlock and race conditions when creating multithreaded applications.


<img width="224" alt="table" src="https://github.com/RafaSoares1/Philosophers/assets/103336451/bfe979c8-1806-4e5a-905b-2e70c31fb79e">

## Rules
The program takes the following arguments:

***./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]***

* ***number_of_philosophers:*** The number of philosophers and also the number of forks.
* ***time_to_die (in milliseconds):*** If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
* ***time_to_eat (in milliseconds):*** The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
* ***time_to_sleep (in milliseconds):*** The time a philosopher will spend sleeping.
* ***number_of_times_each_philosopher_must_eat (optional argument):*** If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.


## Output
The output of the program is in the format <timestamp> <philosopher (1 to number_of_philosophers)> <action>

Each philosopher logs the following actions:

* Taking a fork
* Eating
* Sleeping
* Thinking
* Dying
 
The logged messages are always in sequential order.

## Installation

The program is compiled into a ***philo*** executable using ***make all***
  
### Example
The following example shows the result of 3 philosophers, that take 600ms to die, 200ms to eat, 200ms to sleep and will eat a minimum of 2 times (./philo 3 600 200 200 2):
 
![image](https://github.com/RafaSoares1/Philosophers/assets/103336451/3e639e88-686f-42ae-be70-c67abd4eb6ba)

## Final grade

![image](https://github.com/RafaSoares1/Philosophers/assets/103336451/5023e94d-a5f1-4d59-864e-85e061d4df3b)



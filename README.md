Introduction
									

Philosophy (from Greek, philosophia, literally "love of wisdom") is the study of general
and fundamental questions about existence, knowledge, values, reason, mind, and language. Such questions are often posed as problems to be studied or resolved. The term
was probably coined by Pythagoras (c. 570 – 495 BCE). Philosophical methods include
questioning, critical discussion, rational argument, and systematic presentation.
Classic philosophical questions include: Is it possible to know anything and to prove
it? What is most real? Philosophers also pose more practical and concrete questions such
as: Is there a best way to live? Is it better to be just or unjust (if one can get away with
it)? Do humans have free will?
Historically, "philosophy" encompassed any body of knowledge. From the time of Ancient Greek philosopher Aristotle to the 19th century, "natural philosophy" encompassed
astronomy, medicine, and physics. For example, Newton’s 1687 Mathematical Principles
of Natural Philosophy later became classified as a book of physics.
In the 19th century, the growth of modern research universities led academic philosophy and other disciplines to professionalize and specialize. In the modern era, some
investigations that were traditionally part of philosophy became separate academic disciplines, including psychology, sociology, linguistics, and economics.
Other investigations closely related to art, science, politics, or other pursuits remained
part of philosophy. For example, is beauty objective or subjective? Are there many scientific methods or just one? Is political utopia a hopeful dream or hopeless fantasy?
Major sub-fields of academic philosophy include metaphysics ("concerned with the fundamental nature of reality and being"), epistemology (about the "nature and grounds of
knowledge [and]... its limits and validity"), ethics, aesthetics, political philosophy, logic
and philosophy of science.


Overview

									
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying!


Global rules


You have to write a program for the mandatory part and another one for the bonus part
(if you decide to do the bonus part). They both have to comply with the following rules:
•-->> Global variables are forbidden!
•-->> Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
◦-->> number_of_philosophers: The number of philosophers and also the number
of forks.
◦-->> time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
◦-->> time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
◦-->> time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦-->> number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
•-->> Each philosopher has a number ranging from 1 to number_of_philosophers.
•-->> Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

# CS1_PA3
 Permutations

The Perfect Seat Plan: Optimizing Seating for Soccer Fans
The soccer tournament in Monster Country is generating a lot of excitement. You and your friends
have bought tickets and plan to attend a match at the stadium! However, snacks at the stadium are
comes to seating, each person wants to sit next to someone who will have the snacks. Additionally,
some friends prefer not to sit next to each other. Therefore, the seating arrangements must account
for the following conditions:
   • Some people don’t want to sit next to one another.
   • Everyone must have access to snacks, meaning that each person, either they have snacks,
     or the person directly to their left or right does.

For example, let’s say five friends—Alejandro, Ben, Carla, Mariam, Miraziz are attending the
game. Only Alejandro and Miraziz bought snacks. Furthermore, Alejandro and Carla can’t sit next
to each other, and Ben and Miraziz can’t sit together. Given these restrictions, there are multiple
ways they can be seated in a single row at the stadium.

Alejandro Ben Carla Miraziz Mariam
Alejandro Ben Mariam Miraziz Carla
Ben Alejandro Mariam Carla Miraziz
Ben Alejandro Mariam Miraziz Carla
Carla Miraziz Mariam Alejandro Ben
Carla Miraziz Mariam Ben Alejandro
Mariam Alejandro Ben Carla Miraziz
Mariam Miraziz Carla Ben Alejandro
Miraziz Carla Ben Alejandro Mariam
Miraziz Carla Mariam Alejandro Ben

Problem
Write TWO related but independent programs that process the same input but do not exchange
any data. Given:
   • A list of people attending a game together
   • A list of pairs of people who cannot sit next to each other
   • A list of people buying snacks

Each program should determine the following:
1. Program 1: Compute the total number of valid seat arrangements (permutations) that
satisfy all restrictions.

2. Program 2: Find the first valid seating arrangement in lexicographical order that meets
all restrictions.

Input
The input starts with two positive integers: n (3 ≤ n ≤ 10), representing the number of people
attending the game, and p (0 ≤ p ≤ n), indicating the number of pairs of people who cannot sit next
to each other. These constraints define the problem's scope, ensuring a manageable number of
permutations while incorporating seating restrictions.

The next n lines will provide information about each person attending the game, with one person
described per line. These lines will list the people in alphabetical order. Each line will follow this
format:
NAME 0/1
quite expensive, so not everyone wants to buy them. Instead, snacks will be shared, and when it
Each name will be an uppercase alphabetic string with no more than 19 characters. A '0' on the
line indicates that the person does not have snacks, while a '1' indicates that the person does have
snacks.

The following p lines will each contain a pair of names, representing two people who do not want
to sit next to each other. It is guaranteed that each of the 2p names in this section will be among
the n names listed previously as game attendees. Additionally, it is guaranteed that the two names
on a single line will be distinct.
Output (for Program 1)

On a single line, output the total number of valid orderings of the people attending the game, seated
together in a single row from left to right. It is guaranteed that the input data will ensure this value
is a positive integer.
Output (for Program 2)

Output, with one name per line, the first lexicographical valid ordering of the people attending the
game, seated together in a single row from left to right.
(Hint: Since the given names are already in alphabetical order, the permutation algorithm
shown in class will naturally evaluate the permutations in lexicographical order. Therefore, the
first valid solution found while running the algorithm will be the correct answer.)

Sample Explanation
In each of the three cases, we can verify that the output list is valid.
   • In the first sample, Alejandro and Miraziz have snacks in seats 1 and 4. Everyone else is adjacent
     to one of these two seats. Additionally, Alejandro and Carla are separated, and Ben and Miraziz
     are separated.
   • In the second sample case, many orderings are possible because most of the attendees have snacks,
     and there are limited pairs of attendees who can't sit next to each other.
   • In the last sample, snacks must be in seats 2 and 5. The five pairs of constraints reduce the
     possibilities of the valid orderings and their reverse orderings

Implementation Requirements/Run Time Requirements
1. No dynamically allocated memory is necessary. All memory requirements are relatively small.

2. The permutation algorithm from class must be used (The used helper array approach). The run
time of each program should be roughly O(n x n!). (where n! accounts for each permutation
and nn for evaluating if a permutation is a valid arrangement of the game attendees).

3. You may use global variables to clean up your code so it's easier to read. Please use them
sparingly. (Here are the ones recommended: number of people attending the game, list of names,
the list of who has snacks, and a two dimensional array storing who is allowed to sit next to whom.)

4. Your code must compile and execute on the Codegrade system.
first valid solution found while running the algorithm will be the correct answer.)

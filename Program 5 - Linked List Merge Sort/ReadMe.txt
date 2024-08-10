Read Me #5: Connect Four
Santosh Ramesh   CS 161   Yipeng   12-6-19

Description of Program:
1. The program is a user-based linked list implementation
2. It contains the functionality to insert elements at the front, back and, middle of the list.
3. It is created through a template class, and there are two precreated versions; unsigned and signed
4. It can find the prime numbers inputed into the list.
5. It can also sort the list through ascending and descending order. 
6. The entire program can be repeated as many times sa you want. 


Instructions to Run Program:
1. Firstly, the user will be prompted to choose what type of list they want to use for their linked list; unsigned or signed.
2. Next, through a loop, the user will be asked if they would like to input a new number and where they want to place that number.
They are allowed to input any number on the range (including the range values). 
For instance, on the first input, the range will be "0" to "0"; the user can only choose 0 (the first element) for this. Selecting 0 places the element on the front of the list (through push_front), selecting the highest range value place places the element. This part of the program has error handling against numbers that are incorrect (i.e out of 
range, or a negative value where it can only be positive) but it doesn't have error handling for the cases when the user puts a string instead of an integer value.
on the back of the list (through push_back), and placing in the middle uses the insert function.
3. After inputing the values into the linked list, the program automatically returns the primes it found along with the number of
primes present in the list in total. My program CAN handle the large 10 digit prime number (4294963943) but it is a little slow; please be patient when inputting this value, but it will detect the value as prime. 
4. The user will now be asked if they want to use ascending or descending sorting for their list; this is done through merge sort.
5. After the list has been sorted, the user will finally be prompted if they would like to restart the entire program again. 

Extra Credit Done:
1. The two template class versions; unsigned and signed (once again, it does indeed work for the large prime number of 4294963943).


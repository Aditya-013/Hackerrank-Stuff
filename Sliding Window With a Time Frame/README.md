Programming Assignment - Rate Limiter
System - Windows 10, Language c++

Program returns a string array with either "Blocked" or "Allowed" based on the output from the algorithm. 

As the values of thte UNIX timestamp vary from 
0 - GMT: Thursday, January 1, 1970 12:00:00 AM to GMT: Tuesday, January 19, 2038 3:14:07 AM, which are the values generted by a
random number generator(0 - (2^(31)-1)).

Case 1: If the numbers are to be randomly generated:: 

I generated a random number between 0 - 100 = x. And x number of random timestamps, which I later sorted.
Based on the value of S and R, I entered values into the slot[] array which ejected the 0th element whenever 
a new element was found which was outside the sliding window, S. 

Case 2: If the numbers aren't to be randomly generated:: 

Asked for the input from the user for the value of n. And ran a similar algorithm to print if the timestamp is
"allowed" or "blocked". 



______________________Example (1) of an output with 8 elements (Same as the one given in the problem statement): _____________

Do you want to enter the elements yourself?(Yes = 1; No - !(1) )
1
Enter the number of UNIX timeframes (n)
8
Enter element 1::1
Enter element 2::2
Enter element 3::4
Enter element 4::5
Enter element 5::6
Enter element 6::7
Enter element 7::8
Enter element 8::9

Enter the maximum number of requests (R)
2
Enter the Sliding Window Period (S)
5
1 is Allowed
2 is Allowed
4 is Blocked
5 is Blocked
6 is Blocked
7 is Allowed
8 is Allowed
9 is Blocked




______________Example (2) of an output with 43 elements (Randomly generated): _____________________



Do you want to enter the elements yourself?(Yes = 1; No - !(1) )
5

Enter the maximum number of requests (R)
2
Enter the Sliding Window Period (S)
1000000000
64880615 is Allowed
79686479 is Allowed
215353271 is Blocked
219408930 is Blocked
222293449 is Blocked
242309088 is Blocked
309919888 is Blocked
320008944 is Blocked
342566959 is Blocked
364930600 is Blocked
391880746 is Blocked
410365389 is Blocked
472095431 is Blocked
487895043 is Blocked
510949095 is Blocked
532213337 is Blocked
580887644 is Blocked
627029421 is Blocked
702805401 is Blocked
796240916 is Blocked
833442131 is Blocked
878039043 is Blocked
899055902 is Blocked
900962546 is Blocked
943745843 is Blocked
1008626458 is Blocked
1063384418 is Blocked
1138807875 is Allowed
1178115467 is Allowed
1214130542 is Blocked
1361150639 is Blocked
1436137764 is Blocked
1692508707 is Blocked
1704510260 is Blocked
1710328804 is Blocked
1748269019 is Blocked
1764954749 is Blocked
1820401556 is Blocked
1970956173 is Blocked
2016846918 is Blocked
2024519204 is Blocked
2029890986 is Blocked
2057127202 is Blocked
2085753606 is Blocked



Aditya Gopakumar
CED17I036

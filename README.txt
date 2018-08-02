arr	|	Noah Thompson	|	8/2018



-arr is a simple array container class written in C++, with a template parameter for the contained type
-It is contained in a single header file, 'arr.h'
-arr does depend on <initializer_list>, <vector>, and <assert>. compile with -std=gnu++11 or -std=c++11 
-arr does not distinguish between size and capacity: inserting beyond the last element expands the array to the minimum size needed to include the new element
-slice is accomplished by the parenthetical operator'()'. Here are two examples, assuming arr0 = {0,1,2,3,4,5,6,7,8,9}:
	-arr0(2,4) == {2,3,4}
	-arr0(9,3) == {9,0,1,2,3}
-append is accomplished by the addition operator '+'. Here is another example, assuming arr1 = {10,11,12}:
	-arr0 + arr1 == {0,1,2,3,4,5,6,7,8,9,10,11,12}
	-arr1 + arr0 == {10,11,12,0,1,2,3,4,5,6,7,8,9}
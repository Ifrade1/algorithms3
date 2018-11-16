# algorithms3
Project3

For this project you will work on groups of 3, with the exception of a maximum of two groups with 2 members. No singletons or groups with more than 3 members will be allowed.

Implement an algorithm for finding the kth smallest element in a collection of integers, using a heap. You should implement the Floyd's heap construction algorithm using heapify (bubble-down), place the numbers in the heap, and then remove the smallest element k times to identify the kth smallest element. The complexity of your algorithm should be O(n + k logn), where n is the number of integers provided as input.

Your algorithm should build the heap in place, meaning you should utilize only a single array to store the input and construct the heap. Your algorithm should be as efficient as possible.

Your program should be able to parse input provided in the standard input. The input will consist of an array with n elements and the value k. The first line of input will be the number n (the size of the array), followed by a single space and then the value k. Each subsequent line will be a single element of the array. So, for an input array of size 100, you would expect to read 101 lines total. You can assume that the input has no errors. The elements of the array will be signed 64-bit integers.

The output of your program will be produced in the standard output and will consist of a single number, the kth smallest element, with a newline character following the number.

Your program can consist of multiple files, and should be accompanied by a Makefile. When compiled with the command ‘make’, an executable should be created, called kmin. The executable will parse input from its standard input and produce output in its standard output. No other output except the required output mentioned above should be sent to the standard output.

You should archive your source file(s) and your Makefile using zip. Do not include any directories in your archive. Do not include any executable or any other files except the ones describe above in your archive. Otherwise you will incur at least a 10% grade penalty. The make utility should run correctly and create the appropriate executable in the same directory where the files are extracted.

Your program should be tested for correctness in the Linux lab machines. Projects that do not compile correctly, do not create the requested executable correctly, do not use a heap as described, or whose executable fails to identify the kth smallest number correctly, can only claim 80% of the grade at a maximum.

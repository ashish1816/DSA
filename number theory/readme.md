# [Number Theory](https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/)
## Topics:-
	1. Modular arithmetic
	2. Modular Exponentiation
	3. Greatest Common Divisor
	4. Extended Euclidean algorithm
	5. Modular Multiplicative inverse
### [Modular Arithmetic](https://brilliant.org/wiki/modular-arithmetic/):-
> When one number is divided by another, the modulo operation finds the remainder. It is denoted by the % symbol.

**Properties:-**
    1. *(a + b) % c = (a%c + b%c) % c*
    2. *(a - b) % c = (a%c - b%c + c) % c*
    3. *(a \* b) % c = (a%c \* b%c) % c*
    4. *(a / b) % c = (a%c \* b<sup>-1</sup>\*c) % c*
 
### Modular Exponentiation:-
While calculating  x<sup>n</sup>, the basis of 	Binary Exponentiation relies on whether  n  is odd or even.

If  n  is even, then  x<sup>n</sup>  can be broken down to  (x<sup>2</sup>)<sup><sup>n/2</sup></sup>. Programmatically, finding  x<sup>2</sup>  is a one-step process. However, the problem is to find  (x<sup>2</sup>)<sup><sup>n/2</sup></sup>.

Notice how the computation steps were reduced from  n  to  n/2  in just  **one**  step? You can continue to divide the power by  2  as long as it is even.

When  n  is odd, try and convert it into an even value.  x<sup>n</sup>  can be written as  x⋅x<sup>n−1</sup>. This ensures that  n−1  is even.

-   If  n  is **even**, replace  x<sup>n</sup>  by  (x<sup>2</sup>)<sup><sup>n/2</sup></sup>.
-   If  n  is **odd**, replace  x<sup>n</sup>  by  x⋅x<sup>n-1</sup>.  n−1  becomes even and you can apply the relevant formula.

**Time Complexity:-** _O(n)_
### Greatest Common Divisor:-
> The GCD of two or more numbers is the largest positive number that divides all the numbers that are considered.

**Euclid's algorithm:-** The idea behind this algorithm is GCD(A,B)=GCD(B,A%B). It will recurse until A%B=0. 
The time complexity is  _O(log(max(A, B)))_.
### Extended Euclidean Algorithm:-
This algorithm is an extended form of Euclid’s algorithm.  GCD(A,B)  has a special property so that it can always be represented in the form of an equation i.e.  Ax+By=GCD(A,B).

The coefficients (x and y) of this equation will be used to find the modular multiplicative inverse. The coefficients can be zero, positive or negative in value.

This algorithm takes two inputs as A and B and returns  GCD(A,B)  and coefficients of the above equation as output.
**_Example_**
If A=30 and B=20, then  30∗(1)+20∗(−1)=10  where 10 is the GCD of 20 and 30.

**_Key idea_**
A\*x+B\*y=GCD(A,B). ---(1)
You know that  GCD(A,B)=GCD(B,A%B). Therefore, you can write the equation as follows: B*x1+ (A % B)*y1=GCD(A,B). ---(2)

You can write  A%B=A−B∗⌊A/B⌋  where  ⌊⌋  means floor value and substitute it in equation 2. Your equation will be as follows: B*x1+ (A -  ⌊A/B⌋*B)*y1=GCD(A,B)  

When you solve it further, your equation is as follows: B.(x1  -  ⌊A/B⌋\*y1)+A\*y1=GCD(A,B). ---(3)

Comparing coefficients in equations 1 and 3, you get the following:

-   x=y1
-   y=x1  -  ⌊A/B⌋*y1

These equations are key in understanding the extended Euclidean algorithm.

In this algorithm, recursive calls are made to  GCD(B,A%B). The values that are returned from recursive calls are  x1  and  y1, which are used to get x and y.
### Sieve of Eratosthenes Algorithm:-
> The sieve of Eratosthenes algorithm is an ancient algorithm that is used to find all the prime numbers less than given number T. It can be done using O(n*log(log(n))) operations. Using this algorithm we can eliminate all the numbers which are not prime and those that are less than given T. Also, we will traverse from 2 to the root of the given number ( √T ).
### [Congruence Modulo](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/congruence-modulo):-
**A≡B  (mod C)** 
1. A mod C = B mod C
2. C | (A-B)
3. A = B + K*C where K is some integer

 Congruence Modulo is an **Equivalence Relation** which means the following:-
 > 1. They are  **reflexive**: A is related to A i.e. A ≡ A  (mod C)
 > 2. They are  **symmetric**: if A is related to B, then B is related to A  i.e. if A ≡ B (mod C) then B ≡A  (mod C)
 > 3. They are  **transitive**: if A is related to B and B is related to C then A is related to C i.e. if A ≡ B  (mod C) and B ≡ D (mod C) then A ≡ D  (mod C)

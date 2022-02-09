# Push_swap

## This program sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. 

## *Game rules:*
* The game is composed of 2 stacks named a and b.
* To start with:
    * the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
    * b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:
    * **sa : swap a** - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
    * **sb : swap b** - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
    * **ss** : **sa** and **sb** at the same time.
    * **pa : push a** - take the first element at the top of **b** and put it at the top of **a**. Do nothing if b is empty.
    * **pb : push b** - take the first element at the top of **a** and put it at the top of **b**. Do nothing if a is empty.
    * **ra : rotate a** - shift up all elements of stack **a** by 1. The first element becomes the last one.
    * **rb : rotate b** - shift up all elements of stack **b** by 1. The first element becomes the last one.
    * **rr : ra** and **rb** at the same time.
    * **rra : reverse rotate a** - shift down all elements of stack **a** by 1. The last element becomes the first one.
    * **rrb : reverse rotate b** - shift down all elements of stack **b** by 1. The last element becomes the first one.
    * **rrr : rra** and **rrb** at the same time.

## *Example:*
```
-----------------------------------------------------------------
init a and b:
2
1
3
6
5
8
- -
a b
-----------------------------------------------------------------
exec sa:
1
2
3
6
5
8
- -
a b
-----------------------------------------------------------------
exec pb pb pb:
6 3
5 2
8 1
- -
a b
-----------------------------------------------------------------
exec ra rb (equiv. to rr):
5 2
8 1
6 3
- -
a b
-----------------------------------------------------------------
exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
- -
a b
-----------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
- -
a b
-----------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
- -
a b
-----------------------------------------------------------------
```
## *Launch:*
```
%>make
cc -Wall -Wextra -Werror   -c -o ft_checker.o ft_checker.c
cc -Wall -Wextra -Werror   -c -o ft_cmd.o ft_cmd.c
cc -Wall -Wextra -Werror   -c -o ft_lst.o ft_lst.c
cc -Wall -Wextra -Werror   -c -o ft_lstcmd.o ft_lstcmd.c
cc -Wall -Wextra -Werror   -c -o ft_output.o ft_output.c
cc -Wall -Wextra -Werror   -c -o ft_split.o ft_split.c
cc -Wall -Wextra -Werror   -c -o ft_utils.o ft_utils.c
cc -Wall -Wextra -Werror   -c -o ft_utils2.o ft_utils2.c
cc -Wall -Wextra -Werror   -c -o ft_utils3.o ft_utils3.c
cc -Wall -Wextra -Werror   -c -o push_swap.o push_swap.c
gcc -Wall -Wextra -Werror ft_checker.o ft_cmd.o ft_lst.o ft_lstcmd.o ft_output.o ft_split.o ft_utils.o ft_utils2.o ft_utils3.o push_swap.o -o push_swap
%>
```
> For convenience enter ```make clean``` and objects will be removed
```
%>./push_swap 3 8 6 4
pb
ra
sa
pa
%>
```
> Of course, you can enter any integer numbers
___

# Checker
## The checker checks that after sorting list is really sort.

## *Launch:*
```
%>make bonus
cc -Wall -Wextra -Werror   -c -o checker.o checker.c
cc -Wall -Wextra -Werror   -c -o ft_utils.o ft_utils.c
cc -Wall -Wextra -Werror   -c -o ft_utils2.o ft_utils2.c
cc -Wall -Wextra -Werror   -c -o ft_utils3.o ft_utils3.c
cc -Wall -Wextra -Werror   -c -o ft_lst.o ft_lst.c
cc -Wall -Wextra -Werror   -c -o ft_split.o ft_split.c
cc -Wall -Wextra -Werror   -c -o ft_checker.o ft_checker.c
cc -Wall -Wextra -Werror   -c -o ft_cmd.o ft_cmd.c
cc -Wall -Wextra -Werror   -c -o ft_lstcmd.o ft_lstcmd.c
cc -Wall -Wextra -Werror   -c -o ft_check_cmd.o ft_check_cmd.c
cc -Wall -Wextra -Werror   -c -o ft_output.o ft_output.c
gcc -Wall -Wextra -Werror checker.o ft_utils.o ft_utils2.o ft_utils3.o ft_lst.o ft_split.o ft_checker.o ft_cmd.o ft_lstcmd.o ft_check_cmd.o ft_output.o -o checker
%>
```
> The result can be other if you had entered ```make clean```. Don't worry about it.
 ```
 %>./push_swap 3 8 6 4 | ./checker 3 8 6 4
 OK
 %>
 ```
 ```
 %>./checker 3 8 6 4 
 ```
 > Stdin will be opened and you can enter random commands from 'game rules'. Don't forget to press CTRL+D to stop reading.
 ```
%>./checker 3 8 6 4 
 pb
 ra
 sa
 KO
 %>
 ```

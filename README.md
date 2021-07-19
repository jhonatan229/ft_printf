# ft_printf
This is my third project within 42 sp, as the title says, this project aims to make our own printf. The original printf is huge, so, hypothetically thinking, my fake printf does 1/3 of what the original printf actually does, but even though, it was very interesting to see how printf works inside the box, so let me show you what and how my fake printf do the things.

# The struct of Printf
Don't seem, but the printf do much more than you probably see it doing, principally when he need to formant some datas for you, as print a number and break line, you normaly do like this: "number %d\n", the '%' show for printf that he will need to convert a type of data to string, and the 'd' show what is the type, (in case, is an integer variable).<br />
This exemple is really good, and works, but the printf can do much more, here is an axample:
```c
printf("%[FLAGS][WIDTH][PRECISION][TYPE]");
```
* FLAGS = In case of this project, i treat some flags, but there is more in the original, and depend of type data, the behavior is different. <br />

| Flag | Behavior|
| ---- | ------ |
|-| Aligns the data to the left (this flag is combine with width). |
|0| Fills the spaces before the data with 0 (this flag is combine with precision). |
|+| Specifically, is used for integer type (%d or %i) for put a signal ('+' or '-') in front of the number, depend if the number is negative or positive.
|(space)| Specifically, is used for integer type (%d or %i) for put a blank space in front of the number, instead of '+' or '-'.
|#| Specifically, is used for exadecimal type (%x %X) for put "0x" or "0X" in front of the number.

* WIDTH = as the name say, dictates the quantity of spaces the data will ocupped, if the data is smaller than width, the information is align to right.
* PRECISION = look like with width, determines the quantity of space my data can show, exp: 4263, if my precision is 2, will show only the first two spaces (42). But to separate the precision from the width, is put a flag between then, a dot '.', to the  printf knows that the number after the dot is the precision.
* TYPE = Finally, the type of data, the printf format many types of data, but i treat, in this project, only a couple of then.

| types | Behavior|
| ---- | ------ |
|d or i| A integer number (positive or negative).
|c| A character in ASCII table.|
|s| A string of charactere.|
|u| A unsigned number (a number that not have signal '-' '+').|
|p| A pointer to an address in memory of the computer (is shown in hexadecimal and with "0x" in front).|
|X or x| A hexadecimal number.|

> Each type of data has behavior different way depending of what flags you use with then.

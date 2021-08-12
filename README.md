<h1 align=center>
	<b>get_next_line</b>
</h1>

<h2 align=center>
	 <i>42cursus' project #2</i>
</h2>

<p align=center>
	In this repo you will find all the files regarding the implementations of the `get_next_line` functions, both its <b>mandatory</b> and <b>bonus</b> versions. 

---
<div align=center>
<h2>
	Final score
</h2>
<img src=https://github.com/caroldaniel/caroldaniel-utils/blob/56a285f1aa629e46b5bbcf1d1c4b9d2fd300fd4b/get_next_line_grade.png alt=cado-car's 42Project Score/>
<h4>Completed + Bonus</h4>
<img src=https://github.com/caroldaniel/caroldaniel-utils/blob/56a285f1aa629e46b5bbcf1d1c4b9d2fd300fd4b/get_next_linem.png alt=cado-car's 42Project Badge/>
</div>

---

<h3 align=center>
Mandatory
</h3>

> <i>Calling the function `get_next_line` in a loop will then allow the user to read the text available on the file descriptor one line at a time until the end of it. It has to behave well both on external files and standard input. The function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL. The <b>mandatory</b> part must deal with at least one file descriptor at a time, and can have more than one static variable.</i>

<h3 align=center>
Bonus
</h3>

> <i>The <b>bonus</b> part must behave like the mandatory part but adding up functionality to handle multiple file descriptors opened at once. The bonus function must also deal with only one static variable.</i>

---

<h2>
The project
</h2>

### Mandatory implementation

- [`header file`](get_next_line.h)
- [`get_next_line`](get_next_line.c)	- the main function and its additionals
- [`get_next_line_utils`](get_next_line_utils.c)	- additional functions from [`libft`](https://github.com/caroldaniel/42sp-cursus-libft)

### Bonus implementation

- [`header file`](get_next_line_bonus.h)
- [`get_next_line_bonus`](get_next_line_bonus.c)	- the main function and its additionals
- [`get_next_line_utils_bonus`](get_next_line_utils_bonus.c)	- additional functions from [`libft`](https://github.com/caroldaniel/42sp-cursus-libft)


---
<h2>
Usage
</h2>

### Instructions

When compiling `get_next_line` or its **bonus** version, be sure to include the following flags

```sh
$> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xxx <files>.c.
```

Where the `xxx` can be substituted by the number of bytes read at a time into the buffer for the `read` function. 

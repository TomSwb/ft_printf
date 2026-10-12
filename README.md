*This project has been created as part of the 42 curriculum by [tschwab](https://profile-v3.intra.42.fr/users/tschwab)*

# ft_printf - a function by TomSwb

## Description

#### Goal:

Create my own `printf` function.

#### Brief overview:

##### Basic:

`Files:`

* ft_printf.c
* ft_printf_managers.c
* ft_printf_parsing.c
* ft_printf_parsing_utils.c
* ft_printf_len_utils.c
* ft_printf_printing.c
* ft_printf_printing_utils.c

`Additionally contains:`

* ft_printf.h
* README

`Program version additionally contains:`

* main.c
* a.out

## Instructions

#### Libft version: 
Part of my libft. It can be added to it and used - see instructions in the Libft README (pending...).

#### Test_program:

* Run the ./a.out to see the result of all the test compared with the original printf.
* Alter the main.c and recompile to do your own test.

## Resources

#### Editor:

* `VSCodium`: Used to avoid Microsoft telemetry and AI-integrated temptations.

#### 42:

* `ft_printf.pdf` version: 12.1

#### System:

* Linux man page - printf(3): https://www.man7.org/linux/man-pages/man3/printf.3.html

#### Youtube:

* https://youtu.be/3iX9a_l9W9Y?is=O3_g8FrEvuGjzlap
* https://youtu.be/oDC208zvsdg?is=zg2j5yylIfRxqsWx
* https://youtu.be/LB2vPYwJnfw?is=UwSxPH1sGmzKHfnO

### AI:

#### Before beginning of cursus

⚠️ Disclaimer: I only ask for actual answers/solutions when I realise that I am missing theoretical knowledge.

e.g.: a new syntax or a new concept I had not explored previously.

I always write my code to the best of my abilities first.

My AI agents are set to guide me with questions as per the 42 pedagogical philosophy.

I use VSCodium on purpose to not have AI integration. This means that, except for my copy-pastes into chats for some reviews, AI does not see my code, and AI will never write my code - I do not copy-paste from AI into my code.

`ChatGPT:`

1. Peer-to-peer help as I would get on campus.

2. Understanding of variadic parameters.

3. Original printf converter and flags description to understand what implementation is required (basically a detailed and comprehensif summary of man printf, see detailed description section).

4. Help on making this Readme, generation of the Conversions & Bonus Flags Reference section for reference purposes.

`Claude:`

1. Peer-to-peer help as I would get on campus.

2. Parsing check correction help, made me realise printf check act as turn on/off not as a error return.

3. Guide to structure the final section of this readme: Algorythm

## Detailed descriptions:

### Conversions & Bonus Flags Reference

### Conversions

| Symbol | Meaning | Example |
|---|---|---|
| `c` | Character | `%c` → `A` |
| `s` | String | `%s` → `Hello` |
| `p` | Pointer address in hexadecimal | `%p` → hexadecimal address |
| `d` | Signed decimal integer | `%d` → `-42` |
| `i` | Signed decimal integer | `%i` → `-42` |
| `u` | Unsigned decimal integer | `%u` → `42` |
| `x` | Unsigned hexadecimal, lowercase | `%x` with 42 → `2a` |
| `X` | Unsigned hexadecimal, uppercase | `%X` with 42 → `2A` |
| `%` | Literal percent sign | `%%` → `%` |

### Bonus Flags and Formatting

| Symbol | Type | Meaning | Example |
|---|---|---|---|
| `-` | Flag | Left-align inside the minimum field width | `%-5d`, 42 → `42___` |
| `0` | Flag | Pad numeric field with zeroes instead of spaces | `%05d`, 42 → `00042` |
| `.` | Precision | Introduces precision | `%.5d`, 42 → `00042` |
| number | Width | Minimum total field width | `%5d`, 42 → `___42` |
| `#` | Flag | Alternative hexadecimal form | `%#x`, 42 → `0x2a` |
| `+` | Flag | Always show the sign of a signed number | `%+d`, 42 → `+42` |
| ` ` | Flag | Space before positive signed number if no sign is shown | `% d`, 42 → `_42` |

> `_` represents a space in the examples.

### Relevant Formatting by Conversion

| Conversion | `-` | `0` | `.` | Width | `#` | `+` | Space |
|---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| `c` | ✓ | — | — | ✓ | — | — | — |
| `s` | ✓ | — | ✓ | ✓ | — | — | — |
| `p` | ✓ | — | — | ✓ | — | — | — |
| `d` | ✓ | ✓ | ✓ | ✓ | — | ✓ | ✓ |
| `i` | ✓ | ✓ | ✓ | ✓ | — | ✓ | ✓ |
| `u` | ✓ | ✓ | ✓ | ✓ | — | — | — |
| `x` | ✓ | ✓ | ✓ | ✓ | ✓ | — | — |
| `X` | ✓ | ✓ | ✓ | ✓ | ✓ | — | — |
| `%` | — | — | — | — | — | — | — |

### Precision

| Conversion | Meaning | Example |
|---|---|---|
| `s` | Maximum number of characters printed | `%.3s`, `"Hello"` → `Hel` |
| `d`, `i` | Minimum number of digits | `%.5d`, 42 → `00042` |
| `u` | Minimum number of digits | `%.5u`, 42 → `00042` |
| `x`, `X` | Minimum number of hexadecimal digits | `%.5x`, 42 → `0002a` |

For strings, precision can reduce the number of characters printed.

For integers, precision never removes significant digits. Zeroes are added
when necessary to reach the requested precision.

### Priority, Conflicts and Exceptions

| Situation | Rule | Example |
|---|---|---|
| `-` + `0` | `-` wins; `0` is ignored | `%-05d`, 42 → `42___` |
| Integer precision + `0` | Precision wins; `0` is ignored | `%08.5d`, 42 → `___00042` |
| `+` + space | `+` wins; space is ignored | `%+ d`, 42 → `+42` |
| `#` + `x` | Prefix non-zero value with `0x` | `%#x`, 42 → `0x2a` |
| `#` + `X` | Prefix non-zero value with `0X` | `%#X`, 42 → `0X2A` |
| `#` + hexadecimal zero | Do not add the hexadecimal prefix | `%#x`, 0 → `0` |
| Width smaller than output | Width never truncates | `%3d`, 12345 → `12345` |
| String shorter than precision | Do not add characters | `%.5s`, `"Hi"` → `Hi` |
| String longer than precision | Print only up to precision | `%.3s`, `"Hello"` → `Hel` |
| Integer has fewer digits than precision | Add leading zeroes | `%.5d`, 42 → `00042` |
| Integer has more digits than precision | Keep all digits | `%.2d`, 1234 → `1234` |
| Integer value `0`, precision `0` | Print no digits | `%.0d`, 0 → empty |
| Negative + `0` | `-` comes before zero padding | `%05d`, -42 → `-0042` |
| `+` + `0` | `+` comes before zero padding | `%+05d`, 42 → `+0042` |
| `#` + `0` | `0x` / `0X` comes before zero padding | `%#08x`, 42 → `0x00002a` |
| `-` + width | Padding goes on the right | `%-5d`, 42 → `42___` |
| Width without `-` | Padding goes on the left | `%5d`, 42 → `___42` |

### Main Priority Rules

The three main conflicts to remember:

1. `-` overrides `0`
2. Integer precision overrides the `0` flag
3. `+` overrides the space flag

## Width vs Precision

Width and precision do not mean the same thing and do not override each other.

Example: `%8.5d` with `42`

- `.5` requires at least 5 digits → `00042`
- `8` requires the complete field to occupy at least 8 characters
- 3 spaces are therefore added

Result: `___00042`

Width is always a **minimum field width**. It does not truncate output that
is longer than the requested width.

Precision depends on the conversion:

- Strings: maximum number of characters printed.
- Integers: minimum number of digits printed.

## Algorithm & Data Structure

### Data structure: `t_flags`

#### Fields

t_flags is the structure regroupiong all the necessary information for a proper formating.

The field it contains are splited in 3 categories:
1. Flags
	- Flags act as boolean for each of the required flags in the subject, the list is not complete compared to the original printf.
2.	Width and precision
	- Width and precision_len act as boolean if == 0, and otherwise give the length of the width or precision requested by the user.
3.	Converters
	- Converters define what type of data we are working with and in which return format it will be printed.

#### Why a struct

it is indispensable when doing the bonus and changes the whole implementation. The struct allow to pass around all the necessary information for the convertion and printing without having to pass many variables (which in itself could be against the norm if more than 4 vars are needed to be passed as parameter)

### Algorithm

#### Overview

My ft_printf pass through various steps: 
1. Parsing of the different values needed in the struct, including a check and conflict resolution.
2. A Manager dispatch to sub-manager depending on converters.
3. The printing logic, partially with length helper and also the help of the manager creates the output.
4. The whole cumulates the count for the return value.

#### 1. Parsing

The parsing logic in itself is straightforward:
1. Initialise the struct.
2. Parse the different value according to the charset of flags, number for width and precision_len, and converters.

#### 2. Resolving flag conflicts

Once the parsing is done, before returning the checker ensure that all the original printf flags conflicts are resolved, according to the above table.

#### 3. Dispatching to managers

The main manager simply pass on the data to the right sub-manager depending on the converter.

#### 4. Length calculation & printing

The sub-manager are doing the beginning of the counting and padding job if needed, as well as validating the value. Then they send it all to the printing functions to conclude the paddings/other flags necessities then print the value, then complete the after padding etc if needed.

#### Return value

Throught the whole process, the function return generally an int to add to the count or by pointer arythmetic, to ensure the final count of printed character as return value is correct.

### Design choices

Wanting to do the bonus, I decided right away that a struct and booleans would be the easiest to manage, they are mostly 'flags' after all. 

I therefore needed a parsing system and ensure all parsed values are correct. At first i thought I needed to return errors and not simply to resolves the flags issues, I also thought multiple flags should not parsed and return an error. After research I understood that the flags are more on/off systems. Now printf itself doesn't even compile in these cases. I chose lenience as part of my design as we are not told in much precision how to deal with these error cases. While not compiling (mostly due to the -Werror flag), printf does give us a reason why it does not compile and therefore I attempted to implement a way to satisfy that.

My goal then was re-usability. If a converter is similar to another in their needs, it shall reuse as much as possible of the already implemented functions. I could group 4 category: c & s, d & i & u, x & X, and p. I believe i could have put together p with the xX but i felt it had enough difference in needs to split the logic.

Once the split is done, each manager then ensure the value is treated according to the flag. Always ensuring to keep count. I decided for the manager themselve to centralise the count variable and use pointer arythmetics and avoid return values to ensure I can follow the norm everywhere. I had a bit more space in the printing logics and it made also more sense to actually use returns with them to add-on to the original count. I think at first I wanted to use these returns as boolean but I can't remember the reason why and in anyway I believe it was not useful.

#### File organisation

#### Extensibility

#### Edge cases & platform behaviour

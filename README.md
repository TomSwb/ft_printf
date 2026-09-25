*This project has been created as part of the 42 curriculum by \<tschwab>*

# ft_printf - a function by TomSwb

## Description

#### Goal:

Create my own `printf` function.

#### Brief overview:

##### Basic:

`Files:`

* ft_printf.c
* ft_printf_utils.c
* ft_printf_printing.c

`Additionally contains:`

* ft_printf.h
* README

`Program version additionally contains:`

* main.c
* a.out

##### Bonus:

* ft_printf_flags.c
* flags uses (possible flags are describe in the detailed section).

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

4. Help on making this Readme.

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
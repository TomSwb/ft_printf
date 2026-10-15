*This project has been created as part of the 42 curriculum by [tschwab](https://profile-v3.intra.42.fr/users/tschwab).*

# ft_printf - a function by TomSwb

## Description

### Goal

Recode the `printf()` function from the C standard library as `ft_printf()`, packaged in a static library: `libftprintf.a`.

The main lesson of the project is **variadic functions**: functions that accept a variable number of arguments, read one by one with `va_start`, `va_arg` and `va_end`.

### Brief overview

`ft_printf()` handles the following conversions: `c s p d i u x X %`.

It also handles the bonus flags: `-`, `0`, `.` (precision), the minimum field width, `#`, `+` and ` ` (space), in any combination.

As required by the subject, it does not reproduce the buffer management of the original `printf()`: every piece of output is written immediately with `write()`.

**Submitted files:**

| File | Content |
|---|---|
| `Makefile` | Builds `libftprintf.a` |
| `ft_printf.h` | Header: struct, includes and prototypes |
| `ft_printf.c` | Main function, main loop and write-error tracking |
| `ft_printf_managers.c` | Dispatch per conversion |
| `ft_printf_parsing.c` | Format parsing and flag conflict resolution |
| `ft_printf_parsing_utils.c` | Character checks used by the parser |
| `ft_printf_printing.c` | Printers for each type |
| `ft_printf_printing_utils.c` | Shared printing helpers |
| `ft_printf_len_utils.c` | Length calculations used for padding |
| `README.md` | This file |

The hidden `.test_program/` folder contains my personal test program. It is not part of the evaluated project: it is self-contained, with its own copy of the sources and its own Makefile.

## Instructions

### Compiling the library

From the root of the repository:

```sh
make          # builds libftprintf.a
make bonus    # same library: the bonus flags are part of the main code
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean + all
```

The library is compiled with `cc` and the flags `-Wall -Wextra -Werror`, and archived with `ar`.

### Using it in a program

Include the header and link the library:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s, you are %d\n", "world", 42);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lftprintf -o my_program
./my_program
```

Like the original, `ft_printf()` returns the number of characters printed, or `-1` on an invalid format or if writing to the output fails.

### Test program

The test program compares `ft_printf()` with the original `printf()` on many cases, conversion by conversion, printing both outputs and both return values.

```sh
cd .test_program
make                  # builds test_printf from the copies in this folder
./test_printf d       # run the tests for one conversion
```

Available arguments: `%`, `c`, `s`, `d`, `i`, `u`, `x`, `X`, `p`, and `1` (string ending with a lone `%`).

The test program compiles its own copy of the `ft_printf` sources, so after changing the root files, copy them into `.test_program/` again before testing.

Run it directly in a terminal: `ft_printf` writes immediately while `printf` is buffered, so piping the output into a file or `less` can mix up the order of the lines.

### Adding it to libft

Once the project is validated, the source files and the header can be copied into my libft and added to its Makefile, so `ft_printf()` can be used in my future 42 projects.

## Resources

### Editor

* `VSCodium`: used to avoid Microsoft telemetry and AI-integrated temptations.

### 42

* `ft_printf` subject, version 12.1

### Documentation

* Linux man page - printf(3): https://www.man7.org/linux/man-pages/man3/printf.3.html

### YouTube

* https://youtu.be/3iX9a_l9W9Y?is=O3_g8FrEvuGjzlap
* https://youtu.be/oDC208zvsdg?is=zg2j5yylIfRxqsWx
* https://youtu.be/LB2vPYwJnfw?is=UwSxPH1sGmzKHfnO

### AI

⚠️ Disclaimer: I only ask for actual answers or solutions when I realise that I am missing theoretical knowledge, e.g. a new syntax or a concept I had not explored before.

I always write my code to the best of my abilities first.

My AI agents are set to guide me with questions, following the 42 pedagogical philosophy.

I use VSCodium on purpose, so there is no AI integration in my editor. Apart from what I copy-paste into a chat for a review, AI does not see my code, and AI never writes my project code: I do not copy-paste from AI into my code.

**ChatGPT:**

1. Peer-to-peer help, as I would get on campus.
2. Understanding variadic functions.
3. Description of the original printf conversions and flags, to understand what had to be implemented (a detailed and comprehensive summary of `man 3 printf`, see the *Detailed descriptions* section).
4. Help with this README: generation of the *Conversions & Bonus Flags Reference* section, for reference purposes.

**Claude:**

1. Peer-to-peer help, as I would get on campus.
2. Additional testing on top of my own test program: compared my `ft_printf` with the original `printf` on extra edge cases and 3000 randomly generated formats, then reported the failing cases without giving code.
3. Guided debugging: hints and step-by-step traces to locate bugs (flag conflicts, `#` and `0` with a value of `0`, NULL string with precision). I wrote every fix myself.
4. Help correcting the parsing check: made me realise that printf flags act as on/off switches, not as error returns.
5. README: helped structure the *Algorithm & Data Structure* section, then completed and corrected it from my own draft, which I reviewed and adjusted.
6. Pre-evaluation review of the repository (file names, Makefiles, Norm, headers), and proofreading and restructuring of this README.

## Algorithm & Data Structure

### Data structure: `t_flags`

#### Fields

`t_flags` is the structure grouping all the information needed to format one conversion. A fresh one is created with `init_flags()` for every `%`, so nothing carries over from one conversion to the next.

Its fields are split into 3 categories:

1. **Flags**: `left_align` (`-`), `zero_padding` (`0`), `positive_sign` (`+`), `alt_hexa` (`#`), `space` (` `)
	- They act as booleans, one per flag required by the subject (the original printf has more flags).
	- `neg_sign` is the exception: the user never types it. It is internal state, set while printing a negative number, so the prefix logic knows a `-` has to be printed before any zero padding.
2. **Width and precision**: `min_width`, `precision`, `precision_len`
	- `min_width == 0` simply means "no width".
	- Precision needs **two** fields: `precision` records *whether* a `.` was given, `precision_len` records the number after it. One field is not enough, because "no precision" and "precision 0" behave differently: `%d` with `0` prints `0`, but `%.0d` with `0` prints nothing.
3. **Converter**: `converter`
	- A single `char` defining which type of data is read from the arguments and in which format it is printed.

#### Why a struct

It is indispensable for the bonus and shapes the whole implementation. The struct allows passing all the information needed for conversion and printing as one pointer, instead of many separate variables (which would also break the Norm's limit of 4 parameters per function).

### Algorithm

#### Overview

```
format string → parser → conflict resolution → manager → sub-manager → printers
                                                                ↓
                                                     count updated at each step
```

1. Parsing fills the struct, then resolves flag conflicts.
2. A manager dispatches to a sub-manager depending on the converter.
3. The sub-manager and the printing functions (helped by the length functions) produce the output.
4. Every printed character is added to the count, which becomes the return value.

#### 1. Parsing

The parser expects the elements of a conversion in a fixed order:

```
%  [flags]  [width]  [.precision]  converter
```

1. Initialise the struct.
2. Read flags while the character belongs to the flag charset `-0+# `. A flag given twice simply stays on.
3. Read digits as the width.
4. If a `.` follows, set `precision` and read digits as `precision_len` (no digits means precision 0).
5. Read the converter. If it is not one of `cspdiuxX%`, the parser fails and `ft_printf` returns `-1`.

#### 2. Resolving flag conflicts

Once parsing is done, `parsing_check()` cleans the struct so the printers never see a contradiction. It never rejects a format: it switches off the losing flag, following the priority rules described in the *Priority, Conflicts and Exceptions* section below:

- `-` turns off `0`
- a precision (except on `s`) turns off `0`
- `+` turns off space
- `+` and space only apply to `d`/`i`, `#` only applies to `x`/`X`
- `0` does not apply to `c`/`s`/`p`, precision does not apply to `c`/`p`

#### 3. Dispatching to managers

The main manager passes the struct and the argument list to the right sub-manager depending on the converter: characters/strings, decimals, hexadecimals or addresses.

#### 4. Length calculation & printing

Each sub-manager reads the argument with the right type through `va_arg` and prepares the value: handling the sign of negative numbers, switching off `#` when a hexadecimal value is `0`, etc. Then the printing functions print, in order: left padding, prefix (`-`, `+`, space or `0x`), precision zeros, the value itself, and right padding.

To know how much padding to print, the length functions (`s_len`, `deci_len`, `hexa_len`, `address_len`, `pr_len`) compute in advance how many characters the value will take. This creates an important constraint: **a length function and its printer must apply exactly the same conditions**. If they disagree on a special case, for example whether a `0` digit is printed, the padding is off.

#### Return value

Throughout the whole process, the printing functions return the number of characters they printed. The managers add those returns to a single `count`, which they receive as a pointer, so `ft_printf` returns the exact number of printed characters.

#### Write errors

Like the original, `ft_printf` returns `-1` if writing to the output fails (closed standard output, full device, etc.).

Every character is printed through a single function, `print_char`, which is the only place calling `write()`. When `write()` returns `-1`, `print_char` reports it to `error_state`, a small function holding a `static` variable that remembers whether a write failed. A `static` local variable keeps its value between calls without being a global variable, so it is allowed by the Norm.

`error_state` has three uses, chosen by its argument:

| Argument | Effect |
|---|---|
| `-2` | Resets the state to "no error" (`-2` is a value `write()` never returns) |
| `-1` | Records a failed write (the value `write()` returns on failure) |
| anything else | Only reads the state |

`ft_printf` resets the state at the start of every call, so an error from a previous call cannot affect the next one. The main loop stops at the next step after a failure (a step is one plain character or one whole conversion), and `ft_printf` then returns `-1` instead of the count.

This design keeps the change local: the printers and managers did not need to change, since a single error flag is enough once any write has failed.

### Design choices

Since I wanted to do the bonus, I decided right away that a struct with booleans would be the easiest to manage: they are mostly "flags" after all.

I therefore needed a parsing system that makes sure all parsed values are consistent. At first I thought I had to return errors instead of resolving flag conflicts, and that repeated flags should also be errors. After some research I understood that flags are on/off switches, and that the C standard itself defines the conflicts: the `0` flag is ignored when `-` is present, and the space flag is ignored when `+` is present. What confused me is that with our `-Wall -Wextra -Werror` flags, such a format does not compile with the real printf. This is the compiler checking the format string and warning about it; `-Werror` turns the warning into an error. Compiled without `-Werror`, printf runs and applies the override rules, and the compiler warning itself says so ("'0' flag ignored with '-' flag"). Since `ft_printf` gets no compile-time checking at all, these formats can reach it at runtime, so I chose lenience and implemented the same override rules.

My next goal was reusability: if a converter has similar needs to another one, it should reuse as many of the already implemented functions as possible. I grouped the conversions into 4 categories: `c` & `s`, `d` & `i` & `u`, `x` & `X`, and `p`. I could have put `p` together with `x`/`X`, but it had enough differences (`0x` always printed, `(nil)` for NULL, a pointer-sized value) to justify separate logic.

Once the split is done, each manager makes sure the value is treated according to the flags, always keeping count. I decided to centralise the count in the managers, which receive it as a pointer and modify it directly. This avoids extra return values and helped me respect the Norm everywhere. The printing functions had a bit more room, and it made more sense for them to return what they printed so it can be added to the count.

#### File organisation

| File | Role |
|---|---|
| `ft_printf.h` | Struct definition, includes and all prototypes |
| `ft_printf.c` | `ft_printf` itself, `printf_loop` (prints plain characters, sends every `%` to the parser and the manager) and `error_state` (write-error tracking) |
| `ft_printf_parsing.c` | `init_flags`, the parser, width/precision reading and conflict resolution |
| `ft_printf_parsing_utils.c` | Character checks: `is_flag`, `is_num`, `is_converter` |
| `ft_printf_managers.c` | Main manager and the 4 sub-managers |
| `ft_printf_printing.c` | Printers for each type: char, string, decimal, hexadecimal, address |
| `ft_printf_printing_utils.c` | Shared printing pieces: padding, prefix, precision zeros, divisor calculation |
| `ft_printf_len_utils.c` | Length functions used to compute padding |

#### Extensibility

The pipeline keeps additions local:

- **New conversion:** add its character to `is_converter`, add a branch in the main manager, and write a sub-manager (or reuse an existing one, as `d`/`i`/`u` share theirs). Padding, prefix and precision helpers are already shared.
- **New flag:** add a field to `t_flags`, its character to `is_flag`, a branch in the parser and, if needed, a rule in `parsing_check`. The printers only read the struct, so they don't need to know how the flag was parsed. Each printer then still has to be adapted to how the flag interacts with it in the original printf.

#### Edge cases & platform behaviour

My reference is the original printf on Linux (glibc). Some outputs differ on macOS.

| Case | Behaviour |
|---|---|
| `%s` with `NULL` | Prints `(null)` |
| `%.3s` with `NULL` | Prints nothing: glibc prints `(null)` entirely or not at all (macOS would print `(nu`) |
| `%p` with `NULL` | Prints `(nil)` (macOS prints `0x0`) |
| `%d`, `%u`, `%x` with `0` and precision 0 (`%.0d`, `%.d`) | Prints no digit, only padding if a width is given |
| `%#x` with `0` | Prints `0`, without the `0x` prefix |
| `%d` with `INT_MIN` | The value is stored in a `long long`, so making it positive does not overflow |
| Flag on a conversion it doesn't apply to (`%+u`, `%#d`) | Undefined behaviour in the standard; the flag is ignored, as glibc does |
| Unknown converter, or `%` at the end of the string | Returns `-1` |
| `"abc%"` | No buffer (as required by the subject): `abc` is already written when the error is found, while the original printf prints nothing |
| Write failure (closed output, full device) | Stops at the next step and returns `-1`, like the original printf without a buffer. The original buffered printf only notices the failure when its buffer is flushed, so its return value can differ when the output is a file |

## Detailed descriptions

### Conversions & Bonus Flags Reference

#### Conversions

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

#### Bonus flags and formatting

| Symbol | Type | Meaning | Example |
|---|---|---|---|
| `-` | Flag | Left-align inside the minimum field width | `%-5d`, 42 → `42___` |
| `0` | Flag | Pad a numeric field with zeros instead of spaces | `%05d`, 42 → `00042` |
| `.` | Precision | Introduces the precision | `%.5d`, 42 → `00042` |
| number | Width | Minimum total field width | `%5d`, 42 → `___42` |
| `#` | Flag | Alternative hexadecimal form | `%#x`, 42 → `0x2a` |
| `+` | Flag | Always show the sign of a signed number | `%+d`, 42 → `+42` |
| ` ` | Flag | Space before a positive signed number if no sign is shown | `% d`, 42 → `_42` |

> `_` represents a space in the examples.

#### Relevant formatting by conversion

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

For integers, precision never removes significant digits: zeros are added when necessary to reach the requested precision.

### Priority, Conflicts and Exceptions

| Situation | Rule | Example |
|---|---|---|
| `-` + `0` | `-` wins; `0` is ignored | `%-05d`, 42 → `42___` |
| Integer precision + `0` | Precision wins; `0` is ignored | `%08.5d`, 42 → `___00042` |
| `+` + space | `+` wins; space is ignored | `%+ d`, 42 → `+42` |
| `#` + `x` | Prefix a non-zero value with `0x` | `%#x`, 42 → `0x2a` |
| `#` + `X` | Prefix a non-zero value with `0X` | `%#X`, 42 → `0X2A` |
| `#` + hexadecimal zero | Do not add the hexadecimal prefix | `%#x`, 0 → `0` |
| Width smaller than output | Width never truncates | `%3d`, 12345 → `12345` |
| String shorter than precision | Do not add characters | `%.5s`, `"Hi"` → `Hi` |
| String longer than precision | Print only up to the precision | `%.3s`, `"Hello"` → `Hel` |
| Integer has fewer digits than precision | Add leading zeros | `%.5d`, 42 → `00042` |
| Integer has more digits than precision | Keep all digits | `%.2d`, 1234 → `1234` |
| Integer value `0`, precision `0` | Print no digits | `%.0d`, 0 → empty |
| Negative + `0` | `-` comes before the zero padding | `%05d`, -42 → `-0042` |
| `+` + `0` | `+` comes before the zero padding | `%+05d`, 42 → `+0042` |
| `#` + `0` | `0x` / `0X` comes before the zero padding | `%#08x`, 42 → `0x00002a` |
| `-` + width | Padding goes on the right | `%-5d`, 42 → `42___` |
| Width without `-` | Padding goes on the left | `%5d`, 42 → `___42` |

### Main priority rules

The three main conflicts to remember:

1. `-` overrides `0`
2. Integer precision overrides the `0` flag
3. `+` overrides the space flag

### Width vs Precision

Width and precision do not mean the same thing and do not override each other.

Example: `%8.5d` with `42`

- `.5` requires at least 5 digits → `00042`
- `8` requires the complete field to occupy at least 8 characters
- 3 spaces are therefore added

Result: `___00042`

Width is always a **minimum field width**: it never truncates output that is longer than the requested width.

Precision depends on the conversion:

- Strings: maximum number of characters printed.
- Integers: minimum number of digits printed.
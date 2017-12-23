Note on Pointers
==============

```c++
int * intPtr;
int num;
intPtr = &num;
num = 100;

*intPtr == num; // true
intPtr == &num; // true
```
Say you have a `typedef` called `arrayString` which is a pointer to a char:

```c++
typedef char * arrayString;
```

And then there's this function:

```c++
void changeStr(arrayString s) {
    arrayString n = new char;
    *n = 'A';
    s = n;
}
```

What do you think will happen:

```c++
arrayStrings s = new char;
*s = 'L';
changeStr(s);
```

Will the `s` be changed to `'A'`? **No**. This is what C++ do:

- Create `s`, which is `char` pointer
- Set the memory referred by `s` to `'L'`
- Pass in `s` to `changeStr`:
  - Copy the `s` variable, and make a local variable with the same name. For clarity we'll call it `s_prime`
  - Create a new pointer `n`
  - Set the memory referred by `n` to `'A'`
  - Change the memory referred by `s_prime` to that of `n`. For example, previously `s_prime` refer to memory 200, and `n` is 500. Now `s_prime` refer to memory 500. And so `*s_prime` is now `'A'` instead of `'L'`.
  - But until now we haven't do anything to the global variable `s`!

To allow the function to modify `s`, we need to use the ampersand operator:

```c++
void changeStr(arrayString &s) {
    arrayString n = new char;
    *n = 'A';
    s = n;
}
```

Now, instead of copying `s`, the function will actually use the global variable `s`.

The next question is this: how do we translate this to C++ built-in variable types? Like `int`, `char`, and so on, instead of the `arrayString`.
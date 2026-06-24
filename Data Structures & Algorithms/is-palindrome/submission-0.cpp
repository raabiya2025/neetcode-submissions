class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int n=s.size();
        int right=n-1;
        
        for(int i=0;i<n-1;i++){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
# Valid Palindrome

## Problem

Given a string `s`, determine whether it is a palindrome after:

* Converting all uppercase letters to lowercase.
* Removing all non-alphanumeric characters.

Return `true` if it is a palindrome, otherwise `false`.

---

## Key Observation

A palindrome reads the same from left to right and right to left.

We do **not** care about:

* Spaces
* Commas
* Periods
* Special characters

We only compare:

```text
A-Z
a-z
0-9
```

and comparisons must be case-insensitive.

Example:

```text
"Was it a car or a cat I saw?"
```

becomes

```text
"wasitacaroracatisaw"
```

which is a palindrome.

---

## Approach 1: Build a Clean String

### Idea

Create a new string containing only lowercase alphanumeric characters.

Then check whether the cleaned string is a palindrome.

### Algorithm

1. Traverse the original string.
2. If character is alphanumeric:

   * Convert to lowercase.
   * Add it to a new string.
3. Use two pointers on the cleaned string.
4. Compare characters from both ends.

### Code Idea

```cpp
string t;

for(char c : s) {
    if(isalnum(c))
        t += tolower(c);
}
```

Then perform a normal palindrome check on `t`.

### Complexity

Time:

```text
O(n)
```

Space:

```text
O(n)
```

because of the extra string.

### Drawback

Uses additional memory.

---

## Approach 2: Two Pointers (Optimal)

### Idea

Do not create a new string.

Use two pointers:

```cpp
left
right
```

Skip non-alphanumeric characters and compare valid characters directly.

### Algorithm

1. Initialize:

   * `left = 0`
   * `right = n - 1`
2. Skip invalid characters from the left.
3. Skip invalid characters from the right.
4. Compare lowercase versions.
5. If different → return false.
6. Move both pointers inward.
7. Continue until pointers meet.

### Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            while(left < right && !isalnum(s[left]))
                left++;

            while(left < right && !isalnum(s[right]))
                right--;

            if(tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
```

### Complexity

Time:

```text
O(n)
```

Space:

```text
O(1)
```

### Why O(n)?

Even though there are nested `while` loops:

```cpp
while(...)
    while(...)
```

each pointer only moves in one direction.

Every character is processed at most once.

Therefore:

```text
O(n)
```

not

```text
O(n²)
```

---

## Why Use `left < right`?

Example:

```text
madam
```

```text
m a d a m
0 1 2 3 4
```

After comparisons:

```text
left = 2
right = 2
```

Both pointers meet at:

```text
d
```

A character is always equal to itself.

No further comparison is needed.

Therefore:

```cpp
while(left < right)
```

is sufficient.

When:

```text
left == right
```

middle character remains.

When:

```text
left > right
```

all comparisons are complete.

---

## STL Functions Used

### `isalnum(c)`

Checks whether a character is:

```text
A-Z
a-z
0-9
```

Examples:

```cpp
isalnum('A')  // true
isalnum('9')  // true
isalnum('?')  // false
isalnum(' ')  // false
```

---

### `tolower(c)`

Converts a character to lowercase.

Examples:

```cpp
tolower('A') // 'a'
tolower('Z') // 'z'
```

---

## Pattern

```text
Two Pointers
```

---

## Similar Problems

* Two Sum II
* Container With Most Water
* 3Sum
* Trapping Rain Water
* Reverse String

---

## Interview Takeaway

When a problem asks you to compare elements from both ends of an array or string:

```text
Think Two Pointers.
```

Two pointers often reduce:

```text
O(n²) -> O(n)
```

or

```text
O(n) space -> O(1) space
```

which is exactly what happens in Valid Palindrome.


1a)
```C
int matrix[40][20]

matrix[19][0]
matrix[18][20]
```
WRONG! `matrix[no of rows][no of columns]` and you need to express the address of the first element in the 20th row, not the value.

```c
&matrix[19][0]
matrix[19]
```

1b)
3?

WRONG! not sure why TODO

1c)
i) int
ii) double
iii) float
iv) char

1d)
```c
char** sub_str(char* str int idx);
```

1e)
i) just the size of the pointer, an int, which is 4 bytes
ii) 
```
address of name + size of name +
address of address + size of address +
int + int + int + float

int + 11*char
+int + 40*char
+int + int + float

4+11
+4+40
+4+4+4

15+44+12

15+66

81 bytes
```

1f) false
1g) true
1h) 
```c
int has_ch(char ch, char* line) {
	//iterate through line checking for char
	// if char present then return 1
	// else return 0
	for (int i=0; i<size_of(line); i++) {
		if (line[i] == ch) {
			printf("%s", line);
			return 1;
		}
	}
	return 0;
}
```


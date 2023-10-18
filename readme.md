# Information
Simple C Compiler Framework: Lexical, Syntax, Semantic Analysis, and Intermediate Code Generation for educational purposes.

![Implementation of Compiler Design in C](https://t4tutorials.com/wp-content/uploads/Phases-of-Compiler.webp)
Fig 1.1 - Implementation of Compiler Design in C

# Explanation
This Program demonstrates Lexical Analysis, Syntax Analysis, Semantic Analysis, and Intermediate Code Generation for a specific "if statement". 

### 1. Lexical Analysis
- The lexical_analysis function splits the input code into tokens based on space (' ') as a delimiter and stores them in an array. This part of the code looks reasonable for basic tokenization.


### 2. Syntax Analysis
- The syntax_analysis function checks for the correct structure of the "if statement." It counts the number of "if" and "else" keywords and verifies the presence of opening and closing braces, as well as the presence of semicolons after assignments. It returns 1 if the syntax is valid, 0 otherwise.

### 3. Semantic Analysis
- The semantic_analysis function checks for the presence of relational and assignment operators within the "if statement." It returns 1 if both types of operators are present, 0 otherwise.


### 4. Intermediate Code Generation
- The intermediate_code_generation function prints a simplified intermediate code for the specific example. It appears to be a hardcoded representation of intermediate code.


### 5. Main Function: 
- The main function defines the input code, performs lexical analysis, syntax analysis, and semantic analysis. If all checks pass, it proceeds to intermediate code generation.


# Example: 
### 1. Lexical Analysis :
- Tokens:
"if"
"("
"a"
">"
"b"
")"
"{"
"c"
"="
"a"
";"
"}"
"else"
"{"
"c"
"="
"b"
";"
"}"

### 2. Syntax Analysis (Parsing) :
- Syntax analysis passes. The code follows the structure of a valid "if statement."

### 3. Semantic Analysis :
- Semantic analysis passes. The code includes both a relational operator (>) and an assignment operator (=).

### 4. Intermediate Code Generation :
- Here's a simplified intermediate code for the given code:

```
t1 = a > b
ifFalse t1 goto L1
c = a
goto L2
L1: c = b
L2: nop
```

- This intermediate code represents the logic of the "if statement," including the conditional evaluation and assignment.

# By
- 20CE015 - AYUSH DABHI
- 20CE020 - AKSH DESAI
- 20CE035 - HITEN JADAV

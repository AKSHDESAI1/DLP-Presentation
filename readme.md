# Information
Simple C Compiler Framework: Lexical, Syntax, Semantic Analysis, and Intermediate Code Generation for educational purposes.

# Explanation
This Program demonstrates Lexical Analysis, Syntax Analysis, Semantic Analysis, and Intermediate Code Generation for a specific "if statement". 

### Lexical Analysis
```
The lexical_analysis function splits the input code into tokens based on space (' ') as a delimiter and stores them in an array. This part of the code looks reasonable for basic tokenization.
```

### Syntax Analysis
```
The syntax_analysis function checks for the correct structure of the "if statement." It counts the number of "if" and "else" keywords and verifies the presence of opening and closing braces, as well as the presence of semicolons after assignments. It returns 1 if the syntax is valid, 0 otherwise.
```

## Semantic Analysis
```
The semantic_analysis function checks for the presence of relational and assignment operators within the "if statement." It returns 1 if both types of operators are present, 0 otherwise.
```

### Intermediate Code Generation
```
The intermediate_code_generation function prints a simplified intermediate code for the specific example. It appears to be a hardcoded representation of intermediate code.
```

### Main Function: 
```
The main function defines the input code, performs lexical analysis, syntax analysis, and semantic analysis. If all checks pass, it proceeds to intermediate code generation.
```

## By
- 20CE015 - AYUSH DABHI
- 20CE020 - AKSH DESAI
- 20CE035 - HITEN JADAV
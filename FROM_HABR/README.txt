/* Original code https://habr.com/ru/post/155439/

/* Сopied to my repository so as not to lose and practice. 
/* I independently parsed the code in detail for a better 
/* understanding of the essence.


/* Instead of a separate structure, which is a table of methods, 
/* we will explicitly put pointers to functions in our structure. 
/* And let's put it at the very beginning for simplicity.
/* If you need to do multiple "inheritance", 
/* we will put sequentially first methods of one interface, 
/* then methods of the second, etc.

/* In functions that accept pointers to an interface, 
/* we will pass a pointer to the first method of the interface 
/* in the structure. Since this method will have 
/* a structure-specific implementation, we can lay down 
/* on the offset of this address from the beginning of the address 
/* of the structure as a whole.

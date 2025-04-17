struct FILO {
int* ar;
int size;
int lastIndex;
FILO();

FILO(int); 

~FILO();


int addToEnd(int element);
int getFromEnd(int* element); 
void flush();
};

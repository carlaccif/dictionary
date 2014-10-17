#include "dictionary.h"

extern NODE memory[MAX_MEM];
DICT dictionary= { MAX_DICT,MYNULL,0};

int main (void) {

    WORD word;
    initMemory(); 
    while (1) {
       word = GetNextWord();
       cout << "<" << word << ">\n";
       if ( 0 == word.length()  )  {
           DumpDictionary(dictionary);
           break;
       }
       if (LocateWord(dictionary,word) < 0 ) {
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
       }
    }
    return 0;
}

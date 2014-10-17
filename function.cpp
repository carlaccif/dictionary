#include "dictionary.h"

NODE memory[MAX_MEM];
PTR freeList;

void initMemory (void )
{
  for ( auto i= 0; i < MAX_MEM -1; i++)
     {
        NODE_AT(i).w.frequency = 0;
        NODE_AT(i).nextWord = i+1;
     }
  NODE_AT(MAX_MEM -1).w.frequency = 0;
  NODE_AT(MAX_MEM -1).nextWord = MYNULL;
  freeList = 0;

#ifdef DEBUG 
  while (freeList != MYNULL) {
      cout << __FILE__ << " " << __LINE__ << " " << freeList << "  " << NODE_AT(freeList).w.frequency << endl;
      freeList = NODE_AT(freeList).nextWord;
  }
#endif

} 

void DumpDictionary(DICT &d) 
{
  auto currNode = d.wordList;
  cout << "Dumping dictionary ...\n";
//  for ( auto i =0 ; i < d.currWords; i++)
   while ( MYNULL != currNode)
      {
        cout <<  NODE_AT(currNode).w.word << "  " << NODE_AT(currNode).w.frequency << endl;
        currNode = NODE_AT(currNode).nextWord;
      }
  cout << "...Done!\n";
}

WORD GetNextWord(void)
{
 BOOL inWord = 0;
 WORD s;
 while( cin.good() )
   {
     char ch = cin.get();
     if ( isalpha(ch) ) { /* function test is ch  is A-Z, a-z */
         s.push_back(ch);
         inWord = 1;
     }
     else if (inWord ) return s;
   }
 return s;
}
 

int LocateWord(DICT& d, WORD w)
{
   int loc = 0;
   for (auto i = d.wordList; i != MYNULL ; i = NODE_AT(i).nextWord)
      if (w != NODE_AT(i).w.word) loc++;
          else return loc;
   return -1;
}

BOOL FullDictionary(DICT& d)
{
   return( d.maxWords == d.currWords);
}

BOOL InsertWord(DICT& d ,WORD w)
{
#ifdef DEBUG
   cout << __FILE__ << " " << __LINE__ << " freeList-> " << freeList << endl;
#endif
   PTR p = freeList;
   freeList = NODE_AT(freeList).nextWord;
   NODE_AT(p).w.word = w;
   NODE_AT(p).w.frequency = 1;
   NODE_AT(p).nextWord = MYNULL;
#ifdef DEBUG
   cout << __FILE__ << " " << __LINE__ << " freeList-> " << freeList << endl;
#endif
   if (0 == d.currWords ) 
      {
        d.wordList = p;
        d.currWords++;
      } else {
        NODE_AT(p).nextWord = d.wordList;
        d.wordList = p;
        d.currWords++;
      }
   return 1;
}

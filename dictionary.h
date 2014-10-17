#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_MEM = 500;
const int MAX_DICT= 200;

typedef int BOOL;
typedef string WORD;
typedef int PTR;


typedef struct {
     WORD word;
     int frequency;
} ENTRY;

typedef struct {
     ENTRY w;
     PTR  nextWord;
} NODE;


typedef struct {
       int maxWords;
       PTR wordList;
       int  currWords;
} DICT;


#define NODE_AT(i)  memory[i]
#define MYNULL -1

void initMemory();
int LocateWord(DICT&, WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);

#endif

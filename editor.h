#ifndef EDITOR_H
#define EDITOR_H

#include "stack.h"

void initEditor();
void typeText(const char *text);
void deleteWord(int wordIndex);
void undo();
void redo();
void showText();

#endif

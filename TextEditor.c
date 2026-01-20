#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char action[10];  
    char text[100];   
    int position;    
} Operation;

typedef struct {
    Operation data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Operation op) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++(s->top)] = op;
}

Operation pop(Stack *s) {
    Operation empty = {"", "", 0};
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return empty;
    }
    return s->data[(s->top)--];
}

Operation peek(Stack *s) {
    Operation empty = {"", "", 0};
    if (isEmpty(s)) return empty;
    return s->data[s->top];
}

static char editorText[1000] = "";
static Stack undoStack, redoStack;

void initEditor() {
    initStack(&undoStack);
    initStack(&redoStack);
    strcpy(editorText, "");
}

void typeText(const char *text) {
    Operation op;
    strcpy(op.action, "insert");

    if (strlen(editorText) == 0) {
        strcat(editorText, text);
        strcpy(op.text, text);
        op.position = 0;
    } else {
        strcat(editorText, " ");
        strcat(editorText, text);
        strcpy(op.text, " ");
        strcat(op.text, text);
        op.position = strlen(editorText) - strlen(op.text);
    }

    push(&undoStack, op);
    initStack(&redoStack);
}

void deleteWord(int wordIndex) {
    if (wordIndex < 0) return;

    char temp[1000];
    char deletedWord[100] = "";
    int wordCount = 0;
    temp[0] = '\0';

    char editorCopy[1000];
    strcpy(editorCopy, editorText);
    char *token = strtok(editorCopy, " ");

    while (token != NULL) {
        if (wordCount == wordIndex) {
            strcpy(deletedWord, token);
        } else {
            if (strlen(temp) > 0) strcat(temp, " ");
            strcat(temp, token);
        }
        token = strtok(NULL, " ");
        wordCount++;
    }

    if (wordIndex >= wordCount) {
        printf("Word index out of range!\n");
        return;
    }

    strcpy(editorText, temp);

    Operation op;
    strcpy(op.action, "delete");
    strcpy(op.text, deletedWord);
    op.position = wordIndex;
    push(&undoStack, op);
    initStack(&redoStack);
}

void undo() {
    if (isEmpty(&undoStack)) {
        printf("Nothing to undo!\n");
        return;
    }

    Operation last = pop(&undoStack);

    if (strcmp(last.action, "insert") == 0) {
        int len = strlen(editorText) - strlen(last.text);
        if (len >= 0) editorText[len] = '\0';
    } else if (strcmp(last.action, "delete") == 0) {
        char temp[1000];
        temp[0] = '\0';
        int currentWord = 0;

        char editorCopy[1000];
        strcpy(editorCopy, editorText);
        char *token = strtok(editorCopy, " ");

        while (token != NULL) {
            if (currentWord == last.position) {
                if (strlen(temp) > 0) strcat(temp, " ");
                strcat(temp, last.text);
            }
            if (strlen(temp) > 0) strcat(temp, " ");
            strcat(temp, token);
            token = strtok(NULL, " ");
            currentWord++;
        }

        if (currentWord == last.position) {
            if (strlen(temp) > 0) strcat(temp, " ");
            strcat(temp, last.text);
        }
        strcpy(editorText, temp);
    }

    push(&redoStack, last);
}

void redo() {
    if (isEmpty(&redoStack)) {
        printf("Nothing to redo!\n");
        return;
    }

    Operation last = pop(&redoStack);

    if (strcmp(last.action, "insert") == 0) {
        strcat(editorText, last.text);
    } else if (strcmp(last.action, "delete") == 0) {
        deleteWord(last.position);
        pop(&undoStack); 
    }

    push(&undoStack, last);
}

void showText() {
    printf("Current Text: \"%s\"\n", editorText);
}

int main() {
    int choice;
    char text[100];
    int wordIdx;

    initEditor();

    while (1) {
        printf("\n===== TEXT EDITOR =====\n");
        printf("1. Text\n");
        printf("2. Delete Word\n");
        printf("3. Undo Text\n");
        printf("4. Redo Text\n");
        printf("5. Close Text Editor\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter text: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0;
                typeText(text);
                showText();
                break;
            case 2:
                printf("Enter word index to delete (0-based): ");
                scanf("%d", &wordIdx);
                deleteWord(wordIdx);
                showText();
                break;
            case 3:
                undo();
                showText();
                break;
            case 4:
                redo();
                showText();
                break;
            case 5:
                printf("Closed Text Editor\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

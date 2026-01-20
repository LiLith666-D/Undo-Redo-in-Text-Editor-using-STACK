#include <stdio.h>
#include <string.h>
#include "editor.h"

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
                printf("Closed Text Editor");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

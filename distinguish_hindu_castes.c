#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert string to lowercase
void toLowercase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower((unsigned char)str[i]);
}

// Function to determine caste based on surname
const char* getCaste(const char* surname) {
    // Brahmin surnames
    const char* brahmin[] = {"sharma", "trivedi", "dwivedi", "bhattacharya", "chaturvedi", "mukherjee"};
    // Rajput surnames
    const char* rajput[] = {"singh", "chauhan", "rathore", "solanki", "parmar", "tomar"};
    // Kayastha surnames
    const char* kayastha[] = {"srivastava", "sinha", "mathur", "nigam", "ghosh"};
    // Vaishya surnames
    const char* vaishya[] = {"gupta", "agarwal", "jain", "maheshwari", "khandelwal"};
    // Scheduled Caste surnames
    const char* sc[] = {"valmiki", "paswan", "chamar", "mehra", "ram"};
    // Scheduled Tribe surnames
    const char* st[] = {"bhumij", "munda", "soren", "marandi", "tudu"};

    int i;
    // Check Brahmin
    for (i = 0; i < sizeof(brahmin)/sizeof(brahmin[0]); i++)
        if (strcmp(surname, brahmin[i]) == 0) return "Brahmin";
    // Check Rajput
    for (i = 0; i < sizeof(rajput)/sizeof(rajput[0]); i++)
        if (strcmp(surname, rajput[i]) == 0) return "Rajput";
    // Check Kayastha
    for (i = 0; i < sizeof(kayastha)/sizeof(kayastha[0]); i++)
        if (strcmp(surname, kayastha[i]) == 0) return "Kayastha";
    // Check Vaishya
    for (i = 0; i < sizeof(vaishya)/sizeof(vaishya[0]); i++)
        if (strcmp(surname, vaishya[i]) == 0) return "Vaishya";
    // Check SC
    for (i = 0; i < sizeof(sc)/sizeof(sc[0]); i++)
        if (strcmp(surname, sc[i]) == 0) return "Scheduled Caste";
    // Check ST
    for (i = 0; i < sizeof(st)/sizeof(st[0]); i++)
        if (strcmp(surname, st[i]) == 0) return "Scheduled Tribe";
    // If not found
    return "Caste not found or not listed";
}

int main() {
    char name[100], surname[50];

    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    // Extract surname (assume last word as surname)
    char *token = strtok(name, " ");
    char *last = token;
    while (token != NULL) {
        last = token;
        token = strtok(NULL, " ");
    }

    strcpy(surname, last);
    toLowercase(surname);

    printf("Detected caste: %s\n", getCaste(surname));
    return 0;
}
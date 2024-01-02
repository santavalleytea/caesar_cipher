#include <stdio.h>
#include <string.h>

#define SHIFT_AMOUNT 3  // The fixed number of positions to shift in the Caesar Cipher
#define NUM_SHIFT 3     // Shift amount for numbers

void encrypt(char *message);
void decrypt(char *message);

int main() {
    char choice;
    char password[100];  // Adjust size as needed

    while (1) {
        printf("Enter E to encrypt, D to decrypt, or Q to quit: ");
        scanf(" %c", &choice);  // Notice the space before %c to catch any previous newline characters

        switch (choice) {
            case 'E':
            case 'e':
                printf("Enter password to encrypt: ");
                scanf("%s", password);
                encrypt(password);
                printf("Encrypted password: %s\n", password);
                break;

            case 'D':
            case 'd':
                printf("Enter password to decrypt: ");
                scanf("%s", password);
                decrypt(password);
                printf("Decrypted password: %s\n", password);
                break;

            case 'Q':
            case 'q':
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void encrypt(char *message) {
    while (*message) {
        if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a') + SHIFT_AMOUNT) % 26 + 'a';
        } else if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A') + SHIFT_AMOUNT) % 26 + 'A';
        } else if (*message >= '0' && *message <= '9') {
            *message = ((*message - '0') + NUM_SHIFT) % 10 + '0';
        }
        message++;
    }
}

void decrypt(char *message) {
    while (*message) {
        if (*message >= 'a' && *message <= 'z') {
            *message = ((*message - 'a') - SHIFT_AMOUNT + 26) % 26 + 'a';
        } else if (*message >= 'A' && *message <= 'Z') {
            *message = ((*message - 'A') - SHIFT_AMOUNT + 26) % 26 + 'A';
        } else if (*message >= '0' && *message <= '9') {
            *message = ((*message - '0') - NUM_SHIFT + 10) % 10 + '0';
        }
        message++;
    }
}

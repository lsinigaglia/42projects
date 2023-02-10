#include <stdio.h>

int main() {
    FILE *fp;
    char string[] = "0123456789012345678901234567890123456789012";

    fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
	fprintf(fp, "%s", string);
	fclose(fp);
}

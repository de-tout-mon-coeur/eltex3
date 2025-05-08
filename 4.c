#include <stdio.h>

char* find_string(const char* str, const char* substr) 
{
    if (*substr == '\0') 
    {
        return (char*)str;
    }

    for (const char* p = str; *p != '\0'; p++) 
    {
        const char* s1 = p;
        const char* s2 = substr;

        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) 
	{
            s1++;
            s2++;
        }

        if (*s2 == '\0') 
	{
            return (char*)p;
        }
    }

    return NULL;
}

int main() 
{
    char str[256];
    char substr[256];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == '\n') 
	{
            str[i] = '\0';
            break;
        }
    }

    printf("Enter substring: ");
    fgets(substr, sizeof(substr), stdin);

    for (int i = 0; substr[i] != '\0'; i++) 
    {
        if (substr[i] == '\n') 
	{
            substr[i] = '\0';
            break;
        }
    }

    char* result = find_string(str, substr);

    if (result != NULL) 
    {
        printf("Found substring: \"%s\" (starting at %ld)\n", substr, result - str);
    } 
    else 
    {
        printf("Substring \"%s\" not found.\n", substr);
    }

    return 0;
}

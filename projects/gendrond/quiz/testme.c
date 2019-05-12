#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char inputChar()
{
  // TODO: rewrite this function
  int randomCharNum = 0;                        // Initialize randomCharNum
  randomCharNum = rand() % (126 + 1 - 32) + 32; // Randomly grab number between 32-126
  char character = (char)randomCharNum;         // Set to char form
  return character;                             // Return character
}

char *inputString()
{
  // TODO: rewrite this function
  static char string[6]; // Statically set string for return
  int i = 0;             // Initialize i for looping
  int randomCharNum = 0; // Initialize randomCharNum
  while (i != 5)         // Loop for first 4 chars
  {
    randomCharNum = rand() % (122 + 1 - 97) + 97; // Choose char between a-z randomly
    string[i] = (char)randomCharNum;              // Set to char form and add to string
    i++;                                          // Increment counter
  }
  string[5] = '\0'; // Null terminator for end of string

  return string; // Return static string
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();

    //printf("string: %s\n", s);
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0)
      state = 1;
    if (c == '(' && state == 1)
      state = 2;
    if (c == '{' && state == 2)
      state = 3;
    if (c == ' ' && state == 3)
      state = 4;
    if (c == 'a' && state == 4)
      state = 5;
    if (c == 'x' && state == 5)
      state = 6;
    if (c == '}' && state == 6)
      state = 7;
    if (c == ')' && state == 7)
      state = 8;
    if (c == ']' && state == 8)
      state = 9;
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  testme();
  return 0;
}
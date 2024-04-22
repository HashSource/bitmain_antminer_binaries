
void remove_dot_char(char *number)

{
  size_t sVar1;
  char *number_local;
  char tempStr [64];
  int j;
  int i;
  
  j = 0;
  for (i = 0; sVar1 = strlen(number), (uint)i < sVar1; i = i + 1) {
    if (number[i] != ',') {
      tempStr[j] = number[i];
      j = j + 1;
    }
  }
  tempStr[j] = '\0';
  strcpy(number,tempStr);
  return;
}



void add_dot_number(char *number)

{
  char *pcVar1;
  char *number_local;
  char acStack_2f [3];
  char tempStr [32];
  char *pstr;
  
  remove_dot_char(number);
  strcpy(tempStr,number);
  pcVar1 = strchr(number,0x2e);
  if ((pcVar1 != (char *)0x0) && (3 < (uint)((int)pcVar1 - (int)number))) {
    memcpy(tempStr,number,(size_t)(pcVar1 + (-3 - (int)number)));
    pcVar1[(int)(acStack_2f + -(int)number)] = ',';
    strcpy(pcVar1 + (int)(acStack_2f + (1 - (int)number)),
           number + (int)(pcVar1 + (-3 - (int)number)));
  }
  strcpy(number,tempStr);
  return;
}


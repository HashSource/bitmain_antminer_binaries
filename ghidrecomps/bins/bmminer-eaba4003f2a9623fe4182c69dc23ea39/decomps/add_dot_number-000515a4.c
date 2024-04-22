
void add_dot_number(char *number)

{
  char *number_local;
  char acStack_2f [3];
  char tempStr [32];
  char *pstr;
  
  remove_dot_char(number);
  strcpy(tempStr,number);
  pstr = strchr(number,0x2e);
  if ((pstr != (char *)0x0) && (3 < (uint)((int)pstr - (int)number))) {
    memcpy(tempStr,number,(size_t)(pstr + (-3 - (int)number)));
    pstr[(int)(acStack_2f + -(int)number)] = ',';
    strcpy(pstr + (int)(acStack_2f + (1 - (int)number)),pstr + -3);
  }
  strcpy(number,tempStr);
  return;
}


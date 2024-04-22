
/* WARNING: Unknown calling convention */

void add_dot_number(char *number)

{
  char *pcVar1;
  char *pstr;
  uint uVar2;
  char acStack_33 [3];
  char tempStr [32];
  
  remove_dot_char(number);
  strcpy(tempStr,number);
  pcVar1 = strchr(number,0x2e);
  if ((pcVar1 != (char *)0x0) && (uVar2 = (int)pcVar1 - (int)number, 3 < uVar2)) {
    memcpy(tempStr,number,uVar2 - 3);
    acStack_33[uVar2] = ',';
    strcpy(acStack_33 + uVar2 + 1,number + (uVar2 - 3));
  }
  strcpy(number,tempStr);
  return;
}


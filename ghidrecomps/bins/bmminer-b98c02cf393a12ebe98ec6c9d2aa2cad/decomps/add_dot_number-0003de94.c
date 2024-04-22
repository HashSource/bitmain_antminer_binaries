
void add_dot_number(char *param_1)

{
  char *pcVar1;
  uint uVar2;
  char acStack_33 [35];
  
  remove_dot_char();
  strcpy(acStack_33 + 3,param_1);
  pcVar1 = strchr(param_1,0x2e);
  if ((pcVar1 != (char *)0x0) && (uVar2 = (int)pcVar1 - (int)param_1, 3 < uVar2)) {
    memcpy(acStack_33 + 3,param_1,uVar2 - 3);
    acStack_33[uVar2] = ',';
    strcpy(acStack_33 + uVar2 + 1,param_1 + (uVar2 - 3));
  }
  strcpy(param_1,acStack_33 + 3);
  return;
}


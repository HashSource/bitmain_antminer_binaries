
void remove_dot_char(char *param_1)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  char acStack_50 [68];
  
  sVar2 = strlen(param_1);
  uVar4 = 0;
  iVar3 = 0;
  while (uVar4 < sVar2) {
    pcVar1 = param_1 + uVar4;
    uVar4 = uVar4 + 1;
    if (*pcVar1 != ',') {
      acStack_50[iVar3] = *pcVar1;
      iVar3 = iVar3 + 1;
    }
  }
  acStack_50[iVar3] = '\0';
  strcpy(param_1,acStack_50);
  return;
}


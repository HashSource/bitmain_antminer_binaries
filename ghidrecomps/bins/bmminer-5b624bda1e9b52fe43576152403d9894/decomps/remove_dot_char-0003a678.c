
/* WARNING: Unknown calling convention */

void remove_dot_char(char *number)

{
  char *pcVar1;
  size_t sVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  char tempStr [64];
  
  iVar5 = 0;
  uVar4 = 0;
  sVar2 = strlen(number);
  while (puVar3 = &stack0xfffffff0 + iVar5, uVar4 < sVar2) {
    while( true ) {
      pcVar1 = number + uVar4;
      uVar4 = uVar4 + 1;
      if (*pcVar1 == ',') break;
      puVar3[-0x40] = *pcVar1;
      sVar2 = strlen(number);
      puVar3 = &stack0xfffffff1 + iVar5;
      iVar5 = iVar5 + 1;
      if (sVar2 <= uVar4) goto LAB_0003a6b4;
    }
  }
LAB_0003a6b4:
  puVar3[-0x40] = 0;
  strcpy(number,tempStr);
  return;
}


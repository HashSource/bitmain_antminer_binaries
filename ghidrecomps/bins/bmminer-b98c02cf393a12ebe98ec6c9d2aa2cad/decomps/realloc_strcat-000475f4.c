
char * realloc_strcat(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  uint uVar3;
  char *pcVar4;
  
  sVar1 = strlen(param_2);
  if (sVar1 == 0) {
    return param_1;
  }
  if (param_1 != (char *)0x0) {
    sVar2 = strlen(param_1);
    uVar3 = sVar2 + sVar1 + 1;
    if ((uVar3 & 3) != 0) {
      uVar3 = (uVar3 & 0xfffffffc) + 4;
    }
    pcVar4 = (char *)_cgmalloc(uVar3,"util.c",DAT_0004767c,0xd55);
    sprintf(pcVar4,"%s%s",param_1,param_2);
    free(param_1);
    return pcVar4;
  }
  uVar3 = sVar1 + 1;
  if ((uVar3 & 3) != 0) {
    uVar3 = (uVar3 & 0xfffffffc) + 4;
  }
  pcVar4 = (char *)_cgmalloc(uVar3,"util.c",DAT_0004767c,0xd55);
  pcVar4 = strcpy(pcVar4,param_2);
  return pcVar4;
}


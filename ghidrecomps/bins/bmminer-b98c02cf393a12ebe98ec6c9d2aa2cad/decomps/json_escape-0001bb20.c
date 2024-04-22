
char * json_escape(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char **ppcVar4;
  char *pcVar5;
  
  sVar2 = strlen(param_1);
  pcVar3 = (char *)_cgmalloc(sVar2 * 2 + 1,"cgminer.c","json_escape",0x16cf,param_4);
  ppcVar4 = (char **)_cgmalloc(8,"cgminer.c","json_escape",0x16d0);
  *ppcVar4 = pcVar3;
  ppcVar4[1] = (char *)jedata;
  jedata = ppcVar4;
  cVar1 = *param_1;
  pcVar5 = pcVar3;
  while (cVar1 != '\0') {
    if (cVar1 == '\"' || cVar1 == '\\') {
      *pcVar5 = '\\';
      pcVar5 = pcVar5 + 1;
    }
    *pcVar5 = *param_1;
    cVar1 = param_1[1];
    pcVar5 = pcVar5 + 1;
    param_1 = param_1 + 1;
  }
  *pcVar5 = '\0';
  return pcVar3;
}


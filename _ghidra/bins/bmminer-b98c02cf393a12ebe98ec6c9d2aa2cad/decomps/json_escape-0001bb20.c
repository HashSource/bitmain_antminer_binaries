
char * json_escape(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  sVar2 = strlen(param_1);
  pcVar3 = (char *)_cgmalloc(sVar2 * 2 + 1,"cgminer.c","json_escape",0x16cf,param_4);
  puVar4 = (undefined4 *)_cgmalloc(8,"cgminer.c","json_escape",0x16d0);
  *puVar4 = pcVar3;
  puVar4[1] = jedata;
  jedata = puVar4;
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


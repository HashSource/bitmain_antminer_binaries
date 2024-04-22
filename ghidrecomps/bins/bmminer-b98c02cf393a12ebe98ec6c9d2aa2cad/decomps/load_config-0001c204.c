
char * load_config(char *param_1)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  undefined auStack_114 [92];
  char acStack_b8 [164];
  
  pcVar2 = param_1;
  if (cnfbuf == (char *)0x0) {
    pcVar2 = (char *)__strdup();
    cnfbuf = pcVar2;
  }
  iVar6 = include_count + 1;
  iVar1 = include_count + -9;
  include_count = iVar6;
  if (10 < iVar6) {
    pcVar2 = (char *)0xc450;
  }
  if (iVar6 == 10 || iVar1 < 0 != SBORROW4(iVar6,10)) {
    piVar3 = (int *)json_load_file(param_1,0,auStack_114);
    if ((piVar3 != (int *)0x0) && (*piVar3 == 0)) {
      config_loaded = 1;
      pcVar2 = (char *)parse_config(piVar3,1);
      return pcVar2;
    }
    sVar4 = strlen(param_1);
    sVar5 = strlen(acStack_b8);
    sVar4 = sVar5 + sVar4 + 0x23;
    pcVar2 = (char *)_cgmalloc(sVar4,"cgminer.c",DAT_0001c2a4,0x810);
    snprintf(pcVar2,sVar4,"JSON decode of file \'%s\' failed\n %s",param_1,acStack_b8);
    return pcVar2;
  }
  return (char *)((uint)pcVar2 & 0xffff | 0x50000);
}


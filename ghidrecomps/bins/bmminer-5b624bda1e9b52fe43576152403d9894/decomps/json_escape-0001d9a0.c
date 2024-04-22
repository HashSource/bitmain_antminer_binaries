
/* WARNING: Unknown calling convention */

char * json_escape(char *str)

{
  char **ppcVar1;
  size_t sVar2;
  char *pcVar3;
  char *buf;
  char **ppcVar4;
  JE *jeptr;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char cVar8;
  
  sVar2 = strlen(str);
  pcVar3 = (char *)_cgmalloc(sVar2 * 2 + 1,DAT_0001da04,DAT_0001da08,0x16b8);
  ppcVar4 = (char **)_cgmalloc(8,DAT_0001da04,DAT_0001da08,0x16b9);
  ppcVar1 = DAT_0001da0c;
  *ppcVar4 = pcVar3;
  pcVar5 = *ppcVar1;
  *ppcVar1 = (char *)ppcVar4;
  ppcVar4[1] = pcVar5;
  cVar8 = *str;
  pcVar5 = pcVar3;
  if (cVar8 != '\0') {
    pcVar6 = str + -1;
    do {
      pcVar7 = pcVar5;
      if (cVar8 == '\\' || cVar8 == '\"') {
        pcVar7 = pcVar5 + 1;
        *pcVar5 = '\\';
      }
      pcVar5 = pcVar7 + 1;
      *pcVar7 = pcVar6[1];
      cVar8 = pcVar6[2];
      pcVar6 = pcVar6 + 1;
    } while (cVar8 != '\0');
  }
  *pcVar5 = '\0';
  return pcVar3;
}


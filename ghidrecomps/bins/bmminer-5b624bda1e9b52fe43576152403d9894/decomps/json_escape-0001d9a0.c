
/* WARNING: Unknown calling convention */

char * json_escape(char *str)

{
  size_t sVar1;
  char *pcVar2;
  JE *pJVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char cVar7;
  
  sVar1 = strlen(str);
  pcVar2 = (char *)_cgmalloc(sVar1 * 2 + 1,"cgminer.c","json_escape",0x16b8);
  pJVar3 = (JE *)_cgmalloc(8,"cgminer.c","json_escape",0x16b9);
  pJVar3->buf = pcVar2;
  pJVar3->next = jedata;
  jedata = pJVar3;
  cVar7 = *str;
  pcVar6 = pcVar2;
  if (cVar7 != '\0') {
    pcVar4 = str + -1;
    do {
      pcVar5 = pcVar6;
      if (cVar7 == '\\' || cVar7 == '\"') {
        pcVar5 = pcVar6 + 1;
        *pcVar6 = '\\';
      }
      pcVar6 = pcVar5 + 1;
      *pcVar5 = pcVar4[1];
      cVar7 = pcVar4[2];
      pcVar4 = pcVar4 + 1;
    } while (cVar7 != '\0');
  }
  *pcVar6 = '\0';
  return pcVar2;
}


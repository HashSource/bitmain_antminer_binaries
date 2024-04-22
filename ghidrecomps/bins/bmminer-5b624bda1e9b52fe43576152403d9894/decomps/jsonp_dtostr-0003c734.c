
int jsonp_dtostr(char *buffer,size_t size,double value)

{
  int iVar1;
  char *pcVar2;
  int ret;
  size_t length;
  lconv *plVar3;
  char **point;
  char *pcVar4;
  char *pos;
  char *pcVar5;
  char *start;
  char *__src;
  char *end;
  
  pcVar2 = (char *)snprintf(buffer,size,DAT_0003c7dc);
  if (((int)pcVar2 < 0) || (size <= pcVar2)) {
    return -1;
  }
  plVar3 = localeconv();
  if (((byte)*plVar3->decimal_point != 0x2e) &&
     (pcVar4 = strchr(buffer,(uint)(byte)*plVar3->decimal_point), pcVar4 != (char *)0x0)) {
    *pcVar4 = '.';
  }
  pcVar5 = strchr(buffer,0x2e);
  pcVar4 = pcVar2;
  if (pcVar5 == (char *)0x0) {
    pcVar5 = strchr(buffer,0x65);
    if (pcVar5 != (char *)0x0) goto LAB_0003c77c;
    if (size <= pcVar2 + 3) {
      return -1;
    }
    pcVar4 = pcVar2 + 2;
    buffer[(int)pcVar2] = '.';
    buffer[(int)(pcVar2 + 1)] = '0';
    buffer[(int)pcVar4] = '\0';
  }
  pcVar5 = strchr(buffer,0x65);
  pcVar2 = pcVar4;
  if (pcVar5 == (char *)0x0) {
    return (int)pcVar4;
  }
LAB_0003c77c:
  __src = pcVar5 + 2;
  pcVar4 = __src;
  if (pcVar5[1] != '-') {
    pcVar4 = pcVar5 + 1;
  }
  if (pcVar5[2] == '0') {
    pcVar5 = pcVar5 + 3;
    do {
      __src = pcVar5;
      pcVar5 = __src + 1;
    } while (*__src == '0');
  }
  if (__src != pcVar4) {
    iVar1 = (int)pcVar2 - (int)__src;
    pcVar2 = pcVar4 + ((int)pcVar2 - (int)__src);
    memmove(pcVar4,__src,(size_t)(buffer + iVar1));
  }
  return (int)pcVar2;
}


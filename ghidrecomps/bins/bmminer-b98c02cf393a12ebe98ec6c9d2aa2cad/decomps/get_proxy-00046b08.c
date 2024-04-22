
char * get_proxy(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__dest;
  char *__src;
  char *pcVar3;
  int iVar4;
  size_t __n;
  
  iVar1 = DAT_00046bb0;
  iVar4 = 0;
  pcVar3 = "http:";
  __n = 5;
  *(undefined4 *)(param_2 + 0xb8) = 0;
  while( true ) {
    iVar2 = strncmp(param_1,pcVar3,__n);
    if (iVar2 == 0) {
      pcVar3 = strchr(param_1,0x7c);
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
        __dest = (char *)_cgmalloc(pcVar3 + ((1 - __n) - (int)param_1),"util.c","get_proxy",0x2ee);
        __src = param_1 + __n;
        *(char **)(param_2 + 0xb8) = __dest;
        param_1 = pcVar3 + 1;
        strcpy(__dest,__src);
        extract_sockaddr(*(undefined4 *)(param_2 + 0xb8),param_2 + 0x25c,param_2 + 0x260);
        *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(proxynames + iVar4 * 8 + 4);
      }
      return param_1;
    }
    iVar4 = iVar4 + 1;
    pcVar3 = *(char **)(iVar1 + iVar4 * 8);
    if (pcVar3 == (char *)0x0) break;
    __n = strlen(pcVar3);
  }
  return param_1;
}


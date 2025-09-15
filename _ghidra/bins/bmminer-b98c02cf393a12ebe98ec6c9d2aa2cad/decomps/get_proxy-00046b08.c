
char * get_proxy(char *param_1,int param_2)

{
  int iVar1;
  char *__dest;
  char *__src;
  char *pcVar2;
  int iVar3;
  size_t __n;
  
  iVar3 = 0;
  pcVar2 = "http:";
  __n = 5;
  *(undefined4 *)(param_2 + 0xb8) = 0;
  while( true ) {
    iVar1 = strncmp(param_1,pcVar2,__n);
    if (iVar1 == 0) {
      pcVar2 = strchr(param_1,0x7c);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
        __dest = (char *)_cgmalloc(pcVar2 + ((1 - __n) - (int)param_1),"util.c","get_proxy",0x2ee);
        __src = param_1 + __n;
        *(char **)(param_2 + 0xb8) = __dest;
        param_1 = pcVar2 + 1;
        strcpy(__dest,__src);
        extract_sockaddr(*(undefined4 *)(param_2 + 0xb8),param_2 + 0x25c,param_2 + 0x260);
        *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(proxynames + iVar3 * 8 + 4);
      }
      return param_1;
    }
    iVar3 = iVar3 + 1;
    pcVar2 = *(char **)(proxynames + iVar3 * 8);
    if (pcVar2 == (char *)0x0) break;
    __n = strlen(pcVar2);
  }
  return param_1;
}


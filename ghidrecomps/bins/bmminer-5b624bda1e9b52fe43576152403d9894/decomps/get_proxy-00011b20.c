
/* WARNING: Unknown calling convention */

char * get_proxy(char *url,pool *pool)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *split;
  char *pcVar4;
  char *__src;
  int len;
  int iVar5;
  int plen;
  size_t __n;
  
  iVar1 = DAT_00011bc0;
  pcVar4 = DAT_00011bb8;
  iVar5 = 0;
  __n = 5;
  pool->rpc_proxy = (char *)0x0;
  while( true ) {
    iVar2 = strncmp(url,pcVar4,__n);
    if (iVar2 == 0) {
      pcVar3 = strchr(url,0x7c);
      iVar1 = DAT_00011bc4;
      pcVar4 = DAT_00011bbc;
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
        pcVar4 = (char *)_cgmalloc((uint)(pcVar3 + ((1 - __n) - (int)url)),pcVar4,
                                   (char *)(iVar1 + 0x670),0x2ee);
        __src = url + __n;
        pool->rpc_proxy = pcVar4;
        url = pcVar3 + 1;
        strcpy(pcVar4,__src);
        extract_sockaddr(pool->rpc_proxy,&pool->sockaddr_proxy_url,&pool->sockaddr_proxy_port);
        pool->rpc_proxytype = *(proxytypes_t *)(iVar1 + iVar5 * 8 + 0x420);
      }
      return url;
    }
    iVar5 = iVar5 + 1;
    pcVar4 = *(char **)(iVar1 + iVar5 * 8);
    if (pcVar4 == (char *)0x0) break;
    __n = strlen(pcVar4);
  }
  return url;
}



/* WARNING: Unknown calling convention */

char * get_proxy(char *url,pool *pool)

{
  int iVar1;
  char *__dest;
  char *__src;
  char *pcVar2;
  int iVar3;
  int plen;
  size_t __n;
  
  pcVar2 = "http:";
  iVar3 = 0;
  __n = 5;
  pool->rpc_proxy = (char *)0x0;
  while( true ) {
    iVar1 = strncmp(url,pcVar2,__n);
    if (iVar1 == 0) {
      pcVar2 = strchr(url,0x7c);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
        __dest = (char *)_cgmalloc((uint)(pcVar2 + ((1 - __n) - (int)url)),"util.c","get_proxy",
                                   0x2ee);
        __src = url + __n;
        pool->rpc_proxy = __dest;
        url = pcVar2 + 1;
        strcpy(__dest,__src);
        extract_sockaddr(pool->rpc_proxy,&pool->sockaddr_proxy_url,&pool->sockaddr_proxy_port);
        pool->rpc_proxytype = proxynames[iVar3].proxytype;
      }
      return url;
    }
    iVar3 = iVar3 + 1;
    pcVar2 = proxynames[iVar3].name;
    if (pcVar2 == (char *)0x0) break;
    __n = strlen(pcVar2);
  }
  return url;
}


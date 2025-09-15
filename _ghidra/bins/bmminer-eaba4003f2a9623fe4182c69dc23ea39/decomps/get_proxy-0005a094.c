
char * get_proxy(char *url,pool *pool)

{
  size_t __n;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  pool *pool_local;
  char *url_local;
  int len;
  char *split;
  int plen;
  int i;
  
  pool->rpc_proxy = (char *)0x0;
  i = 0;
  while( true ) {
    if (proxynames[i].name == (char *)0x0) {
      return url;
    }
    __n = strlen(proxynames[i].name);
    iVar1 = strncmp(url,proxynames[i].name,__n);
    if (iVar1 == 0) break;
    i = i + 1;
  }
  pcVar2 = strchr(url,0x7c);
  if (pcVar2 == (char *)0x0) {
    return url;
  }
  *pcVar2 = '\0';
  pcVar3 = (char *)_cgmalloc((uint)(pcVar2 + (-__n - (int)url) + 1),"util.c","get_proxy",0x2ee);
  pool->rpc_proxy = pcVar3;
  strcpy(pool->rpc_proxy,url + __n);
  extract_sockaddr(pool->rpc_proxy,&pool->sockaddr_proxy_url,&pool->sockaddr_proxy_port);
  pool->rpc_proxytype = proxynames[i].proxytype;
  return pcVar2 + 1;
}



/* WARNING: Unknown calling convention */

_Bool detect_stratum(pool *pool,char *url)

{
  _Bool _Var1;
  int iVar2;
  char *pcVar3;
  
  _Var1 = extract_sockaddr(url,&pool->sockaddr_url,&pool->stratum_port);
  if (_Var1) {
    iVar2 = strncasecmp(url,DAT_0001eb98,0xe);
    if (iVar2 == 0) {
      pcVar3 = (char *)__strdup(url);
      pool->rpc_url = pcVar3;
      pool->has_stratum = true;
      pool->stratum_url = pool->sockaddr_url;
      return true;
    }
    _Var1 = false;
  }
  return _Var1;
}



char * setup_url(pool *pool,char *arg)

{
  _Bool _Var1;
  char *url;
  int iVar2;
  char *__dest;
  char *arg_local;
  pool *pool_local;
  char *httpinput;
  
  url = get_proxy(arg,pool);
  _Var1 = detect_stratum(pool,url);
  if (!_Var1) {
    opt_set_charp(url,&pool->rpc_url);
    iVar2 = strncmp(url,"http://",7);
    if ((iVar2 != 0) && (iVar2 = strncmp(url,"https://",8), iVar2 != 0)) {
      __dest = (char *)_cgmalloc(0x100,"cgminer.c","setup_url",0x3fc);
      builtin_strncpy(__dest,"stratum+tcp://",0xf);
      strncat(__dest,url,0xf2);
      detect_stratum(pool,__dest);
    }
  }
  return pool->rpc_url;
}


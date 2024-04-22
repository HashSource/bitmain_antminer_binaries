
/* WARNING: Unknown calling convention */

char * setup_url(pool *pool,char *arg)

{
  char cVar1;
  undefined2 uVar2;
  _Bool _Var3;
  char *url;
  int iVar4;
  char **__dest;
  char *httpinput;
  char *pcVar5;
  char *pcVar6;
  
  url = get_proxy(arg,pool);
  _Var3 = detect_stratum(pool,url);
  if (!_Var3) {
    opt_set_charp(url,&pool->rpc_url);
    iVar4 = strncmp(url,DAT_0001ec18,7);
    if ((iVar4 != 0) && (iVar4 = strncmp(url,DAT_0001ec1c,8), iVar4 != 0)) {
      __dest = (char **)_cgmalloc(0x100,DAT_0001ec20,DAT_0001ec24,0x3ef);
      httpinput = *DAT_0001ec28;
      pcVar5 = DAT_0001ec28[1];
      pcVar6 = DAT_0001ec28[2];
      uVar2 = *(undefined2 *)(DAT_0001ec28 + 3);
      cVar1 = *(char *)((int)DAT_0001ec28 + 0xe);
      *__dest = httpinput;
      __dest[1] = pcVar5;
      __dest[2] = pcVar6;
      *(undefined2 *)(__dest + 3) = uVar2;
      *(char *)((int)__dest + 0xe) = cVar1;
      strncat((char *)__dest,url,0xf2);
      detect_stratum(pool,(char *)__dest);
    }
  }
  return pool->rpc_url;
}


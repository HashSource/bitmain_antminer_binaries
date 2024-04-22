
char * setup_url(pool *pool,char *arg)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  _Bool _Var4;
  char *url;
  int iVar5;
  undefined4 *__dest;
  char *arg_local;
  pool *pool_local;
  char *httpinput;
  
  url = get_proxy(arg,pool);
  _Var4 = detect_stratum(pool,url);
  if (!_Var4) {
    opt_set_charp(url,&pool->rpc_url);
    iVar5 = strncmp(url,"http://",7);
    if ((iVar5 != 0) && (iVar5 = strncmp(url,"https://",8), iVar5 != 0)) {
      __dest = (undefined4 *)_cgmalloc(0x100,"cgminer.c","setup_url",0x3fc);
      uVar2 = s_stratum_tcp____000a1ddc._8_4_;
      uVar1 = s_stratum_tcp____000a1ddc._4_4_;
      *__dest = s_stratum_tcp____000a1ddc._0_4_;
      __dest[1] = uVar1;
      __dest[2] = uVar2;
      cVar3 = s_stratum_tcp____000a1ddc[14];
      *(undefined2 *)(__dest + 3) = s_stratum_tcp____000a1ddc._12_2_;
      *(char *)((int)__dest + 0xe) = cVar3;
      strncat((char *)__dest,url,0xf2);
      detect_stratum(pool,(char *)__dest);
    }
  }
  return pool->rpc_url;
}


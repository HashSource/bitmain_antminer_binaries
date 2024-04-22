
undefined4 ssl_ctx_make_profiles(char *param_1,_STACK **param_2)

{
  char **data;
  char **ppcVar1;
  _STACK *st;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  char *__s;
  size_t __n;
  int line;
  
  st = sk_new_null();
  ppcVar1 = DAT_000795f0;
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x14,0x135,0x16a,DAT_000795f4,0xb0);
    return 1;
  }
  while( true ) {
    pcVar2 = strchr(param_1,0x3a);
    if (pcVar2 == (char *)0x0) {
      __n = strlen(param_1);
    }
    else {
      __n = (int)pcVar2 - (int)param_1;
    }
    __s = *ppcVar1;
    data = DAT_000795f0;
    while( true ) {
      if (__s == (char *)0x0) {
        iVar4 = 0x16c;
        line = 0xc3;
        goto LAB_000795a2;
      }
      sVar3 = strlen(__s);
      if ((__n == sVar3) && (iVar4 = strncmp(__s,param_1,__n), iVar4 == 0)) break;
      __s = data[2];
      HintPreloadData(data + 0xe);
      data = data + 2;
    }
    iVar4 = sk_find(st,data);
    if (-1 < iVar4) break;
    sk_push(st,data);
    if (pcVar2 == (char *)0x0) {
      *param_2 = st;
      return 0;
    }
    param_1 = pcVar2 + 1;
  }
  line = 0xbb;
  iVar4 = 0x161;
LAB_000795a2:
  ERR_put_error(0x14,0x135,iVar4,DAT_000795f4,line);
  sk_free(st);
  return 1;
}


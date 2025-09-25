
undefined4 ssl_ctx_make_profiles(char *param_1,int *param_2)

{
  undefined4 *puVar1;
  char *__s;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  size_t __n;
  
  iVar2 = OPENSSL_sk_new_null();
  if (iVar2 == 0) {
    ERR_put_error(0x14,0x135,0x16a,"ssl/d1_srtp.c",0x48);
  }
  else {
    while( true ) {
      pcVar3 = strchr(param_1,0x3a);
      __n = (int)pcVar3 - (int)param_1;
      puVar1 = &srtp_known_profiles;
      __s = srtp_known_profiles;
      if (pcVar3 == (char *)0x0) {
        __n = strlen(param_1);
        __s = srtp_known_profiles;
      }
      while( true ) {
        if (__s == (char *)0x0) {
          ERR_put_error(0x14,0x135,0x16c,"ssl/d1_srtp.c",0x5e);
          goto LAB_000fb898;
        }
        HintPreloadData(puVar1 + 0xe);
        sVar4 = strlen(__s);
        if ((__n == sVar4) && (iVar5 = strncmp(__s,param_1,__n), iVar5 == 0)) break;
        puVar1 = puVar1 + 2;
        __s = (char *)*puVar1;
      }
      iVar5 = OPENSSL_sk_find(iVar2,puVar1);
      if (-1 < iVar5) break;
      iVar5 = OPENSSL_sk_push(iVar2,puVar1);
      if (iVar5 == 0) {
        ERR_put_error(0x14,0x135,0x16a,"ssl/d1_srtp.c",0x59);
        goto LAB_000fb898;
      }
      if (pcVar3 == (char *)0x0) {
        OPENSSL_sk_free(*param_2);
        *param_2 = iVar2;
        return 0;
      }
      param_1 = pcVar3 + 1;
    }
    ERR_put_error(0x14,0x135,0x161,"ssl/d1_srtp.c",0x53);
LAB_000fb898:
    OPENSSL_sk_free(iVar2);
  }
  return 1;
}


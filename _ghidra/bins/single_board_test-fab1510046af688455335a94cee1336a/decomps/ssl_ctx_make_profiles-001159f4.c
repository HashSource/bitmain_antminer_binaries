
undefined4 ssl_ctx_make_profiles(char *param_1,undefined4 *param_2)

{
  _STACK *st;
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  int *data;
  char *__s;
  size_t __n;
  int line;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x14,0x135,0x16a,"d1_srtp.c",0xb0);
    return 1;
  }
  do {
    pcVar1 = strchr(param_1,0x3a);
    if (pcVar1 == (char *)0x0) {
      __n = strlen(param_1);
    }
    else {
      __n = (int)pcVar1 - (int)param_1;
    }
    if (srtp_known_profiles == (char *)0x0) {
LAB_00115a68:
      iVar3 = 0x16c;
      line = 0xc3;
LAB_00115a76:
      ERR_put_error(0x14,0x135,iVar3,"d1_srtp.c",line);
      sk_free(st);
      return 1;
    }
    data = (int *)&srtp_known_profiles;
    __s = srtp_known_profiles;
    while ((sVar2 = strlen(__s), __n != sVar2 || (iVar3 = strncmp(__s,param_1,__n), iVar3 != 0))) {
      __s = (char *)data[2];
      HintPreloadData(data + 0xe);
      data = data + 2;
      if (__s == (char *)0x0) goto LAB_00115a68;
    }
    iVar3 = sk_find(st,data);
    if (-1 < iVar3) {
      line = 0xbb;
      iVar3 = 0x161;
      goto LAB_00115a76;
    }
    sk_push(st,data);
    if (pcVar1 == (char *)0x0) {
      *param_2 = st;
      return 0;
    }
    param_1 = pcVar1 + 1;
  } while( true );
}


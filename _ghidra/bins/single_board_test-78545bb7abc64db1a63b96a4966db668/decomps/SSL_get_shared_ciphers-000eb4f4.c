
char * SSL_get_shared_ciphers(SSL *s,char *buf,int len)

{
  stack_st_SSL_CIPHER *psVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  int iVar4;
  int iVar5;
  char *__dest;
  int iVar6;
  char *pcVar7;
  bool bVar8;
  
  if (s->in_handshake != 0) {
    iVar6 = *(int *)(s->sid_ctx + 0x18);
    bVar8 = iVar6 != 0;
    iVar4 = iVar6;
    if (bVar8) {
      iVar4 = len + -1;
    }
    if ((bVar8 && len != 1) && iVar4 < 0 == (bVar8 && SBORROW4(len,1))) {
      iVar4 = 0;
      psVar1 = SSL_get_ciphers(s);
      if (((psVar1 != (stack_st_SSL_CIPHER *)0x0) && (iVar2 = OPENSSL_sk_num(iVar6), iVar2 != 0)) &&
         (iVar2 = OPENSSL_sk_num(psVar1), __dest = buf, iVar2 != 0)) {
        while( true ) {
          do {
            iVar2 = OPENSSL_sk_num(iVar6);
            iVar5 = iVar4 + 1;
            if (iVar2 <= iVar4) {
              __dest[-1] = '\0';
              return buf;
            }
            iVar2 = OPENSSL_sk_value(iVar6,iVar4);
            iVar3 = OPENSSL_sk_find(psVar1,iVar2);
            iVar4 = iVar5;
          } while (iVar3 < 0);
          pcVar7 = *(char **)(iVar2 + 4);
          __n = strlen(pcVar7);
          if (len <= (int)__n) break;
          memcpy(__dest,pcVar7,__n);
          len = len - (__n + 1);
          __dest[__n] = ':';
          __dest = __dest + __n + 1;
        }
        pcVar7 = buf;
        if (__dest != buf) {
          pcVar7 = __dest + -1;
        }
        *pcVar7 = '\0';
        return buf;
      }
    }
  }
  return (char *)0x0;
}


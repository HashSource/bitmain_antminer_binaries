
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SSL_SESSION * SSL_SESSION_new(void)

{
  SSL_SESSION *__s;
  time_t tVar1;
  
  __s = (SSL_SESSION *)CRYPTO_malloc(0xf4,DAT_0007eacc,0xc4);
  if (__s == (SSL_SESSION *)0x0) {
    ERR_put_error(0x14,0xbd,0x41,DAT_0007eacc,0xc6);
  }
  else {
    memset(__s,0,0xf4);
    *(undefined4 *)(__s->krb5_client_princ + 0x10) = 1;
    *(undefined4 *)(__s->krb5_client_princ + 0x14) = 1;
    *(undefined4 *)(__s->krb5_client_princ + 0x18) = 0x130;
    tVar1 = time((time_t *)0x0);
    *(undefined4 *)(__s->krb5_client_princ + 0x38) = 0;
    *(time_t *)(__s->krb5_client_princ + 0x1c) = tVar1;
    *(undefined4 *)(__s->krb5_client_princ + 0x3c) = 0;
    *(undefined4 *)(__s->krb5_client_princ + 0x20) = 0;
    *(undefined4 *)(__s->krb5_client_princ + 0x40) = 0;
    *(undefined4 *)(__s->krb5_client_princ + 0x44) = 0;
    *(undefined4 *)(__s->krb5_client_princ + 0x48) = 0;
    *(undefined4 *)(__s->krb5_client_princ + 0x4c) = 0;
    *(undefined4 *)(__s->krb5_client_princ + 0x50) = 0;
    CRYPTO_new_ex_data(3,__s,(CRYPTO_EX_DATA *)(__s->krb5_client_princ + 0x30));
    __s->krb5_client_princ_len = 0;
    *(undefined4 *)__s->krb5_client_princ = 0;
    *(undefined4 *)(__s->krb5_client_princ + 0x60) = 0;
  }
  return __s;
}


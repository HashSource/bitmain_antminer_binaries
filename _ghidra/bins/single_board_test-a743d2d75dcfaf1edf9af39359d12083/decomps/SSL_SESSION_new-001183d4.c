
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SSL_SESSION * SSL_SESSION_new(void)

{
  SSL_SESSION *__s;
  time_t tVar1;
  
  __s = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xc4);
  if (__s == (SSL_SESSION *)0x0) {
    ERR_put_error(0x14,0xbd,0x41,"ssl_sess.c",0xc6);
  }
  else {
    memset(__s,0,0xf4);
    __s->krb5_client_princ[0x10] = '\x01';
    __s->krb5_client_princ[0x11] = '\0';
    __s->krb5_client_princ[0x12] = '\0';
    __s->krb5_client_princ[0x13] = '\0';
    __s->krb5_client_princ[0x14] = '\x01';
    __s->krb5_client_princ[0x15] = '\0';
    __s->krb5_client_princ[0x16] = '\0';
    __s->krb5_client_princ[0x17] = '\0';
    __s->krb5_client_princ[0x18] = '0';
    __s->krb5_client_princ[0x19] = '\x01';
    __s->krb5_client_princ[0x1a] = '\0';
    __s->krb5_client_princ[0x1b] = '\0';
    tVar1 = time((time_t *)0x0);
    __s->krb5_client_princ[0x38] = '\0';
    __s->krb5_client_princ[0x39] = '\0';
    __s->krb5_client_princ[0x3a] = '\0';
    __s->krb5_client_princ[0x3b] = '\0';
    *(time_t *)(__s->krb5_client_princ + 0x1c) = tVar1;
    __s->krb5_client_princ[0x3c] = '\0';
    __s->krb5_client_princ[0x3d] = '\0';
    __s->krb5_client_princ[0x3e] = '\0';
    __s->krb5_client_princ[0x3f] = '\0';
    __s->krb5_client_princ[0x20] = '\0';
    __s->krb5_client_princ[0x21] = '\0';
    __s->krb5_client_princ[0x22] = '\0';
    __s->krb5_client_princ[0x23] = '\0';
    __s->krb5_client_princ[0x40] = '\0';
    __s->krb5_client_princ[0x41] = '\0';
    __s->krb5_client_princ[0x42] = '\0';
    __s->krb5_client_princ[0x43] = '\0';
    __s->krb5_client_princ[0x44] = '\0';
    __s->krb5_client_princ[0x45] = '\0';
    __s->krb5_client_princ[0x46] = '\0';
    __s->krb5_client_princ[0x47] = '\0';
    __s->krb5_client_princ[0x48] = '\0';
    __s->krb5_client_princ[0x49] = '\0';
    __s->krb5_client_princ[0x4a] = '\0';
    __s->krb5_client_princ[0x4b] = '\0';
    __s->krb5_client_princ[0x4c] = '\0';
    __s->krb5_client_princ[0x4d] = '\0';
    __s->krb5_client_princ[0x4e] = '\0';
    __s->krb5_client_princ[0x4f] = '\0';
    __s->krb5_client_princ[0x50] = '\0';
    __s->krb5_client_princ[0x51] = '\0';
    __s->krb5_client_princ[0x52] = '\0';
    __s->krb5_client_princ[0x53] = '\0';
    CRYPTO_new_ex_data(3,__s,(CRYPTO_EX_DATA *)(__s->krb5_client_princ + 0x30));
    __s->krb5_client_princ_len = 0;
    __s->krb5_client_princ[0] = '\0';
    __s->krb5_client_princ[1] = '\0';
    __s->krb5_client_princ[2] = '\0';
    __s->krb5_client_princ[3] = '\0';
    __s->krb5_client_princ[0x60] = '\0';
    __s->krb5_client_princ[0x61] = '\0';
    __s->krb5_client_princ[0x62] = '\0';
    __s->krb5_client_princ[99] = '\0';
  }
  return __s;
}


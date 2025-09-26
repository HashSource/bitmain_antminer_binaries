
char * SSL_get_cipher_list(SSL *s,int n)

{
  stack_st_SSL_CIPHER *psVar1;
  int iVar2;
  
  if (s == (SSL *)0x0) {
    return (char *)0x0;
  }
  psVar1 = SSL_get_ciphers(s);
  if (((psVar1 != (stack_st_SSL_CIPHER *)0x0) && (iVar2 = OPENSSL_sk_num(), n < iVar2)) &&
     (iVar2 = OPENSSL_sk_value(psVar1,n), iVar2 != 0)) {
    return *(char **)(iVar2 + 4);
  }
  return (char *)0x0;
}


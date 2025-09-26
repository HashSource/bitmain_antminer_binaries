
stack_st_SSL_CIPHER * SSL_get_ciphers(SSL *s)

{
  stack_st_SSL_CIPHER *psVar1;
  
  if (s == (SSL *)0x0) {
    psVar1 = (stack_st_SSL_CIPHER *)0x0;
  }
  else {
    psVar1 = *(stack_st_SSL_CIPHER **)(s->sid_ctx + 0x1c);
    if ((psVar1 == (stack_st_SSL_CIPHER *)0x0) && (s[3].method != (SSL_METHOD *)0x0)) {
      return (stack_st_SSL_CIPHER *)(s[3].method)->ssl_new;
    }
  }
  return psVar1;
}


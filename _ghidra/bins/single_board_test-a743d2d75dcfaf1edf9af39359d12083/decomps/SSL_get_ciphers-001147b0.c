
stack_st_SSL_CIPHER * SSL_get_ciphers(SSL *s)

{
  SSL *pSVar1;
  
  pSVar1 = s;
  if (((s != (SSL *)0x0) && (pSVar1 = (SSL *)s->cipher_list, pSVar1 == (SSL *)0x0)) &&
     (s->psk_server_callback != (_func_3296 *)0x0)) {
    return *(stack_st_SSL_CIPHER **)(s->psk_server_callback + 4);
  }
  return (stack_st_SSL_CIPHER *)pSVar1;
}


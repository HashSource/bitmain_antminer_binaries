
stack_st_X509_NAME * SSL_get_client_CA_list(SSL *s)

{
  stack_st_X509_NAME *psVar1;
  
  if (s->in_handshake == 0) {
    psVar1 = (stack_st_X509_NAME *)s->mac_flags;
    if (psVar1 != (stack_st_X509_NAME *)0x0) {
      psVar1 = (stack_st_X509_NAME *)psVar1[0x1b].stack.sorted;
    }
  }
  else {
    psVar1 = (stack_st_X509_NAME *)s[3].in_handshake;
    if (psVar1 == (stack_st_X509_NAME *)0x0) {
      return (stack_st_X509_NAME *)s[3].method[1].ssl_read_bytes;
    }
  }
  return psVar1;
}


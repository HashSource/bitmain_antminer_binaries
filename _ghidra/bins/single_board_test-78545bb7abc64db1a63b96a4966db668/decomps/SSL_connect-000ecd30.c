
int SSL_connect(SSL *ssl)

{
  int iVar1;
  
  if (ssl->rwstate != 0) {
    iVar1 = SSL_do_handshake(ssl);
    return iVar1;
  }
  SSL_set_connect_state(ssl);
  iVar1 = SSL_do_handshake(ssl);
  return iVar1;
}


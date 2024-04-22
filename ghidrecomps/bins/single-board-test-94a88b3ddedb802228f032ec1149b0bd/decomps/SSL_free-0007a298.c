
void SSL_free(SSL *ssl)

{
  int iVar1;
  
  if (ssl != (SSL *)0x0) {
    iVar1 = CRYPTO_add_lock((int *)&ssl->client_CA,-1,0x10,DAT_0007a2c8,0x230);
    if (iVar1 < 1) {
      SSL_free_part_6(ssl);
      return;
    }
  }
  return;
}


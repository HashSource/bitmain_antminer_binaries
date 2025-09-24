
int SSL_set_session_ticket_ext(SSL *s,void *ext_data,int ext_len)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (s->version < 0x301) {
    return 0;
  }
  CRYPTO_free(*(void **)(s[3].sid_ctx + 0x18));
  s[3].sid_ctx[0x18] = '\0';
  s[3].sid_ctx[0x19] = '\0';
  s[3].sid_ctx[0x1a] = '\0';
  s[3].sid_ctx[0x1b] = '\0';
  puVar1 = (undefined2 *)CRYPTO_malloc(ext_len + 8,"ssl/ssl_sess.c",0x400);
  *(undefined2 **)(s[3].sid_ctx + 0x18) = puVar1;
  if (puVar1 == (undefined2 *)0x0) {
    ERR_put_error(0x14,0x126,0x41,"ssl/ssl_sess.c",0x402);
    iVar2 = 0;
  }
  else {
    if (ext_data == (void *)0x0) {
      *puVar1 = 0;
      *(undefined4 *)(puVar1 + 2) = 0;
      return 1;
    }
    *puVar1 = (short)ext_len;
    *(undefined2 **)(puVar1 + 2) = puVar1 + 4;
    memcpy(puVar1 + 4,ext_data,ext_len);
    iVar2 = 1;
  }
  return iVar2;
}


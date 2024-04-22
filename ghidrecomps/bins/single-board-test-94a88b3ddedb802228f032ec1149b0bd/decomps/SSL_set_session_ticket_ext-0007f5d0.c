
int SSL_set_session_ticket_ext(SSL *s,void *ext_data,int ext_len)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (s->version < 0x301) {
    iVar1 = 0;
  }
  else {
    if ((void *)s->tlsext_opaque_prf_input_len != (void *)0x0) {
      CRYPTO_free((void *)s->tlsext_opaque_prf_input_len);
      s->tlsext_opaque_prf_input_len = 0;
    }
    puVar2 = (undefined2 *)CRYPTO_malloc(ext_len + 8,DAT_0007f644,0x423);
    s->tlsext_opaque_prf_input_len = (size_t)puVar2;
    if (puVar2 == (undefined2 *)0x0) {
      ERR_put_error(0x14,0x126,0x41,DAT_0007f644,0x425);
      iVar1 = 0;
    }
    else if (ext_data == (void *)0x0) {
      *puVar2 = 0;
      iVar1 = 1;
      *(undefined4 *)(puVar2 + 2) = 0;
    }
    else {
      *puVar2 = (short)ext_len;
      *(undefined2 **)(puVar2 + 2) = puVar2 + 4;
      memcpy(puVar2 + 4,ext_data,ext_len);
      iVar1 = 1;
    }
  }
  return iVar1;
}


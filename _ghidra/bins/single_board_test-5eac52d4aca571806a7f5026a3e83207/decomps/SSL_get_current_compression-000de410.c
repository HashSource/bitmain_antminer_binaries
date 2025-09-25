
COMP_METHOD * SSL_get_current_compression(SSL *s)

{
  COMP_METHOD *pCVar1;
  
  if (*(int *)(s[2].sid_ctx + 0x14) != 0) {
    pCVar1 = (COMP_METHOD *)COMP_CTX_get_method();
    return pCVar1;
  }
  return (COMP_METHOD *)0x0;
}


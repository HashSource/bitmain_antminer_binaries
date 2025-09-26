
COMP_METHOD * SSL_get_current_expansion(SSL *s)

{
  COMP_METHOD *pCVar1;
  
  pCVar1 = (COMP_METHOD *)s->expand;
  if (pCVar1 != (COMP_METHOD *)0x0) {
    pCVar1 = (COMP_METHOD *)pCVar1->type;
  }
  return pCVar1;
}


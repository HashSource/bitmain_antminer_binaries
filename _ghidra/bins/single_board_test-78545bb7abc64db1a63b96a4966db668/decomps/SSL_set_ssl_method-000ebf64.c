
int SSL_set_ssl_method(SSL *s,SSL_METHOD *method)

{
  int iVar1;
  SSL_METHOD *pSVar2;
  _func_3201 *p_Var3;
  
  pSVar2 = (SSL_METHOD *)s->type;
  if (pSVar2 == method) {
    return 1;
  }
  p_Var3 = (_func_3201 *)s->rwstate;
  if (pSVar2->version == method->version) {
    s->type = (int)method;
    iVar1 = 1;
  }
  else {
    (*pSVar2->ssl_connect)(s);
    s->type = (int)method;
    iVar1 = (*method->ssl_free)(s);
  }
  if (p_Var3 == pSVar2->ssl_peek) {
    s->rwstate = (int)method->ssl_peek;
    return iVar1;
  }
  if (p_Var3 == (_func_3201 *)pSVar2->ssl_read) {
    s->rwstate = (int)method->ssl_read;
    return iVar1;
  }
  return iVar1;
}


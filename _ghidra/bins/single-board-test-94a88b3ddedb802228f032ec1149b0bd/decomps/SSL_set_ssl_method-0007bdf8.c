
int SSL_set_ssl_method(SSL *s,SSL_METHOD *method)

{
  int iVar1;
  SSL_METHOD *pSVar2;
  uint uVar3;
  
  pSVar2 = s->method;
  if (pSVar2 == method) {
    iVar1 = 1;
  }
  else {
    uVar3 = 0xffffffff;
    if (s->handshake_func != (_func_3291 *)0x0) {
      uVar3 = (uint)(s->handshake_func == (_func_3291 *)pSVar2->ssl_connect);
    }
    if (pSVar2->version == method->version) {
      s->method = method;
      iVar1 = 1;
    }
    else {
      (*pSVar2->ssl_free)(s);
      s->method = method;
      iVar1 = (*method->ssl_new)(s);
    }
    if (uVar3 == 1) {
      s->handshake_func = (_func_3291 *)method->ssl_connect;
      return iVar1;
    }
    if (uVar3 == 0) {
      s->handshake_func = (_func_3291 *)method->ssl_accept;
      return iVar1;
    }
  }
  return iVar1;
}


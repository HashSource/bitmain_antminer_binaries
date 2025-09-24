
void SSL_copy_session_id(SSL *to,SSL *from)

{
  bool bVar1;
  SSL_SESSION *session;
  int iVar2;
  void *sid_ctx_len;
  int *piVar3;
  
  session = SSL_get_session(from);
  iVar2 = SSL_set_session(to,session);
  if (iVar2 == 0) {
    return;
  }
  if (to->type != from->type) {
    (**(code **)(to->type + 0x14))(to);
    iVar2 = from->type;
    to->type = iVar2;
    iVar2 = (**(code **)(iVar2 + 0xc))(to);
    if (iVar2 == 0) {
      return;
    }
  }
  piVar3 = (int *)(from[2].error + 0x108);
  do {
    ExclusiveAccess(piVar3);
    bVar1 = (bool)hasExclusiveAccess(piVar3);
  } while (!bVar1);
  *piVar3 = *piVar3 + 1;
  ssl_cert_free(to[2].error);
  sid_ctx_len = from[2].tlsext_debug_arg;
  to[2].error = from[2].error;
  SSL_set_session_id_context(to,(uchar *)&from[2].tlsext_hostname,(uint)sid_ctx_len);
  return;
}


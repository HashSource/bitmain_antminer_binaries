
int SSL_add_client_CA(SSL *ssl,X509 *x)

{
  X509_NAME *pXVar1;
  int iVar2;
  _STACK *p_Var3;
  
  if (x != (X509 *)0x0) {
    if ((ssl->ex_data).dummy == 0) {
      p_Var3 = sk_new_null();
      (ssl->ex_data).dummy = (int)p_Var3;
      if (p_Var3 == (_STACK *)0x0) {
        return 0;
      }
    }
    pXVar1 = X509_get_subject_name(x);
    pXVar1 = X509_NAME_dup(pXVar1);
    if (pXVar1 != (X509_NAME *)0x0) {
      iVar2 = sk_push((_STACK *)(ssl->ex_data).dummy,pXVar1);
      if (iVar2 == 0) {
        X509_NAME_free(pXVar1);
        return 0;
      }
      return 1;
    }
  }
  return 0;
}


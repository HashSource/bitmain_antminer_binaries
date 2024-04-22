
void ssl_sess_cert_free(_STACK **param_1)

{
  int iVar1;
  
  if (param_1 != (_STACK **)0x0) {
    iVar1 = CRYPTO_add_lock((int *)(param_1 + 0x3e),-1,0xf,DAT_0007dd08,0x292);
    if (iVar1 < 1) {
      if (*param_1 != (_STACK *)0x0) {
        sk_pop_free(*param_1,DAT_0007dd0c);
      }
      if ((X509 *)param_1[3] != (X509 *)0x0) {
        X509_free((X509 *)param_1[3]);
      }
      if ((X509 *)param_1[10] != (X509 *)0x0) {
        X509_free((X509 *)param_1[10]);
      }
      if ((X509 *)param_1[0x11] != (X509 *)0x0) {
        X509_free((X509 *)param_1[0x11]);
      }
      if ((X509 *)param_1[0x18] != (X509 *)0x0) {
        X509_free((X509 *)param_1[0x18]);
      }
      if ((X509 *)param_1[0x1f] != (X509 *)0x0) {
        X509_free((X509 *)param_1[0x1f]);
      }
      if ((X509 *)param_1[0x26] != (X509 *)0x0) {
        X509_free((X509 *)param_1[0x26]);
      }
      if ((X509 *)param_1[0x2d] != (X509 *)0x0) {
        X509_free((X509 *)param_1[0x2d]);
      }
      if ((X509 *)param_1[0x34] != (X509 *)0x0) {
        X509_free((X509 *)param_1[0x34]);
      }
      if ((RSA *)param_1[0x3b] != (RSA *)0x0) {
        RSA_free((RSA *)param_1[0x3b]);
      }
      if ((DH *)param_1[0x3c] != (DH *)0x0) {
        DH_free((DH *)param_1[0x3c]);
      }
      if (param_1[0x3d] != (_STACK *)0x0) {
        EC_KEY_free((EC_KEY *)param_1[0x3d]);
      }
      CRYPTO_free(param_1);
      return;
    }
  }
  return;
}


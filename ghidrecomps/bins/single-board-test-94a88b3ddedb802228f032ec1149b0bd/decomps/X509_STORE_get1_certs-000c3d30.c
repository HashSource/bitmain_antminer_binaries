
stack_st_X509 * X509_STORE_get1_certs(X509_STORE_CTX *st,X509_NAME *nm)

{
  _STACK *st_00;
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  X509 *a;
  _STACK *p_Var5;
  int local_2c;
  X509_OBJECT local_28;
  
  st_00 = sk_new_null();
  CRYPTO_lock(9,0xb,DAT_000c3e54,0x1ed);
  iVar1 = x509_object_idx_cnt(st->ctx->objs,1,nm,&local_2c);
  if (iVar1 < 0) {
    CRYPTO_lock(10,0xb,DAT_000c3e54,0x1f5);
    iVar1 = X509_STORE_get_by_subject(st,1,nm,&local_28);
    if (iVar1 != 0) {
      if (local_28.type == 1) {
        X509_free(local_28.data.x509);
      }
      else if (local_28.type == 2) {
        X509_CRL_free(local_28.data.crl);
      }
      CRYPTO_lock(9,0xb,DAT_000c3e54,0x1fb);
      iVar1 = x509_object_idx_cnt(st->ctx->objs,1,nm,&local_2c);
      if (-1 < iVar1) goto LAB_000c3d64;
      CRYPTO_lock(10,0xb,DAT_000c3e54,0x1fe);
    }
    p_Var5 = (_STACK *)0x0;
    sk_free(st_00);
  }
  else {
LAB_000c3d64:
    if (0 < local_2c) {
      iVar4 = 0;
      do {
        iVar3 = iVar4 + iVar1;
        iVar4 = iVar4 + 1;
        pvVar2 = sk_value(&st->ctx->objs->stack,iVar3);
        a = *(X509 **)((int)pvVar2 + 4);
        CRYPTO_add_lock(&a->references,1,3,DAT_000c3e54,0x206);
        iVar3 = sk_push(st_00,a);
        if (iVar3 == 0) {
          CRYPTO_lock(10,0xb,DAT_000c3e54,0x208);
          X509_free(a);
          sk_pop_free(st_00,DAT_000c3e58);
          return (stack_st_X509 *)0x0;
        }
      } while (iVar4 < local_2c);
    }
    CRYPTO_lock(10,0xb,DAT_000c3e54,0x20e);
    p_Var5 = st_00;
  }
  return (stack_st_X509 *)p_Var5;
}



int X509_STORE_add_cert(X509_STORE *ctx,X509 *x)

{
  X509_OBJECT *a;
  int extraout_r0;
  X509_OBJECT *pXVar1;
  int iVar2;
  int iVar3;
  
  if ((x == (X509 *)0x0) || (a = (X509_OBJECT *)X509_OBJECT_new(), a == (X509_OBJECT *)0x0))
  goto LAB_00171196;
  iVar3 = 1;
  (a->data).x509 = x;
  a->type = 1;
  X509_OBJECT_up_ref_count(a);
  if (extraout_r0 == 0) {
    a->type = 0;
    X509_OBJECT_free(a);
    goto LAB_00171196;
  }
  X509_STORE_lock(ctx);
  pXVar1 = X509_OBJECT_retrieve_match(ctx->objs,a);
  if (pXVar1 == (X509_OBJECT *)0x0) {
    iVar2 = OPENSSL_sk_push(ctx->objs,a);
    iVar3 = iVar2;
    if (iVar2 != 0) {
      iVar3 = 1;
    }
    X509_STORE_unlock(ctx);
    if (iVar2 == 0) goto LAB_00171180;
  }
  else {
    X509_STORE_unlock(ctx);
LAB_00171180:
    X509_OBJECT_free(a);
  }
  if (iVar3 != 0) {
    return 1;
  }
LAB_00171196:
  ERR_put_error(0xb,0x7c,0x41,"crypto/x509/x509_lu.c",0x173);
  return 0;
}


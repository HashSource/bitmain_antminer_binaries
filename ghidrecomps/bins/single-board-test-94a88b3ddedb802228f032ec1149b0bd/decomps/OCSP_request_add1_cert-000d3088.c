
int OCSP_request_add1_cert(OCSP_REQUEST *req,X509 *cert)

{
  _STACK *st;
  int iVar1;
  OCSP_SIGNATURE *pOVar2;
  
  pOVar2 = req->optionalSignature;
  if (pOVar2 == (OCSP_SIGNATURE *)0x0) {
    pOVar2 = OCSP_SIGNATURE_new();
    req->optionalSignature = pOVar2;
    if (pOVar2 == (OCSP_SIGNATURE *)0x0) {
      return 0;
    }
  }
  if (cert == (X509 *)0x0) {
    return 1;
  }
  st = &pOVar2->certs->stack;
  if (st == (_STACK *)0x0) {
    st = sk_new_null();
    pOVar2->certs = (stack_st_X509 *)st;
    if (st == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar1 = sk_push(st,cert);
  if (iVar1 == 0) {
    return 0;
  }
  CRYPTO_add_lock(&cert->references,1,3,DAT_000d30dc,0x8c);
  return 1;
}



int X509_STORE_CTX_purpose_inherit(X509_STORE_CTX *ctx,int def_purpose,int purpose,int trust)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  stack_st_X509_CRL *psVar3;
  
  if (purpose == 0) {
    purpose = def_purpose;
    if (def_purpose == 0) {
      if (trust == 0) {
        return 1;
      }
      iVar1 = X509_TRUST_get_by_id(trust);
      if (iVar1 == -1) goto LAB_0016aaa8;
      psVar3 = ctx->crls;
      goto LAB_0016aa3e;
    }
  }
  else if (def_purpose == 0) {
    def_purpose = purpose;
  }
  iVar1 = X509_PURPOSE_get_by_id(purpose);
  if (iVar1 == -1) {
    ERR_put_error(0xb,0x86,0x79,"crypto/x509/x509_vfy.c",0x8a8);
    return 0;
  }
  pXVar2 = X509_PURPOSE_get0(iVar1);
  if (pXVar2->trust == 0) {
    iVar1 = X509_PURPOSE_get_by_id(def_purpose);
    if (iVar1 == -1) {
      ERR_put_error(0xb,0x86,0x79,"crypto/x509/x509_vfy.c",0x8b0);
      return 0;
    }
    pXVar2 = X509_PURPOSE_get0(iVar1);
    if (trust == 0) goto LAB_0016aa2e;
LAB_0016aa66:
    iVar1 = X509_TRUST_get_by_id(trust);
    if (iVar1 == -1) {
LAB_0016aaa8:
      ERR_put_error(0xb,0x86,0x78,"crypto/x509/x509_vfy.c",0x8bd);
      return 0;
    }
    psVar3 = ctx->crls;
    if ((psVar3->stack).comp != (_func_290 *)0x0) goto LAB_0016aa3e;
  }
  else {
    if (trust != 0) goto LAB_0016aa66;
LAB_0016aa2e:
    trust = pXVar2->trust;
    if (trust != 0) goto LAB_0016aa66;
    psVar3 = ctx->crls;
    if ((psVar3->stack).comp != (_func_290 *)0x0) {
      return 1;
    }
  }
  (psVar3->stack).comp = (_func_290 *)purpose;
  if (trust == 0) {
    return 1;
  }
LAB_0016aa3e:
  if (psVar3[1].stack.num == 0) {
    psVar3[1].stack.num = trust;
  }
  return 1;
}


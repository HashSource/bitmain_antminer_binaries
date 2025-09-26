
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
      if (iVar1 == -1) goto LAB_00174680;
      psVar3 = ctx->crls;
      goto LAB_00174616;
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
    if (trust == 0) goto LAB_00174606;
LAB_0017463e:
    iVar1 = X509_TRUST_get_by_id(trust);
    if (iVar1 == -1) {
LAB_00174680:
      ERR_put_error(0xb,0x86,0x78,"crypto/x509/x509_vfy.c",0x8bd);
      return 0;
    }
    psVar3 = ctx->crls;
    if ((psVar3->stack).comp != (_func_290 *)0x0) goto LAB_00174616;
  }
  else {
    if (trust != 0) goto LAB_0017463e;
LAB_00174606:
    trust = pXVar2->trust;
    if (trust != 0) goto LAB_0017463e;
    psVar3 = ctx->crls;
    if ((psVar3->stack).comp != (_func_290 *)0x0) {
      return 1;
    }
  }
  (psVar3->stack).comp = (_func_290 *)purpose;
  if (trust == 0) {
    return 1;
  }
LAB_00174616:
  if (psVar3[1].stack.num == 0) {
    psVar3[1].stack.num = trust;
  }
  return 1;
}


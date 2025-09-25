
int X509_CRL_get0_by_cert(X509_CRL *crl,X509_REVOKED **ret,X509 *x)

{
  ASN1_INTEGER *pAVar1;
  X509_NAME *pXVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(crl[1].sha1_hash + 4) + 0xc);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
    pAVar1 = X509_get_serialNumber(x);
    pXVar2 = X509_get_issuer_name(x);
                    /* WARNING: Could not recover jumptable at 0x001690f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*UNRECOVERED_JUMPTABLE)(crl,ret,pAVar1,pXVar2);
    return iVar3;
  }
  return 0;
}



int X509_CRL_get0_by_serial(X509_CRL *crl,X509_REVOKED **ret,ASN1_INTEGER *serial)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(crl[1].sha1_hash + 4) + 0xc);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00176ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 0;
}


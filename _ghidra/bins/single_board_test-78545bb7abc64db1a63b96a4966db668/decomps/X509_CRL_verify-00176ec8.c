
int X509_CRL_verify(X509_CRL *a,EVP_PKEY *r)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(a[1].sha1_hash + 4) + 0x10);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00176ece. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 0;
}


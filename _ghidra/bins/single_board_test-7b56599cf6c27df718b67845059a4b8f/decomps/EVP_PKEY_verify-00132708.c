
int EVP_PKEY_verify(EVP_PKEY_CTX *ctx,uchar *sig,size_t siglen,uchar *tbs,size_t tbslen)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x30), UNRECOVERED_JUMPTABLE == (code *)0x0))
  {
    ERR_put_error(6,0x8e,0x96,"crypto/evp/pmeth_fn.c",0x5c);
    iVar1 = -2;
  }
  else {
    if (*(int *)(ctx + 0x10) == 0x10) {
                    /* WARNING: Could not recover jumptable at 0x00132728. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(6,0x8e,0x97,"crypto/evp/pmeth_fn.c",0x60);
    iVar1 = -1;
  }
  return iVar1;
}


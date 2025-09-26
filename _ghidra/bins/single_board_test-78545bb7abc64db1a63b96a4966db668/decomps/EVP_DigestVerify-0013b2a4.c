
int EVP_DigestVerify(EVP_MD_CTX *param_1,uchar *param_2,size_t param_3,void *param_4,size_t param_5)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)param_1->pctx + 0x70);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0013b2b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  iVar1 = EVP_DigestUpdate(param_1,param_4,param_5);
  if (0 < iVar1) {
    iVar1 = EVP_DigestVerifyFinal(param_1,param_2,param_3);
    return iVar1;
  }
  return -1;
}



int EC_GROUP_precompute_mult(EC_GROUP *group,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*(int *)(*(int *)group + 0x7c) == 0) {
    iVar1 = ec_wNAF_precompute_mult();
    return iVar1;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x80);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00128d68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 1;
}


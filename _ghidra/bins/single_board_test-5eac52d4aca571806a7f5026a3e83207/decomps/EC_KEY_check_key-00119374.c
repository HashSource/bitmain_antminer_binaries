
int EC_KEY_check_key(EC_KEY *key)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((key == (EC_KEY *)0x0) || (*(int **)(key + 0xc) == (int *)0x0)) ||
     (*(int *)(key + 0x10) == 0)) {
    ERR_put_error(0x10,0xb1,0x43,"crypto/ec/ec_key.c",0x103);
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(key + 0xc) + 0xb4);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00119390. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0xb1,0x42,"crypto/ec/ec_key.c",0x108);
  }
  return 0;
}


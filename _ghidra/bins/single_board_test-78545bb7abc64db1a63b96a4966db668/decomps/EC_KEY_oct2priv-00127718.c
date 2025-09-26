
undefined4 EC_KEY_oct2priv(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((*(int **)(param_1 + 0xc) != (int *)0x0) && (iVar2 = **(int **)(param_1 + 0xc), iVar2 != 0)) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0xa8);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00127726. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    ERR_put_error(0x10,0xff,0x42,"crypto/ec/ec_key.c",0x290);
    return 0;
  }
  return 0;
}


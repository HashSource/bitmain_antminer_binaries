
undefined4 ossl_ecdh_compute_key(void)

{
  undefined4 uVar1;
  int in_r3;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(in_r3 + 0xc) + 0xc4);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012a3e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  ERR_put_error(0x10,0xf7,0xa0,"crypto/ec/ecdh_ossl.c",0x1a);
  return 0;
}


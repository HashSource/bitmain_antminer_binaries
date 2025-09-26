
undefined4 EVP_PKEY_security_bits(int param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0xc) + 0x38),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013b4ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0xfffffffe;
}


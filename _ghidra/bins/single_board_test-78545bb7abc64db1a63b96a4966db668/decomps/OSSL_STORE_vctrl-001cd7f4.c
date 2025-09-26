
undefined4 OSSL_STORE_vctrl(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0xc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001cd7fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xc))(param_1[1]);
    return uVar1;
  }
  return 0;
}


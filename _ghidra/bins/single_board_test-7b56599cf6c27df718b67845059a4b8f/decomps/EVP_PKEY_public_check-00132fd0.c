
undefined4 EVP_PKEY_public_check(int *param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  
  iVar2 = param_1[2];
  if (iVar2 == 0) {
    ERR_put_error(6,0xbe,0x9a,"crypto/evp/pmeth_gn.c",200);
    uVar1 = 0;
  }
  else {
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x78);
    if ((UNRECOVERED_JUMPTABLE != (code *)0x0) ||
       ((*(int *)(iVar2 + 0xc) != 0 &&
        (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar2 + 0xc) + 0x78),
        UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x00132fe6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)(iVar2);
      return uVar1;
    }
    ERR_put_error(6,0xbe,0x96,"crypto/evp/pmeth_gn.c",0xd3);
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


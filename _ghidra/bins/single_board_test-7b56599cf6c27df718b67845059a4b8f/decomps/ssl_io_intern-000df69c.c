
undefined4 ssl_io_intern(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[3];
  iVar3 = *param_1;
  if ((iVar2 != 1) && (iVar2 != 0)) {
    if (iVar2 == 2) {
                    /* WARNING: Could not recover jumptable at 0x000df6b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)param_1[4])(iVar3);
      return uVar1;
    }
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x000df6c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)param_1[4])(iVar3,param_1[1],param_1[2],iVar3 + 0xf4c);
  return uVar1;
}


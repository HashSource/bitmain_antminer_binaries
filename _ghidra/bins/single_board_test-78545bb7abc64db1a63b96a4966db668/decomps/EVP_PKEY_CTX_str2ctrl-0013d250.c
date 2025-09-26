
undefined4 EVP_PKEY_CTX_str2ctrl(int *param_1,undefined4 param_2,char *param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = strlen(param_3);
  if (-1 < (int)sVar1) {
                    /* WARNING: Could not recover jumptable at 0x0013d274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 100))(param_1,param_2,sVar1,param_3);
    return uVar2;
  }
  return 0xffffffff;
}


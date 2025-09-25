
undefined4 final_sig_algs(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_3 == 0) && (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c)) &&
      (iVar1 = **(int **)(param_1 + 4), iVar1 != 0x10000 && 0x303 < iVar1)) &&
     (*(int *)(param_1 + 0x8c) == 0)) {
    ossl_statem_fatal(param_1,0x6d,0x1f1,0x70,"ssl/statem/extensions.c",0x50b);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


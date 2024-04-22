
void gost_enc(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (0 < param_4) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      gostcrypt(param_1,param_2,param_3);
      param_2 = param_2 + 8;
      param_3 = param_3 + 8;
    } while (iVar1 != param_4);
  }
  return;
}


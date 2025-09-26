
undefined4 bn_set_words(undefined4 *param_1,void *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = bn_wexpand(param_1,param_3);
  if (iVar1 != 0) {
    memcpy((void *)*param_1,param_2,param_3 << 2);
    param_1[1] = param_3;
    bn_correct_top(param_1);
    return 1;
  }
  ERR_put_error(3,0x90,0x41,"crypto/bn/bn_intern.c",0xbf);
  return 0;
}


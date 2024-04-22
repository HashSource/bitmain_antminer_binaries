
undefined4 store_bignum(BIGNUM *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = BN_num_bits(param_1);
  iVar2 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar2 = iVar1 + 7;
  }
  if ((int)param_3 < iVar2 >> 3) {
    return 0;
  }
  memset(param_2,0,param_3);
  BN_bn2bin(param_1,(uchar *)((int)param_2 + (param_3 - (iVar2 >> 3))));
  return 1;
}


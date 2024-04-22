
undefined4 pack_sign_cp(DSA_SIG *param_1,size_t param_2,void *param_3,size_t *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  
  *param_4 = param_2 << 1;
  memset(param_3,0,param_2 << 1);
  pBVar2 = param_1->s;
  iVar1 = BN_num_bits(pBVar2);
  iVar3 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar3 = iVar1 + 7;
  }
  if (iVar3 >> 3 <= (int)param_2) {
    memset(param_3,0,param_2);
    BN_bn2bin(pBVar2,(uchar *)((int)param_3 + (param_2 - (iVar3 >> 3))));
  }
  pBVar2 = param_1->r;
  iVar1 = BN_num_bits(pBVar2);
  iVar3 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar3 = iVar1 + 7;
  }
  if (iVar3 >> 3 <= (int)param_2) {
    memset((void *)((int)param_3 + param_2),0,param_2);
    BN_bn2bin(pBVar2,(uchar *)((int)(void *)((int)param_3 + param_2) + (param_2 - (iVar3 >> 3))));
  }
  DSA_SIG_free(param_1);
  return 1;
}


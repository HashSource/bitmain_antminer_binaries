
int bn_i2c(BIGNUM **param_1,uchar *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  BIGNUM *a;
  uchar *to;
  
  a = *param_1;
  if (a == (BIGNUM *)0x0) {
    return -1;
  }
  uVar1 = BN_num_bits(a);
  uVar1 = (uint)((uVar1 & 7) == 0);
  if (param_2 != (uchar *)0x0) {
    to = param_2;
    if (uVar1 != 0) {
      to = param_2 + 1;
      *param_2 = '\0';
    }
    BN_bn2bin(a,to);
  }
  iVar2 = BN_num_bits(a);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  return uVar1 + (iVar3 >> 3);
}


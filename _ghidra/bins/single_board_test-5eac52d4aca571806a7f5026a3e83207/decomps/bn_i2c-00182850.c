
uchar * bn_i2c(undefined4 *param_1,uchar *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  BIGNUM *a;
  uchar *puVar4;
  
  a = (BIGNUM *)*param_1;
  if (a == (BIGNUM *)0x0) {
    return (uchar *)0xffffffff;
  }
  uVar1 = BN_num_bits(a);
  if ((uVar1 & 7) == 0) {
    puVar4 = (uchar *)0x1;
    if (param_2 == (uchar *)0x0) goto LAB_00182872;
    puVar4 = (uchar *)0x1;
    *param_2 = '\0';
    param_2 = param_2 + 1;
  }
  else {
    puVar4 = param_2;
    if (param_2 == (uchar *)0x0) goto LAB_00182872;
    puVar4 = (uchar *)0x0;
  }
  BN_bn2bin(a,param_2);
LAB_00182872:
  iVar2 = BN_num_bits(a);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  return puVar4 + (iVar3 >> 3);
}


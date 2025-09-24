
uint ec_key_simple_priv2oct(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = EC_GROUP_order_bits(*(undefined4 *)(param_1 + 0xc));
  iVar2 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar2 = iVar1 + 7;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar3 = iVar2 >> 3;
    if (param_2 == 0) {
      return uVar3;
    }
    if (uVar3 <= param_3) {
      iVar2 = BN_bn2binpad(*(int *)(param_1 + 0x14),param_2,uVar3);
      if (iVar2 != -1) {
        return uVar3;
      }
      ERR_put_error(0x10,0x104,100,"crypto/ec/ec_key.c",0x284);
    }
  }
  return 0;
}


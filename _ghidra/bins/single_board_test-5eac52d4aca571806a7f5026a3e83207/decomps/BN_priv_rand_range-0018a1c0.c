
undefined4 BN_priv_rand_range(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_2 + 0xc) == 0) && (iVar1 = BN_is_zero(param_2), iVar1 == 0)) {
    uVar2 = bnrand_range_part_1(2,param_1,param_2);
    return uVar2;
  }
  ERR_put_error(3,0x8a,0x73,"crypto/bn/bn_rand.c",0x77);
  return 0;
}


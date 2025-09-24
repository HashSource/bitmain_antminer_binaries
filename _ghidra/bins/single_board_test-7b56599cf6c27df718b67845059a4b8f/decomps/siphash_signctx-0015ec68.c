
undefined4 siphash_signctx(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14) + 0x10;
  uVar1 = SipHash_hash_size(iVar2);
  *param_3 = uVar1;
  if (param_2 != 0) {
    uVar1 = SipHash_Final(iVar2,param_2,uVar1);
    return uVar1;
  }
  return 1;
}


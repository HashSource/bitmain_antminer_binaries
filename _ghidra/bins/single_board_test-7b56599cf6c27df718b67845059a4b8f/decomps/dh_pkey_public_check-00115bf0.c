
undefined4 dh_pkey_public_check(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x14);
  if (iVar2 != 0) {
    uVar1 = DH_check_pub_key_ex(*(int *)(param_1 + 0x18),iVar2);
    return uVar1;
  }
  ERR_put_error(5,0x7c,0x7d,"crypto/dh/dh_ameth.c",0x205);
  return 0;
}


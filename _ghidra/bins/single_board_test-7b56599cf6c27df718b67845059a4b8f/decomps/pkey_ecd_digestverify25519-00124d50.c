
undefined4
pkey_ecd_digestverify25519
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = EVP_MD_CTX_pkey_ctx();
  if (param_3 != 0x40) {
    return 0;
  }
  uVar2 = ED25519_verify(param_4,param_5,param_2,*(undefined4 *)(*(int *)(iVar1 + 8) + 0x18));
  return uVar2;
}



void pkey_ecd_digestverify448
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  
  iVar1 = EVP_MD_CTX_pkey_ctx();
  if (param_3 == 0x72) {
    ED448_verify(param_4,param_5,param_2,*(undefined4 *)(*(int *)(iVar1 + 8) + 0x18),0,0);
    return;
  }
  return;
}


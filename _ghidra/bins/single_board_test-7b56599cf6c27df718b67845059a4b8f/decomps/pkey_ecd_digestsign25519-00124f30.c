
undefined4
pkey_ecd_digestsign25519
          (undefined4 param_1,int param_2,uint *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = EVP_MD_CTX_pkey_ctx();
  if (param_2 != 0) {
    if (*param_3 < 0x40) {
      ERR_put_error(0x10,0x114,100,"crypto/ec/ecx_meth.c",0x2ed);
      return 0;
    }
    iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x18);
    iVar1 = ED25519_sign(param_2,param_4,param_5,iVar1,*(undefined4 *)(iVar1 + 0x3c));
    if (iVar1 == 0) {
      return 0;
    }
  }
  *param_3 = 0x40;
  return 1;
}


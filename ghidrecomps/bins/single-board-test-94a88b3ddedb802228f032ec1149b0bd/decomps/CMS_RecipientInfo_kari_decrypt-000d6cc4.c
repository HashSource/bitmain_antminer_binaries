
void * CMS_RecipientInfo_kari_decrypt(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *local_20;
  undefined4 local_1c;
  
  uVar2 = **(undefined4 **)(param_3 + 4);
  uVar3 = (*(undefined4 **)(param_3 + 4))[2];
  local_20 = (void *)0x0;
  iVar1 = cms_env_asn1_ctrl(param_2,1);
  if ((iVar1 != 0) &&
     (iVar1 = cms_kek_cipher(&local_20,&local_1c,uVar3,uVar2,*(undefined4 *)(param_2 + 4),0),
     iVar1 != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc);
    if (*(void **)(iVar1 + 0x10) != (void *)0x0) {
      OPENSSL_cleanse(*(void **)(iVar1 + 0x10),*(size_t *)(iVar1 + 0x14));
      CRYPTO_free(*(void **)(iVar1 + 0x10));
    }
    *(void **)(iVar1 + 0x10) = local_20;
    *(undefined4 *)(iVar1 + 0x14) = local_1c;
    return (void *)0x1;
  }
  if (local_20 != (void *)0x0) {
    CRYPTO_free(local_20);
    local_20 = (void *)0x0;
  }
  return local_20;
}


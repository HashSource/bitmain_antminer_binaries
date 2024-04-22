
int cms_DigestedData_do_final(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  size_t __n;
  int iVar2;
  size_t local_6c;
  EVP_MD_CTX EStack_68;
  uchar auStack_50 [64];
  
  EVP_MD_CTX_init(&EStack_68);
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = cms_DigestAlgorithm_find_ctx(&EStack_68,param_2,*(undefined4 *)(iVar2 + 4));
  if ((iVar1 != 0) && (iVar1 = EVP_DigestFinal_ex(&EStack_68,auStack_50,&local_6c), 0 < iVar1)) {
    if (param_3 == 0) {
      iVar1 = ASN1_STRING_set(*(ASN1_STRING **)(iVar2 + 0xc),auStack_50,local_6c);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      goto LAB_00111650;
    }
    __n = **(size_t **)(iVar2 + 0xc);
    if (__n != local_6c) {
      ERR_put_error(0x2e,0x75,0x79,DAT_001116bc,0x7d);
      iVar1 = 0;
      goto LAB_00111650;
    }
    iVar2 = memcmp(auStack_50,(void *)(*(size_t **)(iVar2 + 0xc))[2],__n);
    iVar1 = 1;
    if (iVar2 == 0) goto LAB_00111650;
    ERR_put_error(0x2e,0x75,0x9e,DAT_001116bc,0x83);
  }
  iVar1 = 0;
LAB_00111650:
  EVP_MD_CTX_cleanup(&EStack_68);
  return iVar1;
}


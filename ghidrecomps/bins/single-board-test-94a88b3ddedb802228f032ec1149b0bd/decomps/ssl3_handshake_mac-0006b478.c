
undefined4 ssl3_handshake_mac(int param_1,int param_2,void *param_3,size_t param_4,uchar *param_5)

{
  EVP_MD *pEVar1;
  int iVar2;
  EVP_MD_CTX *pEVar3;
  int iVar4;
  uint local_80;
  uint local_7c;
  EVP_MD_CTX EStack_78;
  uchar auStack_60 [68];
  
  iVar4 = *(int *)(param_1 + 0x58);
  if (*(int *)(iVar4 + 0x178) != 0) {
    iVar4 = ssl3_digest_cached_records();
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = *(int *)(param_1 + 0x58);
  }
  local_7c = 0;
  do {
    pEVar3 = *(EVP_MD_CTX **)(*(int *)(iVar4 + 0x17c) + local_7c * 4);
    if (pEVar3 != (EVP_MD_CTX *)0x0) {
      pEVar1 = EVP_MD_CTX_md(pEVar3);
      iVar4 = EVP_MD_type(pEVar1);
      if (iVar4 == param_2) {
        pEVar3 = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + local_7c * 4);
        if (pEVar3 != (EVP_MD_CTX *)0x0) {
          EVP_MD_CTX_init(&EStack_78);
          EVP_MD_CTX_set_flags(&EStack_78,8);
          EVP_MD_CTX_copy_ex(&EStack_78,pEVar3);
          pEVar1 = EVP_MD_CTX_md(&EStack_78);
          iVar4 = EVP_MD_size(pEVar1);
          if (iVar4 < 0) {
            return 0;
          }
          iVar2 = __aeabi_idiv(0x30,iVar4);
          if (param_3 != (void *)0x0) {
            EVP_DigestUpdate(&EStack_78,param_3,param_4);
          }
          EVP_DigestUpdate(&EStack_78,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                           *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
          EVP_DigestUpdate(&EStack_78,DAT_0006b5a8,iVar4 * iVar2);
          EVP_DigestFinal_ex(&EStack_78,auStack_60,&local_7c);
          pEVar1 = EVP_MD_CTX_md(&EStack_78);
          EVP_DigestInit_ex(&EStack_78,pEVar1,(ENGINE *)0x0);
          EVP_DigestUpdate(&EStack_78,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                           *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
          EVP_DigestUpdate(&EStack_78,DAT_0006b5ac,iVar4 * iVar2);
          EVP_DigestUpdate(&EStack_78,auStack_60,local_7c);
          EVP_DigestFinal_ex(&EStack_78,param_5,&local_80);
          EVP_MD_CTX_cleanup(&EStack_78);
          return local_80;
        }
LAB_0006b4c4:
        ERR_put_error(0x14,0x11d,0x144,DAT_0006b5a4,0x2ab);
        return 0;
      }
    }
    local_7c = local_7c + 1;
    if (5 < local_7c) goto LAB_0006b4c4;
    iVar4 = *(int *)(param_1 + 0x58);
  } while( true );
}


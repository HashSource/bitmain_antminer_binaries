
undefined4 tls1_cert_verify_mac(int param_1,int param_2,uchar *param_3)

{
  EVP_MD *pEVar1;
  EVP_MD_CTX *pEVar2;
  int iVar3;
  uint local_34;
  EVP_MD_CTX EStack_30;
  
  iVar3 = *(int *)(param_1 + 0x58);
  if (*(int *)(iVar3 + 0x178) != 0) {
    iVar3 = ssl3_digest_cached_records();
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0x58);
  }
  if (**(EVP_MD_CTX ***)(iVar3 + 0x17c) == (EVP_MD_CTX *)0x0) {
LAB_00074c0a:
    pEVar2 = *(EVP_MD_CTX **)(*(int *)(iVar3 + 0x17c) + 4);
    if (pEVar2 != (EVP_MD_CTX *)0x0) {
      pEVar1 = EVP_MD_CTX_md(pEVar2);
      iVar3 = EVP_MD_type(pEVar1);
      if (iVar3 == param_2) {
        iVar3 = 4;
        goto LAB_00074c98;
      }
      iVar3 = *(int *)(param_1 + 0x58);
    }
    pEVar2 = *(EVP_MD_CTX **)(*(int *)(iVar3 + 0x17c) + 8);
    if (pEVar2 != (EVP_MD_CTX *)0x0) {
      pEVar1 = EVP_MD_CTX_md(pEVar2);
      iVar3 = EVP_MD_type(pEVar1);
      if (iVar3 == param_2) {
        iVar3 = 8;
        goto LAB_00074c98;
      }
      iVar3 = *(int *)(param_1 + 0x58);
    }
    pEVar2 = *(EVP_MD_CTX **)(*(int *)(iVar3 + 0x17c) + 0xc);
    if (pEVar2 != (EVP_MD_CTX *)0x0) {
      pEVar1 = EVP_MD_CTX_md(pEVar2);
      iVar3 = EVP_MD_type(pEVar1);
      if (iVar3 == param_2) {
        iVar3 = 0xc;
        goto LAB_00074c98;
      }
      iVar3 = *(int *)(param_1 + 0x58);
    }
    pEVar2 = *(EVP_MD_CTX **)(*(int *)(iVar3 + 0x17c) + 0x10);
    if (pEVar2 != (EVP_MD_CTX *)0x0) {
      pEVar1 = EVP_MD_CTX_md(pEVar2);
      iVar3 = EVP_MD_type(pEVar1);
      if (iVar3 == param_2) {
        iVar3 = 0x10;
        goto LAB_00074c98;
      }
      iVar3 = *(int *)(param_1 + 0x58);
    }
    pEVar2 = *(EVP_MD_CTX **)(*(int *)(iVar3 + 0x17c) + 0x14);
    if (pEVar2 == (EVP_MD_CTX *)0x0) goto LAB_00074c7a;
    pEVar1 = EVP_MD_CTX_md(pEVar2);
    iVar3 = EVP_MD_type(pEVar1);
    if (iVar3 != param_2) goto LAB_00074c7a;
    iVar3 = 0x14;
  }
  else {
    pEVar1 = EVP_MD_CTX_md(**(EVP_MD_CTX ***)(iVar3 + 0x17c));
    iVar3 = EVP_MD_type(pEVar1);
    if (iVar3 != param_2) {
      iVar3 = *(int *)(param_1 + 0x58);
      goto LAB_00074c0a;
    }
    iVar3 = 0;
  }
LAB_00074c98:
  pEVar2 = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar3);
  if (pEVar2 != (EVP_MD_CTX *)0x0) {
    EVP_MD_CTX_init(&EStack_30);
    EVP_MD_CTX_copy_ex(&EStack_30,pEVar2);
    EVP_DigestFinal_ex(&EStack_30,param_3,&local_34);
    EVP_MD_CTX_cleanup(&EStack_30);
    return local_34;
  }
LAB_00074c7a:
  ERR_put_error(0x14,0x11e,0x144,DAT_00074cd8,0x3a1);
  return 0;
}


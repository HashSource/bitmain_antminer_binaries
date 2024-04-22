
undefined4
tls1_final_finish_mac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  EVP_MD_CTX *in;
  uint uVar6;
  size_t len;
  uchar *md;
  uint local_d8;
  uint local_d4;
  EVP_MD *local_d0;
  undefined auStack_cc [12];
  EVP_MD_CTX EStack_c0;
  uchar auStack_a8 [128];
  undefined auStack_28 [4];
  
  if ((*(int *)(*(int *)(param_1 + 0x58) + 0x178) == 0) ||
     (iVar2 = ssl3_digest_cached_records(), iVar2 != 0)) {
    bVar1 = false;
    EVP_MD_CTX_init(&EStack_c0);
    iVar2 = 0;
    md = auStack_a8;
    while (iVar3 = ssl_get_handshake_digest(iVar2,&local_d4,&local_d0), iVar3 != 0) {
      uVar4 = ssl_get_algorithm2(param_1);
      if ((uVar4 & local_d4) != 0) {
        uVar4 = EVP_MD_size(local_d0);
        in = *(EVP_MD_CTX **)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar2 * 4);
        uVar6 = 1 - (int)in;
        if ((EVP_MD_CTX *)0x1 < in) {
          uVar6 = 0;
        }
        if (((uVar6 | uVar4 >> 0x1f) == 0) && ((int)uVar4 <= (int)(auStack_28 + -(int)md))) {
          iVar3 = EVP_MD_CTX_copy_ex(&EStack_c0,in);
          if ((iVar3 == 0) || (iVar3 = EVP_DigestFinal_ex(&EStack_c0,md,&local_d8), iVar3 == 0)) {
            bVar1 = true;
          }
          else if (uVar4 != local_d8) {
            bVar1 = true;
          }
          md = md + uVar4;
        }
        else {
          bVar1 = true;
        }
      }
      iVar2 = iVar2 + 1;
    }
    len = (int)md - (int)auStack_a8;
    uVar5 = ssl_get_algorithm2(param_1);
    iVar2 = tls1_PRF_constprop_0
                      (uVar5,param_2,param_3,auStack_a8,len,0,0,0,0,*(int *)(param_1 + 0xc0) + 0x14,
                       *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10),param_4,auStack_cc,0xc);
    if (iVar2 == 0) {
      EVP_MD_CTX_cleanup(&EStack_c0);
      OPENSSL_cleanse(auStack_a8,len);
      OPENSSL_cleanse(auStack_cc,0xc);
      return 0;
    }
    EVP_MD_CTX_cleanup(&EStack_c0);
    OPENSSL_cleanse(auStack_a8,len);
    OPENSSL_cleanse(auStack_cc,0xc);
    if (!bVar1) {
      return 0xc;
    }
  }
  return 0;
}


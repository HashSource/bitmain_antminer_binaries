
int ssl3_final_finish_mac(int param_1,void *param_2,size_t param_3,uchar *param_4)

{
  int iVar1;
  EVP_MD *pEVar2;
  EVP_MD_CTX *out;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = ssl3_digest_cached_records(param_1,0);
  if (iVar1 != 0) {
    pEVar2 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8));
    iVar1 = EVP_MD_type(pEVar2);
    if (iVar1 != 0x72) {
      ossl_statem_fatal(param_1,0x50,0x11d,0x144,"ssl/s3_enc.c",0x1aa);
      return 0;
    }
    out = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if (out != (EVP_MD_CTX *)0x0) {
      iVar1 = EVP_MD_CTX_copy_ex(out,*(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8));
      if (iVar1 == 0) {
        ossl_statem_fatal(param_1,0x50,0x11d,0x44,"ssl/s3_enc.c",0x1b6);
        iVar1 = 0;
      }
      else {
        pEVar2 = EVP_MD_CTX_md(out);
        iVar1 = EVP_MD_size(pEVar2);
        if (iVar1 < 0) {
          uVar4 = 0x1be;
        }
        else {
          if ((((param_2 == (void *)0x0) ||
               (iVar3 = EVP_DigestUpdate(out,param_2,param_3), 0 < iVar3)) &&
              (iVar3 = EVP_MD_CTX_ctrl(out,0x1d,*(undefined4 *)(*(int *)(param_1 + 0x474) + 4),
                                       *(int *)(param_1 + 0x474) + 0x48), 0 < iVar3)) &&
             (iVar3 = EVP_DigestFinal_ex(out,param_4,(uint *)0x0), 0 < iVar3)) goto LAB_0010ad9a;
          uVar4 = 0x1c9;
        }
        ossl_statem_fatal(param_1,0x50,0x11d,0x44,"ssl/s3_enc.c",uVar4);
        iVar1 = 0;
      }
LAB_0010ad9a:
      EVP_MD_CTX_free(out);
      return iVar1;
    }
    ossl_statem_fatal(param_1,0x50,0x11d,0x41,"ssl/s3_enc.c",0x1b1);
    iVar1 = 0;
  }
  return iVar1;
}


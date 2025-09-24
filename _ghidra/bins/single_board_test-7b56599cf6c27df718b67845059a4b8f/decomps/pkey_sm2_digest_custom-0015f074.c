
int pkey_sm2_digest_custom(int param_1,EVP_MD_CTX *param_2)

{
  EVP_MD *md;
  size_t cnt;
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_60 [64];
  
  iVar1 = *(int *)(param_1 + 0x14);
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x18);
  md = EVP_MD_CTX_md(param_2);
  cnt = EVP_MD_size(md);
  if (*(int *)(iVar1 + 0x10) == 0) {
    ERR_put_error(0x35,0x72,0x70,"crypto/sm2/sm2_pmeth.c",0x112);
    return 0;
  }
  if (-1 < (int)cnt) {
    iVar1 = sm2_compute_z_digest
                      (auStack_60,md,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),uVar2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = EVP_DigestUpdate(param_2,auStack_60,cnt);
    return iVar1;
  }
  ERR_put_error(0x35,0x72,0x66,"crypto/sm2/sm2_pmeth.c",0x117);
  return 0;
}


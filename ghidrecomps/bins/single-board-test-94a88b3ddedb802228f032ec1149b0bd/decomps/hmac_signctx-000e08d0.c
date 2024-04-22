
undefined4 hmac_signctx(int param_1,uchar *param_2,uint *param_3,EVP_MD_CTX *param_4)

{
  EVP_MD *md;
  uint uVar1;
  int iVar2;
  uint local_14;
  
  iVar2 = *(int *)(param_1 + 0x14);
  md = EVP_MD_CTX_md(param_4);
  uVar1 = EVP_MD_size(md);
  if (-1 < (int)uVar1) {
    *param_3 = uVar1;
    if (param_2 == (uchar *)0x0) {
      return 1;
    }
    iVar2 = HMAC_Final((HMAC_CTX *)(iVar2 + 0x14),param_2,&local_14);
    if (iVar2 != 0) {
      *param_3 = local_14;
      return 1;
    }
  }
  return 0;
}


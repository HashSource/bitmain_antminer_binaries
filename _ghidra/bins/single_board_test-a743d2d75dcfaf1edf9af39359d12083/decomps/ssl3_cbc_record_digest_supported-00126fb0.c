
undefined4 ssl3_cbc_record_digest_supported(EVP_MD_CTX *param_1)

{
  EVP_MD *md;
  int iVar1;
  
  md = EVP_MD_CTX_md(param_1);
  iVar1 = EVP_MD_type(md);
  if (iVar1 == 0x40) {
    return 1;
  }
  if (iVar1 < 0x41) {
    if (iVar1 == 4) {
      return 1;
    }
  }
  else if (iVar1 - 0x2a0U < 4) {
    return 1;
  }
  return 0;
}



void final(undefined4 param_1,uchar *param_2)

{
  MD5_CTX *c;
  int iVar1;
  
  c = (MD5_CTX *)EVP_MD_CTX_md_data();
  iVar1 = MD5_Final(param_2,c);
  if (iVar1 == 0) {
    return;
  }
  SHA1_Final(param_2 + 0x10,(SHA_CTX *)(c + 1));
  return;
}


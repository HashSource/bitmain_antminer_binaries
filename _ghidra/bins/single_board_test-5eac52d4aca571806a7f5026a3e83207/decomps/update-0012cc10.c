
void update(undefined4 param_1,void *param_2,size_t param_3)

{
  MD5_CTX *c;
  int iVar1;
  
  c = (MD5_CTX *)EVP_MD_CTX_md_data();
  iVar1 = MD5_Update(c,param_2,param_3);
  if (iVar1 == 0) {
    return;
  }
  SHA1_Update((SHA_CTX *)(c + 1),param_2,param_3);
  return;
}


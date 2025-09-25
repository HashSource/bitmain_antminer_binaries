
int init(EVP_PKEY_CTX *ctx)

{
  MD5_CTX *c;
  int iVar1;
  
  c = (MD5_CTX *)EVP_MD_CTX_md_data(ctx);
  iVar1 = MD5_Init(c);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = SHA1_Init((SHA_CTX *)(c + 1));
  return iVar1;
}


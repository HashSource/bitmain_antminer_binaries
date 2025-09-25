
void update384(undefined4 param_1,void *param_2,size_t param_3)

{
  SHA512_CTX *c;
  
  c = (SHA512_CTX *)EVP_MD_CTX_md_data();
  SHA384_Update(c,param_2,param_3);
  return;
}


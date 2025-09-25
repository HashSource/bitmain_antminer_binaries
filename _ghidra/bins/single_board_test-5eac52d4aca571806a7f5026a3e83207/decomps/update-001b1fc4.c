
void update(undefined4 param_1,void *param_2,size_t param_3)

{
  MD4_CTX *c;
  
  c = (MD4_CTX *)EVP_MD_CTX_md_data();
  MD4_Update(c,param_2,param_3);
  return;
}


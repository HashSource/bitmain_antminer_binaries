
void update(undefined4 param_1,void *param_2,size_t param_3)

{
  RIPEMD160_CTX *c;
  
  c = (RIPEMD160_CTX *)EVP_MD_CTX_md_data();
  RIPEMD160_Update(c,param_2,param_3);
  return;
}


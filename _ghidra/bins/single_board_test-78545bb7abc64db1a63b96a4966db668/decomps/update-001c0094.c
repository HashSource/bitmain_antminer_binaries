
void update(undefined4 param_1,void *param_2,size_t param_3)

{
  WHIRLPOOL_CTX *c;
  
  c = (WHIRLPOOL_CTX *)EVP_MD_CTX_md_data();
  WHIRLPOOL_Update(c,param_2,param_3);
  return;
}


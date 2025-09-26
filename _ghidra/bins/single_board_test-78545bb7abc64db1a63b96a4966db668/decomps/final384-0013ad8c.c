
void final384(undefined4 param_1,uchar *param_2)

{
  SHA512_CTX *c;
  
  c = (SHA512_CTX *)EVP_MD_CTX_md_data();
  SHA384_Final(param_2,c);
  return;
}


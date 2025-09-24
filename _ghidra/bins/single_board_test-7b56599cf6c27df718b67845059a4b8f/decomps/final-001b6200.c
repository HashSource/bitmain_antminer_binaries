
void final(undefined4 param_1,uchar *param_2)

{
  MD4_CTX *c;
  
  c = (MD4_CTX *)EVP_MD_CTX_md_data();
  MD4_Final(param_2,c);
  return;
}



void final256(undefined4 param_1,uchar *param_2)

{
  SHA256_CTX *c;
  
  c = (SHA256_CTX *)EVP_MD_CTX_md_data();
  SHA256_Final(param_2,c);
  return;
}


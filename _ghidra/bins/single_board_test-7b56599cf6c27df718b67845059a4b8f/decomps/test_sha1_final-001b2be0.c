
void test_sha1_final(undefined4 param_1,uchar *param_2)

{
  SHA_CTX *c;
  
  c = (SHA_CTX *)EVP_MD_CTX_md_data();
  SHA1_Final(param_2,c);
  return;
}


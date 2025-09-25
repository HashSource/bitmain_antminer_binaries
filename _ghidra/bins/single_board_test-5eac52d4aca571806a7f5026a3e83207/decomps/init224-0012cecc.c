
void init224(void)

{
  SHA256_CTX *c;
  
  c = (SHA256_CTX *)EVP_MD_CTX_md_data();
  SHA224_Init(c);
  return;
}


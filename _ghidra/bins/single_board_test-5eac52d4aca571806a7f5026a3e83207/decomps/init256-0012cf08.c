
void init256(void)

{
  SHA256_CTX *c;
  
  c = (SHA256_CTX *)EVP_MD_CTX_md_data();
  SHA256_Init(c);
  return;
}


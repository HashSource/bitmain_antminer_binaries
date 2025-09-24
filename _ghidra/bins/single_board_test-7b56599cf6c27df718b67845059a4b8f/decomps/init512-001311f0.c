
void init512(void)

{
  SHA512_CTX *c;
  
  c = (SHA512_CTX *)EVP_MD_CTX_md_data();
  SHA512_Init(c);
  return;
}


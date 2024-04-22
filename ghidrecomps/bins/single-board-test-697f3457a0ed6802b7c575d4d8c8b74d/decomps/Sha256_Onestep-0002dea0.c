
void Sha256_Onestep(uint8_t *data,size_t size,uint8_t *digest)

{
  uint8_t *digest_local;
  size_t size_local;
  uint8_t *data_local;
  CSha256 p;
  
  Sha256_Init(&p);
  Sha256_Update(&p,data,size);
  Sha256_Final(&p,digest);
  return;
}


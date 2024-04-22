
int SHA224_Update(SHA256_CTX *c,void *data,size_t len)

{
  if (len != 0) {
    SHA256_Update_part_0();
  }
  return 1;
}


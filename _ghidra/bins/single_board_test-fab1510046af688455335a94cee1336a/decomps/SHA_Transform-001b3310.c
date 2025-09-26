
void SHA_Transform(SHA_CTX *c,uchar *data)

{
  sha_block_data_order(c,data,1);
  return;
}



void SHA1_Transform(SHA_CTX *c,uchar *data)

{
  sha1_block_data_order(c,data,1);
  return;
}


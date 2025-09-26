
void MD5_Transform(MD5_CTX *c,uchar *b)

{
  md5_block_data_order(c,b,1);
  return;
}


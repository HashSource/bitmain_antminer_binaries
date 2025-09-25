
void MD4_Transform(MD4_CTX *c,uchar *b)

{
  md4_block_data_order(c,b,1);
  return;
}


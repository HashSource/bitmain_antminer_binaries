
void RIPEMD160_Transform(RIPEMD160_CTX *c,uchar *b)

{
  ripemd160_block_data_order(c,b,1);
  return;
}


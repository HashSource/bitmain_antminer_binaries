
void SHA512_Transform(SHA512_CTX *c,uchar *data)

{
  if (((uint)data & 7) != 0) {
    data = (uchar *)memcpy(&c->u,data,0x80);
  }
  sha512_block_data_order(c,data,1);
  return;
}


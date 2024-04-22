
void SHA512_Transform(SHA512_CTX *c,uchar *data)

{
  undefined4 in_r3;
  _union_320 *__dest;
  
  __dest = (_union_320 *)data;
  if (((uint)data & 7) != 0) {
    __dest = &c->u;
    memcpy(__dest,data,0x80);
  }
  sha512_block_data_order(c,__dest,1,in_r3);
  return;
}



int MD4_Final(uchar *md,MD4_CTX *c)

{
  uint uVar1;
  size_t __n;
  uint uVar2;
  uint *ptr;
  
  ptr = c->data;
  uVar1 = c->num + 1;
  *(undefined1 *)((int)ptr + c->num) = 0x80;
  if (uVar1 < 0x39) {
    __n = 0x38 - uVar1;
  }
  else {
    memset((void *)(uVar1 + (int)ptr),0,0x40 - uVar1);
    md4_block_data_order(c,ptr,1);
    __n = 0x38;
    uVar1 = 0;
  }
  memset((void *)(uVar1 + (int)ptr),0,__n);
  uVar1 = c->Nl;
  uVar2 = c->Nh;
  *(char *)(c->data + 0xe) = (char)uVar1;
  *(char *)(c->data + 0xf) = (char)uVar2;
  *(char *)((int)c->data + 0x39) = (char)(uVar1 >> 8);
  *(char *)((int)c->data + 0x3a) = (char)(uVar1 >> 0x10);
  *(char *)((int)c->data + 0x3b) = (char)(uVar1 >> 0x18);
  *(char *)((int)c->data + 0x3d) = (char)(uVar2 >> 8);
  *(char *)((int)c->data + 0x3f) = (char)(uVar2 >> 0x18);
  *(char *)((int)c->data + 0x3e) = (char)(uVar2 >> 0x10);
  md4_block_data_order(c,ptr,1);
  c->num = 0;
  OPENSSL_cleanse(ptr,0x40);
  uVar1 = c->A;
  *md = (uchar)uVar1;
  md[1] = (uchar)(uVar1 >> 8);
  md[2] = (uchar)(uVar1 >> 0x10);
  md[3] = (uchar)(uVar1 >> 0x18);
  uVar1 = c->B;
  md[4] = (uchar)uVar1;
  md[5] = (uchar)(uVar1 >> 8);
  md[6] = (uchar)(uVar1 >> 0x10);
  md[7] = (uchar)(uVar1 >> 0x18);
  uVar1 = c->C;
  md[8] = (uchar)uVar1;
  md[9] = (uchar)(uVar1 >> 8);
  md[10] = (uchar)(uVar1 >> 0x10);
  md[0xb] = (uchar)(uVar1 >> 0x18);
  uVar1 = c->D;
  md[0xc] = (uchar)uVar1;
  md[0xd] = (uchar)(uVar1 >> 8);
  md[0xe] = (uchar)(uVar1 >> 0x10);
  md[0xf] = (uchar)(uVar1 >> 0x18);
  return 1;
}


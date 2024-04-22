
int SHA1_Final(uchar *md,SHA_CTX *c)

{
  uint uVar1;
  uint uVar2;
  size_t __n;
  uint *__s;
  
  uVar2 = c->num;
  __s = c->data;
  uVar1 = uVar2 + 1;
  *(undefined *)((int)__s + uVar2) = 0x80;
  if (uVar1 < 0x39) {
    __n = 0x37 - uVar2;
  }
  else {
    memset((void *)((int)__s + uVar1),0,0x3f - uVar2);
    sha1_block_data_order(c,__s,1);
    __n = 0x38;
    uVar1 = 0;
  }
  memset((void *)((int)__s + uVar1),0,__n);
  uVar1 = c->Nl;
  uVar2 = c->Nh;
  *(char *)((int)c->data + 0x3f) = (char)uVar1;
  *(char *)((int)c->data + 0x3b) = (char)uVar2;
  *(char *)((int)c->data + 0x3d) = (char)(uVar1 >> 0x10);
  *(char *)((int)c->data + 0x3e) = (char)(uVar1 >> 8);
  *(char *)(c->data + 0xe) = (char)(uVar2 >> 0x18);
  *(char *)((int)c->data + 0x39) = (char)(uVar2 >> 0x10);
  *(char *)((int)c->data + 0x3a) = (char)(uVar2 >> 8);
  *(char *)(c->data + 0xf) = (char)(uVar1 >> 0x18);
  sha1_block_data_order(c,__s,1);
  c->num = 0;
  memset(__s,0,0x40);
  uVar1 = c->h0;
  md[3] = (uchar)uVar1;
  *md = (uchar)(uVar1 >> 0x18);
  md[1] = (uchar)(uVar1 >> 0x10);
  md[2] = (uchar)(uVar1 >> 8);
  uVar1 = c->h1;
  md[7] = (uchar)uVar1;
  md[4] = (uchar)(uVar1 >> 0x18);
  md[5] = (uchar)(uVar1 >> 0x10);
  md[6] = (uchar)(uVar1 >> 8);
  uVar1 = c->h2;
  md[0xb] = (uchar)uVar1;
  md[8] = (uchar)(uVar1 >> 0x18);
  md[9] = (uchar)(uVar1 >> 0x10);
  md[10] = (uchar)(uVar1 >> 8);
  uVar1 = c->h3;
  md[0xf] = (uchar)uVar1;
  md[0xc] = (uchar)(uVar1 >> 0x18);
  md[0xd] = (uchar)(uVar1 >> 0x10);
  md[0xe] = (uchar)(uVar1 >> 8);
  uVar1 = c->h4;
  md[0x13] = (uchar)uVar1;
  md[0x10] = (uchar)(uVar1 >> 0x18);
  md[0x11] = (uchar)(uVar1 >> 0x10);
  md[0x12] = (uchar)(uVar1 >> 8);
  return 1;
}


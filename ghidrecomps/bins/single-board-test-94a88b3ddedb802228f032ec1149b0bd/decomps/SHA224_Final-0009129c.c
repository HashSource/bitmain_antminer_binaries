
int SHA224_Final(uchar *md,SHA256_CTX *c)

{
  uint uVar1;
  uint uVar2;
  size_t __n;
  uint *puVar3;
  
  uVar2 = c->num;
  puVar3 = c->data;
  uVar1 = uVar2 + 1;
  *(undefined *)((int)puVar3 + uVar2) = 0x80;
  if (uVar1 < 0x39) {
    __n = 0x37 - uVar2;
  }
  else {
    memset((void *)((int)puVar3 + uVar1),0,0x3f - uVar2);
    sha256_block_data_order(c,puVar3,1);
    __n = 0x38;
    uVar1 = 0;
  }
  memset((void *)((int)puVar3 + uVar1),0,__n);
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
  sha256_block_data_order(c,puVar3,1);
  c->num = 0;
  memset(puVar3,0,0x40);
  uVar1 = c->md_len;
  if (uVar1 == 0x1c) {
    uVar1 = c->h[0];
    md[3] = (uchar)uVar1;
    *md = (uchar)(uVar1 >> 0x18);
    md[1] = (uchar)(uVar1 >> 0x10);
    md[2] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[1];
    md[7] = (uchar)uVar1;
    md[4] = (uchar)(uVar1 >> 0x18);
    md[5] = (uchar)(uVar1 >> 0x10);
    md[6] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[2];
    md[0xb] = (uchar)uVar1;
    md[8] = (uchar)(uVar1 >> 0x18);
    md[9] = (uchar)(uVar1 >> 0x10);
    md[10] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[3];
    md[0xf] = (uchar)uVar1;
    md[0xc] = (uchar)(uVar1 >> 0x18);
    md[0xd] = (uchar)(uVar1 >> 0x10);
    md[0xe] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[4];
    md[0x13] = (uchar)uVar1;
    md[0x10] = (uchar)(uVar1 >> 0x18);
    md[0x11] = (uchar)(uVar1 >> 0x10);
    md[0x12] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[5];
    md[0x17] = (uchar)uVar1;
    md[0x14] = (uchar)(uVar1 >> 0x18);
    md[0x15] = (uchar)(uVar1 >> 0x10);
    md[0x16] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[6];
    md[0x18] = (uchar)(uVar1 >> 0x18);
    md[0x19] = (uchar)(uVar1 >> 0x10);
    md[0x1a] = (uchar)(uVar1 >> 8);
    md[0x1b] = (uchar)uVar1;
    return 1;
  }
  if (uVar1 == 0x20) {
    uVar1 = c->h[0];
    md[3] = (uchar)uVar1;
    *md = (uchar)(uVar1 >> 0x18);
    md[1] = (uchar)(uVar1 >> 0x10);
    md[2] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[1];
    md[7] = (uchar)uVar1;
    md[4] = (uchar)(uVar1 >> 0x18);
    md[5] = (uchar)(uVar1 >> 0x10);
    md[6] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[2];
    md[0xb] = (uchar)uVar1;
    md[8] = (uchar)(uVar1 >> 0x18);
    md[9] = (uchar)(uVar1 >> 0x10);
    md[10] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[3];
    md[0xf] = (uchar)uVar1;
    md[0xc] = (uchar)(uVar1 >> 0x18);
    md[0xd] = (uchar)(uVar1 >> 0x10);
    md[0xe] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[4];
    md[0x13] = (uchar)uVar1;
    md[0x10] = (uchar)(uVar1 >> 0x18);
    md[0x11] = (uchar)(uVar1 >> 0x10);
    md[0x12] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[5];
    md[0x17] = (uchar)uVar1;
    md[0x14] = (uchar)(uVar1 >> 0x18);
    md[0x15] = (uchar)(uVar1 >> 0x10);
    md[0x16] = (uchar)(uVar1 >> 8);
    uVar1 = c->h[6];
    md[0x18] = (uchar)(uVar1 >> 0x18);
    md[0x19] = (uchar)(uVar1 >> 0x10);
    md[0x1a] = (uchar)(uVar1 >> 8);
    md[0x1b] = (uchar)uVar1;
    uVar1 = c->h[7];
    md[0x1f] = (uchar)uVar1;
    md[0x1c] = (uchar)(uVar1 >> 0x18);
    md[0x1d] = (uchar)(uVar1 >> 0x10);
    md[0x1e] = (uchar)(uVar1 >> 8);
    return 1;
  }
  if (0x20 < uVar1) {
    return 0;
  }
  if (uVar1 >> 2 != 0) {
    uVar1 = 0;
    puVar3 = &c[-1].md_len;
    do {
      puVar3 = puVar3 + 1;
      uVar2 = *puVar3;
      uVar1 = uVar1 + 1;
      md[3] = (uchar)uVar2;
      *md = (uchar)(uVar2 >> 0x18);
      md[1] = (uchar)(uVar2 >> 0x10);
      md[2] = (uchar)(uVar2 >> 8);
      md = md + 4;
    } while (uVar1 < c->md_len >> 2);
  }
  return 1;
}



int MD4_Update(MD4_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *__s;
  size_t __n;
  
  if (len != 0) {
    uVar4 = c->Nl;
    uVar2 = c->Nh;
    uVar1 = c->num;
    uVar3 = uVar4 + len * 8;
    c->Nl = uVar3;
    if (uVar3 < uVar4) {
      uVar2 = uVar2 + 1;
    }
    c->Nh = uVar2 + (len >> 0x1d);
    if (uVar1 != 0) {
      __s = c->data;
      if ((len < 0x40) && (len + uVar1 < 0x40)) {
        memcpy((void *)((int)__s + uVar1),data,len);
        c->num = c->num + len;
        return 1;
      }
      __n = 0x40 - uVar1;
      memcpy((void *)((int)__s + uVar1),data,__n);
      len = len - __n;
      md4_block_data_order(c,__s,1);
      c->num = 0;
      data = (void *)((int)data + __n);
      memset(__s,0,0x40);
    }
    uVar1 = len >> 6;
    if (uVar1 != 0) {
      uVar2 = len & 0xffffffc0;
      len = len - uVar2;
      md4_block_data_order(c,data,uVar1);
      data = (void *)((int)data + uVar2);
    }
    if (len != 0) {
      c->num = len;
      memcpy(c->data,data,len);
      return 1;
    }
  }
  return 1;
}


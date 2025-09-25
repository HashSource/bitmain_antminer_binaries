
int RIPEMD160_Update(RIPEMD160_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *__s;
  size_t __n;
  
  if (len == 0) {
    return 1;
  }
  uVar3 = c->Nl;
  uVar2 = uVar3 + len * 8;
  uVar4 = c->Nh;
  uVar1 = c->num;
  c->Nl = uVar2;
  if (uVar2 < uVar3) {
    uVar4 = uVar4 + 1;
  }
  c->Nh = uVar4 + (len >> 0x1d);
  if (uVar1 == 0) {
    uVar1 = len >> 6;
    if (uVar1 == 0) goto LAB_001b97ec;
LAB_001b984a:
    len = len + uVar1 * -0x40;
    ripemd160_block_data_order(c,data,uVar1);
    data = (void *)((int)data + uVar1 * 0x40);
  }
  else {
    __s = c->data;
    if ((len < 0x40) && (len + uVar1 < 0x40)) {
      memcpy((void *)(uVar1 + (int)__s),data,len);
      c->num = len + c->num;
      return 1;
    }
    __n = 0x40 - uVar1;
    memcpy((void *)(uVar1 + (int)__s),data,__n);
    len = len - __n;
    ripemd160_block_data_order(c,__s,1);
    c->num = 0;
    memset(__s,0,0x40);
    uVar1 = len >> 6;
    data = (void *)((int)data + __n);
    if (uVar1 != 0) goto LAB_001b984a;
  }
  if (len == 0) {
    return 1;
  }
LAB_001b97ec:
  c->num = len;
  memcpy(c->data,data,len);
  return 1;
}


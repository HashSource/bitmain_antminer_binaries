
int SHA512_Update(SHA512_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  void *__src;
  _union_320 *__dest;
  bool bVar6;
  
  if (len == 0) {
    return 1;
  }
  uVar1 = (uint)c->Nl;
  uVar2 = *(uint *)((int)&c->Nl + 4);
  uVar4 = len * 8 + uVar1;
  uVar5 = (len >> 0x1d) + uVar2 + (uint)CARRY4(len * 8,uVar1);
  bVar6 = uVar2 <= uVar5;
  if (uVar5 == uVar2) {
    bVar6 = uVar1 <= uVar4;
  }
  if (!bVar6) {
    uVar1 = (uint)c->Nh;
    iVar3 = *(int *)((int)&c->Nh + 4);
    *(uint *)&c->Nh = uVar1 + 1;
    *(uint *)((int)&c->Nh + 4) = iVar3 + (uint)(0xfffffffe < uVar1);
  }
  uVar1 = c->num;
  __dest = &c->u;
  *(uint *)&c->Nl = uVar4;
  *(uint *)((int)&c->Nl + 4) = uVar5;
  if (uVar1 == 0) {
    if (len < 0x80) goto LAB_0015a740;
LAB_0015a704:
    uVar1 = len;
    __src = data;
    if (((uint)data & 7) == 0) {
      sha512_block_data_order(c,data,len >> 7);
      uVar4 = len & 0x7f;
      data = (void *)((int)data + (len - uVar4));
    }
    else {
      do {
        uVar1 = uVar1 - 0x80;
        memcpy(__dest,__src,0x80);
        sha512_block_data_order(c,__dest,1);
        __src = (void *)((int)__src + 0x80);
      } while (0x7f < uVar1);
      uVar4 = len & 0x7f;
      data = (void *)((int)data + (len - 0x80 & 0xffffff80) + 0x80);
    }
  }
  else {
    uVar2 = 0x80 - uVar1;
    if (len < uVar2) {
      memcpy((void *)(uVar1 + (int)__dest),data,len);
      c->num = len + c->num;
      return 1;
    }
    uVar4 = len - uVar2;
    memcpy((void *)(uVar1 + (int)__dest),data,uVar2);
    c->num = 0;
    data = (void *)((int)data + uVar2);
    sha512_block_data_order(c,__dest,1);
    len = uVar4;
    if (0x7f < uVar4) goto LAB_0015a704;
  }
  len = uVar4;
  if (uVar4 == 0) {
    return 1;
  }
LAB_0015a740:
  memcpy(__dest,data,len);
  c->num = len;
  return 1;
}


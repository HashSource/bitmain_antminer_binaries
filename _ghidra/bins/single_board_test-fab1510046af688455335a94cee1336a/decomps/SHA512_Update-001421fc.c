
int SHA512_Update(SHA512_CTX *c,void *data,size_t len)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  _union_320 *__dest;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  if (len != 0) {
    uVar1 = (uint)c->Nl;
    uVar5 = *(uint *)((int)&c->Nl + 4);
    uVar2 = len * 8 + uVar1;
    uVar4 = (len >> 0x1d) + uVar5 + CARRY4(len * 8,uVar1);
    bVar7 = uVar5 <= uVar4;
    if (uVar4 == uVar5) {
      bVar7 = uVar1 <= uVar2;
    }
    if (!bVar7) {
      uVar1 = (uint)c->Nh;
      iVar6 = *(int *)((int)&c->Nh + 4);
      *(uint *)&c->Nh = uVar1 + 1;
      *(uint *)((int)&c->Nh + 4) = iVar6 + (uint)(0xfffffffe < uVar1);
    }
    uVar1 = c->num;
    __dest = &c->u;
    *(uint *)&c->Nl = uVar2;
    *(uint *)((int)&c->Nl + 4) = uVar4;
    if (uVar1 != 0) {
      uVar2 = 0x80 - uVar1;
      pvVar3 = (void *)((int)c->h + uVar1 + 0x50);
      if (len < uVar2) {
        memcpy(pvVar3,data,len);
        c->num = c->num + len;
        return 1;
      }
      len = len - uVar2;
      memcpy(pvVar3,data,uVar2);
      c->num = 0;
      data = (void *)((int)data + uVar2);
      sha512_block_data_order(c,__dest,1);
    }
    if (0x7f < len) {
      pvVar3 = data;
      uVar2 = len;
      if (((uint)data & 7) == 0) {
        uVar2 = len & 0x7f;
        sha512_block_data_order(c,data,len >> 7);
        data = (void *)((int)data + (len - uVar2));
        if (uVar2 == 0) {
          return 1;
        }
        goto LAB_001422b2;
      }
      do {
        uVar2 = uVar2 - 0x80;
        memcpy(__dest,pvVar3,0x80);
        sha512_block_data_order(c,__dest,1);
        pvVar3 = (void *)((int)pvVar3 + 0x80);
      } while (0x7f < uVar2);
      uVar2 = len - 0x80;
      len = len & 0x7f;
      data = (void *)((int)data + (uVar2 & 0xffffff80) + 0x80);
    }
    uVar2 = len;
    if (len != 0) {
LAB_001422b2:
      memcpy(__dest,data,uVar2);
      c->num = uVar2;
      return 1;
    }
  }
  return 1;
}


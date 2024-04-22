
int SHA384_Update(SHA512_CTX *c,void *data,size_t len)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  _union_320 *__dest;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  if (len != 0) {
    uVar4 = *(uint *)&c->Nl;
    uVar5 = *(uint *)((int)&c->Nl + 4);
    uVar1 = len * 8 + uVar4;
    uVar3 = (len >> 0x1d) + uVar5 + CARRY4(len * 8,uVar4);
    bVar7 = uVar5 <= uVar3;
    if (uVar3 == uVar5) {
      bVar7 = uVar4 <= uVar1;
    }
    if (!bVar7) {
      uVar4 = *(uint *)&c->Nh;
      iVar6 = *(int *)((int)&c->Nh + 4);
      *(uint *)&c->Nh = uVar4 + 1;
      *(uint *)((int)&c->Nh + 4) = iVar6 + (uint)(0xfffffffe < uVar4);
    }
    uVar4 = c->num;
    __dest = &c->u;
    *(uint *)&c->Nl = uVar1;
    *(uint *)((int)&c->Nl + 4) = uVar3;
    if (uVar4 != 0) {
      uVar1 = 0x80 - uVar4;
      pvVar2 = (void *)((int)c->h + uVar4 + 0x50);
      if (len < uVar1) {
        memcpy(pvVar2,data,len);
        c->num = c->num + len;
        return 1;
      }
      len = len - uVar1;
      memcpy(pvVar2,data,uVar1);
      c->num = 0;
      data = (void *)((int)data + uVar1);
      sha512_block_data_order(c,__dest,1);
    }
    if (0x7f < len) {
      pvVar2 = data;
      uVar1 = len;
      if (((uint)data & 7) == 0) {
        uVar1 = len & 0x7f;
        sha512_block_data_order(c,data,len >> 7);
        data = (void *)((int)data + (len - uVar1));
        if (uVar1 == 0) {
          return 1;
        }
        goto LAB_000971e2;
      }
      do {
        uVar1 = uVar1 - 0x80;
        memcpy(__dest,pvVar2,0x80);
        sha512_block_data_order(c,__dest,1);
        pvVar2 = (void *)((int)pvVar2 + 0x80);
      } while (0x7f < uVar1);
      uVar1 = len - 0x80;
      len = len & 0x7f;
      data = (void *)((int)data + (uVar1 & 0xffffff80) + 0x80);
    }
    uVar1 = len;
    if (len != 0) {
LAB_000971e2:
      memcpy(__dest,data,uVar1);
      c->num = uVar1;
      return 1;
    }
  }
  return 1;
}


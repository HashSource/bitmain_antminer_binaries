
void * ocb_lookup_l(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(param_1 + 0x14);
  if (param_2 <= uVar7) {
    return (void *)(*(int *)(param_1 + 0x40) + param_2 * 0x10);
  }
  uVar5 = *(uint *)(param_1 + 0x18);
  if (param_2 < uVar5) {
    pvVar4 = *(void **)(param_1 + 0x40);
  }
  else {
    iVar6 = uVar5 + ((4 - uVar5) + param_2 & 0xfffffffc);
    *(int *)(param_1 + 0x18) = iVar6;
    pvVar4 = CRYPTO_realloc(*(void **)(param_1 + 0x40),iVar6 * 0x10,"crypto/modes/ocb128.c",0x71);
    if (pvVar4 == (void *)0x0) {
      return (void *)0x0;
    }
    *(void **)(param_1 + 0x40) = pvVar4;
  }
  iVar6 = uVar7 << 4;
  do {
    bVar2 = *(byte *)((int)pvVar4 + iVar6 + 0xf);
    bVar3 = *(byte *)((int)pvVar4 + iVar6 + 0xe);
    uVar7 = uVar7 + 1;
    *(byte *)((int)pvVar4 + iVar6 + 0x1e) = (byte)((int)(uint)bVar2 >> 7) | bVar3 << 1;
    bVar1 = *(byte *)((int)pvVar4 + iVar6 + 0xd);
    *(byte *)((int)pvVar4 + iVar6 + 0x1d) = (byte)((int)(uint)bVar3 >> 7) | bVar1 << 1;
    bVar3 = *(byte *)((int)pvVar4 + iVar6 + 0xc);
    *(byte *)((int)pvVar4 + iVar6 + 0x1c) = (byte)((int)(uint)bVar1 >> 7) | bVar3 << 1;
    bVar1 = *(byte *)((int)pvVar4 + iVar6 + 0xb);
    *(byte *)((int)pvVar4 + iVar6 + 0x1b) = (byte)((int)(uint)bVar3 >> 7) | bVar1 << 1;
    bVar3 = *(byte *)((int)pvVar4 + iVar6 + 10);
    *(byte *)((int)pvVar4 + iVar6 + 0x1a) = (byte)((int)(uint)bVar1 >> 7) | bVar3 << 1;
    bVar1 = *(byte *)((int)pvVar4 + iVar6 + 9);
    *(byte *)((int)pvVar4 + iVar6 + 0x19) = (byte)((int)(uint)bVar3 >> 7) | bVar1 << 1;
    bVar3 = *(byte *)((int)pvVar4 + iVar6 + 8);
    *(byte *)((int)pvVar4 + iVar6 + 0x18) = (byte)((int)(uint)bVar1 >> 7) | bVar3 << 1;
    bVar1 = *(byte *)((int)pvVar4 + iVar6 + 7);
    *(byte *)((int)pvVar4 + iVar6 + 0x17) = (byte)((int)(uint)bVar3 >> 7) | bVar1 << 1;
    bVar3 = *(byte *)((int)pvVar4 + iVar6 + 6);
    *(byte *)((int)pvVar4 + iVar6 + 0x16) = (byte)((int)(uint)bVar1 >> 7) | bVar3 << 1;
    bVar1 = *(byte *)((int)pvVar4 + iVar6 + 5);
    *(byte *)((int)pvVar4 + iVar6 + 0x15) = (byte)((int)(uint)bVar3 >> 7) | bVar1 << 1;
    bVar3 = *(byte *)((int)pvVar4 + iVar6 + 4);
    *(byte *)((int)pvVar4 + iVar6 + 0x14) = (byte)((int)(uint)bVar1 >> 7) | bVar3 << 1;
    bVar1 = *(byte *)((int)pvVar4 + iVar6 + 3);
    *(byte *)((int)pvVar4 + iVar6 + 0x13) = (byte)((int)(uint)bVar3 >> 7) | bVar1 << 1;
    bVar3 = *(byte *)((int)pvVar4 + iVar6 + 2);
    *(byte *)((int)pvVar4 + iVar6 + 0x12) = (byte)((int)(uint)bVar1 >> 7) | bVar3 << 1;
    bVar1 = *(byte *)((int)pvVar4 + iVar6 + 1);
    *(byte *)((int)pvVar4 + iVar6 + 0x11) = (byte)((int)(uint)bVar3 >> 7) | bVar1 << 1;
    *(byte *)((int)pvVar4 + iVar6 + 0x10) =
         (byte)((int)(uint)bVar1 >> 7) | *(char *)((int)pvVar4 + iVar6) << 1;
    *(byte *)((int)pvVar4 + iVar6 + 0x1f) = *(char *)((int)pvVar4 + iVar6) >> 7 & 0x87U ^ bVar2 << 1
    ;
    pvVar4 = *(void **)(param_1 + 0x40);
    iVar6 = iVar6 + 0x10;
  } while (param_2 != uVar7);
  *(uint *)(param_1 + 0x14) = param_2;
  return (void *)((int)pvVar4 + param_2 * 0x10);
}


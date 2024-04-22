
undefined4 inflateCopy(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  void *__dest;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  void *__src;
  void *__dest_00;
  undefined4 uVar10;
  
  if ((((param_1 == (undefined4 *)0x0 || param_2 == (undefined4 *)0x0) ||
       (__src = (void *)param_2[7], __src == (void *)0x0)) || ((code *)param_2[8] == (code *)0x0))
     || (param_2[9] == 0)) {
    return 0xfffffffe;
  }
  __dest = (void *)(*(code *)param_2[8])(param_2[10],1,0x1bcc);
  if (__dest == (void *)0x0) {
    return 0xfffffffc;
  }
  __dest_00 = *(void **)((int)__src + 0x34);
  if ((__dest_00 != (void *)0x0) &&
     (__dest_00 = (void *)(*(code *)param_2[8])
                                    (param_2[10],1 << (*(uint *)((int)__src + 0x24) & 0xff),1),
     __dest_00 == (void *)0x0)) {
    (*(code *)param_2[9])(param_2[10],__dest);
    return 0xfffffffc;
  }
  puVar7 = param_2;
  puVar1 = param_1;
  do {
    puVar9 = puVar1;
    puVar6 = puVar7;
    uVar10 = puVar6[1];
    uVar2 = puVar6[2];
    uVar3 = puVar6[3];
    puVar7 = puVar6 + 4;
    *puVar9 = *puVar6;
    puVar9[1] = uVar10;
    puVar9[2] = uVar2;
    puVar9[3] = uVar3;
    puVar1 = puVar9 + 4;
  } while (puVar7 != param_2 + 0xc);
  uVar2 = puVar6[5];
  puVar9[4] = *puVar7;
  puVar9[5] = uVar2;
  memcpy(__dest,__src,0x1bcc);
  uVar4 = *(uint *)((int)__src + 0x4c);
  uVar8 = (int)__src + 0x530;
  if ((uVar8 <= uVar4) && (uVar4 <= (int)__src + 0x1bbcU)) {
    iVar5 = *(int *)((int)__src + 0x50);
    *(uint *)((int)__dest + 0x4c) = (int)__dest + (uVar4 - uVar8 & 0xfffffffc) + 0x530;
    *(uint *)((int)__dest + 0x50) = (int)__dest + (iVar5 - uVar8 & 0xfffffffc) + 0x530;
  }
  *(uint *)((int)__dest + 0x6c) =
       (int)__dest + (*(int *)((int)__src + 0x6c) - uVar8 & 0xfffffffc) + 0x530;
  if (__dest_00 != (void *)0x0) {
    memcpy(__dest_00,*(void **)((int)__src + 0x34),1 << (*(uint *)((int)__src + 0x24) & 0xff));
  }
  *(void **)((int)__dest + 0x34) = __dest_00;
  param_1[7] = __dest;
  return 0;
}


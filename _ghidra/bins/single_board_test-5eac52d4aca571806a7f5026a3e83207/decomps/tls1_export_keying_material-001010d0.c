
undefined4
tls1_export_keying_material
          (int param_1,undefined4 param_2,undefined4 param_3,void *param_4,size_t param_5,
          void *param_6,size_t param_7,int param_8)

{
  void *__dest;
  undefined4 uVar1;
  int iVar2;
  int num;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_2c;
  
  num = param_5 + 0x40;
  if (param_8 == 0) {
    __dest = CRYPTO_malloc(num,"ssl/t1_enc.c",0x21e);
    iVar3 = num;
    if (__dest == (void *)0x0) goto LAB_001012c2;
    memcpy(__dest,param_4,param_5);
    iVar3 = *(int *)(param_1 + 0x7c);
    uVar4 = *(undefined4 *)(iVar3 + 0xb0);
    uVar5 = *(undefined4 *)(iVar3 + 0xb4);
    uVar1 = *(undefined4 *)(iVar3 + 0xb8);
    *(undefined4 *)((int)__dest + param_5) = *(undefined4 *)(iVar3 + 0xac);
    *(undefined4 *)((int)__dest + param_5 + 4) = uVar4;
    *(undefined4 *)((int)__dest + param_5 + 8) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0xc) = uVar1;
    uVar1 = *(undefined4 *)(iVar3 + 200);
    uVar4 = *(undefined4 *)(iVar3 + 0xbc);
    uVar5 = *(undefined4 *)(iVar3 + 0xc0);
    *(undefined4 *)((int)__dest + param_5 + 0x18) = *(undefined4 *)(iVar3 + 0xc4);
    *(undefined4 *)((int)__dest + param_5 + 0x10) = uVar4;
    *(undefined4 *)((int)__dest + param_5 + 0x14) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0x1c) = uVar1;
    iVar3 = *(int *)(param_1 + 0x7c);
    uVar5 = *(undefined4 *)(iVar3 + 0x90);
    uVar1 = *(undefined4 *)(iVar3 + 0x94);
    uVar4 = *(undefined4 *)(iVar3 + 0x98);
    *(undefined4 *)((int)__dest + param_5 + 0x20) = *(undefined4 *)(iVar3 + 0x8c);
    *(undefined4 *)((int)__dest + param_5 + 0x24) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0x28) = uVar1;
    *(undefined4 *)((int)__dest + param_5 + 0x2c) = uVar4;
    uVar4 = *(undefined4 *)(iVar3 + 0xa8);
    uVar5 = *(undefined4 *)(iVar3 + 0xa0);
    uVar1 = *(undefined4 *)(iVar3 + 0xa4);
    *(undefined4 *)((int)__dest + param_5 + 0x30) = *(undefined4 *)(iVar3 + 0x9c);
    *(undefined4 *)((int)__dest + param_5 + 0x34) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0x38) = uVar1;
    *(undefined4 *)((int)__dest + param_5 + 0x3c) = uVar4;
  }
  else {
    iVar3 = param_7 + 2 + num;
    __dest = CRYPTO_malloc(iVar3,"ssl/t1_enc.c",0x21e);
    if (__dest == (void *)0x0) {
LAB_001012c2:
      __dest = (void *)0x0;
      uVar1 = 0;
      ERR_put_error(0x14,0x13a,0x41,"ssl/t1_enc.c",599);
      goto LAB_001012a8;
    }
    memcpy(__dest,param_4,param_5);
    iVar2 = *(int *)(param_1 + 0x7c);
    uVar4 = *(undefined4 *)(iVar2 + 0xb0);
    uVar5 = *(undefined4 *)(iVar2 + 0xb4);
    uVar1 = *(undefined4 *)(iVar2 + 0xb8);
    *(undefined4 *)((int)__dest + param_5) = *(undefined4 *)(iVar2 + 0xac);
    *(undefined4 *)((int)__dest + param_5 + 4) = uVar4;
    *(undefined4 *)((int)__dest + param_5 + 8) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0xc) = uVar1;
    uVar4 = *(undefined4 *)(iVar2 + 0xc0);
    uVar5 = *(undefined4 *)(iVar2 + 0xc4);
    uVar1 = *(undefined4 *)(iVar2 + 200);
    *(undefined4 *)((int)__dest + param_5 + 0x10) = *(undefined4 *)(iVar2 + 0xbc);
    *(undefined4 *)((int)__dest + param_5 + 0x14) = uVar4;
    *(undefined4 *)((int)__dest + param_5 + 0x18) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0x1c) = uVar1;
    iVar2 = *(int *)(param_1 + 0x7c);
    uVar4 = *(undefined4 *)(iVar2 + 0x90);
    uVar5 = *(undefined4 *)(iVar2 + 0x94);
    uVar1 = *(undefined4 *)(iVar2 + 0x98);
    *(undefined4 *)((int)__dest + param_5 + 0x20) = *(undefined4 *)(iVar2 + 0x8c);
    *(undefined4 *)((int)__dest + param_5 + 0x24) = uVar4;
    *(undefined4 *)((int)__dest + param_5 + 0x28) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0x2c) = uVar1;
    uVar4 = *(undefined4 *)(iVar2 + 0xa0);
    uVar5 = *(undefined4 *)(iVar2 + 0xa4);
    uVar1 = *(undefined4 *)(iVar2 + 0xa8);
    *(undefined4 *)((int)__dest + param_5 + 0x30) = *(undefined4 *)(iVar2 + 0x9c);
    local_2c = (undefined1)(param_7 >> 8);
    *(undefined4 *)((int)__dest + param_5 + 0x34) = uVar4;
    *(undefined4 *)((int)__dest + param_5 + 0x38) = uVar5;
    *(undefined4 *)((int)__dest + param_5 + 0x3c) = uVar1;
    *(undefined1 *)((int)__dest + num) = local_2c;
    *(undefined1 *)((int)__dest + param_5 + 0x41) = (undefined1)param_7;
    num = iVar3;
    if (param_6 != (void *)0x0 || param_7 != 0) {
      memcpy((void *)(param_5 + 0x42 + (int)__dest),param_6,param_7);
    }
  }
  iVar2 = memcmp(__dest,"client finished",0xf);
  iVar3 = num;
  if ((((iVar2 == 0) || (iVar2 = memcmp(__dest,"server finished",0xf), iVar2 == 0)) ||
      (iVar2 = memcmp(__dest,"master secret",0xd), iVar2 == 0)) ||
     ((iVar2 = memcmp(__dest,"extended master secret",0x16), iVar2 == 0 ||
      (iVar2 = memcmp(__dest,"key expansion",0xd), iVar2 == 0)))) {
    uVar1 = 0;
    ERR_put_error(0x14,0x13a,0x16f,"ssl/t1_enc.c",0x253);
  }
  else {
    uVar1 = tls1_PRF_constprop_0
                      (param_1,__dest,num,0,0,0,0,0,0,*(int *)(param_1 + 0x474) + 0x48,
                       *(undefined4 *)(*(int *)(param_1 + 0x474) + 4),param_2,param_3,0);
  }
LAB_001012a8:
  CRYPTO_clear_free(__dest,iVar3,"ssl/t1_enc.c",0x25a);
  return uVar1;
}


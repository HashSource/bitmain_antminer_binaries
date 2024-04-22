
undefined4
tls1_export_keying_material
          (int param_1,undefined4 param_2,size_t param_3,void *param_4,size_t param_5,void *param_6,
          size_t param_7,int param_8)

{
  void *ptr;
  void *__dest;
  undefined4 uVar1;
  int iVar2;
  size_t len;
  undefined4 uVar3;
  undefined4 uVar4;
  
  ptr = CRYPTO_malloc(param_3,DAT_00075258,0x4b2);
  if (ptr == (void *)0x0) {
    ERR_put_error(0x14,0x13a,0x41,DAT_00075258,0x4fc);
    uVar1 = 0;
  }
  else {
    len = param_5 + 0x40;
    if (param_8 != 0) {
      len = param_5 + 0x42 + param_7;
    }
    __dest = CRYPTO_malloc(len,DAT_00075258,0x4c0);
    if (__dest == (void *)0x0) {
      ERR_put_error(0x14,0x13a,0x41,DAT_00075258,0x4fc);
      CRYPTO_free(ptr);
      uVar1 = 0;
    }
    else {
      memcpy(__dest,param_4,param_5);
      iVar2 = *(int *)(param_1 + 0x58);
      uVar3 = *(undefined4 *)(iVar2 + 0xc4);
      uVar4 = *(undefined4 *)(iVar2 + 200);
      uVar1 = *(undefined4 *)(iVar2 + 0xcc);
      *(undefined4 *)((int)__dest + param_5) = *(undefined4 *)(iVar2 + 0xc0);
      *(undefined4 *)((int)__dest + param_5 + 4) = uVar3;
      *(undefined4 *)((int)__dest + param_5 + 8) = uVar4;
      *(undefined4 *)((int)__dest + param_5 + 0xc) = uVar1;
      uVar3 = *(undefined4 *)(iVar2 + 0xd4);
      uVar4 = *(undefined4 *)(iVar2 + 0xd8);
      uVar1 = *(undefined4 *)(iVar2 + 0xdc);
      *(undefined4 *)((int)__dest + param_5 + 0x10) = *(undefined4 *)(iVar2 + 0xd0);
      *(undefined4 *)((int)__dest + param_5 + 0x14) = uVar3;
      *(undefined4 *)((int)__dest + param_5 + 0x18) = uVar4;
      *(undefined4 *)((int)__dest + param_5 + 0x1c) = uVar1;
      iVar2 = *(int *)(param_1 + 0x58);
      uVar3 = *(undefined4 *)(iVar2 + 0xa4);
      uVar4 = *(undefined4 *)(iVar2 + 0xa8);
      uVar1 = *(undefined4 *)(iVar2 + 0xac);
      *(undefined4 *)((int)__dest + param_5 + 0x20) = *(undefined4 *)(iVar2 + 0xa0);
      *(undefined4 *)((int)__dest + param_5 + 0x24) = uVar3;
      *(undefined4 *)((int)__dest + param_5 + 0x28) = uVar4;
      *(undefined4 *)((int)__dest + param_5 + 0x2c) = uVar1;
      uVar3 = *(undefined4 *)(iVar2 + 0xb4);
      uVar4 = *(undefined4 *)(iVar2 + 0xb8);
      uVar1 = *(undefined4 *)(iVar2 + 0xbc);
      *(undefined4 *)((int)__dest + param_5 + 0x30) = *(undefined4 *)(iVar2 + 0xb0);
      *(undefined4 *)((int)__dest + param_5 + 0x34) = uVar3;
      *(undefined4 *)((int)__dest + param_5 + 0x38) = uVar4;
      *(undefined4 *)((int)__dest + param_5 + 0x3c) = uVar1;
      if (param_8 != 0) {
        *(char *)((int)__dest + param_5 + 0x40) = (char)(param_7 >> 8);
        *(char *)((int)__dest + param_5 + 0x41) = (char)param_7;
        if (param_6 != (void *)0x0 || param_7 != 0) {
          memcpy((void *)((int)__dest + param_5 + 0x42),param_6,param_7);
        }
      }
      iVar2 = memcmp(__dest,DAT_0007525c,0xf);
      if ((((iVar2 == 0) || (iVar2 = memcmp(__dest,DAT_00075260,0xf), iVar2 == 0)) ||
          (iVar2 = memcmp(__dest,DAT_00075264,0xd), iVar2 == 0)) ||
         (iVar2 = memcmp(__dest,DAT_00075268,0xd), iVar2 == 0)) {
        uVar1 = 0;
        ERR_put_error(0x14,0x13a,0x16f,DAT_00075258,0x4f8);
      }
      else {
        uVar1 = ssl_get_algorithm2(param_1);
        uVar1 = tls1_PRF_constprop_0
                          (uVar1,__dest,len,0,0,0,0,0,0,*(int *)(param_1 + 0xc0) + 0x14,
                           *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10),param_2,ptr,param_3);
        OPENSSL_cleanse(__dest,len);
        OPENSSL_cleanse(ptr,param_3);
      }
      CRYPTO_free(ptr);
      CRYPTO_free(__dest);
    }
  }
  return uVar1;
}


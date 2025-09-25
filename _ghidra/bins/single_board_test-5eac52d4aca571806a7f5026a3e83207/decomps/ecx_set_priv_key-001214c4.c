
undefined4 ecx_set_priv_key(EVP_PKEY *param_1,undefined4 *param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  void *ptr;
  void *__dest;
  undefined4 *puVar3;
  undefined4 uVar4;
  size_t __n;
  undefined4 *puVar5;
  int iVar6;
  int type;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  
  type = *(int *)param_1->ameth;
  if (param_2 == (undefined4 *)0x0) {
LAB_001214f0:
    ERR_put_error(0x10,0x10a,0x66,"crypto/ec/ecx_meth.c",0x41);
    return 0;
  }
  if (type == 0x40a || type == 0x43f) {
    bVar1 = false;
    if (param_3 != 0x20) goto LAB_001214f0;
  }
  else {
    bVar1 = true;
    if (type == 0x40b) {
      iVar6 = 0x38;
    }
    else {
      iVar6 = 0x39;
    }
    if (param_3 != iVar6) goto LAB_001214f0;
  }
  ptr = (void *)CRYPTO_zalloc(0x40,"crypto/ec/ecx_meth.c",0x46);
  if (ptr == (void *)0x0) {
    ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x48);
    return 0;
  }
  if (bVar1) {
    if (type != 0x40b) {
      __dest = (void *)CRYPTO_secure_malloc(0x39,"crypto/ec/ecx_meth.c",0x50);
      *(void **)((int)ptr + 0x3c) = __dest;
      if (__dest == (void *)0x0) {
LAB_0012160a:
        ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x52);
        CRYPTO_free(ptr);
        return 0;
      }
      __n = 0x39;
      goto LAB_00121548;
    }
    puVar3 = (undefined4 *)CRYPTO_secure_malloc(0x38,"crypto/ec/ecx_meth.c",0x50);
    *(undefined4 **)((int)ptr + 0x3c) = puVar3;
    puVar2 = puVar3;
    puVar9 = param_2;
    if (puVar3 == (undefined4 *)0x0) goto LAB_0012160a;
    do {
      puVar8 = puVar9;
      puVar5 = puVar2;
      puVar9 = puVar8 + 4;
      uVar10 = puVar8[1];
      uVar7 = puVar8[2];
      uVar4 = puVar8[3];
      *puVar5 = *puVar8;
      puVar5[1] = uVar10;
      puVar5[2] = uVar7;
      puVar5[3] = uVar4;
      puVar2 = puVar5 + 4;
    } while (puVar9 != param_2 + 0xc);
    uVar4 = puVar8[5];
    puVar5[4] = *puVar9;
    puVar5[5] = uVar4;
  }
  else {
    __dest = (void *)CRYPTO_secure_malloc(0x20,"crypto/ec/ecx_meth.c",0x50);
    *(void **)((int)ptr + 0x3c) = __dest;
    if (__dest == (void *)0x0) goto LAB_0012160a;
    __n = 0x20;
LAB_00121548:
    puVar3 = (undefined4 *)memcpy(__dest,param_2,__n);
    if (type != 0x40b) {
      if (type < 0x40c) {
        if (type == 0x40a) {
          X25519_public_from_private(ptr,puVar3);
        }
      }
      else if (type == 0x43f) {
        ED25519_public_from_private(ptr,puVar3);
      }
      else if (type == 0x440) {
        ED448_public_from_private(ptr,puVar3);
      }
      goto LAB_00121572;
    }
  }
  X448_public_from_private(ptr,puVar3);
LAB_00121572:
  EVP_PKEY_assign(param_1,type,ptr);
  return 1;
}



uint i2o_SCT_LIST(undefined4 param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 *local_24;
  
  uVar7 = 2;
  local_24 = (undefined1 *)0x0;
  if (param_2 == (int *)0x0) {
    do {
      iVar4 = OPENSSL_sk_num(param_1);
      if (iVar4 <= (int)param_2) {
        if (0xffff < uVar7) {
          return 0xffffffff;
        }
        return uVar7;
      }
      uVar2 = OPENSSL_sk_value(param_1,param_2);
      iVar4 = i2o_SCT(uVar2,0);
      uVar7 = uVar7 + iVar4 + 2;
      param_2 = (int *)((int)param_2 + 1);
    } while (iVar4 != -1);
    return 0xffffffff;
  }
  pvVar5 = (void *)*param_2;
  bVar1 = false;
  if (pvVar5 == (void *)0x0) {
    iVar4 = i2o_SCT_LIST();
    if (iVar4 == -1) {
      ERR_put_error(0x32,0x6c,0x69,"crypto/ct/ct_oct.c",0x14a);
      return 0xffffffff;
    }
    bVar1 = true;
    pvVar5 = CRYPTO_malloc(iVar4,"crypto/ct/ct_oct.c",0x14d);
    *param_2 = (int)pvVar5;
    if (pvVar5 == (void *)0x0) {
      ERR_put_error(0x32,0x6c,0x41,"crypto/ct/ct_oct.c",0x14e);
      return 0xffffffff;
    }
  }
  local_24 = (undefined1 *)((int)pvVar5 + 2);
  uVar7 = 2;
  iVar4 = 0;
  while( true ) {
    iVar3 = OPENSSL_sk_num(param_1);
    puVar6 = local_24;
    if (iVar3 <= iVar4) break;
    local_24 = local_24 + 2;
    uVar2 = OPENSSL_sk_value(param_1,iVar4);
    iVar3 = i2o_SCT(uVar2,&local_24);
    uVar7 = uVar7 + iVar3 + 2;
    if (iVar3 == -1) goto LAB_00114bee;
    *puVar6 = (char)((uint)iVar3 >> 8);
    puVar6[1] = (char)iVar3;
    iVar4 = iVar4 + 1;
  }
  if (uVar7 < 0x10000) {
    puVar6 = (undefined1 *)*param_2;
    *puVar6 = (char)(uVar7 - 2 >> 8);
    puVar6[1] = (char)(uVar7 - 2);
    if (!bVar1) {
      *param_2 = *param_2 + uVar7;
    }
    return uVar7;
  }
LAB_00114bee:
  if (!bVar1) {
    return 0xffffffff;
  }
  CRYPTO_free((void *)*param_2);
  *param_2 = 0;
  return 0xffffffff;
}


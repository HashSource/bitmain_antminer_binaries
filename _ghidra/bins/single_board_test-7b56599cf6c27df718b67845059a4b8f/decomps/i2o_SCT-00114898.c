
size_t i2o_SCT(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 *__dest;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  size_t __n;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined1 *__dest_00;
  undefined1 *local_1c;
  
  local_1c = (undefined1 *)0x0;
  iVar1 = SCT_is_complete();
  if (iVar1 == 0) {
    ERR_put_error(0x32,0x6b,0x6a,"crypto/ct/ct_oct.c",0xce);
    __dest = (undefined1 *)0x0;
  }
  else {
    iVar1 = *param_1;
    if (iVar1 == 0) {
      __n = param_1[0xc] + param_1[9] + 0x2f;
    }
    else {
      __n = param_1[2];
    }
    if (param_2 == (undefined4 *)0x0) {
      return __n;
    }
    __dest = (undefined1 *)*param_2;
    if (__dest == (undefined1 *)0x0) {
      __dest = (undefined1 *)CRYPTO_malloc(__n,"crypto/ct/ct_oct.c",0xe3);
      if (__dest == (undefined1 *)0x0) {
        local_1c = __dest;
        ERR_put_error(0x32,0x6b,0x41,"crypto/ct/ct_oct.c",0xe5);
        goto LAB_001149b4;
      }
      iVar1 = *param_1;
      *param_2 = __dest;
      puVar5 = __dest;
    }
    else {
      *param_2 = __dest + __n;
      puVar5 = (undefined1 *)0x0;
    }
    if (iVar1 != 0) {
      local_1c = __dest;
      memcpy(__dest,(void *)param_1[1],__n);
      return __n;
    }
    *__dest = 0;
    puVar4 = (undefined4 *)param_1[3];
    uVar6 = puVar4[1];
    uVar2 = puVar4[2];
    uVar3 = puVar4[3];
    *(undefined4 *)(__dest + 1) = *puVar4;
    *(undefined4 *)(__dest + 5) = uVar6;
    *(undefined4 *)(__dest + 9) = uVar2;
    *(undefined4 *)(__dest + 0xd) = uVar3;
    uVar6 = puVar4[4];
    uVar2 = puVar4[6];
    uVar3 = puVar4[7];
    *(undefined4 *)(__dest + 0x15) = puVar4[5];
    *(undefined4 *)(__dest + 0x11) = uVar6;
    *(undefined4 *)(__dest + 0x19) = uVar2;
    *(undefined4 *)(__dest + 0x1d) = uVar3;
    __dest_00 = __dest + 0x2b;
    __dest[0x21] = *(undefined1 *)((int)param_1 + 0x1f);
    __dest[0x22] = (char)*(undefined2 *)((int)param_1 + 0x1e);
    __dest[0x23] = (char)((uint)param_1[7] >> 8);
    __dest[0x24] = (char)param_1[7];
    __dest[0x25] = *(undefined1 *)((int)param_1 + 0x1b);
    __dest[0x26] = (char)*(undefined2 *)((int)param_1 + 0x1a);
    __dest[0x27] = (char)((uint)param_1[6] >> 8);
    __dest[0x28] = (char)param_1[6];
    __dest[0x29] = (char)((uint)param_1[9] >> 8);
    __dest[0x2a] = (char)param_1[9];
    local_1c = __dest_00;
    if (param_1[9] != 0) {
      memcpy(__dest_00,(void *)param_1[8],param_1[9]);
      local_1c = __dest_00 + param_1[9];
    }
    iVar1 = i2o_SCT_signature(param_1,&local_1c);
    __dest = puVar5;
    if (0 < iVar1) {
      return __n;
    }
  }
LAB_001149b4:
  CRYPTO_free(__dest);
  return 0xffffffff;
}


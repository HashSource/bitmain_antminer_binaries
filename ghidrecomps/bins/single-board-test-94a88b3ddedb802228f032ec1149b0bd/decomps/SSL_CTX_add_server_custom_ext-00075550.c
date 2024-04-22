
undefined4
SSL_CTX_add_server_custom_ext
          (int param_1,uint param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
          undefined4 param_7)

{
  ushort *addr;
  void *pvVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  void *__s;
  int iVar5;
  
  iVar3 = param_4;
  if (param_4 != 0) {
    iVar3 = 1;
  }
  if (param_3 != 0) {
    iVar3 = 0;
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  if (iVar3 == 0) {
    if (param_2 < 0x11) {
      if (9 < param_2) {
        return 0;
      }
      if (param_2 == 0) {
        return 0;
      }
      if (param_2 == 5) {
        return 0;
      }
    }
    else {
      if (param_2 == 0x23) {
        return 0;
      }
      if (param_2 < 0x24) {
        if (param_2 == 0x15) {
          return 0;
        }
      }
      else {
        if (param_2 == 0x3374) {
          return 0;
        }
        if (param_2 == 0xff01) {
          return 0;
        }
      }
    }
    if (param_2 < 0x10000) {
      iVar3 = *(int *)(iVar5 + 0x168);
      addr = *(ushort **)(iVar5 + 0x164);
      if (iVar3 == 0) {
LAB_000755c2:
        pvVar1 = CRYPTO_realloc(addr,(iVar3 + 1) * 0x18,DAT_00075628,0xe4);
        *(void **)(iVar5 + 0x164) = pvVar1;
        if (pvVar1 != (void *)0x0) {
          iVar4 = *(int *)(iVar5 + 0x168) * 0x18;
          __s = (void *)((int)pvVar1 + iVar4);
          memset(__s,0,0x18);
          iVar3 = *(int *)(iVar5 + 0x168);
          *(short *)((int)pvVar1 + iVar4) = (short)param_2;
          *(undefined4 *)((int)__s + 0x10) = param_6;
          *(int *)((int)__s + 4) = param_3;
          *(int *)((int)__s + 8) = param_4;
          *(undefined4 *)((int)__s + 0xc) = param_5;
          *(undefined4 *)((int)__s + 0x14) = param_7;
          *(int *)(iVar5 + 0x168) = iVar3 + 1;
          return 1;
        }
        *(undefined4 *)(iVar5 + 0x168) = 0;
        return 0;
      }
      if (param_2 != *addr) {
        iVar4 = 0;
        puVar2 = addr;
        do {
          iVar4 = iVar4 + 1;
          if (iVar4 == iVar3) goto LAB_000755c2;
          puVar2 = puVar2 + 0xc;
        } while (param_2 != *puVar2);
      }
    }
  }
  return 0;
}


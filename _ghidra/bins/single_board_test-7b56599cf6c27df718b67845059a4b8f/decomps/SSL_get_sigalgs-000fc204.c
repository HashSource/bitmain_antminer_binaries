
uint SSL_get_sigalgs(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined4 *param_5,undefined1 *param_6,undefined1 *param_7)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x7c) + 0x270);
  iVar5 = *(int *)(*(int *)(param_1 + 0x7c) + 0x268);
  uVar4 = uVar1 >> 0x1f;
  if (iVar5 == 0) {
    uVar4 = 1;
  }
  if (uVar4 != 0) {
    return 0;
  }
  if (param_2 < 0) {
    return uVar1;
  }
  if ((int)uVar1 <= param_2) {
    return 0;
  }
  if (param_7 != (undefined1 *)0x0) {
    *param_7 = (char)((ushort)*(undefined2 *)(iVar5 + param_2 * 2) >> 8);
  }
  if (param_6 != (undefined1 *)0x0) {
    *param_6 = (char)*(undefined2 *)(iVar5 + param_2 * 2);
  }
  puVar2 = &sigalg_lookup_tbl;
  do {
    if (*(short *)(puVar2 + 4) == *(short *)(iVar5 + param_2 * 2)) {
      if (param_3 != (undefined4 *)0x0) {
        puVar3 = *(undefined1 **)(puVar2 + 0x10);
        goto LAB_000fc266;
      }
      if (param_4 != (undefined4 *)0x0) goto LAB_000fc26c;
      goto LAB_000fc270;
    }
    puVar2 = puVar2 + 0x20;
  } while (puVar2 != legacy_rsa_sigalg);
  if (param_3 == (undefined4 *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      puVar2 = (undefined1 *)0x0;
      if (param_5 == (undefined4 *)0x0) {
        return uVar1;
      }
      goto LAB_000fc27e;
    }
    puVar2 = (undefined1 *)0x0;
    puVar3 = puVar2;
LAB_000fc26e:
    *param_4 = puVar3;
  }
  else {
    puVar2 = (undefined1 *)0x0;
    puVar3 = puVar2;
LAB_000fc266:
    *param_3 = puVar3;
    if (param_4 != (undefined4 *)0x0) {
      puVar3 = puVar2;
      if (puVar2 != (undefined1 *)0x0) {
LAB_000fc26c:
        puVar3 = *(undefined1 **)(puVar2 + 8);
      }
      goto LAB_000fc26e;
    }
  }
LAB_000fc270:
  if (param_5 == (undefined4 *)0x0) {
    return uVar1;
  }
  if (puVar2 != (undefined1 *)0x0) {
    puVar2 = *(undefined1 **)(puVar2 + 0x18);
  }
LAB_000fc27e:
  *param_5 = puVar2;
  return uVar1;
}


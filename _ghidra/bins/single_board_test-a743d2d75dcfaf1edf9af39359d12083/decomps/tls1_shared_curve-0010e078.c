
uint tls1_shared_curve(int param_1,uint param_2)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  bool bVar10;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    return 0xffffffff;
  }
  if ((param_2 == 0xfffffffe) &&
     (param_2 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000, param_2 != 0)) {
    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 8);
    if (iVar4 == 0x300c02b) {
      return 0x19f;
    }
    if (iVar4 == 0x300c02c) {
      return 0x2cb;
    }
    return 0;
  }
  uVar5 = *(uint *)(param_1 + 0x100) & 0x400000;
  if (uVar5 == 0) {
    uVar7 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
    if (uVar7 == 0x20000) {
      puVar8 = (undefined1 *)((int)&suiteb_curves + 2);
      uVar7 = 2;
      goto LAB_0010e0a2;
    }
    if (uVar7 == 0x30000) {
      puVar8 = "";
      uVar7 = 4;
      goto LAB_0010e0a2;
    }
    if (uVar7 == 0x10000) {
      puVar8 = "";
      uVar7 = 2;
      goto LAB_0010e0a2;
    }
    puVar8 = *(undefined1 **)(param_1 + 0x150);
    uVar7 = *(uint *)(param_1 + 0x14c);
    if (puVar8 != (char *)0x0) goto LAB_0010e0a2;
    puVar8 = eccurves_all;
    if (*(int *)(*(int *)(param_1 + 0x98) + 0x34) == 0) {
      uVar7 = 0x1c;
    }
    else {
      uVar7 = 0xd;
      puVar8 = eccurves_auto;
    }
LAB_0010e1de:
    puVar6 = *(undefined1 **)(*(int *)(param_1 + 0xc0) + 0xe0);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xc0) + 0xdc);
    goto LAB_0010e1ea;
  }
  puVar8 = *(undefined1 **)(*(int *)(param_1 + 0xc0) + 0xe0);
  uVar7 = *(uint *)(*(int *)(param_1 + 0xc0) + 0xdc);
LAB_0010e0a2:
  if ((int)(uVar7 << 0x1f) < 0) goto LAB_0010e208;
  uVar7 = uVar7 >> 1;
  if (uVar5 == 0) goto LAB_0010e1de;
  uVar2 = *(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30000;
  if (uVar2 == 0x20000) {
    puVar6 = (undefined1 *)((int)&suiteb_curves + 2);
    uVar2 = 2;
LAB_0010e1ea:
    if ((int)(uVar2 << 0x1f) < 0) {
LAB_0010e208:
      ERR_put_error(0x14,0x152,0x44,"t1_lib.c",0x200);
      return 0;
    }
    uVar2 = uVar2 >> 1;
    if ((uVar7 == 0) && (uVar5 != 0)) goto LAB_0010e0fc;
LAB_0010e1f8:
    uVar9 = uVar2;
    if (uVar2 == 0) {
      uVar2 = 0;
      if (uVar5 != 0) goto LAB_0010e236;
      uVar9 = 0x1c;
      puVar6 = eccurves_all;
    }
  }
  else {
    if (uVar2 == 0x30000) {
      puVar6 = "";
      uVar2 = 4;
      goto LAB_0010e1ea;
    }
    if (uVar2 == 0x10000) {
      puVar6 = "";
      uVar2 = 2;
      goto LAB_0010e1ea;
    }
    puVar6 = *(undefined1 **)(param_1 + 0x150);
    uVar2 = *(uint *)(param_1 + 0x14c);
    if (puVar6 != (char *)0x0) goto LAB_0010e1ea;
    puVar6 = eccurves_all;
    if (*(int *)(*(int *)(param_1 + 0x98) + 0x34) == 0) {
      uVar2 = 0x1c;
    }
    else {
      uVar2 = 0xd;
      puVar6 = eccurves_auto;
    }
    if (uVar7 != 0) goto LAB_0010e1f8;
LAB_0010e0fc:
    if (uVar2 == 0) goto LAB_0010e236;
    puVar8 = eccurves_all;
    uVar7 = 0x1c;
    uVar9 = uVar2;
  }
  uVar5 = 0;
  uVar2 = 0;
  do {
    if (uVar7 != 0) {
      uVar3 = 0;
      pcVar1 = puVar8;
      do {
        uVar3 = uVar3 + 1;
        if (((*pcVar1 == *puVar6) && (pcVar1[1] == puVar6[1])) &&
           (bVar10 = param_2 == uVar2, uVar2 = uVar2 + 1, bVar10)) {
          uVar5 = CONCAT11(*puVar6,pcVar1[1]) - 1;
          if (uVar5 < 0x1c) {
            return *(uint *)(nid_list + uVar5 * 4);
          }
          goto LAB_0010e23a;
        }
        pcVar1 = pcVar1 + 2;
      } while (uVar3 != uVar7);
    }
    uVar5 = uVar5 + 1;
    puVar6 = puVar6 + 2;
  } while (uVar5 < uVar9);
LAB_0010e236:
  if (param_2 != 0xffffffff) {
LAB_0010e23a:
    uVar2 = 0;
  }
  return uVar2;
}


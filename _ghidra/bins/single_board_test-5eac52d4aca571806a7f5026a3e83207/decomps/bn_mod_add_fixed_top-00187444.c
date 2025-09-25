
ulong * bn_mod_add_fixed_top(undefined4 *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ulong *puVar12;
  int iVar13;
  ulong *puVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  ulong *puVar18;
  uint *puVar19;
  uint num;
  bool bVar20;
  ulong *local_80;
  ulong *local_74;
  ulong local_68 [17];
  
  num = param_4[1];
  iVar2 = bn_wexpand(param_1,num);
  if (iVar2 == 0) {
    return (ulong *)0x0;
  }
  if (num < 0x11) {
    local_80 = local_68;
  }
  else {
    local_80 = (ulong *)CRYPTO_malloc(num << 2,"crypto/bn/bn_mod.c",0x3c);
    if (local_80 == (ulong *)0x0) {
      return (ulong *)0x0;
    }
  }
  local_74 = local_68;
  puVar18 = (ulong *)*param_2;
  if ((ulong *)*param_2 == (ulong *)0x0) {
    puVar18 = local_80;
  }
  puVar12 = (ulong *)*param_3;
  if ((ulong *)*param_3 == (ulong *)0x0) {
    puVar12 = local_80;
  }
  if (num == 0) {
    bn_sub_words((ulong *)*param_1,local_80,(ulong *)*param_4,0);
  }
  else {
    iVar9 = param_2[1];
    uVar15 = 0;
    iVar13 = param_2[2];
    iVar17 = 0;
    iVar3 = param_3[2];
    iVar16 = 0;
    iVar6 = param_3[1];
    iVar2 = -iVar9;
    puVar8 = local_80 + -1;
    do {
      puVar19 = puVar18 + iVar16;
      iVar4 = (iVar9 - iVar6) + iVar2;
      puVar1 = puVar12 + iVar17;
      iVar16 = iVar16 - (((iVar9 + 1) - iVar13) + iVar2 >> 0x1f);
      iVar17 = iVar17 - (((iVar9 + 1) - iVar3) + iVar2 >> 0x1f);
      uVar10 = *puVar19 & iVar2 >> 0x1f;
      iVar2 = iVar2 + 1;
      uVar11 = uVar10 + uVar15;
      uVar7 = (*puVar1 & iVar4 >> 0x1f) + uVar11;
      uVar15 = (uint)CARRY4(uVar10,uVar15);
      puVar8 = puVar8 + 1;
      *puVar8 = uVar7;
      if (uVar7 < uVar11) {
        uVar15 = uVar15 + 1;
      }
    } while (iVar2 != num - iVar9);
    puVar18 = (ulong *)*param_1;
    uVar5 = bn_sub_words(puVar18,local_80,(ulong *)*param_4,num);
    uVar15 = uVar15 - uVar5;
    if (num < 9) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
      puVar12 = local_80 + 0x10;
      puVar14 = puVar18 + 0x10;
      do {
        uVar10 = uVar7 + 9;
        HintPreloadData(puVar12);
        uVar7 = uVar7 + 8;
        HintPreloadData(puVar14);
        puVar14[-0x10] = (puVar14[-0x10] ^ puVar12[-0x10]) & uVar15 ^ puVar14[-0x10];
        puVar12[-0x10] = 0;
        puVar14[-0xf] = (puVar14[-0xf] ^ puVar12[-0xf]) & uVar15 ^ puVar14[-0xf];
        puVar12[-0xf] = 0;
        puVar14[-0xe] = (puVar14[-0xe] ^ puVar12[-0xe]) & uVar15 ^ puVar14[-0xe];
        puVar12[-0xe] = 0;
        puVar14[-0xd] = (puVar14[-0xd] ^ puVar12[-0xd]) & uVar15 ^ puVar14[-0xd];
        puVar12[-0xd] = 0;
        puVar14[-0xc] = (puVar14[-0xc] ^ puVar12[-0xc]) & uVar15 ^ puVar14[-0xc];
        puVar12[-0xc] = 0;
        puVar14[-0xb] = (puVar14[-0xb] ^ puVar12[-0xb]) & uVar15 ^ puVar14[-0xb];
        puVar12[-0xb] = 0;
        puVar14[-10] = (puVar14[-10] ^ puVar12[-10]) & uVar15 ^ puVar14[-10];
        puVar12[-10] = 0;
        puVar14[-9] = (puVar14[-9] ^ puVar12[-9]) & uVar15 ^ puVar14[-9];
        puVar12[-9] = 0;
        puVar12 = puVar12 + 8;
        puVar14 = puVar14 + 8;
      } while (uVar10 < num - 7);
    }
    puVar8 = local_80 + uVar7;
    puVar19 = puVar18 + uVar7;
    do {
      uVar7 = uVar7 + 1;
      *puVar19 = (*puVar8 ^ *puVar19) & uVar15 ^ *puVar19;
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
      puVar19 = puVar19 + 1;
    } while (uVar7 < num);
  }
  bVar20 = local_80 == local_74;
  param_1[1] = num;
  if (bVar20) {
    local_80 = (ulong *)0x1;
  }
  param_1[3] = 0;
  if (!bVar20) {
    CRYPTO_free(local_80);
    local_80 = (ulong *)0x1;
  }
  return local_80;
}


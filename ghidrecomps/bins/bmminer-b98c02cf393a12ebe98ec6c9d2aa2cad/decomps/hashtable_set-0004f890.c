
undefined4 hashtable_set(uint *param_1,char *param_2,uint param_3,undefined4 param_4)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int extraout_r1;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  undefined4 *puVar14;
  
  uVar7 = param_1[2];
  if (*param_1 >> (uVar7 & 0xff) == 0) {
    iVar13 = 1 << (uVar7 & 0xff);
    puVar3 = (undefined4 *)param_1[1];
  }
  else {
    iVar13 = 1 << (uVar7 + 1 & 0xff);
    puVar3 = (undefined4 *)jsonp_malloc(iVar13 * 8);
    if (puVar3 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    jsonp_free(param_1[1]);
    param_1[2] = uVar7 + 1;
    param_1[1] = (uint)puVar3;
    puVar14 = puVar3;
    if (iVar13 != 0) {
      do {
        puVar14[1] = param_1 + 3;
        puVar9 = puVar14 + 2;
        *puVar14 = param_1 + 3;
        puVar14 = puVar9;
      } while (puVar3 + iVar13 * 2 != puVar9);
    }
    puVar12 = (uint *)param_1[4];
    puVar4 = param_1 + 3;
    *puVar4 = (uint)puVar4;
    param_1[4] = (uint)puVar4;
    if (puVar12 != puVar4) {
      puVar14 = (undefined4 *)param_1[1];
      do {
        while( true ) {
          __aeabi_uidivmod(puVar12[4],iVar13);
          puVar10 = (uint *)puVar3[extraout_r1 * 2];
          puVar5 = puVar3 + extraout_r1 * 2;
          puVar6 = (uint *)puVar12[1];
          puVar3 = puVar14;
          if ((puVar10 != puVar4) || ((uint *)puVar5[1] != puVar4)) break;
          *puVar12 = param_1[3];
          puVar12[1] = (uint)puVar4;
          *(uint **)(param_1[3] + 4) = puVar12;
          param_1[3] = (uint)puVar12;
          puVar5[1] = (uint)puVar12;
          *puVar5 = (uint)puVar12;
          puVar12 = puVar6;
          if (puVar6 == puVar4) goto LAB_0004f994;
        }
        uVar7 = *puVar10;
        puVar12[1] = (uint)puVar10;
        *puVar12 = uVar7;
        *(uint **)(*puVar10 + 4) = puVar12;
        *puVar10 = (uint)puVar12;
        *puVar5 = (uint)puVar12;
        puVar12 = puVar6;
      } while (puVar6 != puVar4);
LAB_0004f994:
      iVar13 = 1 << (param_1[2] & 0xff);
    }
  }
  sVar1 = strlen(param_2);
  uVar7 = hashlittle(param_2,sVar1,hashtable_seed,&hashtable_seed,param_4);
  puVar3 = puVar3 + (iVar13 - 1U & uVar7) * 2;
  iVar13 = hashtable_find_pair(param_1,puVar3,param_2,uVar7);
  if (iVar13 == 0) {
    if ((sVar1 < 0xffffffe7) && (puVar4 = (uint *)jsonp_malloc(sVar1 + 0x19), puVar4 != (uint *)0x0)
       ) {
      puVar4[4] = uVar7;
      strncpy((char *)(puVar4 + 6),param_2,sVar1 + 1);
      puVar10 = (uint *)*puVar3;
      puVar12 = puVar4 + 2;
      puVar4[5] = param_3;
      puVar4[1] = (uint)puVar4;
      *puVar4 = (uint)puVar4;
      puVar4[3] = (uint)puVar12;
      puVar4[2] = (uint)puVar12;
      if ((puVar10 == param_1 + 3) && (puVar10 == (uint *)puVar3[1])) {
        *puVar4 = param_1[3];
        puVar4[1] = (uint)puVar10;
        *(uint **)(param_1[3] + 4) = puVar4;
        param_1[3] = (uint)puVar4;
        puVar3[1] = puVar4;
        *puVar3 = puVar4;
      }
      else {
        *puVar4 = *puVar10;
        puVar4[1] = (uint)puVar10;
        *(uint **)(*puVar10 + 4) = puVar4;
        *puVar10 = (uint)puVar4;
        *puVar3 = puVar4;
      }
      uVar7 = param_1[5];
      uVar11 = *param_1;
      puVar4[3] = (uint)(param_1 + 5);
      puVar4[2] = uVar7;
      *(uint **)(param_1[5] + 4) = puVar12;
      param_1[5] = (uint)puVar12;
      *param_1 = uVar11 + 1;
      return 0;
    }
    return 0xffffffff;
  }
  iVar2 = *(int *)(iVar13 + 0x14);
  if (((iVar2 != 0) && (*(int *)(iVar2 + 4) != -1)) &&
     (iVar8 = *(int *)(iVar2 + 4) + -1, *(int *)(iVar2 + 4) = iVar8, iVar8 == 0)) {
    json_delete();
    *(uint *)(iVar13 + 0x14) = param_3;
    return 0;
  }
  *(uint *)(iVar13 + 0x14) = param_3;
  return 0;
}


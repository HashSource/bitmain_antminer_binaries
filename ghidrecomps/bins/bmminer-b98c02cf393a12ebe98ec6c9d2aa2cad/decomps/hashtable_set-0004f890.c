
undefined4 hashtable_set(uint *param_1,char *param_2,uint *param_3,undefined4 param_4)

{
  size_t sVar1;
  uint *puVar2;
  int iVar3;
  uint **ppuVar4;
  uint **ppuVar5;
  uint **ppuVar6;
  int extraout_r1;
  uint **ppuVar7;
  uint **ppuVar8;
  uint uVar9;
  int iVar10;
  uint **ppuVar11;
  uint **ppuVar12;
  int iVar13;
  
  uVar9 = param_1[2];
  if (*param_1 >> (uVar9 & 0xff) == 0) {
    iVar13 = 1 << (uVar9 & 0xff);
    ppuVar4 = (uint **)param_1[1];
  }
  else {
    iVar13 = 1 << (uVar9 + 1 & 0xff);
    ppuVar4 = (uint **)jsonp_malloc(iVar13 * 8);
    if (ppuVar4 == (uint **)0x0) {
      return 0xffffffff;
    }
    jsonp_free(param_1[1]);
    param_1[2] = uVar9 + 1;
    param_1[1] = (uint)ppuVar4;
    ppuVar6 = ppuVar4;
    if (iVar13 != 0) {
      do {
        ppuVar6[1] = param_1 + 3;
        ppuVar12 = ppuVar6 + 2;
        *ppuVar6 = param_1 + 3;
        ppuVar6 = ppuVar12;
      } while (ppuVar4 + iVar13 * 2 != ppuVar12);
    }
    ppuVar12 = (uint **)param_1[4];
    ppuVar6 = (uint **)(param_1 + 3);
    *ppuVar6 = (uint *)ppuVar6;
    param_1[4] = (uint)ppuVar6;
    if (ppuVar12 != ppuVar6) {
      ppuVar11 = (uint **)param_1[1];
      do {
        while( true ) {
          __aeabi_uidivmod(ppuVar12[4],iVar13);
          ppuVar5 = (uint **)ppuVar4[extraout_r1 * 2];
          ppuVar7 = ppuVar4 + extraout_r1 * 2;
          ppuVar8 = (uint **)ppuVar12[1];
          ppuVar4 = ppuVar11;
          if ((ppuVar5 != ppuVar6) || ((uint **)ppuVar7[1] != ppuVar6)) break;
          *ppuVar12 = (uint *)param_1[3];
          ppuVar12[1] = (uint *)ppuVar6;
          *(uint ***)(param_1[3] + 4) = ppuVar12;
          param_1[3] = (uint)ppuVar12;
          ppuVar7[1] = (uint *)ppuVar12;
          *ppuVar7 = (uint *)ppuVar12;
          ppuVar12 = ppuVar8;
          if (ppuVar8 == ppuVar6) goto LAB_0004f994;
        }
        puVar2 = *ppuVar5;
        ppuVar12[1] = (uint *)ppuVar5;
        *ppuVar12 = puVar2;
        (*ppuVar5)[1] = (uint)ppuVar12;
        *ppuVar5 = (uint *)ppuVar12;
        *ppuVar7 = (uint *)ppuVar12;
        ppuVar12 = ppuVar8;
      } while (ppuVar8 != ppuVar6);
LAB_0004f994:
      iVar13 = 1 << (param_1[2] & 0xff);
    }
  }
  sVar1 = strlen(param_2);
  puVar2 = (uint *)hashlittle(param_2,sVar1,hashtable_seed,&hashtable_seed,param_4);
  ppuVar4 = ppuVar4 + (iVar13 - 1U & (uint)puVar2) * 2;
  iVar13 = hashtable_find_pair(param_1,ppuVar4,param_2,puVar2);
  if (iVar13 == 0) {
    if ((sVar1 < 0xffffffe7) &&
       (ppuVar6 = (uint **)jsonp_malloc(sVar1 + 0x19), ppuVar6 != (uint **)0x0)) {
      ppuVar6[4] = puVar2;
      strncpy((char *)(ppuVar6 + 6),param_2,sVar1 + 1);
      ppuVar11 = (uint **)*ppuVar4;
      ppuVar12 = ppuVar6 + 2;
      ppuVar6[5] = param_3;
      ppuVar6[1] = (uint *)ppuVar6;
      *ppuVar6 = (uint *)ppuVar6;
      ppuVar6[3] = (uint *)ppuVar12;
      ppuVar6[2] = (uint *)ppuVar12;
      if ((ppuVar11 == (uint **)(param_1 + 3)) && (ppuVar11 == (uint **)ppuVar4[1])) {
        *ppuVar6 = (uint *)param_1[3];
        ppuVar6[1] = (uint *)ppuVar11;
        *(uint ***)(param_1[3] + 4) = ppuVar6;
        param_1[3] = (uint)ppuVar6;
        ppuVar4[1] = (uint *)ppuVar6;
        *ppuVar4 = (uint *)ppuVar6;
      }
      else {
        *ppuVar6 = *ppuVar11;
        ppuVar6[1] = (uint *)ppuVar11;
        (*ppuVar11)[1] = (uint)ppuVar6;
        *ppuVar11 = (uint *)ppuVar6;
        *ppuVar4 = (uint *)ppuVar6;
      }
      puVar2 = (uint *)param_1[5];
      uVar9 = *param_1;
      ppuVar6[3] = param_1 + 5;
      ppuVar6[2] = puVar2;
      *(uint ***)(param_1[5] + 4) = ppuVar12;
      param_1[5] = (uint)ppuVar12;
      *param_1 = uVar9 + 1;
      return 0;
    }
    return 0xffffffff;
  }
  iVar3 = *(int *)(iVar13 + 0x14);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 4) != -1)) &&
     (iVar10 = *(int *)(iVar3 + 4) + -1, *(int *)(iVar3 + 4) = iVar10, iVar10 == 0)) {
    json_delete();
    *(uint **)(iVar13 + 0x14) = param_3;
    return 0;
  }
  *(uint **)(iVar13 + 0x14) = param_3;
  return 0;
}


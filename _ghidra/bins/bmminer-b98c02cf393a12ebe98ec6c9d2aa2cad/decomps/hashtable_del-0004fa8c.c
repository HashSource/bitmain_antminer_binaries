
undefined4 hashtable_del(int *param_1,char *param_2)

{
  size_t sVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined8 uVar11;
  
  sVar1 = strlen(param_2);
  uVar2 = hashlittle(param_2,sVar1,hashtable_seed);
  iVar8 = param_1[1];
  uVar7 = uVar2 & (1 << (param_1[2] & 0xffU)) - 1U;
  iVar9 = iVar8 + uVar7 * 8;
  uVar11 = hashtable_find_pair(param_1,iVar9,param_2,uVar2);
  piVar4 = (int *)((ulonglong)uVar11 >> 0x20);
  piVar3 = (int *)uVar11;
  if (piVar3 != (int *)0x0) {
    piVar6 = *(int **)(iVar9 + 4);
    if (piVar3 == *(int **)(iVar8 + uVar7 * 8)) {
      bVar10 = piVar3 != piVar6;
      if (bVar10) {
        iVar5 = piVar3[1];
      }
      else {
        piVar4 = param_1 + 3;
        iVar5 = piVar3[1];
        piVar6 = (int *)*piVar3;
      }
      if (bVar10) {
        piVar6 = (int *)*piVar3;
        *(int *)(iVar8 + uVar7 * 8) = iVar5;
      }
      else {
        *(int **)(iVar9 + 4) = piVar4;
        *(int **)(iVar8 + uVar7 * 8) = piVar4;
      }
    }
    else {
      bVar10 = piVar3 == piVar6;
      piVar6 = (int *)*piVar3;
      iVar5 = piVar3[1];
      if (bVar10) {
        *(int **)(iVar9 + 4) = piVar6;
      }
    }
    *(int *)((int)piVar6 + 4) = iVar5;
    iVar9 = piVar3[3];
    iVar8 = piVar3[5];
    *(int **)piVar3[1] = piVar6;
    iVar5 = piVar3[2];
    *(int *)(iVar5 + 4) = iVar9;
    *(int *)piVar3[3] = iVar5;
    if (((iVar8 != 0) && (*(int *)(iVar8 + 4) != -1)) &&
       (iVar9 = *(int *)(iVar8 + 4) + -1, *(int *)(iVar8 + 4) = iVar9, iVar9 == 0)) {
      json_delete();
    }
    jsonp_free(piVar3);
    *param_1 = *param_1 + -1;
    return 0;
  }
  return 0xffffffff;
}


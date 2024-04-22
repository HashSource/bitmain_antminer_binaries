
int * Curl_pipeline_penalized(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined8 uVar10;
  
  if (param_1 == 0) {
    return (int *)0x0;
  }
  uVar10 = Curl_multi_content_length_penalty_size(*(undefined4 *)(param_1 + 0x40));
  iVar7 = (int)((ulonglong)uVar10 >> 0x20);
  uVar6 = (uint)uVar10;
  uVar10 = Curl_multi_chunk_length_penalty_size(*(undefined4 *)(param_1 + 0x40));
  iVar2 = (int)((ulonglong)uVar10 >> 0x20);
  uVar1 = (uint)uVar10;
  piVar3 = *(int **)(param_2 + 0x25c);
  if ((piVar3 == (int *)0x0) || (piVar3 = (int *)*piVar3, piVar3 == (int *)0x0)) {
    uVar8 = 0xfffffffe;
    iVar9 = -1;
  }
  else {
    uVar8 = *(uint *)(*piVar3 + 0x50);
    iVar9 = *(int *)(*piVar3 + 0x54);
    piVar3 = (int *)(uint)((int)((iVar7 - iVar9) - (uint)(uVar6 < uVar8)) < 0 !=
                          (SBORROW4(iVar7,iVar9) != SBORROW4(iVar7 - iVar9,(uint)(uVar6 < uVar8))));
    if ((int)(iVar7 - (uint)(uVar6 == 0)) < 0 != (SBORROW4(iVar7,(uint)(uVar6 == 0)) != false)) {
      piVar3 = (int *)0x0;
    }
  }
  uVar6 = *(uint *)(param_2 + 0x28);
  iVar7 = *(int *)(param_2 + 0x2c);
  if (((int)(iVar2 - (uint)(uVar1 == 0)) < 0 == (SBORROW4(iVar2,(uint)(uVar1 == 0)) != false)) &&
     ((int)((iVar2 - iVar7) - (uint)(uVar1 < uVar6)) < 0 !=
      (SBORROW4(iVar2,iVar7) != SBORROW4(iVar2 - iVar7,(uint)(uVar1 < uVar6))))) {
    uVar4 = *(undefined4 *)(param_2 + 0x44);
    piVar3 = (int *)0x1;
  }
  else {
    uVar4 = *(undefined4 *)(param_2 + 0x44);
    uVar5 = DAT_0003c3f0;
    if (piVar3 == (int *)0x0) goto LAB_0003c3c2;
  }
  uVar5 = DAT_0003c3ec;
LAB_0003c3c2:
  Curl_infof(param_1,DAT_0003c3f4,uVar4,param_2,uVar8,iVar9,uVar6,iVar7,uVar5);
  return piVar3;
}


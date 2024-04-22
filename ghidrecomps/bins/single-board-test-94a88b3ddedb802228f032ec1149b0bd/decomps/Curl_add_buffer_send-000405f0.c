
int Curl_add_buffer_send(void **param_1,int *param_2,int *param_3,int param_4,int param_5)

{
  code **ppcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  void *pvVar9;
  uint uVar10;
  void *__src;
  void *local_2c [2];
  
  __src = *param_1;
  iVar7 = *(int *)(*param_2 + 0x14c);
  iVar6 = param_2[param_5 + 0x55];
  pvVar8 = param_1[2];
  pvVar9 = pvVar8;
  if ((*(int *)(param_2[0x86] + 0x40) << 0x1f < 0) && (param_2[0x4f] != 0x14)) {
    if ((void *)0x3fff < pvVar8) {
      pvVar9 = (void *)0x4000;
    }
    memcpy((void *)(*param_2 + 0x459d),__src,(size_t)pvVar9);
    __src = (void *)(*param_2 + 0x459d);
  }
  iVar6 = Curl_write(param_2,iVar6,__src,pvVar9,local_2c);
  if (iVar6 != 0) goto LAB_00040726;
  pvVar9 = (void *)((int)pvVar8 - param_4);
  if (local_2c[0] <= pvVar9) {
    pvVar9 = local_2c[0];
  }
  uVar10 = (int)local_2c[0] - (int)pvVar9;
  if (*(char *)(*param_2 + 0x310) == '\0') {
    if (uVar10 == 0) goto LAB_00040708;
LAB_0004068a:
    uVar4 = *(uint *)(iVar7 + 0x28);
    iVar3 = *param_3;
    *(uint *)(iVar7 + 0x28) = uVar4 + uVar10;
    *(uint *)(iVar7 + 0x2c) = *(int *)(iVar7 + 0x2c) + (uint)CARRY4(uVar4,uVar10);
    *param_3 = iVar3 + (int)local_2c[0];
  }
  else {
    Curl_debug(*param_2,2,__src,pvVar9,param_2);
    if (uVar10 != 0) {
      Curl_debug(*param_2,4,(int)__src + (int)pvVar9,uVar10,param_2);
      goto LAB_0004068a;
    }
LAB_00040708:
    *param_3 = *param_3 + (int)local_2c[0];
    if (iVar7 == 0) {
      if (pvVar8 != local_2c[0]) {
        return 0x37;
      }
      Curl_pipeline_leave_write(param_2);
      goto LAB_00040726;
    }
  }
  uVar2 = DAT_0004075c;
  if (pvVar8 != local_2c[0]) {
    iVar6 = *param_2;
    pvVar9 = *param_1;
    *(undefined4 *)(iVar7 + 0x40) = *(undefined4 *)(iVar6 + 0x86c0);
    uVar5 = *(undefined4 *)(iVar6 + 0x86c4);
    *(undefined4 *)(iVar7 + 0x50) = *(undefined4 *)(iVar7 + 8);
    *(undefined4 *)(iVar7 + 0x54) = *(undefined4 *)(iVar7 + 0xc);
    *(undefined4 *)(iVar7 + 0x44) = uVar5;
    *(undefined4 *)(iVar7 + 0x48) = *(undefined4 *)(iVar7 + 0x10);
    *(int **)(iVar6 + 0x86c4) = param_2;
    *(undefined4 *)(iVar6 + 0x86c0) = uVar2;
    *(int *)(iVar7 + 8) = (int)pvVar8 - (int)local_2c[0];
    *(int *)(iVar7 + 0x10) = (int)pvVar9 + (int)local_2c[0];
    *(void ***)(iVar7 + 0x5c) = param_1;
    *(undefined4 *)(iVar7 + 0xc) = 0;
    *(undefined4 *)(iVar7 + 0x58) = 1;
    return 0;
  }
  *(undefined4 *)(iVar7 + 0x58) = 2;
LAB_00040726:
  ppcVar1 = DAT_00040758;
  (**DAT_00040758)(*param_1);
  (**ppcVar1)(param_1);
  return iVar6;
}


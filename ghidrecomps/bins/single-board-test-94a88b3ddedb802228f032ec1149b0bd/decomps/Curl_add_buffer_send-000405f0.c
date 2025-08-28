
int Curl_add_buffer_send(int *param_1,int *param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  void *__src;
  size_t __n;
  uint local_2c [2];
  
  __src = (void *)*param_1;
  iVar4 = *(int *)(*param_2 + 0x14c);
  iVar3 = param_2[param_5 + 0x55];
  uVar5 = param_1[2];
  __n = uVar5;
  if ((*(int *)(param_2[0x86] + 0x40) << 0x1f < 0) && (param_2[0x4f] != 0x14)) {
    if (0x3fff < uVar5) {
      __n = 0x4000;
    }
    memcpy((void *)(*param_2 + 0x459d),__src,__n);
    __src = (void *)(*param_2 + 0x459d);
  }
  iVar3 = Curl_write(param_2,iVar3,__src,__n,local_2c);
  if (iVar3 != 0) goto LAB_00040726;
  uVar6 = uVar5 - param_4;
  if (local_2c[0] <= uVar6) {
    uVar6 = local_2c[0];
  }
  uVar7 = local_2c[0] - uVar6;
  if (*(char *)(*param_2 + 0x310) == '\0') {
    if (uVar7 == 0) goto LAB_00040708;
LAB_0004068a:
    uVar6 = *(uint *)(iVar4 + 0x28);
    iVar1 = *param_3;
    *(uint *)(iVar4 + 0x28) = uVar6 + uVar7;
    *(uint *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + (uint)CARRY4(uVar6,uVar7);
    *param_3 = iVar1 + local_2c[0];
  }
  else {
    Curl_debug(*param_2,2,__src,uVar6,param_2);
    if (uVar7 != 0) {
      Curl_debug(*param_2,4,(int)__src + uVar6,uVar7,param_2);
      goto LAB_0004068a;
    }
LAB_00040708:
    *param_3 = *param_3 + local_2c[0];
    if (iVar4 == 0) {
      if (uVar5 != local_2c[0]) {
        return 0x37;
      }
      Curl_pipeline_leave_write(param_2);
      goto LAB_00040726;
    }
  }
  if (uVar5 != local_2c[0]) {
    iVar1 = *param_2;
    iVar3 = *param_1;
    *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(iVar1 + 0x86c0);
    uVar2 = *(undefined4 *)(iVar1 + 0x86c4);
    *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar4 + 8);
    *(undefined4 *)(iVar4 + 0x54) = *(undefined4 *)(iVar4 + 0xc);
    *(undefined4 *)(iVar4 + 0x44) = uVar2;
    *(undefined4 *)(iVar4 + 0x48) = *(undefined4 *)(iVar4 + 0x10);
    *(int **)(iVar1 + 0x86c4) = param_2;
    *(undefined4 *)(iVar1 + 0x86c0) = 0x3fa85;
    *(uint *)(iVar4 + 8) = uVar5 - local_2c[0];
    *(uint *)(iVar4 + 0x10) = iVar3 + local_2c[0];
    *(int **)(iVar4 + 0x5c) = param_1;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(undefined4 *)(iVar4 + 0x58) = 1;
    return 0;
  }
  *(undefined4 *)(iVar4 + 0x58) = 2;
LAB_00040726:
  (*Curl_cfree)(*param_1);
  (*Curl_cfree)(param_1);
  return iVar3;
}


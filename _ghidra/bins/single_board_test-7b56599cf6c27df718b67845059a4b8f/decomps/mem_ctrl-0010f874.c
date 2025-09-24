
size_t mem_ctrl(int param_1,int param_2,undefined4 param_3,size_t *param_4)

{
  char *pcVar1;
  size_t sVar2;
  size_t *psVar3;
  size_t sVar4;
  size_t sVar5;
  undefined4 *puVar6;
  BUF_MEM *a;
  BUF_MEM *pBVar7;
  uint uVar8;
  BUF_MEM *pBVar9;
  
  puVar6 = *(undefined4 **)(param_1 + 0x24);
  a = (BUF_MEM *)*puVar6;
  pBVar9 = (BUF_MEM *)puVar6[1];
  uVar8 = *(uint *)(param_1 + 0x18) & 0x200;
  pBVar7 = a;
  if (uVar8 == 0) {
    pBVar7 = pBVar9;
  }
  if (param_2 == 10) {
    return pBVar7->length;
  }
  if (param_2 < 0xb) {
    if (param_2 == 3) {
      sVar2 = pBVar7->length;
      if (param_4 == (size_t *)0x0) {
        return sVar2;
      }
      *param_4 = (size_t)pBVar7->data;
      return sVar2;
    }
    if (param_2 < 4) {
      if (param_2 == 1) {
        if (a->data == (char *)0x0) {
          return 1;
        }
        if (uVar8 == 0) {
          if ((*(uint *)(param_1 + 0x18) & 0x400) == 0) {
            memset(a->data,0,a->max);
            a->length = 0;
            pBVar9 = (BUF_MEM *)puVar6[1];
            a = (BUF_MEM *)*puVar6;
          }
          pcVar1 = a->data;
          sVar2 = a->max;
          sVar4 = a[1].length;
          pBVar9->length = a->length;
          pBVar9->data = pcVar1;
          pBVar9->max = sVar2;
          pBVar9[1].length = sVar4;
          return 1;
        }
        pcVar1 = pBVar9->data;
        sVar2 = pBVar9->max;
        sVar4 = pBVar9[1].length;
        a->length = pBVar9->length;
        a->data = pcVar1;
        a->max = sVar2;
        a[1].length = sVar4;
        return 1;
      }
      if (param_2 == 2) {
        return (uint)(pBVar7->length == 0);
      }
    }
    else {
      if (param_2 == 8) {
        return *(size_t *)(param_1 + 0x14);
      }
      if (param_2 == 9) {
        *(undefined4 *)(param_1 + 0x14) = param_3;
        return 1;
      }
    }
  }
  else {
    if (param_2 == 0x72) {
      if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x10) != 0)) {
        if (uVar8 != 0) {
          a->data = (char *)0x0;
        }
        BUF_MEM_free(a);
        pBVar9 = (BUF_MEM *)puVar6[1];
      }
      sVar2 = *param_4;
      pcVar1 = (char *)param_4[1];
      sVar4 = param_4[2];
      sVar5 = param_4[3];
      *(undefined4 *)(param_1 + 0x14) = param_3;
      *puVar6 = param_4;
      pBVar9->length = sVar2;
      pBVar9->data = pcVar1;
      pBVar9->max = sVar4;
      pBVar9[1].length = sVar5;
      return 1;
    }
    if (param_2 < 0x73) {
      if (param_2 < 0xd) {
        return 1;
      }
    }
    else {
      if (param_2 == 0x73) {
        if (param_4 != (size_t *)0x0) {
          if ((uVar8 == 0) && (*(int *)(param_1 + 0x10) != 0)) {
            if (pBVar9->data != a->data) {
              memmove(a->data,pBVar9->data,pBVar9->length);
              psVar3 = (size_t *)puVar6[1];
              a = (BUF_MEM *)*puVar6;
              a->length = *psVar3;
              psVar3[1] = (size_t)a->data;
            }
          }
          *param_4 = (size_t)a;
          return 1;
        }
        return 1;
      }
      if (param_2 == 0x82) {
        *(undefined4 *)(param_1 + 0x20) = param_3;
        return 1;
      }
    }
  }
  return 0;
}



size_t mem_ctrl(int param_1,int param_2,undefined4 param_3,BUF_MEM **param_4)

{
  size_t sVar1;
  char *pcVar2;
  BUF_MEM *a;
  bool bVar3;
  
  a = *(BUF_MEM **)(param_1 + 0x20);
  if (param_2 == 10) {
    return a->length;
  }
  if (param_2 < 0xb) {
    if (param_2 == 3) {
      sVar1 = a->length;
      if (param_4 != (BUF_MEM **)0x0) {
        *param_4 = (BUF_MEM *)a->data;
        return sVar1;
      }
      return sVar1;
    }
    if (param_2 < 4) {
      if (param_2 == 1) {
        pcVar2 = a->data;
        if (pcVar2 == (char *)0x0) {
          return 1;
        }
        if ((*(uint *)(param_1 + 0x14) & 0x200) == 0) {
          memset(pcVar2,0,a->max);
          a->length = 0;
          return 1;
        }
        sVar1 = a->length;
        a->length = a->max;
        a->data = pcVar2 + (sVar1 - a->max);
        return 1;
      }
      if (param_2 == 2) {
        if (1 < a->length) {
          return 0;
        }
        return 1 - a->length;
      }
    }
    else {
      if (param_2 == 8) {
        return *(size_t *)(param_1 + 0x10);
      }
      if (param_2 == 9) {
        *(undefined4 *)(param_1 + 0x10) = param_3;
        return 1;
      }
    }
  }
  else {
    if (param_2 == 0x72) {
      if (((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
         (a != (BUF_MEM *)0x0)) {
        pcVar2 = (char *)(*(int *)(param_1 + 0x14) << 0x16);
        bVar3 = (int)pcVar2 < 0;
        if (bVar3) {
          pcVar2 = (char *)0x0;
        }
        if (bVar3) {
          a->data = pcVar2;
        }
        BUF_MEM_free(a);
      }
      *(undefined4 *)(param_1 + 0x10) = param_3;
      *(BUF_MEM ***)(param_1 + 0x20) = param_4;
      return 1;
    }
    if (param_2 < 0x73) {
      if (param_2 < 0xd) {
        return 1;
      }
    }
    else {
      if (param_2 == 0x73) {
        if (param_4 == (BUF_MEM **)0x0) {
          return 1;
        }
        *param_4 = a;
        return 1;
      }
      if (param_2 == 0x82) {
        *(undefined4 *)(param_1 + 0x1c) = param_3;
        return 1;
      }
    }
  }
  return 0;
}


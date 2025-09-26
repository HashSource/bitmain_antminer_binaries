
undefined4 extract_min_max(int *param_1,void *param_2,void *param_3,int param_4)

{
  size_t sVar1;
  size_t *psVar2;
  
  if (param_1 != (int *)0x0 && (param_3 != (void *)0x0 && param_2 != (void *)0x0)) {
    if (*param_1 == 0) {
      psVar2 = (size_t *)param_1[1];
      sVar1 = *psVar2;
      if ((int)sVar1 <= param_4 && -1 < (int)sVar1) {
        if (sVar1 != 0) {
          memcpy(param_2,(void *)psVar2[2],sVar1);
          sVar1 = *psVar2;
          if ((psVar2[3] & 7) != 0) {
            *(byte *)((int)param_2 + (sVar1 - 1)) =
                 *(byte *)((int)param_2 + (sVar1 - 1)) &
                 ~(byte)(0xff >> (8 - (psVar2[3] & 7) & 0xff));
            sVar1 = *psVar2;
          }
        }
        memset((void *)((int)param_2 + sVar1),0,param_4 - sVar1);
        psVar2 = (size_t *)param_1[1];
        sVar1 = *psVar2;
        if ((int)sVar1 <= param_4 && -1 < (int)sVar1) {
          if (sVar1 != 0) {
            memcpy(param_3,(void *)psVar2[2],sVar1);
            if ((psVar2[3] & 7) != 0) {
              *(byte *)((int)param_3 + (*psVar2 - 1)) =
                   *(byte *)((int)param_3 + (*psVar2 - 1)) |
                   (byte)(0xff >> (8 - (psVar2[3] & 7) & 0xff));
            }
            sVar1 = *psVar2;
          }
          memset((void *)(sVar1 + (int)param_3),0xff,param_4 - sVar1);
          return 1;
        }
      }
    }
    else {
      if (*param_1 != 1) {
        return 0;
      }
      psVar2 = *(size_t **)param_1[1];
      sVar1 = *psVar2;
      if ((int)sVar1 <= param_4 && -1 < (int)sVar1) {
        if (sVar1 != 0) {
          memcpy(param_2,(void *)psVar2[2],sVar1);
          sVar1 = *psVar2;
          if ((psVar2[3] & 7) != 0) {
            *(byte *)((int)param_2 + (sVar1 - 1)) =
                 *(byte *)((int)param_2 + (sVar1 - 1)) &
                 ~(byte)(0xff >> (8 - (psVar2[3] & 7) & 0xff));
            sVar1 = *psVar2;
          }
        }
        memset((void *)((int)param_2 + sVar1),0,param_4 - sVar1);
        psVar2 = *(size_t **)(param_1[1] + 4);
        sVar1 = *psVar2;
        if ((int)sVar1 <= param_4 && -1 < (int)sVar1) {
          if (sVar1 != 0) {
            memcpy(param_3,(void *)psVar2[2],sVar1);
            if ((psVar2[3] & 7) != 0) {
              *(byte *)((int)param_3 + (*psVar2 - 1)) =
                   *(byte *)((int)param_3 + (*psVar2 - 1)) |
                   (byte)(0xff >> (8 - (psVar2[3] & 7) & 0xff));
            }
            sVar1 = *psVar2;
          }
          memset((void *)(sVar1 + (int)param_3),0xff,param_4 - sVar1);
          return 1;
        }
      }
    }
  }
  return 0;
}


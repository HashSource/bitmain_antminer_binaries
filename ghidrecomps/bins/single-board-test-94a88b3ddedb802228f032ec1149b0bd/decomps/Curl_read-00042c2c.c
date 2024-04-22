
undefined4 Curl_read(int *param_1,int param_2,void *param_3,uint param_4,size_t *param_5)

{
  int iVar1;
  size_t __n;
  uint uVar2;
  undefined4 local_24;
  
  local_24 = 0x38;
  iVar1 = Curl_pipeline_wanted(*(undefined4 *)(*param_1 + 0x40),1);
  if ((iVar1 == 0) || (*(int *)param_1[0x11c] != 1)) {
    iVar1 = param_1[0x56];
    uVar2 = *(uint *)(*param_1 + 0x2cc);
    *param_5 = 0;
    if (uVar2 == 0) {
      uVar2 = 0x4000;
    }
    if ((int)param_4 <= (int)uVar2) {
      uVar2 = param_4;
    }
    __n = (*(code *)param_1[(iVar1 == param_2) + 0x5a])
                    (param_1,(uint)(iVar1 == param_2),param_3,uVar2,&local_24);
    if ((int)__n < 0) {
      return local_24;
    }
  }
  else {
    iVar1 = param_1[0x56];
    *param_5 = 0;
    uVar2 = param_1[0x9a] - param_1[0x99];
    if (param_4 < uVar2) {
      uVar2 = param_4;
    }
    if (uVar2 != 0) {
      memcpy(param_3,(void *)(param_1[0x98] + param_1[0x99]),uVar2);
      *(undefined *)((int)param_1 + 0x201) = 0;
      param_1[0x99] = param_1[0x99] + uVar2;
      *param_5 = uVar2;
      return 0;
    }
    if (0x3fff < param_4) {
      param_4 = 0x4000;
    }
    __n = (*(code *)param_1[(iVar1 == param_2) + 0x5a])
                    (param_1,(uint)(iVar1 == param_2),param_1[0x98],param_4,&local_24);
    if ((int)__n < 0) {
      return local_24;
    }
    memcpy(param_3,(void *)param_1[0x98],__n);
    param_1[0x9a] = __n;
    param_1[0x99] = __n;
  }
  *param_5 = *param_5 + __n;
  return 0;
}



undefined4 cca_get_random_bytes(void *param_1,size_t param_2)

{
  code **ppcVar1;
  void *pvVar2;
  undefined4 uVar3;
  int local_44;
  undefined auStack_40 [4];
  undefined auStack_3c [4];
  undefined auStack_38 [4];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined local_24;
  
  ppcVar1 = DAT_000d8660;
  local_2c = *DAT_000d865c;
  uStack_28 = DAT_000d865c[1];
  local_24 = (undefined)DAT_000d865c[2];
  if (7 < (int)param_2) {
    pvVar2 = (void *)((int)param_1 + 8);
    do {
      param_1 = pvVar2;
      param_2 = param_2 - 8;
      (**ppcVar1)(&local_44,auStack_40,auStack_3c,auStack_38,&local_2c,&local_34);
      HintPreloadData((int)param_1 + 0x30);
      if (local_44 != 0) goto LAB_000d8622;
      *(undefined4 *)((int)param_1 + -8) = local_34;
      *(undefined4 *)((int)param_1 + -4) = uStack_30;
      pvVar2 = (void *)((int)param_1 + 8);
    } while (7 < (int)param_2);
  }
  uVar3 = 1;
  if (param_2 != 0) {
    (**DAT_000d8660)(&local_44,auStack_40,0,0,&local_2c,&local_34);
    if (local_44 == 0) {
      memcpy(param_1,&local_34,param_2);
      uVar3 = 1;
    }
    else {
LAB_000d8622:
      uVar3 = 0;
    }
  }
  return uVar3;
}


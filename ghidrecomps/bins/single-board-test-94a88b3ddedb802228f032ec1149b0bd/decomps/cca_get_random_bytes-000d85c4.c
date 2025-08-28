
undefined4 cca_get_random_bytes(void *param_1,size_t param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int local_44;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined4 local_34;
  undefined4 uStack_30;
  char local_2c [16];
  
  builtin_strncpy(local_2c,"RANDOM  ",8);
  local_2c[8] = 0;
  if (7 < (int)param_2) {
    pvVar1 = (void *)((int)param_1 + 8);
    do {
      param_1 = pvVar1;
      param_2 = param_2 - 8;
      (*randomNumberGenerate)(&local_44,auStack_40,auStack_3c,auStack_38,local_2c,&local_34);
      HintPreloadData((int)param_1 + 0x30);
      if (local_44 != 0) goto LAB_000d8622;
      *(undefined4 *)((int)param_1 + -8) = local_34;
      *(undefined4 *)((int)param_1 + -4) = uStack_30;
      pvVar1 = (void *)((int)param_1 + 8);
    } while (7 < (int)param_2);
  }
  uVar2 = 1;
  if (param_2 != 0) {
    (*randomNumberGenerate)(&local_44,auStack_40,0,0,local_2c,&local_34);
    if (local_44 == 0) {
      memcpy(param_1,&local_34,param_2);
      uVar2 = 1;
    }
    else {
LAB_000d8622:
      uVar2 = 0;
    }
  }
  return uVar2;
}


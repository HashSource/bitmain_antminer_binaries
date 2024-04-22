
undefined4 showit(int param_1,uint param_2,void *param_3,size_t param_4)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x1c8) == (code *)0x0) {
    uVar1 = 0;
    if (param_2 < 3) {
      fwrite((void *)(DAT_00042bac + param_2 * 3),2,1,*(FILE **)(param_1 + 0x150));
      fwrite(param_3,param_4,1,*(FILE **)(param_1 + 0x150));
    }
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x1c8))();
  }
  return uVar1;
}


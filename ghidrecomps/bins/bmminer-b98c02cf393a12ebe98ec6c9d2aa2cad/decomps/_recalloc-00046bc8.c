
void _recalloc(int *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6)

{
  int iVar1;
  
  if (param_3 != param_2) {
    iVar1 = _cgrealloc(*param_1,param_3,param_4,param_5,param_6);
    *param_1 = iVar1;
    if (param_2 < param_3) {
      (*(code *)PTR_memset_0007cfb4)(iVar1 + param_2,0,param_3 - param_2);
      return;
    }
  }
  return;
}


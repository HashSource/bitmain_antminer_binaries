
void __aeabi_ldivmod(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    bVar2 = param_2 < 0;
    bVar3 = param_2 == 0;
    if (bVar3) {
      bVar2 = param_1 < 0;
    }
    bVar1 = param_1 != 0;
    if (bVar2) {
      param_1 = 0;
      param_2 = -0x80000000;
    }
    if ((!bVar3 || bVar1) && !bVar2) {
      param_2 = 0x7fffffff;
    }
    if ((!bVar3 || bVar1) && !bVar2) {
      param_1 = -1;
    }
    __aeabi_ldiv0(param_1,param_2);
    return;
  }
  __gnu_ldivmod_helper();
  return;
}



void __aeabi_uldivmod(int param_1,int param_2,int param_3,int param_4)

{
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_1 = -1;
    }
    __aeabi_ldiv0(param_1);
    return;
  }
  __gnu_uldivmod_helper();
  return;
}


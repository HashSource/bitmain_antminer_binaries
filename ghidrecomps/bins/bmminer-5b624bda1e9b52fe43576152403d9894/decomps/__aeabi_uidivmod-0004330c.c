
void __aeabi_uidivmod(int param_1,int param_2)

{
  if (param_2 != 0) {
    __aeabi_uidiv();
    return;
  }
  if (param_1 != 0) {
    param_1 = -1;
  }
  __aeabi_ldiv0(param_1);
  return;
}


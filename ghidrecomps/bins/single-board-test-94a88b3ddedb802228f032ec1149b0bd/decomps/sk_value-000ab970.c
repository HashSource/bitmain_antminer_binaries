
void * sk_value(_STACK *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 1 - (int)param_1;
  if ((_STACK *)0x1 < param_1) {
    uVar1 = 0;
  }
  if ((uVar1 | (uint)param_2 >> 0x1f) == 0) {
    if (param_2 < param_1->num) {
      return param_1->data[param_2];
    }
    return (void *)0x0;
  }
  return (void *)0x0;
}


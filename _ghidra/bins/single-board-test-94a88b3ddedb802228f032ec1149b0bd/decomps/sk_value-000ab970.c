
void * sk_value(_STACK *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 1 - (int)param_1;
  if ((_STACK *)0x1 < param_1) {
    iVar1 = 0;
  }
  if (iVar1 == 0 && -1 < param_2) {
    if (param_2 < param_1->num) {
      return param_1->data[param_2];
    }
    return (void *)0x0;
  }
  return (void *)0x0;
}


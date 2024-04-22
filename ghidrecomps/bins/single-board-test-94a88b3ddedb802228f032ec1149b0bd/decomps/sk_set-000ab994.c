
void * sk_set(_STACK *param_1,int param_2,void *param_3)

{
  uint uVar1;
  
  uVar1 = 1 - (int)param_1;
  if ((_STACK *)0x1 < param_1) {
    uVar1 = 0;
  }
  if ((uVar1 | (uint)param_2 >> 0x1f) == 0) {
    if (param_2 < param_1->num) {
      param_1->data[param_2] = (char *)param_3;
    }
    else {
      param_3 = (void *)0x0;
    }
  }
  else {
    param_3 = (void *)0x0;
  }
  return param_3;
}


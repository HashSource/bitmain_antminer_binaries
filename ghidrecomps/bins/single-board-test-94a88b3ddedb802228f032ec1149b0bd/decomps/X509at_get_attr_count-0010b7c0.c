
int X509at_get_attr_count(_STACK *param_1)

{
  if (param_1 != (_STACK *)0x0) {
    return param_1->num;
  }
  return -1;
}


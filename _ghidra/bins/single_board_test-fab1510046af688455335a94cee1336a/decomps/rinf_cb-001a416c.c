
_STACK * rinf_cb(int param_1,int *param_2)

{
  _STACK *p_Var1;
  int iVar2;
  
  iVar2 = *param_2;
  if (param_1 != 1) {
    return (_STACK *)0x1;
  }
  p_Var1 = sk_new_null();
  *(_STACK **)(iVar2 + 0x18) = p_Var1;
  if (p_Var1 != (_STACK *)0x0) {
    p_Var1 = (_STACK *)0x1;
  }
  return p_Var1;
}


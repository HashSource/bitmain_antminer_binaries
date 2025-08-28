
void obj_name_LHASH_COMP(int *param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  
  if (*param_1 != *param_2) {
    return;
  }
  if (name_funcs_stack != (_STACK *)0x0) {
    iVar1 = sk_num(name_funcs_stack);
    if (*param_1 < iVar1) {
      pvVar2 = sk_value(name_funcs_stack,*param_1);
      (**(code **)((int)pvVar2 + 4))(param_1[2],param_2[2]);
      return;
    }
  }
  (*(code *)(undefined *)0x0)(param_1[2],param_2[2]);
  return;
}


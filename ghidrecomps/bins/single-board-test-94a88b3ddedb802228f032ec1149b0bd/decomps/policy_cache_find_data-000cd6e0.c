
void * policy_cache_find_data(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined auStack_18 [4];
  undefined4 local_14;
  
  local_14 = param_2;
  iVar1 = sk_find(*(_STACK **)(param_1 + 4),auStack_18);
  if (iVar1 == -1) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = sk_value(*(_STACK **)(param_1 + 4),iVar1);
  }
  return pvVar2;
}


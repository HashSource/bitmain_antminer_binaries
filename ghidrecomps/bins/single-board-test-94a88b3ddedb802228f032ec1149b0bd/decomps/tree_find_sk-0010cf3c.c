
void * tree_find_sk(_STACK *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined *local_24 [3];
  undefined auStack_18 [4];
  undefined4 local_14;
  
  local_24[0] = auStack_18;
  local_14 = param_2;
  iVar1 = sk_find(param_1,local_24);
  if (iVar1 == -1) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = sk_value(param_1,iVar1);
  }
  return pvVar2;
}


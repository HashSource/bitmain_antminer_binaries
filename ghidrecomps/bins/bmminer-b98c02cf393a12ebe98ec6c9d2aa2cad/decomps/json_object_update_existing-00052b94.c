
undefined4 json_object_update_existing(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if ((*param_1 == 0 && param_2 != (int *)0x0) && (*param_2 == 0)) {
    iVar1 = hashtable_iter(param_2 + 2);
    if (iVar1 != 0) {
      while( true ) {
        iVar1 = hashtable_iter_key();
        if ((iVar1 == 0) || (iVar2 = hashtable_iter_value(iVar1 + -0x10), iVar2 == 0)) break;
        iVar3 = json_object_get(param_1,iVar1);
        if (iVar3 != 0) {
          if (*(int *)(iVar2 + 4) != -1) {
            *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
          }
          json_object_set_new_nocheck(param_1,iVar1,iVar2);
        }
        if (*param_2 != 0) {
          return 0;
        }
        iVar1 = hashtable_iter_next(param_2 + 2,iVar1 + -0x10);
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    return 0;
  }
  return 0xffffffff;
}


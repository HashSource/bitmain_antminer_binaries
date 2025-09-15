
int * json_deep_copy(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  switch(*param_1) {
  case 0:
    piVar2 = (int *)json_object();
    if (piVar2 != (int *)0x0) {
      if (*param_1 == 0) {
        for (iVar3 = hashtable_iter(param_1 + 2); iVar3 != 0;
            iVar3 = hashtable_iter_next(param_1 + 2,iVar3)) {
          uVar1 = hashtable_iter_key(iVar3);
          hashtable_iter_value(iVar3);
          uVar4 = json_deep_copy();
          json_object_set_new_nocheck(piVar2,uVar1,uVar4);
          if (*param_1 != 0) {
            return piVar2;
          }
        }
      }
      return piVar2;
    }
    break;
  case 1:
    piVar2 = (int *)json_array();
    if (piVar2 != (int *)0x0) {
      if (*param_1 != 1) {
        return piVar2;
      }
      uVar5 = param_1[3];
      if (uVar5 == 0) {
        return piVar2;
      }
      uVar6 = 0;
      while( true ) {
        uVar1 = 0;
        if (uVar6 < uVar5) {
          uVar1 = *(undefined4 *)(param_1[4] + uVar6 * 4);
        }
        uVar1 = json_deep_copy(uVar1);
        json_array_append_new(piVar2,uVar1);
        if (*param_1 != 1) break;
        uVar5 = param_1[3];
        uVar6 = uVar6 + 1;
        if (uVar5 <= uVar6) {
          return piVar2;
        }
      }
      return piVar2;
    }
    break;
  case 2:
    piVar2 = (int *)string_create(param_1[2],param_1[3],0);
    return piVar2;
  case 3:
    piVar2 = (int *)json_integer_copy();
    return piVar2;
  case 4:
    piVar2 = (int *)json_real((int)*(undefined8 *)(param_1 + 2));
    return piVar2;
  case 5:
  case 6:
  case 7:
    return param_1;
  }
  return (int *)0x0;
}


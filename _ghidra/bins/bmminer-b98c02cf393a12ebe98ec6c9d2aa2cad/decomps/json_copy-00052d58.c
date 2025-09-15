
int * json_copy(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  switch(*param_1) {
  case 0:
    piVar1 = (int *)json_object();
    if (piVar1 != (int *)0x0) {
      if (*param_1 == 0) {
        iVar3 = hashtable_iter(param_1 + 2);
        if (iVar3 != 0) {
          while( true ) {
            iVar3 = hashtable_iter_key();
            if ((iVar3 == 0) || (iVar2 = hashtable_iter_value(iVar3 + -0x10), iVar2 == 0)) break;
            if (*(int *)(iVar2 + 4) != -1) {
              *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
            }
            json_object_set_new_nocheck(piVar1,iVar3);
            if (*param_1 != 0) {
              return piVar1;
            }
            iVar3 = hashtable_iter_next(param_1 + 2,iVar3 + -0x10);
            if (iVar3 == 0) {
              return piVar1;
            }
          }
        }
      }
      return piVar1;
    }
    break;
  case 1:
    piVar1 = (int *)json_array();
    if (piVar1 != (int *)0x0) {
      if (*param_1 != 1) {
        return piVar1;
      }
      uVar4 = param_1[3];
      if (uVar4 == 0) {
        return piVar1;
      }
      uVar5 = 0;
      while( true ) {
        iVar3 = 0;
        if ((uVar5 < uVar4) && (iVar3 = *(int *)(param_1[4] + uVar5 * 4), iVar3 != 0)) {
          if (*(int *)(iVar3 + 4) != -1) {
            *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
          }
        }
        json_array_append_new(piVar1,iVar3);
        if (*param_1 != 1) break;
        uVar4 = param_1[3];
        uVar5 = uVar5 + 1;
        if (uVar4 <= uVar5) {
          return piVar1;
        }
      }
      return piVar1;
    }
    break;
  case 2:
    piVar1 = (int *)string_create(param_1[2],param_1[3],0);
    return piVar1;
  case 3:
    piVar1 = (int *)json_integer_copy();
    return piVar1;
  case 4:
    piVar1 = (int *)json_real((int)*(undefined8 *)(param_1 + 2));
    return piVar1;
  case 5:
  case 6:
  case 7:
    return param_1;
  }
  return (int *)0x0;
}


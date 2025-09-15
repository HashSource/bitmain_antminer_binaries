
bool json_equal_part_3(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (*param_1 == *param_2) {
    if (param_1 == param_2) {
      return true;
    }
    switch(*param_1) {
    case 0:
      if (param_1[2] == param_2[2]) {
        iVar2 = hashtable_iter(param_1 + 2);
        if (iVar2 == 0) {
          return true;
        }
        while( true ) {
          iVar2 = hashtable_iter_key();
          if (iVar2 == 0) {
            return true;
          }
          iVar3 = hashtable_iter_value(iVar2 + -0x10);
          if (iVar3 == 0) {
            return true;
          }
          iVar1 = json_object_get(param_2,iVar2);
          if (iVar1 == 0) {
            return false;
          }
          iVar3 = json_equal_part_3(iVar3,iVar1);
          if (iVar3 == 0) break;
          if (*param_1 != 0) {
            return true;
          }
          iVar2 = hashtable_iter_next(param_1 + 2,iVar2 + -0x10);
          if (iVar2 == 0) {
            return true;
          }
        }
        return false;
      }
      break;
    case 1:
      uVar5 = param_1[3];
      if (uVar5 == param_2[3]) {
        if (uVar5 == 0) {
          return true;
        }
        iVar3 = 1;
        uVar4 = 0;
        iVar2 = 1;
        while( true ) {
          if ((iVar2 == 1) && (uVar4 < (uint)param_1[3])) {
            iVar2 = *(int *)(param_1[4] + uVar4 * 4);
          }
          else {
            iVar2 = 0;
          }
          if (iVar3 != 1) {
            return false;
          }
          if ((uint)param_2[3] <= uVar4) {
            return false;
          }
          if (*(int *)(param_2[4] + uVar4 * 4) == 0 || iVar2 == 0) break;
          iVar2 = json_equal_part_3();
          if (iVar2 == 0) {
            return false;
          }
          uVar4 = uVar4 + 1;
          if (uVar5 == uVar4) {
            return true;
          }
          iVar2 = *param_1;
          iVar3 = *param_2;
        }
        return false;
      }
      break;
    case 2:
      if ((param_1[3] == param_2[3]) &&
         (iVar2 = memcmp((void *)param_1[2],(void *)param_2[2],param_1[3]), iVar2 == 0)) {
        return true;
      }
      break;
    case 3:
      return param_1[3] == param_2[3] && param_1[2] == param_2[2];
    case 4:
      return *(double *)(param_1 + 2) == *(double *)(param_2 + 2);
    }
  }
  return false;
}


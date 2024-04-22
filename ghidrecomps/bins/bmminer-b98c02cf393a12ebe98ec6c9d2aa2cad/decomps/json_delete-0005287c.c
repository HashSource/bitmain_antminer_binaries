
void json_delete(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 != (undefined4 *)0x0) {
    switch(*param_1) {
    case 0:
      hashtable_close(param_1 + 2);
      jsonp_free(param_1);
      return;
    case 1:
      goto switchD_0005288a_caseD_1;
    case 2:
      jsonp_free(param_1[2]);
      jsonp_free(param_1);
      return;
    case 3:
    case 4:
      jsonp_free();
      return;
    default:
      return;
    }
  }
  return;
switchD_0005288a_caseD_1:
  uVar3 = param_1[3];
  uVar5 = 0;
  iVar2 = param_1[4];
  if (uVar3 != 0) {
    do {
      iVar1 = *(int *)(iVar2 + uVar5 * 4);
      uVar5 = uVar5 + 1;
      if (((iVar1 != 0) && (iVar4 = *(int *)(iVar1 + 4) + -1, *(int *)(iVar1 + 4) != -1)) &&
         (*(int *)(iVar1 + 4) = iVar4, iVar4 == 0)) {
        json_delete();
        iVar2 = param_1[4];
        uVar3 = param_1[3];
      }
    } while (uVar5 < uVar3);
  }
  jsonp_free(iVar2);
  jsonp_free(param_1);
  return;
}



int pack(int param_1,int **param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined8 *puVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined4 local_28;
  int local_24 [2];
  
  switch(*(undefined *)(param_1 + 0x24)) {
  case 0x49:
    puVar8 = (undefined4 *)((int)*param_2 + 7U & 0xfffffff8);
    uVar5 = *puVar8;
    uVar6 = puVar8[1];
    *param_2 = puVar8 + 2;
    iVar2 = json_integer(uVar5,uVar6);
    break;
  default:
    set_error(param_1,"<format>","Unexpected format character \'%c\'");
    return 0;
  case 0x4f:
    next_token();
    bVar10 = *(char *)(param_1 + 0x24) != '?';
    if (bVar10) {
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
    }
    piVar7 = *param_2;
    *param_2 = piVar7 + 1;
    iVar2 = *piVar7;
    if (iVar2 != 0 || bVar10) {
      if (iVar2 == 0) {
        return 0;
      }
      if (*(int *)(iVar2 + 4) == -1) {
        return iVar2;
      }
      *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
      return iVar2;
    }
  case 0x6e:
switchD_000517a8_caseD_6e:
    iVar2 = json_null();
    break;
  case 0x5b:
    iVar2 = json_array();
    do {
      next_token(param_1);
      if (*(char *)(param_1 + 0x24) == ']') {
        return iVar2;
      }
      if (*(char *)(param_1 + 0x24) == '\0') {
        set_error(param_1,"<format>","Unexpected end of format string");
        goto LAB_00051aba;
      }
      iVar3 = pack(param_1,param_2);
      if (iVar3 == 0) goto LAB_00051aba;
      iVar3 = json_array_append_new(iVar2,iVar3);
    } while (iVar3 == 0);
    set_error(param_1,"<internal>","Unable to append to array");
LAB_00051aba:
    if (iVar2 == 0) {
      return 0;
    }
    if (*(int *)(iVar2 + 4) == -1) {
      return 0;
    }
    iVar3 = *(int *)(iVar2 + 4) + -1;
    *(int *)(iVar2 + 4) = iVar3;
    if (iVar3 != 0) {
      return 0;
    }
    json_delete(iVar2);
    iVar2 = 0;
    break;
  case 0x62:
    iVar2 = **param_2;
    *param_2 = *param_2 + 1;
    if (iVar2 == 0) {
      iVar2 = json_false();
    }
    else {
      iVar2 = json_true();
    }
    break;
  case 0x66:
    puVar9 = (undefined8 *)((int)*param_2 + 7U & 0xfffffff8);
    uVar11 = *puVar9;
    *param_2 = (int *)(puVar9 + 1);
    iVar2 = json_real((int)uVar11);
    break;
  case 0x69:
    iVar2 = **param_2;
    *param_2 = *param_2 + 1;
    iVar2 = json_integer(iVar2,iVar2 >> 0x1f);
    break;
  case 0x6f:
    next_token();
    bVar10 = *(char *)(param_1 + 0x24) != '?';
    if (bVar10) {
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
    }
    piVar7 = *param_2;
    *param_2 = piVar7 + 1;
    iVar2 = *piVar7;
    if (iVar2 != 0 || bVar10) {
      return iVar2;
    }
    goto switchD_000517a8_caseD_6e;
  case 0x73:
    next_token();
    if (*(char *)(param_1 + 0x24) == '?') {
      iVar2 = read_string(param_1,param_2,"string",&local_28,local_24);
      if (iVar2 == 0) goto switchD_000517a8_caseD_6e;
    }
    else {
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
      iVar2 = read_string(param_1,param_2,"string",&local_28,local_24);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (local_24[0] == 0) {
      iVar2 = json_stringn_nocheck();
    }
    else {
      iVar2 = jsonp_stringn_nocheck_own(iVar2,local_28);
    }
    break;
  case 0x7b:
    iVar2 = json_object();
    next_token(param_1);
    cVar1 = *(char *)(param_1 + 0x24);
    if (cVar1 != '}') {
      if (cVar1 == '\0') {
LAB_00051afe:
        set_error(param_1,"<format>","Unexpected end of format string");
      }
      else {
        if (cVar1 == 's') {
          do {
            iVar3 = read_string(param_1,param_2,"object key",&local_28,local_24);
            if (iVar3 == 0) goto LAB_00051a88;
            next_token(param_1);
            iVar4 = pack(param_1,param_2);
            if (iVar4 == 0) {
LAB_00051a7e:
              if (local_24[0] != 0) {
                jsonp_free(iVar3);
              }
              goto LAB_00051a88;
            }
            iVar4 = json_object_set_new_nocheck(iVar2,iVar3,iVar4);
            if (iVar4 != 0) {
              set_error(param_1,"<internal>","Unable to add key \"%s\"",iVar3);
              goto LAB_00051a7e;
            }
            if (local_24[0] != 0) {
              jsonp_free(iVar3);
            }
            next_token(param_1);
            cVar1 = *(char *)(param_1 + 0x24);
            if (cVar1 == '}') {
              return iVar2;
            }
            if (cVar1 == '\0') goto LAB_00051afe;
          } while (cVar1 == 's');
        }
        set_error(param_1,"<format>","Expected format \'s\', got \'%c\'");
      }
LAB_00051a88:
      if (iVar2 == 0) {
        return 0;
      }
      if (*(int *)(iVar2 + 4) == -1) {
        return 0;
      }
      iVar3 = *(int *)(iVar2 + 4) + -1;
      *(int *)(iVar2 + 4) = iVar3;
      if (iVar3 != 0) {
        return 0;
      }
      json_delete(iVar2);
      iVar2 = 0;
    }
  }
  return iVar2;
}


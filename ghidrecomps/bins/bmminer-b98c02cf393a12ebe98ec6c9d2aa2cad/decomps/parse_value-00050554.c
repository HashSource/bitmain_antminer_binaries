
int parse_value(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  uVar2 = *(int *)(param_1 + 0x38) + 1;
  *(uint *)(param_1 + 0x38) = uVar2;
  if (0x800 < uVar2) {
    error_set(param_3,param_1,"maximum parsing depth reached",uVar2,param_4);
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x3c);
  if (iVar3 == 0x101) {
    iVar3 = json_integer(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44));
  }
  else {
    if (iVar3 < 0x102) {
      if (iVar3 == 0x5b) {
        iVar3 = json_array();
        if (iVar3 == 0) {
          return 0;
        }
        lex_scan(param_1,param_3);
        iVar1 = *(int *)(param_1 + 0x3c);
        if (iVar1 != 0x5d) {
          while (iVar1 != 0) {
            iVar1 = parse_value(param_1,param_2,param_3);
            if (iVar1 == 0) goto LAB_000507a0;
            if (*(int *)(iVar1 + 4) != -1) {
              *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
            }
            iVar4 = json_array_append_new(iVar3,iVar1);
            iVar7 = *(int *)(iVar1 + 4);
            if (iVar4 != 0) goto joined_r0x00050820;
            if ((iVar7 != -1) && (*(int *)(iVar1 + 4) = iVar7 + -1, iVar7 + -1 == 0)) {
              json_delete(iVar1);
            }
            lex_scan(param_1,param_3);
            if (*(int *)(param_1 + 0x3c) != 0x2c) {
              if (*(int *)(param_1 + 0x3c) == 0x5d) goto LAB_000505f4;
              break;
            }
            lex_scan(param_1,param_3);
            iVar1 = *(int *)(param_1 + 0x3c);
          }
          error_set(param_3,param_1,"\']\' expected");
LAB_000507a0:
          if (*(int *)(iVar3 + 4) == -1) {
            return 0;
          }
          iVar1 = *(int *)(iVar3 + 4) + -1;
          *(int *)(iVar3 + 4) = iVar1;
          if (iVar1 != 0) {
            return 0;
          }
          json_delete(iVar3);
          return 0;
        }
      }
      else {
        if (iVar3 < 0x5c) {
          iVar3 = iVar3 + 1;
          if (iVar3 == 0) {
            error_set(param_3,param_1,"invalid token",0,param_4);
            return 0;
          }
LAB_000507ba:
          error_set(param_3,param_1,"unexpected token",iVar3,param_4);
          return 0;
        }
        if (iVar3 == 0x7b) {
          iVar3 = json_object();
          if (iVar3 == 0) {
            return 0;
          }
          lex_scan(param_1,param_3);
          if (*(int *)(param_1 + 0x3c) != 0x7d) {
            if (*(int *)(param_1 + 0x3c) == 0x100) {
              iVar7 = *(int *)(param_1 + 0x40);
              uVar5 = *(undefined4 *)(param_1 + 0x44);
              *(undefined4 *)(param_1 + 0x40) = 0;
              *(undefined4 *)(param_1 + 0x44) = 0;
              do {
                if (iVar7 == 0) {
                  return 0;
                }
                iVar1 = rpl_memchr(iVar7,0,uVar5);
                if (iVar1 != 0) {
                  jsonp_free(iVar7);
                  error_set(param_3,param_1,"NUL byte in object key not supported");
                  goto LAB_000507a0;
                }
                if (((param_2 & 1) != 0) && (iVar1 = json_object_get(iVar3,iVar7), iVar1 != 0)) {
                  jsonp_free(iVar7);
                  error_set(param_3,param_1,"duplicate object key");
                  goto LAB_000507a0;
                }
                lex_scan(param_1,param_3);
                if (*(int *)(param_1 + 0x3c) != 0x3a) {
                  jsonp_free(iVar7);
                  error_set(param_3,param_1,"\':\' expected");
                  goto LAB_000507a0;
                }
                lex_scan(param_1,param_3);
                iVar1 = parse_value(param_1,param_2,param_3);
                if (iVar1 == 0) {
                  jsonp_free(iVar7);
                  goto LAB_000507a0;
                }
                iVar4 = *(int *)(iVar1 + 4);
                bVar8 = iVar4 != -1;
                if (bVar8) {
                  iVar4 = iVar4 + 1;
                }
                if (bVar8) {
                  *(int *)(iVar1 + 4) = iVar4;
                }
                iVar4 = json_object_set_new_nocheck(iVar3,iVar7,iVar1);
                if (iVar4 != 0) {
                  jsonp_free(iVar7);
                  iVar7 = *(int *)(iVar1 + 4);
joined_r0x00050820:
                  if ((iVar7 != -1) && (*(int *)(iVar1 + 4) = iVar7 + -1, iVar7 + -1 == 0)) {
                    json_delete(iVar1);
                  }
                  goto LAB_000507a0;
                }
                if ((*(int *)(iVar1 + 4) != -1) &&
                   (iVar4 = *(int *)(iVar1 + 4) + -1, *(int *)(iVar1 + 4) = iVar4, iVar4 == 0)) {
                  json_delete(iVar1);
                }
                jsonp_free(iVar7);
                lex_scan(param_1,param_3);
                if (*(int *)(param_1 + 0x3c) != 0x2c) {
                  if (*(int *)(param_1 + 0x3c) == 0x7d) goto LAB_000505f4;
                  error_set(param_3,param_1,"\'}\' expected");
                  goto LAB_000507a0;
                }
                lex_scan(param_1,param_3);
                if (*(int *)(param_1 + 0x3c) != 0x100) break;
                iVar7 = *(int *)(param_1 + 0x40);
                uVar5 = *(undefined4 *)(param_1 + 0x44);
                *(undefined4 *)(param_1 + 0x40) = 0;
                *(undefined4 *)(param_1 + 0x44) = 0;
              } while( true );
            }
            error_set(param_3,param_1,"string or \'}\' expected");
            goto LAB_000507a0;
          }
        }
        else {
          if (iVar3 != 0x100) goto LAB_000507ba;
          uVar5 = *(undefined4 *)(param_1 + 0x40);
          uVar6 = *(undefined4 *)(param_1 + 0x44);
          if (((param_2 & 0x10) == 0) && (iVar3 = rpl_memchr(uVar5,0,uVar6), iVar3 != 0)) {
            error_set(param_3,param_1,"\\u0000 is not allowed without JSON_ALLOW_NUL");
            return 0;
          }
          iVar3 = jsonp_stringn_nocheck_own(uVar5,uVar6);
          if (iVar3 == 0) {
            return 0;
          }
          *(undefined4 *)(param_1 + 0x40) = 0;
          *(undefined4 *)(param_1 + 0x44) = 0;
        }
      }
      goto LAB_000505f4;
    }
    if (iVar3 == 0x103) {
      iVar3 = json_true();
    }
    else if (iVar3 < 0x103) {
      iVar3 = json_real((int)*(undefined8 *)(param_1 + 0x40));
    }
    else if (iVar3 == 0x104) {
      iVar3 = json_false();
    }
    else {
      if (iVar3 != 0x105) goto LAB_000507ba;
      iVar3 = json_null();
    }
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_000505f4:
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
  return iVar3;
}


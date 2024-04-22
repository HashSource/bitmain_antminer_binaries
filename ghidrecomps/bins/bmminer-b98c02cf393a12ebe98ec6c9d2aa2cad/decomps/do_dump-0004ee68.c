
undefined4 do_dump(undefined4 *param_1,uint param_2,int param_3,code *param_4,undefined4 param_5)

{
  undefined4 uVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  void *__base;
  char *pcVar8;
  char **ppcVar9;
  uint uVar10;
  int iVar11;
  char **ppcVar12;
  size_t sVar13;
  int iVar14;
  char acStack_8c [104];
  
  if (param_1 == (undefined4 *)0x0) {
switchD_0004ee86_caseD_8:
    return 0xffffffff;
  }
  switch(*param_1) {
  case 0:
    pcVar8 = ": ";
    if ((param_2 & 0x20) == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
      pcVar8 = ":";
    }
    if (param_1[9] == 0) {
      param_1[9] = 1;
      iVar7 = json_object_iter(param_1);
      iVar11 = (*param_4)(&DAT_000634c8,1,param_5);
      if (iVar11 == 0) {
        if (iVar7 == 0) {
          param_1[9] = 0;
          uVar1 = (*param_4)("}",1,param_5);
          return uVar1;
        }
        iVar14 = param_3 + 1;
        iVar11 = dump_indent(param_2,iVar14,0,param_4,param_5);
        if (iVar11 == 0) {
          if ((param_2 & 0x80) == 0) {
            while( true ) {
              iVar11 = json_object_iter_next(param_1,iVar7);
              pcVar2 = (char *)json_object_iter_key(iVar7);
              sVar3 = strlen(pcVar2);
              dump_string(pcVar2,sVar3,param_4,param_5,param_2);
              iVar4 = (*param_4)(pcVar8,uVar1,param_5);
              if (iVar4 != 0) break;
              uVar5 = json_object_iter_value(iVar7);
              iVar7 = do_dump(uVar5,param_2,iVar14,param_4,param_5);
              if (iVar7 != 0) break;
              if (iVar11 == 0) {
                iVar7 = dump_indent(param_2,param_3,0,param_4,param_5);
                if (iVar7 == 0) goto LAB_0004f0f2;
                break;
              }
              iVar7 = (*param_4)(&DAT_0005c74c,1,param_5);
              if ((iVar7 != 0) ||
                 (iVar4 = dump_indent(param_2,iVar14,1,param_4,param_5), iVar7 = iVar11, iVar4 != 0)
                 ) break;
            }
          }
          else {
            sVar3 = json_object_size(param_1);
            __base = (void *)jsonp_malloc(sVar3 << 2);
            if (__base != (void *)0x0) {
              ppcVar9 = (char **)((int)__base + -4);
              sVar13 = 0;
              ppcVar12 = ppcVar9;
              do {
                sVar13 = sVar13 + 1;
                pcVar2 = (char *)json_object_iter_key(iVar7);
                ppcVar12 = ppcVar12 + 1;
                *ppcVar12 = pcVar2;
                iVar7 = json_object_iter_next(param_1,iVar7);
              } while (iVar7 != 0);
              if (sVar3 != sVar13) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("i == size","compat/jansson-2.9/src/dump.c",0x152,DAT_0004f28c);
              }
              qsort(__base,sVar3,4,compare_keys + 1);
              uVar6 = 0;
              do {
                ppcVar9 = ppcVar9 + 1;
                pcVar2 = *ppcVar9;
                iVar7 = json_object_get(param_1,pcVar2);
                if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                  __assert_fail("value","compat/jansson-2.9/src/dump.c",0x15d,DAT_0004f28c);
                }
                sVar13 = strlen(pcVar2);
                dump_string(pcVar2,sVar13,param_4,param_5,param_2);
                iVar11 = (*param_4)(pcVar8,uVar1,param_5);
                if ((iVar11 != 0) ||
                   (iVar7 = do_dump(iVar7,param_2,iVar14,param_4,param_5), iVar7 != 0)) {
LAB_0004f21c:
                  jsonp_free(__base);
                  goto LAB_0004ef9a;
                }
                if (uVar6 < sVar3 - 1) {
                  iVar7 = (*param_4)(&DAT_0005c74c,1,param_5);
                  if (iVar7 != 0) goto LAB_0004f21c;
                  iVar7 = dump_indent(param_2,iVar14,1,param_4,param_5);
                }
                else {
                  iVar7 = dump_indent(param_2,param_3,0,param_4,param_5);
                }
                if (iVar7 != 0) goto LAB_0004f21c;
                uVar6 = uVar6 + 1;
              } while (sVar3 != uVar6);
              jsonp_free(__base);
LAB_0004f0f2:
              param_1[9] = 0;
              uVar1 = (*param_4)("}",1,param_5);
              return uVar1;
            }
          }
        }
      }
    }
LAB_0004ef9a:
    uVar1 = 0xffffffff;
    param_1[9] = 0;
    break;
  case 1:
    if (param_1[5] == 0) {
      param_1[5] = 1;
      uVar6 = json_array_size();
      iVar7 = (*param_4)(&DAT_0005c6d0,1,param_5);
      if (iVar7 == 0) {
        if (uVar6 == 0) {
          param_1[5] = 0;
          uVar1 = (*param_4)("]",1,param_5);
          return uVar1;
        }
        iVar11 = param_3 + 1;
        iVar7 = dump_indent(param_2,iVar11,0,param_4,param_5);
        if (iVar7 == 0) {
          uVar10 = 0;
          while( true ) {
            uVar1 = json_array_get(param_1,uVar10);
            iVar7 = do_dump(uVar1,param_2,iVar11,param_4,param_5);
            if (iVar7 != 0) break;
            if (uVar10 < uVar6 - 1) {
              iVar7 = (*param_4)(&DAT_0005c74c,1,param_5);
              if (iVar7 != 0) break;
              iVar7 = dump_indent(param_2,iVar11,1,param_4,param_5);
            }
            else {
              iVar7 = dump_indent(param_2,param_3,0,param_4,param_5);
            }
            if (iVar7 != 0) break;
            uVar10 = uVar10 + 1;
            if (uVar6 == uVar10) {
              param_1[5] = 0;
              uVar1 = (*param_4)("]",1,param_5);
              return uVar1;
            }
          }
        }
      }
    }
    uVar1 = 0xffffffff;
    param_1[5] = 0;
    break;
  case 2:
    uVar1 = json_string_value();
    uVar5 = json_string_length(param_1);
    uVar1 = dump_string(uVar1,uVar5,param_4,param_5,param_2);
    return uVar1;
  case 3:
    json_integer_value();
    uVar6 = snprintf(acStack_8c,100,"%lld");
    if (99 < uVar6) {
      return 0xffffffff;
    }
    uVar1 = (*param_4)(acStack_8c,uVar6,param_5);
    break;
  case 4:
    json_real_value();
    iVar7 = jsonp_dtostr(acStack_8c,100,(param_2 << 0x10) >> 0x1b);
    if (iVar7 < 0) {
      return 0xffffffff;
    }
    uVar1 = (*param_4)(acStack_8c,iVar7,param_5);
    break;
  case 5:
    uVar1 = (*param_4)(&DAT_00057f5c,4,param_5);
    return uVar1;
  case 6:
    uVar1 = (*param_4)("false",5,param_5);
    return uVar1;
  case 7:
    uVar1 = (*param_4)(&DAT_000698a0,4,param_5);
    break;
  default:
    goto switchD_0004ee86_caseD_8;
  }
  return uVar1;
}


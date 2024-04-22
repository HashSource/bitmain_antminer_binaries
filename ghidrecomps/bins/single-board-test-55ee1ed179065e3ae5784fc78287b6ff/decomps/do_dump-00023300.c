
undefined4 do_dump(undefined4 *param_1,uint param_2,int param_3,code *param_4,undefined4 param_5)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  char acStack_c0 [100];
  int local_5c;
  undefined4 local_58;
  void *local_54;
  uint local_50;
  int local_4c;
  undefined4 *local_48;
  int local_44;
  undefined4 *local_40;
  int local_3c;
  undefined8 local_38;
  int local_2c;
  __compar_fn_t local_28;
  uint local_24;
  undefined4 local_20;
  undefined *local_1c;
  int local_18;
  int local_14;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    switch(*param_1) {
    case 0:
      if ((param_2 & 0x20) == 0) {
        local_1c = &DAT_0002ce74;
        local_20 = 2;
      }
      else {
        local_1c = &DAT_0002ce70;
        local_20 = 1;
      }
      local_48 = param_1;
      if (param_1[8] == 0) {
        param_1[8] = 1;
        local_18 = json_object_iter(param_1);
        iVar3 = (*param_4)(&DAT_0002ce78,1,param_5);
        if (iVar3 == 0) {
          if (local_18 == 0) {
            local_48[8] = 0;
            uVar4 = (*param_4)(&DAT_0002ce7c,1,param_5);
            return uVar4;
          }
          iVar3 = dump_indent(param_2,param_3 + 1,0,param_4,param_5);
          if (iVar3 == 0) {
            if (((param_2 & 0x80) == 0) && ((param_2 & 0x100) == 0)) {
              do {
                if (local_18 == 0) goto LAB_00023924;
                local_4c = json_object_iter_next(param_1,local_18);
                uVar4 = json_object_iter_key(local_18);
                dump_string(uVar4,param_4,param_5,param_2);
                iVar3 = (*param_4)(local_1c,local_20,param_5);
                if (iVar3 != 0) break;
                uVar4 = json_object_iter_value(local_18);
                iVar3 = do_dump(uVar4,param_2,param_3 + 1,param_4,param_5);
                if (iVar3 != 0) break;
                if (local_4c == 0) {
                  iVar3 = dump_indent(param_2,param_3,0,param_4,param_5);
                }
                else {
                  iVar3 = (*param_4)(&DAT_0002ce6c,1,param_5);
                  if (iVar3 != 0) break;
                  iVar3 = dump_indent(param_2,param_3 + 1,1,param_4,param_5);
                }
                local_18 = local_4c;
              } while (iVar3 == 0);
            }
            else {
              local_50 = json_object_size(param_1);
              local_54 = (void *)jsonp_malloc(local_50 << 3);
              if (local_54 != (void *)0x0) {
                local_24 = 0;
                while (local_18 != 0) {
                  puVar5 = (undefined4 *)((int)local_54 + local_24 * 8);
                  uVar4 = hashtable_iter_serial(local_18);
                  pvVar2 = local_54;
                  *puVar5 = uVar4;
                  iVar3 = local_24 * 8;
                  uVar4 = json_object_iter_key(local_18);
                  *(undefined4 *)((int)pvVar2 + iVar3 + 4) = uVar4;
                  local_18 = json_object_iter_next(param_1,local_18);
                  local_24 = local_24 + 1;
                }
                if (local_24 != local_50) {
                    /* WARNING: Subroutine does not return */
                  __assert_fail("i == size","3rdparty/jansson-2.6/src/dump.c",0x141,"do_dump");
                }
                if ((param_2 & 0x80) == 0) {
                  pcVar1 = object_key_compare_serials;
                }
                else {
                  pcVar1 = object_key_compare_keys;
                }
                local_28 = pcVar1 + 1;
                qsort(local_54,local_50,8,local_28);
                for (local_24 = 0; local_24 < local_50; local_24 = local_24 + 1) {
                  local_58 = *(undefined4 *)((int)local_54 + local_24 * 8 + 4);
                  local_5c = json_object_get(param_1,local_58);
                  if (local_5c == 0) {
                    /* WARNING: Subroutine does not return */
                    __assert_fail("value","3rdparty/jansson-2.6/src/dump.c",0x151,"do_dump");
                  }
                  dump_string(local_58,param_4,param_5,param_2);
                  iVar3 = (*param_4)(local_1c,local_20,param_5);
                  if ((iVar3 != 0) ||
                     (iVar3 = do_dump(local_5c,param_2,param_3 + 1,param_4,param_5), iVar3 != 0)) {
                    jsonp_free(local_54);
                    goto LAB_00023954;
                  }
                  if (local_24 < local_50 - 1) {
                    iVar3 = (*param_4)(&DAT_0002ce6c,1,param_5);
                    if ((iVar3 != 0) ||
                       (iVar3 = dump_indent(param_2,param_3 + 1,1,param_4,param_5), iVar3 != 0)) {
                      jsonp_free(local_54);
                      goto LAB_00023954;
                    }
                  }
                  else {
                    iVar3 = dump_indent(param_2,param_3,0,param_4,param_5);
                    if (iVar3 != 0) {
                      jsonp_free(local_54);
                      goto LAB_00023954;
                    }
                  }
                }
                jsonp_free(local_54);
LAB_00023924:
                local_48[8] = 0;
                uVar4 = (*param_4)(&DAT_0002ce7c,1,param_5);
                return uVar4;
              }
            }
          }
        }
      }
LAB_00023954:
      local_48[8] = 0;
      uVar4 = 0xffffffff;
      break;
    case 1:
      local_40 = param_1;
      if (param_1[5] == 0) {
        param_1[5] = 1;
        local_44 = json_array_size(param_1);
        iVar3 = (*param_4)(&DAT_0002ce64,1,param_5);
        if (iVar3 == 0) {
          if (local_44 == 0) {
            local_40[5] = 0;
            uVar4 = (*param_4)(&DAT_0002ce68,1,param_5);
            return uVar4;
          }
          iVar3 = dump_indent(param_2,param_3 + 1,0,param_4,param_5);
          if (iVar3 == 0) {
            local_14 = 0;
            while( true ) {
              if (local_44 <= local_14) {
                local_40[5] = 0;
                uVar4 = (*param_4)(&DAT_0002ce68,1,param_5);
                return uVar4;
              }
              uVar4 = json_array_get(param_1,local_14);
              iVar3 = do_dump(uVar4,param_2,param_3 + 1,param_4,param_5);
              if (iVar3 != 0) break;
              if (local_14 < local_44 + -1) {
                iVar3 = (*param_4)(&DAT_0002ce6c,1,param_5);
                if (iVar3 != 0) break;
                iVar3 = dump_indent(param_2,param_3 + 1,1,param_4,param_5);
              }
              else {
                iVar3 = dump_indent(param_2,param_3,0,param_4,param_5);
              }
              if (iVar3 != 0) break;
              local_14 = local_14 + 1;
            }
          }
        }
      }
      local_40[5] = 0;
      uVar4 = 0xffffffff;
      break;
    case 2:
      uVar4 = json_string_value(param_1);
      uVar4 = dump_string(uVar4,param_4,param_5,param_2);
      break;
    case 3:
      uVar6 = json_integer_value(param_1);
      uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
      local_2c = snprintf(acStack_c0,100,"%lld",uVar4,(int)uVar6,uVar4);
      if ((local_2c < 0) || (99 < local_2c)) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (*param_4)(acStack_c0,local_2c,param_5);
      }
      break;
    case 4:
      local_38 = json_real_value(param_1);
      local_3c = jsonp_dtostr((int)local_38,acStack_c0,100);
      if (local_3c < 0) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (*param_4)(acStack_c0,local_3c,param_5);
      }
      break;
    case 5:
      uVar4 = (*param_4)(&DAT_0002ce4c,4,param_5);
      break;
    case 6:
      uVar4 = (*param_4)("false",5,param_5);
      break;
    case 7:
      uVar4 = (*param_4)(&DAT_0002ce44,4,param_5);
      break;
    default:
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}


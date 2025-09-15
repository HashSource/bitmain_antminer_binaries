
/* WARNING: Type propagation algorithm not settling */

uint unpack(int param_1,int *param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined8 *puVar14;
  bool bVar15;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined8 uVar16;
  undefined1 auStack_48 [12];
  int local_3c [7];
  
  uVar10 = (uint)*(byte *)(param_1 + 0x24);
  switch(uVar10) {
  case 0x46:
    if (param_2 != (int *)0x0) {
      if (1 < *param_2 - 3U) {
        set_error(param_1,"<validation>","Expected real or integer, got %s",
                  *(undefined4 *)(&type_names + *param_2 * 4));
        return 0xffffffff;
      }
      if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
        puVar11 = (undefined4 *)*param_3;
        *param_3 = (int)(puVar11 + 1);
        puVar14 = (undefined8 *)*puVar11;
        uVar5 = json_number_value(param_2);
        *puVar14 = CONCAT44(extraout_s1,uVar5);
        return 0;
      }
      return 0;
    }
    break;
  default:
    goto LAB_00051328;
  case 0x49:
    if (param_2 != (int *)0x0) {
      iVar3 = *param_2;
      if (iVar3 == 3) {
        if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
          puVar11 = (undefined4 *)*param_3;
          *param_3 = (int)(puVar11 + 1);
          puVar14 = (undefined8 *)*puVar11;
          uVar16 = json_integer_value(param_2);
          *puVar14 = uVar16;
          return 0;
        }
        return 0;
      }
LAB_00051550:
      set_error(param_1,"<validation>","Expected integer, got %s",
                *(undefined4 *)(&type_names + iVar3 * 4));
      return 0xffffffff;
    }
    break;
  case 0x4f:
    if (param_2 != (int *)0x0) {
      if (*(int *)(param_1 + 0x3c) << 0x1f < 0) {
        return 0;
      }
      if (param_2[1] != -1) {
        param_2[1] = param_2[1] + 1;
      }
      puVar11 = (undefined4 *)*param_3;
      *param_3 = (int)(puVar11 + 1);
      piVar12 = (int *)*puVar11;
      goto LAB_00050fd6;
    }
  case 0x6f:
    if (*(int *)(param_1 + 0x3c) << 0x1f < 0) {
      return 0;
    }
    puVar11 = (undefined4 *)*param_3;
    *param_3 = (int)(puVar11 + 1);
    piVar12 = (int *)*puVar11;
    if (param_2 == (int *)0x0) {
      return 0;
    }
LAB_00050fd6:
    *piVar12 = (int)param_2;
    return 0;
  case 0x5b:
    if ((param_2 != (int *)0x0) && (*param_2 != 1)) {
      set_error(param_1,"<validation>","Expected array, got %s",
                *(undefined4 *)(&type_names + *param_2 * 4));
      return 0xffffffff;
    }
    iVar3 = 0;
    next_token(param_1);
    while( true ) {
      iVar6 = 0;
      bVar1 = *(byte *)(param_1 + 0x24);
      while( true ) {
        uVar10 = (uint)bVar1;
        if (uVar10 == 0x5d) {
          if (iVar6 == 0) {
            if (-1 < *(int *)(param_1 + 0x3c) << 0x1e) {
              return 0;
            }
            bVar2 = true;
          }
          else {
            bVar2 = iVar6 == 1;
          }
          if (param_2 == (int *)0x0) {
            bVar2 = false;
          }
          if (bVar2) {
            iVar6 = json_array_size(param_2);
            if (iVar3 != iVar6) {
              iVar6 = json_array_size(param_2);
              set_error(param_1,"<validation>","%li array item(s) left unpacked",iVar6 - iVar3);
              return 0xffffffff;
            }
            return 0;
          }
          return 0;
        }
        if (iVar6 != 0) {
          if (iVar6 == 1) {
            uVar5 = 0x21;
          }
          else {
            uVar5 = 0x2a;
          }
          set_error(param_1,"<format>","Expected \']\' after \'%c\', got \'%c\'",uVar5,uVar10);
          return 0xffffffff;
        }
        if (uVar10 == 0) {
          set_error(param_1,"<format>","Unexpected end of format string");
          return 0xffffffff;
        }
        if (uVar10 != 0x2a && uVar10 != 0x21) break;
        if (uVar10 == 0x21) {
          iVar6 = 1;
        }
        else {
          iVar6 = -1;
        }
        next_token(param_1);
        bVar1 = *(byte *)(param_1 + 0x24);
      }
      pcVar4 = strchr(unpack_value_starters,uVar10);
      if (pcVar4 == (char *)0x0) break;
      if (param_2 == (int *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = json_array_get(param_2,iVar3);
        if (iVar6 == 0) {
          set_error(param_1,"<validation>","Array index %lu out of range",iVar3);
          return 0xffffffff;
        }
      }
      iVar6 = unpack(param_1,iVar6,param_3);
      if (iVar6 != 0) {
        return 0xffffffff;
      }
      iVar3 = iVar3 + 1;
      next_token(param_1);
    }
LAB_00051328:
    set_error(param_1,"<format>","Unexpected format character \'%c\'",uVar10);
    return 0xffffffff;
  case 0x62:
    if (param_2 != (int *)0x0) {
      iVar3 = *param_2;
      if (1 < iVar3 - 5U) {
        set_error(param_1,"<validation>","Expected true or false, got %s",
                  *(undefined4 *)(&type_names + iVar3 * 4));
        return 0xffffffff;
      }
      if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
        puVar11 = (undefined4 *)*param_3;
        *param_3 = (int)(puVar11 + 1);
        *(uint *)*puVar11 = (uint)(iVar3 == 5);
        return 0;
      }
      return 0;
    }
    break;
  case 0x66:
    if (param_2 != (int *)0x0) {
      if (*param_2 != 4) {
        set_error(param_1,"<validation>","Expected real, got %s",
                  *(undefined4 *)(&type_names + *param_2 * 4));
        return 0xffffffff;
      }
      if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
        puVar11 = (undefined4 *)*param_3;
        *param_3 = (int)(puVar11 + 1);
        puVar14 = (undefined8 *)*puVar11;
        uVar5 = json_real_value(param_2);
        *puVar14 = CONCAT44(extraout_s1_00,uVar5);
        return 0;
      }
      return 0;
    }
    break;
  case 0x69:
    if (param_2 != (int *)0x0) {
      iVar3 = *param_2;
      if (iVar3 == 3) {
        if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
          puVar11 = (undefined4 *)*param_3;
          *param_3 = (int)(puVar11 + 1);
          puVar11 = (undefined4 *)*puVar11;
          uVar5 = json_integer_value(param_2);
          *puVar11 = uVar5;
          return 0;
        }
        return 0;
      }
      goto LAB_00051550;
    }
    break;
  case 0x6e:
    if (param_2 == (int *)0x0) {
      return 0;
    }
    if (*param_2 != 7) {
      set_error(param_1,"<validation>","Expected null, got %s",
                *(undefined4 *)(&type_names + *param_2 * 4));
      return 0xffffffff;
    }
    return 0;
  case 0x73:
    if ((param_2 != (int *)0x0) && (*param_2 != 2)) {
      set_error(param_1,"<validation>","Expected string, got %s",
                *(undefined4 *)(&type_names + *param_2 * 4));
      return 0xffffffff;
    }
    if ((*(uint *)(param_1 + 0x3c) & 1) != 0) {
      return 0;
    }
    puVar11 = (undefined4 *)*param_3;
    *param_3 = (int)(puVar11 + 1);
    puVar11 = (undefined4 *)*puVar11;
    if (puVar11 == (undefined4 *)0x0) {
      set_error(param_1,"<args>","NULL string argument");
      return 0xffffffff;
    }
    next_token(param_1);
    if (*(char *)(param_1 + 0x24) != '%') {
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x14);
      if (param_2 != (int *)0x0) {
        uVar5 = json_string_value(param_2);
        *puVar11 = uVar5;
        return 0;
      }
      return 0;
    }
    puVar13 = (undefined4 *)*param_3;
    *param_3 = (int)(puVar13 + 1);
    puVar13 = (undefined4 *)*puVar13;
    if (puVar13 != (undefined4 *)0x0) {
      if (param_2 != (int *)0x0) {
        uVar5 = json_string_value(param_2);
        *puVar11 = uVar5;
        uVar5 = json_string_length(param_2);
        *puVar13 = uVar5;
        return 0;
      }
      return 0;
    }
    set_error(param_1,"<args>","NULL string length argument");
    return 0xffffffff;
  case 0x7b:
    iVar3 = hashtable_init(local_3c);
    if (iVar3 != 0) {
      set_error(param_1,"<internal>","Out of memory");
      return 0xffffffff;
    }
    if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
      set_error(param_1,"<validation>","Expected object, got %s",
                *(undefined4 *)(&type_names + *param_2 * 4));
      uVar10 = 0xffffffff;
      goto LAB_0005140c;
    }
    bVar2 = false;
    iVar3 = 0;
    next_token(param_1);
    while (cVar9 = *(char *)(param_1 + 0x24), cVar9 != '}') {
      while( true ) {
        if (iVar3 != 0) {
          if (iVar3 == 1) {
            uVar5 = 0x21;
          }
          else {
            uVar5 = 0x2a;
          }
          uVar10 = 0xffffffff;
          set_error(param_1,"<format>","Expected \'}\' after \'%c\', got \'%c\'",uVar5,cVar9);
          goto LAB_0005140c;
        }
        if (cVar9 == '\0') {
          uVar10 = 0xffffffff;
          set_error(param_1,"<format>","Unexpected end of format string");
          goto LAB_0005140c;
        }
        if (cVar9 != '*' && cVar9 != '!') break;
        if (cVar9 == '!') {
          iVar3 = 1;
        }
        else {
          iVar3 = -1;
        }
        next_token(param_1);
        cVar9 = *(char *)(param_1 + 0x24);
        if (cVar9 == '}') goto LAB_0005109a;
      }
      if (cVar9 != 's') {
        uVar10 = 0xffffffff;
        set_error(param_1,"<format>","Expected format \'s\', got \'%c\'");
        goto LAB_0005140c;
      }
      piVar12 = (int *)*param_3;
      *param_3 = (int)(piVar12 + 1);
      iVar6 = *piVar12;
      if (iVar6 == 0) {
        uVar10 = 0xffffffff;
        set_error(param_1,"<args>","NULL object key");
        goto LAB_0005140c;
      }
      next_token(param_1);
      bVar15 = *(char *)(param_1 + 0x24) != '?';
      if (!bVar15) {
        bVar2 = true;
        next_token(param_1);
      }
      if (param_2 == (int *)0x0) {
        iVar8 = 0;
      }
      else {
        iVar8 = json_object_get(param_2,iVar6);
        if (iVar8 == 0 && bVar15) {
          set_error(param_1,"<validation>","Object item not found: %s",iVar6);
          uVar10 = 0xffffffff;
          goto LAB_0005140c;
        }
      }
      iVar8 = unpack(param_1,iVar8,param_3);
      if (iVar8 != 0) {
        uVar10 = 0xffffffff;
        goto LAB_0005140c;
      }
      uVar5 = json_null();
      hashtable_set(local_3c,iVar6,uVar5);
      next_token(param_1);
    }
LAB_0005109a:
    if (iVar3 == 0) {
      uVar10 = 0;
      if (-1 < *(int *)(param_1 + 0x3c) << 0x1e) goto LAB_0005140c;
      uVar10 = 1;
    }
    else {
      uVar10 = (uint)(iVar3 == 1);
    }
    if (param_2 == (int *)0x0) {
      uVar10 = 0;
    }
    if (uVar10 == 0) goto LAB_0005140c;
    if (bVar2) {
      json_object_iter();
      bVar2 = false;
      pcVar4 = (char *)json_object_iter_key();
      iVar3 = 0;
      if (pcVar4 != (char *)0x0) {
        do {
          json_object_key_to_iter(pcVar4);
          iVar6 = json_object_iter_value();
          if (iVar6 == 0) break;
          iVar6 = hashtable_get(local_3c,pcVar4);
          if (iVar6 == 0) {
            iVar3 = iVar3 + 1;
            if (bVar2) {
              strbuffer_append_bytes(auStack_48,&DAT_00069de8,2);
            }
            else {
              strbuffer_init(auStack_48);
            }
            bVar2 = true;
            sVar7 = strlen(pcVar4);
            strbuffer_append_bytes(auStack_48,pcVar4,sVar7);
          }
          uVar5 = json_object_key_to_iter(pcVar4);
          json_object_iter_next(param_2,uVar5);
          pcVar4 = (char *)json_object_iter_key();
        } while (pcVar4 != (char *)0x0);
        if (iVar3 != 0) goto LAB_00051662;
      }
    }
    else {
      iVar3 = json_object_size(param_2);
      iVar3 = iVar3 - local_3c[0];
      if (iVar3 != 0) {
        json_object_iter(param_2);
        pcVar4 = (char *)json_object_iter_key();
        if (pcVar4 != (char *)0x0) {
          do {
            json_object_key_to_iter(pcVar4);
            iVar6 = json_object_iter_value();
            if (iVar6 == 0) break;
            iVar6 = hashtable_get(local_3c,pcVar4);
            if (iVar6 == 0) {
              if (bVar2) {
                strbuffer_append_bytes(auStack_48,&DAT_00069de8,2);
              }
              else {
                strbuffer_init(auStack_48);
              }
              bVar2 = true;
              sVar7 = strlen(pcVar4);
              strbuffer_append_bytes(auStack_48,pcVar4,sVar7);
            }
            uVar5 = json_object_key_to_iter(pcVar4);
            json_object_iter_next(param_2,uVar5);
            pcVar4 = (char *)json_object_iter_key();
          } while (pcVar4 != (char *)0x0);
        }
LAB_00051662:
        uVar10 = 0xffffffff;
        uVar5 = strbuffer_value(auStack_48);
        set_error(param_1,"<validation>","%li object item(s) left unpacked: %s",iVar3,uVar5);
        strbuffer_close(auStack_48);
        goto LAB_0005140c;
      }
    }
    uVar10 = 0;
LAB_0005140c:
    hashtable_close(local_3c);
    return uVar10;
  }
  if (-1 < *(int *)(param_1 + 0x3c) << 0x1f) {
    *param_3 = *param_3 + 4;
  }
  return 0;
}


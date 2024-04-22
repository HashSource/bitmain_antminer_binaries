
void lex_scan_string(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  size_t local_28;
  undefined auStack_24 [4];
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  byte *local_10;
  int local_c;
  
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  local_c = lex_get_save(param_1,param_2);
  while (local_c != 0x22) {
    if (local_c == -2) goto LAB_00024c8e;
    if (local_c == -1) {
      error_set(param_2,param_1,"premature end of input");
      goto LAB_00024c8e;
    }
    if ((-1 < local_c) && (local_c < 0x20)) {
      lex_unget_unsave(param_1,local_c);
      if (local_c == 10) {
        error_set(param_2,param_1,"unexpected newline",10);
      }
      else {
        error_set(param_2,param_1,"control character 0x%x",local_c);
      }
      goto LAB_00024c8e;
    }
    if (local_c == 0x5c) {
      local_c = lex_get_save(param_1,param_2);
      if (local_c == 0x75) {
        local_c = lex_get_save(param_1,param_2);
        for (local_18 = 0; local_18 < 4; local_18 = local_18 + 1) {
          if ((((local_c < 0x30) || (0x39 < local_c)) && ((local_c < 0x41 || (0x46 < local_c)))) &&
             ((local_c < 0x61 || (0x66 < local_c)))) {
            error_set(param_2,param_1,"invalid escape");
            goto LAB_00024c8e;
          }
          local_c = lex_get_save(param_1,param_2);
        }
      }
      else {
        if (((((local_c != 0x22) && (local_c != 0x5c)) && (local_c != 0x2f)) &&
            ((local_c != 0x62 && (local_c != 0x66)))) &&
           ((local_c != 0x6e && ((local_c != 0x72 && (local_c != 0x74)))))) {
          error_set(param_2,param_1,"invalid escape");
          goto LAB_00024c8e;
        }
        local_c = lex_get_save(param_1,param_2);
      }
    }
    else {
      local_c = lex_get_save(param_1,param_2);
    }
  }
  uVar2 = jsonp_malloc(*(int *)(param_1 + 0x2c) + 1);
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  if (*(int *)(param_1 + 0x38) == 0) {
LAB_00024c8e:
    jsonp_free(*(undefined4 *)(param_1 + 0x38));
  }
  else {
    local_14 = *(byte **)(param_1 + 0x38);
    iVar3 = strbuffer_value(param_1 + 0x28);
    local_10 = (byte *)(iVar3 + 1);
    while (*local_10 != 0x22) {
      if (*local_10 == 0x5c) {
        pbVar4 = local_10 + 1;
        if (*pbVar4 == 0x75) {
          local_10 = pbVar4;
          local_1c = decode_unicode_escape(pbVar4);
          pbVar4 = local_10 + 5;
          if ((local_1c < 0xd800) || (0xdbff < local_1c)) {
            if ((0xdbff < local_1c) && (local_1c < 0xe000)) {
              local_10 = pbVar4;
              error_set(param_2,param_1,"invalid Unicode \'\\u%04X\'",local_1c);
              goto LAB_00024c8e;
            }
            local_10 = pbVar4;
            if (local_1c == 0) {
              error_set(param_2,param_1,"\\u0000 is not allowed");
              goto LAB_00024c8e;
            }
          }
          else {
            if ((*pbVar4 != 0x5c) || (local_10[6] != 0x75)) {
              local_10 = pbVar4;
              error_set(param_2,param_1,"invalid Unicode \'\\u%04X\'",local_1c);
              goto LAB_00024c8e;
            }
            local_10 = local_10 + 6;
            local_20 = decode_unicode_escape(local_10);
            local_10 = local_10 + 5;
            if ((local_20 < 0xdc00) || (0xdfff < local_20)) {
              error_set(param_2,param_1,"invalid Unicode \'\\u%04X\\u%04X\'",local_1c,local_20);
              goto LAB_00024c8e;
            }
            local_1c = (local_1c + -0xd800) * 0x400 + local_20 + 0x2400;
          }
          iVar3 = utf8_encode(local_1c,auStack_24,&local_28);
          if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("0","3rdparty/jansson-2.6/src/load.c",0x1ae,"lex_scan_string");
          }
          memcpy(local_14,auStack_24,local_28);
          local_14 = local_14 + local_28;
        }
        else {
          bVar1 = *pbVar4;
          if (bVar1 == 0x66) {
            *local_14 = 0xc;
          }
          else if (bVar1 < 0x67) {
            if (bVar1 != 0x5c) {
              if (0x5c < bVar1) {
                if (bVar1 != 0x62) goto LAB_00024c2c;
                *local_14 = 8;
                goto LAB_00024c4c;
              }
              if ((bVar1 != 0x22) && (bVar1 != 0x2f)) {
LAB_00024c2c:
                local_10 = pbVar4;
                    /* WARNING: Subroutine does not return */
                __assert_fail("0","3rdparty/jansson-2.6/src/load.c",0x1bc,"lex_scan_string");
              }
            }
            *local_14 = *pbVar4;
          }
          else if (bVar1 == 0x72) {
            *local_14 = 0xd;
          }
          else if (bVar1 == 0x74) {
            *local_14 = 9;
          }
          else {
            if (bVar1 != 0x6e) goto LAB_00024c2c;
            *local_14 = 10;
          }
LAB_00024c4c:
          local_14 = local_14 + 1;
          local_10 = local_10 + 2;
        }
      }
      else {
        *local_14 = *local_10;
        local_14 = local_14 + 1;
        local_10 = local_10 + 1;
      }
    }
    *local_14 = 0;
    *(undefined4 *)(param_1 + 0x34) = 0x100;
  }
  return;
}


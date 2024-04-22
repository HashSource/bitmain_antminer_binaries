
uint lex_scan(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  longlong lVar13;
  char *local_30;
  undefined4 uStack_2c;
  
  iVar9 = param_1 + 0x28;
  strbuffer_clear(iVar9);
  if (*(int *)(param_1 + 0x3c) == 0x100) {
    jsonp_free(*(undefined4 *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  do {
    uVar8 = *(uint *)(param_1 + 0x14);
    if (uVar8 == 0) {
      uVar8 = stream_get_part_3(param_1,param_2);
    }
    bVar11 = 0x1f < uVar8;
    if (uVar8 != 0x20) {
      bVar11 = uVar8 != 9;
    }
  } while ((!bVar11 || (uVar8 == 0x20 || uVar8 == 10)) || (uVar2 = 0, uVar8 == 0xd));
  if (uVar8 != 0xffffffff) {
    if (uVar8 != 0xfffffffe) {
      strbuffer_append_byte(iVar9,uVar8 & 0xff);
      if ((((uVar8 & 0xffffffdf) - 0x5b & 0xfffffffd) == 0) || (uVar8 == 0x2c || uVar8 == 0x3a)) {
LAB_00050180:
        *(uint *)(param_1 + 0x3c) = uVar8;
        return uVar8;
      }
      if (uVar8 == 0x22) {
        *(undefined4 *)(param_1 + 0x40) = 0;
        *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
LAB_000501e8:
        do {
          uVar8 = lex_get_save(param_1,param_2);
          while( true ) {
            if (uVar8 == 0x22) {
              pbVar5 = (byte *)jsonp_malloc(*(int *)(param_1 + 0x2c) + 1);
              if (pbVar5 == (byte *)0x0) goto LAB_00050244;
              *(byte **)(param_1 + 0x40) = pbVar5;
              iVar9 = strbuffer_value(iVar9);
              pbVar10 = (byte *)(iVar9 + 1);
              goto LAB_0005032e;
            }
            if (uVar8 == 0xfffffffe) goto LAB_00050244;
            if (uVar8 == 0xffffffff) {
              error_set(param_2,param_1,"premature end of input");
              goto LAB_00050244;
            }
            if (uVar8 < 0x20) {
              lex_unget_unsave(param_1,uVar8);
              error_set(param_2,param_1);
              goto LAB_00050244;
            }
            if (uVar8 != 0x5c) goto LAB_000501e8;
            uVar8 = lex_get_save(param_1,param_2);
            if (uVar8 != 0x75) break;
            uVar8 = lex_get_save(param_1,param_2);
            iVar7 = 4;
            do {
              uVar2 = (uVar8 & 0xffffffdf) - 0x41;
              bVar12 = 4 < uVar2;
              bVar11 = uVar2 == 5;
              if (5 < uVar2) {
                bVar12 = 8 < uVar8 - 0x30;
                bVar11 = uVar8 - 0x30 == 9;
              }
              if (bVar12 && !bVar11) goto LAB_00050234;
              uVar8 = lex_get_save(param_1,param_2);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        } while (((uVar8 == 0x5c || (uVar8 & 0xffffffbf) == 0x22) || (uVar8 == 0x2f)) ||
                (((uVar8 & 0xfffffff7) == 0x66 || ((uVar8 - 0x72 & 0xfffffffd) == 0))));
LAB_00050234:
        error_set(param_2,param_1,"invalid escape");
LAB_00050244:
        jsonp_free(*(undefined4 *)(param_1 + 0x40));
        *(undefined4 *)(param_1 + 0x40) = 0;
        *(undefined4 *)(param_1 + 0x44) = 0;
        return *(uint *)(param_1 + 0x3c);
      }
      bVar11 = 0x2c < uVar8;
      if (uVar8 != 0x2d) {
        bVar11 = 8 < uVar8 - 0x30;
      }
      if (!bVar11 || (uVar8 == 0x2d || uVar8 - 0x30 == 9)) {
        *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
        if (uVar8 == 0x2d) {
          uVar8 = lex_get_save(param_1,param_2);
        }
        if (uVar8 == 0x30) {
          uVar8 = lex_get_save(param_1,param_2);
          if (uVar8 - 0x30 < 10) goto LAB_000502f6;
        }
        else {
          if (9 < uVar8 - 0x30) {
            lex_unget_unsave(param_1,uVar8);
            return *(uint *)(param_1 + 0x3c);
          }
          do {
            uVar8 = lex_get_save(param_1,param_2);
          } while (uVar8 - 0x30 < 10);
        }
        if (((*(uint *)(param_1 + 0x34) & 8) == 0) && (uVar8 != 0x2e && uVar8 != 0x45)) {
          if (uVar8 != 0x65) {
            lex_unget_unsave(param_1,uVar8);
            pcVar3 = (char *)strbuffer_value(iVar9);
            piVar4 = __errno_location();
            *piVar4 = 0;
            lVar13 = strtoll(pcVar3,&local_30,10);
            if (*piVar4 == 0x22) {
              error_set(param_2,param_1);
              return *(uint *)(param_1 + 0x3c);
            }
            if (local_30 != pcVar3 + *(int *)(param_1 + 0x2c)) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("end == saved_text + lex->saved_text.length",
                            "compat/jansson-2.9/src/load.c",0x249,DAT_00050550);
            }
            uVar8 = 0x101;
            *(longlong *)(param_1 + 0x40) = lVar13;
            goto LAB_00050180;
          }
        }
        else {
          if (uVar8 == 0x2e) {
            uVar8 = *(uint *)(param_1 + 0x14);
            if (uVar8 == 0) {
              uVar8 = stream_get_part_3(param_1,param_2);
            }
            if (9 < uVar8 - 0x30) {
              stream_unget(param_1);
              return *(uint *)(param_1 + 0x3c);
            }
            strbuffer_append_byte(iVar9,uVar8 & 0xff);
            do {
              uVar8 = lex_get_save(param_1,param_2);
            } while (uVar8 - 0x30 < 10);
          }
          if ((uVar8 & 0xffffffdf) != 0x45) goto LAB_000501ae;
        }
        uVar8 = lex_get_save(param_1,param_2);
        if ((uVar8 - 0x2b & 0xfffffffd) == 0) {
          uVar8 = lex_get_save(param_1,param_2);
        }
        if (9 < uVar8 - 0x30) {
LAB_000502f6:
          lex_unget_unsave(param_1,uVar8);
          return *(uint *)(param_1 + 0x3c);
        }
        do {
          uVar8 = lex_get_save(param_1,param_2);
        } while (uVar8 - 0x30 < 10);
LAB_000501ae:
        lex_unget_unsave(param_1,uVar8);
        iVar9 = jsonp_strtod(iVar9,&local_30);
        if (iVar9 == 0) {
          *(undefined4 *)(param_1 + 0x3c) = 0x102;
          *(char **)(param_1 + 0x40) = local_30;
          *(undefined4 *)(param_1 + 0x44) = uStack_2c;
          return 0x102;
        }
        error_set(param_2,param_1,"real number overflow");
        return *(uint *)(param_1 + 0x3c);
      }
      if ((uVar8 & 0xffffffdf) - 0x41 < 0x1a) {
        do {
          uVar8 = lex_get_save(param_1,param_2);
        } while ((uVar8 & 0xffffffdf) - 0x41 < 0x1a);
        lex_unget_unsave(param_1,uVar8);
        pcVar3 = (char *)strbuffer_value(iVar9);
        iVar9 = strcmp(pcVar3,"true");
        if (iVar9 == 0) {
          *(undefined4 *)(param_1 + 0x3c) = 0x103;
          return 0x103;
        }
        iVar9 = strcmp(pcVar3,"false");
        if (iVar9 == 0) {
          *(undefined4 *)(param_1 + 0x3c) = 0x104;
          return 0x104;
        }
        iVar9 = strcmp(pcVar3,"null");
        if (iVar9 == 0) {
          *(undefined4 *)(param_1 + 0x3c) = 0x105;
          return 0x105;
        }
      }
      else {
        cVar1 = *(char *)(*(int *)(param_1 + 0x10) + param_1 + 8);
        while (cVar1 != '\0') {
          strbuffer_append_byte(iVar9);
          iVar7 = *(int *)(param_1 + 0x10) + 1;
          *(int *)(param_1 + 0x10) = iVar7;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          cVar1 = *(char *)(param_1 + iVar7 + 8);
        }
      }
    }
    uVar2 = 0xffffffff;
  }
  *(uint *)(param_1 + 0x3c) = uVar2;
  return uVar2;
LAB_0005032e:
  while( true ) {
    bVar6 = *pbVar10;
    if (bVar6 == 0x22) {
      *pbVar5 = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0x100;
      *(int *)(param_1 + 0x44) = (int)pbVar5 - *(int *)(param_1 + 0x40);
      return 0x100;
    }
    if (bVar6 == 0x5c) break;
    *pbVar5 = bVar6;
    pbVar10 = pbVar10 + 1;
    pbVar5 = pbVar5 + 1;
  }
  bVar6 = pbVar10[1];
  if (bVar6 == 0x75) {
    iVar9 = decode_unicode_escape(pbVar10 + 1);
    if (iVar9 < 0) {
      error_set(param_2,param_1,"invalid Unicode escape \'%.6s\'",pbVar10);
      goto LAB_00050244;
    }
    if (iVar9 - 0xd800U < 0x400) {
      if ((pbVar10[6] != 0x5c) || (pbVar10[7] != 0x75)) {
LAB_0005049c:
        error_set(param_2,param_1,"invalid Unicode \'\\u%04X\'",iVar9);
        goto LAB_00050244;
      }
      iVar7 = decode_unicode_escape(pbVar10 + 7);
      if (iVar7 < 0) {
        error_set(param_2,param_1,"invalid Unicode escape \'%.6s\'",pbVar10 + 6);
        goto LAB_00050244;
      }
      if (0x3ff < iVar7 - 0xdc00U) {
        error_set(param_2,param_1,"invalid Unicode \'\\u%04X\\u%04X\'",iVar9,iVar7);
        goto LAB_00050244;
      }
      iVar9 = (iVar7 - 0xdc00U) + (iVar9 - 0xd800U) * 0x400 + 0x10000;
      pbVar10 = pbVar10 + 0xc;
    }
    else {
      pbVar10 = pbVar10 + 6;
      if (iVar9 - 0xdc00U < 0x400) goto LAB_0005049c;
    }
    iVar9 = utf8_encode(iVar9,pbVar5,&local_30);
    if (iVar9 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("0","compat/jansson-2.9/src/load.c",0x1db,DAT_0005054c);
    }
    pbVar5 = pbVar5 + (int)local_30;
    goto LAB_0005032e;
  }
  if (bVar6 == 0x62) {
    *pbVar5 = 8;
  }
  else if (bVar6 < 99) {
    if (((bVar6 != 0x2f) && (bVar6 != 0x5c)) && (bVar6 != 0x22)) goto LAB_000503c8;
LAB_00050444:
    *pbVar5 = bVar6;
  }
  else if (bVar6 == 0x6e) {
    *pbVar5 = 10;
  }
  else if (bVar6 < 0x6f) {
    if (bVar6 != 0x66) {
LAB_000503c8:
                    /* WARNING: Subroutine does not return */
      __assert_fail("0","compat/jansson-2.9/src/load.c",0x1f7,DAT_0005054c);
    }
    *pbVar5 = 0xc;
  }
  else {
    if (bVar6 == 0x72) {
      bVar6 = 0xd;
      goto LAB_00050444;
    }
    if (bVar6 != 0x74) goto LAB_000503c8;
    *pbVar5 = 9;
  }
  pbVar5 = pbVar5 + 1;
  pbVar10 = pbVar10 + 2;
  goto LAB_0005032e;
}


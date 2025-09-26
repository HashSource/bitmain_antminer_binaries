
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int lex_scan(lex_t *lex,json_error_t *error)

{
  char byte;
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  byte *buffer;
  int32_t codepoint;
  int32_t iVar5;
  uint uVar6;
  byte bVar7;
  size_t sVar8;
  byte *pbVar9;
  strbuffer_t *strbuff;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  longlong lVar13;
  size_t local_38;
  char *local_34;
  anon_union_8_3_477c3ef1_for_value local_30;
  
  strbuff = &lex->saved_text;
  strbuffer_clear(strbuff);
  if (lex->token == 0x100) {
    jsonp_free((lex->value).string.val);
    (lex->value).string.val = (char *)0x0;
    (lex->value).string.len = 0;
  }
  do {
    uVar1 = (lex->stream).state;
    if (uVar1 == 0) {
      uVar1 = stream_get(&lex->stream,error);
    }
  } while ((uVar1 == 0x20 || uVar1 == 9) || (uVar1 == 10 || uVar1 == 0xd));
  if (uVar1 == 0xffffffff) {
    lex->token = 0;
    return 0;
  }
  if (uVar1 != 0xfffffffe) {
    strbuffer_append_byte(strbuff,(char)uVar1);
    if (((uVar1 == 0x7b || uVar1 == 0x7d) || (uVar1 == 0x5b || uVar1 == 0x5d)) ||
       (uVar1 == 0x3a || uVar1 == 0x2c)) goto LAB_000dbba4;
    if (uVar1 == 0x22) {
      (lex->value).string.val = (char *)0x0;
      lex->token = -1;
      uVar1 = lex_get_save(lex,error);
      while (uVar1 != 0x22) {
        if (uVar1 == 0xfffffffe) goto LAB_000dbd1c;
        if (uVar1 == 0xffffffff) {
          error_set(error,lex,json_error_premature_end_of_input,"premature end of input");
          goto LAB_000dbd1c;
        }
        if (uVar1 < 0x20) {
          lex_unget_unsave(lex,uVar1);
          if (uVar1 == 10) {
            error_set(error,lex,json_error_invalid_syntax,"unexpected newline");
          }
          else {
            error_set(error,lex,json_error_invalid_syntax,"control character 0x%x",uVar1);
          }
          goto LAB_000dbd1c;
        }
        if (uVar1 == 0x5c) {
          uVar1 = lex_get_save(lex,error);
          if (uVar1 == 0x75) {
            iVar3 = 4;
            uVar1 = lex_get_save(lex,error);
            do {
              uVar6 = uVar1 - 0x41;
              bVar12 = 4 < uVar6;
              bVar11 = uVar6 == 5;
              if (5 < uVar6) {
                bVar12 = 8 < uVar1 - 0x30;
                bVar11 = uVar1 - 0x30 == 9;
              }
              if ((bVar12 && !bVar11) && (5 < uVar1 - 0x61)) goto LAB_000dbf88;
              uVar1 = lex_get_save(lex,error);
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          else {
            if (((uVar1 != 0x22 && uVar1 != 0x5c) && (uVar1 != 0x2f && uVar1 != 0x62)) &&
               (((uVar1 & 0xfffffff7) != 0x66 && (uVar1 != 0x72 && uVar1 != 0x74)))) {
LAB_000dbf88:
              error_set(error,lex,json_error_invalid_syntax,"invalid escape");
              goto LAB_000dbd1c;
            }
            uVar1 = lex_get_save(lex,error);
          }
        }
        else {
          uVar1 = lex_get_save(lex,error);
        }
      }
      buffer = (byte *)jsonp_malloc((lex->saved_text).length + 1);
      if (buffer == (byte *)0x0) {
LAB_000dbd1c:
        jsonp_free((lex->value).string.val);
        uVar1 = lex->token;
        (lex->value).string.val = (char *)0x0;
        (lex->value).string.len = 0;
        return uVar1;
      }
      (lex->value).string.val = (char *)buffer;
      pcVar2 = strbuffer_value(strbuff);
      pbVar10 = (byte *)(pcVar2 + 1);
      do {
        while( true ) {
          while( true ) {
            bVar7 = *pbVar10;
            if (bVar7 == 0x22) {
              *buffer = 0;
              pcVar2 = (lex->value).string.val;
              lex->token = 0x100;
              (lex->value).string.len = (int)buffer - (int)pcVar2;
              return 0x100;
            }
            if (bVar7 == 0x5c) break;
            *buffer = bVar7;
            buffer = buffer + 1;
            pbVar10 = pbVar10 + 1;
          }
          bVar7 = pbVar10[1];
          if (bVar7 == 0x75) break;
          if (bVar7 == 0x66) {
            *buffer = 0xc;
          }
          else if (bVar7 < 0x67) {
            if (bVar7 != 0x5c) {
              if (0x5c < bVar7) {
                if (bVar7 != 0x62) goto LAB_000dbe06;
                *buffer = 8;
                goto LAB_000dbe52;
              }
              if ((bVar7 != 0x22) && (bVar7 != 0x2f)) {
LAB_000dbe06:
                    /* WARNING: Subroutine does not return */
                __assert_fail("0","load.c",0x1ba,"lex_scan_string");
              }
            }
LAB_000dbe50:
            *buffer = bVar7;
          }
          else if (bVar7 == 0x72) {
            *buffer = 0xd;
          }
          else {
            if (bVar7 != 0x74) {
              if (bVar7 != 0x6e) goto LAB_000dbe06;
              bVar7 = 10;
              goto LAB_000dbe50;
            }
            *buffer = 9;
          }
LAB_000dbe52:
          buffer = buffer + 1;
          pbVar10 = pbVar10 + 2;
        }
        codepoint = decode_unicode_escape((char *)(pbVar10 + 1));
        pbVar9 = pbVar10;
        if (codepoint < 0) {
LAB_000dbfb8:
          error_set(error,lex,json_error_invalid_syntax,"invalid Unicode escape \'%.6s\'",pbVar9);
          goto LAB_000dbd1c;
        }
        pbVar9 = pbVar10 + 6;
        if (codepoint - 0xd800U < 0x400) {
          if ((pbVar10[6] != 0x5c) || (pbVar10[7] != 0x75)) {
LAB_000dbfd0:
            error_set(error,lex,json_error_invalid_syntax,"invalid Unicode \'\\u%04X\'",codepoint);
            goto LAB_000dbd1c;
          }
          iVar5 = decode_unicode_escape((char *)(pbVar10 + 7));
          if (iVar5 < 0) goto LAB_000dbfb8;
          pbVar9 = pbVar10 + 0xc;
          if (0x3ff < iVar5 - 0xdc00U) {
            error_set(error,lex,json_error_invalid_syntax,"invalid Unicode \'\\u%04X\\u%04X\'",
                      codepoint,iVar5);
            goto LAB_000dbd1c;
          }
          codepoint = (iVar5 - 0xdc00U) + (codepoint - 0xd800U) * 0x400 + 0x10000;
        }
        else if (codepoint - 0xdc00U < 0x400) goto LAB_000dbfd0;
        iVar3 = utf8_encode(codepoint,(char *)buffer,&local_38);
        if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("0","load.c",0x1a1,"lex_scan_string");
        }
        buffer = buffer + local_38;
        pbVar10 = pbVar9;
      } while( true );
    }
    bVar11 = 0x2c < uVar1;
    if (uVar1 != 0x2d) {
      bVar11 = 8 < uVar1 - 0x30;
    }
    if (!bVar11 || (uVar1 == 0x2d || uVar1 - 0x30 == 9)) {
      lex->token = -1;
      if (uVar1 == 0x2d) {
        uVar1 = lex_get_save(lex,error);
      }
      if (uVar1 == 0x30) {
        uVar1 = lex_get_save(lex,error);
        if (uVar1 - 0x30 < 10) goto LAB_000dbe30;
      }
      else {
        if (9 < uVar1 - 0x30) {
          lex_unget_unsave(lex,uVar1);
          return lex->token;
        }
        do {
          uVar1 = lex_get_save(lex,error);
        } while (uVar1 - 0x30 < 10);
      }
      if (((lex->flags & 8) == 0) && (uVar1 != 0x45 && uVar1 != 0x2e)) {
        if (uVar1 != 0x65) {
          lex_unget_unsave(lex,uVar1);
          pcVar2 = strbuffer_value(strbuff);
          piVar4 = __errno_location();
          *piVar4 = 0;
          lVar13 = strtoll(pcVar2,&local_34,10);
          if (*piVar4 == 0x22) {
            if (lVar13 < 0) {
              pcVar2 = "too big negative integer";
            }
            else {
              pcVar2 = "too big integer";
            }
            error_set(error,lex,json_error_numeric_overflow,pcVar2);
            return lex->token;
          }
          if (local_34 == pcVar2 + (lex->saved_text).length) {
            (lex->value).integer = lVar13;
            lex->token = 0x101;
            return 0x101;
          }
                    /* WARNING: Subroutine does not return */
          __assert_fail("end == saved_text + lex->saved_text.length","load.c",0x202,
                        "lex_scan_number");
        }
      }
      else {
        if (uVar1 == 0x2e) {
          iVar3 = (lex->stream).state;
          if (iVar3 == 0) {
            iVar3 = stream_get(&lex->stream,error);
          }
          if (9 < iVar3 - 0x30U) {
            stream_unget(&lex->stream,iVar3);
            return lex->token;
          }
          strbuffer_append_byte(strbuff,(char)iVar3);
          do {
            uVar1 = lex_get_save(lex,error);
          } while (uVar1 - 0x30 < 10);
        }
        if ((uVar1 & 0xffffffdf) != 0x45) goto LAB_000dbc56;
      }
      uVar1 = lex_get_save(lex,error);
      if (uVar1 == 0x2b || uVar1 == 0x2d) {
        uVar1 = lex_get_save(lex,error);
      }
      if (9 < uVar1 - 0x30) {
LAB_000dbe30:
        lex_unget_unsave(lex,uVar1);
        return lex->token;
      }
      do {
        uVar1 = lex_get_save(lex,error);
      } while (uVar1 - 0x30 < 10);
LAB_000dbc56:
      lex_unget_unsave(lex,uVar1);
      iVar3 = jsonp_strtod(strbuff,&local_30.real);
      if (iVar3 == 0) {
        lex->token = 0x102;
        lex->value = local_30;
        return 0x102;
      }
      error_set(error,lex,json_error_numeric_overflow,"real number overflow");
      return lex->token;
    }
    if ((uVar1 & 0xffffffdf) - 0x41 < 0x1a) {
      do {
        uVar1 = lex_get_save(lex,error);
      } while ((uVar1 & 0xffffffdf) - 0x41 < 0x1a);
      lex_unget_unsave(lex,uVar1);
      pcVar2 = strbuffer_value(strbuff);
      iVar3 = strcmp(pcVar2,"true");
      if (iVar3 == 0) {
        lex->token = 0x103;
        return 0x103;
      }
      iVar3 = strcmp(pcVar2,"false");
      if (iVar3 == 0) {
        lex->token = 0x104;
        return 0x104;
      }
      iVar3 = strcmp(pcVar2,"null");
      if (iVar3 == 0) {
        lex->token = 0x105;
        return 0x105;
      }
    }
    else {
      byte = (lex->stream).buffer[(lex->stream).buffer_pos];
      while (byte != '\0') {
        strbuffer_append_byte(strbuff,byte);
        sVar8 = (lex->stream).buffer_pos;
        byte = (lex->stream).buffer[sVar8 + 1];
        (lex->stream).buffer_pos = sVar8 + 1;
        (lex->stream).position = (lex->stream).position + 1;
      }
    }
  }
  uVar1 = 0xffffffff;
LAB_000dbba4:
  lex->token = uVar1;
  return uVar1;
}



/* WARNING: Unknown calling convention */

int lex_scan(lex_t *lex,json_error_t *error)

{
  char byte;
  byte bVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  byte *__dest;
  int32_t codepoint;
  byte *str;
  int32_t iVar6;
  uint uVar7;
  size_t sVar8;
  strbuffer_t *strbuff;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  longlong lVar12;
  char buffer [4];
  size_t local_38;
  char *local_34;
  anon_union_8_3_477c3ef1_for_value local_30;
  
  strbuff = &lex->saved_text;
  strbuffer_clear(strbuff);
  if (lex->token == 0x100) {
    _jsonp_free(&(lex->value).string);
    (lex->value).string = (char *)0x0;
  }
  do {
    do {
      uVar2 = stream_get(&lex->stream,error);
    } while (uVar2 == 0x20 || uVar2 == 9);
  } while (uVar2 == 10 || uVar2 == 0xd);
  if (uVar2 == 0xffffffff) {
    lex->token = 0;
    return 0;
  }
  if (uVar2 != 0xfffffffe) {
    strbuffer_append_byte(strbuff,(char)uVar2);
    if (((uVar2 == 0x7b || uVar2 == 0x7d) || (uVar2 == 0x5b || uVar2 == 0x5d)) ||
       (uVar2 == 0x3a || uVar2 == 0x2c)) goto LAB_0003cc4e;
    if (uVar2 == 0x22) {
      (lex->value).string = (char *)0x0;
      lex->token = -1;
LAB_0003cd48:
      do {
        uVar2 = lex_get_save(lex,error);
        while( true ) {
          if (uVar2 == 0x22) {
            __dest = (byte *)jsonp_malloc((lex->saved_text).length + 1);
            (lex->value).string = (char *)__dest;
            if (__dest == (byte *)0x0) goto LAB_0003cd9e;
            pcVar3 = strbuffer_value(strbuff);
            pbVar9 = (byte *)(pcVar3 + 1);
            goto LAB_0003cee2;
          }
          if (uVar2 == 0xfffffffe) goto LAB_0003cd9e;
          if (uVar2 == 0xffffffff) {
            error_set(error,lex,"premature end of input");
            goto LAB_0003cd9e;
          }
          if (uVar2 < 0x20) {
            lex_unget_unsave(lex,uVar2);
            if (uVar2 == 10) {
              pcVar3 = "unexpected newline";
            }
            else {
              pcVar3 = "control character 0x%x";
            }
            error_set(error,lex,pcVar3,uVar2);
            goto LAB_0003cd9e;
          }
          if (uVar2 != 0x5c) goto LAB_0003cd48;
          uVar2 = lex_get_save(lex,error);
          if (uVar2 != 0x75) break;
          uVar2 = lex_get_save(lex,error);
          iVar4 = 4;
          do {
            uVar7 = uVar2 - 0x41;
            bVar11 = 4 < uVar7;
            bVar10 = uVar7 == 5;
            if (5 < uVar7) {
              bVar11 = 8 < uVar2 - 0x30;
              bVar10 = uVar2 - 0x30 == 9;
            }
            if ((bVar11 && !bVar10) && (5 < uVar2 - 0x61)) goto LAB_0003cd94;
            uVar2 = lex_get_save(lex,error);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      } while ((((uVar2 == 0x22 || uVar2 == 0x5c) || (uVar2 == 0x2f || uVar2 == 0x62)) ||
               ((uVar2 & 0xfffffff7) == 0x66)) || (uVar2 == 0x72 || uVar2 == 0x74));
LAB_0003cd94:
      error_set(error,lex,"invalid escape");
LAB_0003cd9e:
      _jsonp_free(&(lex->value).string);
      return lex->token;
    }
    bVar10 = 0x2c < uVar2;
    if (uVar2 != 0x2d) {
      bVar10 = 8 < uVar2 - 0x30;
    }
    if (!bVar10 || (uVar2 == 0x2d || uVar2 - 0x30 == 9)) {
      lex->token = -1;
      if (uVar2 == 0x2d) {
        uVar2 = lex_get_save(lex,error);
      }
      if (uVar2 == 0x30) {
        uVar2 = lex_get_save(lex,error);
        if (uVar2 - 0x30 < 10) goto LAB_0003ce64;
      }
      else {
        if (9 < uVar2 - 0x30) {
          lex_unget_unsave(lex,uVar2);
          return lex->token;
        }
        do {
          uVar2 = lex_get_save(lex,error);
        } while (uVar2 - 0x30 < 10);
      }
      if (uVar2 == 0x45 || uVar2 == 0x2e) {
        if (uVar2 == 0x2e) {
          iVar4 = stream_get(&lex->stream,error);
          if (9 < iVar4 - 0x30U) {
            stream_unget(&lex->stream,iVar4);
            return lex->token;
          }
          strbuffer_append_byte(strbuff,(char)iVar4);
          do {
            uVar2 = lex_get_save(lex,error);
          } while (uVar2 - 0x30 < 10);
        }
        if ((uVar2 & 0xffffffdf) != 0x45) goto LAB_0003cdb8;
      }
      else if (uVar2 != 0x65) {
        lex_unget_unsave(lex,uVar2);
        pcVar3 = strbuffer_value(strbuff);
        piVar5 = __errno_location();
        *piVar5 = 0;
        lVar12 = strtoll(pcVar3,&local_34,10);
        if (*piVar5 == 0x22) {
          if (lVar12 < 0) {
            pcVar3 = "too big negative integer";
          }
          else {
            pcVar3 = "too big integer";
          }
          error_set(error,lex,pcVar3);
          return lex->token;
        }
        if (local_34 == pcVar3 + (lex->saved_text).length) {
          (lex->value).integer = lVar12;
          lex->token = 0x101;
          return 0x101;
        }
                    /* WARNING: Subroutine does not return */
        __assert_fail("end == saved_text + lex->saved_text.length","compat/jansson-2.6/src/load.c",
                      0x206,"lex_scan_number");
      }
      uVar2 = lex_get_save(lex,error);
      if (uVar2 == 0x2b || uVar2 == 0x2d) {
        uVar2 = lex_get_save(lex,error);
      }
      if (9 < uVar2 - 0x30) {
LAB_0003ce64:
        lex_unget_unsave(lex,uVar2);
        return lex->token;
      }
      do {
        uVar2 = lex_get_save(lex,error);
      } while (uVar2 - 0x30 < 10);
LAB_0003cdb8:
      lex_unget_unsave(lex,uVar2);
      iVar4 = jsonp_strtod(strbuff,&local_30.real);
      if (iVar4 == 0) {
        lex->token = 0x102;
        lex->value = local_30;
        return 0x102;
      }
      error_set(error,lex,"real number overflow");
      return lex->token;
    }
    if ((uVar2 & 0xffffffdf) - 0x41 < 0x1a) {
      do {
        uVar2 = lex_get_save(lex,error);
      } while ((uVar2 & 0xffffffdf) - 0x41 < 0x1a);
      lex_unget_unsave(lex,uVar2);
      pcVar3 = strbuffer_value(strbuff);
      iVar4 = strcmp(pcVar3,"true");
      if (iVar4 == 0) {
        lex->token = 0x103;
        return 0x103;
      }
      iVar4 = strcmp(pcVar3,"false");
      if (iVar4 == 0) {
        lex->token = 0x104;
        return 0x104;
      }
      iVar4 = strcmp(pcVar3,"null");
      if (iVar4 == 0) {
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
  uVar2 = 0xffffffff;
LAB_0003cc4e:
  lex->token = uVar2;
  return uVar2;
LAB_0003cee2:
  while( true ) {
    bVar1 = *pbVar9;
    if (bVar1 == 0x22) {
      *__dest = 0;
      lex->token = 0x100;
      return 0x100;
    }
    if (bVar1 == 0x5c) break;
    pbVar9 = pbVar9 + 1;
    *__dest = bVar1;
    __dest = __dest + 1;
  }
  bVar1 = pbVar9[1];
  if (bVar1 == 0x75) {
    codepoint = decode_unicode_escape((char *)(pbVar9 + 1));
    if (codepoint - 0xd800U < 0x400) {
      if ((pbVar9[6] != 0x5c) || (pbVar9[7] != 0x75)) {
LAB_0003d044:
        error_set(error,lex,"invalid Unicode \'\\u%04X\'",codepoint);
        goto LAB_0003cd9e;
      }
      str = pbVar9 + 7;
      pbVar9 = pbVar9 + 0xc;
      iVar6 = decode_unicode_escape((char *)str);
      if (0x3ff < iVar6 - 0xdc00U) {
        error_set(error,lex,"invalid Unicode \'\\u%04X\\u%04X\'",codepoint,iVar6);
        goto LAB_0003cd9e;
      }
      codepoint = (iVar6 - 0xdc00U) + (codepoint - 0xd800U) * 0x400 + 0x10000;
    }
    else {
      if (codepoint - 0xdc00U < 0x400) goto LAB_0003d044;
      if (codepoint == 0) {
        error_set(error,lex,"\\u0000 is not allowed");
        goto LAB_0003cd9e;
      }
      pbVar9 = pbVar9 + 6;
    }
    iVar4 = utf8_encode(codepoint,buffer,(int *)&local_38);
    if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("0","compat/jansson-2.6/src/load.c",0x1ae,"lex_scan_string");
    }
    memcpy(__dest,buffer,local_38);
    __dest = __dest + local_38;
    goto LAB_0003cee2;
  }
  if (bVar1 == 0x66) {
    *__dest = 0xc;
  }
  else if (bVar1 < 0x67) {
    if (bVar1 != 0x5c) {
      if (0x5c < bVar1) {
        if (bVar1 != 0x62) goto LAB_0003cf10;
        *__dest = 8;
        goto LAB_0003cf32;
      }
      if ((bVar1 != 0x22) && (bVar1 != 0x2f)) {
LAB_0003cf10:
                    /* WARNING: Subroutine does not return */
        __assert_fail("0","compat/jansson-2.6/src/load.c",0x1bc,"lex_scan_string");
      }
    }
    *__dest = bVar1;
  }
  else if (bVar1 == 0x72) {
    *__dest = 0xd;
  }
  else if (bVar1 == 0x74) {
    *__dest = 9;
  }
  else {
    if (bVar1 != 0x6e) goto LAB_0003cf10;
    *__dest = 10;
  }
LAB_0003cf32:
  __dest = __dest + 1;
  pbVar9 = pbVar9 + 2;
  goto LAB_0003cee2;
}


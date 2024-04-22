
/* WARNING: Unknown calling convention */

int lex_scan(lex_t *lex,json_error_t *error)

{
  char byte;
  byte bVar1;
  uint uVar2;
  int c;
  char *pcVar3;
  char *saved_text;
  int iVar4;
  char *saved_text_1;
  byte *__dest;
  char *t;
  int32_t codepoint;
  int32_t value_1;
  byte *str;
  int32_t iVar5;
  int32_t value2;
  char *end;
  size_t sVar6;
  int c_1;
  strbuffer_t *strbuff;
  byte *pbVar7;
  char *p;
  bool bVar8;
  bool bVar9;
  longlong lVar10;
  char buffer [4];
  int length;
  char *local_34;
  double value;
  
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
        c_1 = lex_get_save(lex,error);
        while( true ) {
          if (c_1 == 0x22) {
            __dest = (byte *)jsonp_malloc((lex->saved_text).length + 1);
            (lex->value).string = (char *)__dest;
            if (__dest == (byte *)0x0) goto out;
            pcVar3 = strbuffer_value(strbuff);
            pbVar7 = (byte *)(pcVar3 + 1);
            goto LAB_0003cee2;
          }
          if (c_1 == -2) goto out;
          if (c_1 == -1) {
            error_set(error,lex,DAT_0003cf68);
            goto out;
          }
          if ((uint)c_1 < 0x20) {
            lex_unget_unsave(lex,c_1);
            pcVar3 = DAT_0003cf58;
            if (c_1 != 10) {
              pcVar3 = DAT_0003cf5c;
            }
            error_set(error,lex,pcVar3,c_1);
            goto out;
          }
          if (c_1 != 0x5c) goto LAB_0003cd48;
          uVar2 = lex_get_save(lex,error);
          if (uVar2 != 0x75) break;
          c_1 = lex_get_save(lex,error);
          iVar4 = 4;
          do {
            uVar2 = c_1 - 0x41;
            bVar9 = 4 < uVar2;
            bVar8 = uVar2 == 5;
            if (5 < uVar2) {
              bVar9 = 8 < c_1 - 0x30U;
              bVar8 = c_1 - 0x30U == 9;
            }
            if ((bVar9 && !bVar8) && (5 < c_1 - 0x61U)) goto LAB_0003cd94;
            c_1 = lex_get_save(lex,error);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      } while ((((uVar2 == 0x22 || uVar2 == 0x5c) || (uVar2 == 0x2f || uVar2 == 0x62)) ||
               ((uVar2 & 0xfffffff7) == 0x66)) || (uVar2 == 0x72 || uVar2 == 0x74));
LAB_0003cd94:
      error_set(error,lex,DAT_0003cf54);
out:
      _jsonp_free(&(lex->value).string);
      return lex->token;
    }
    bVar8 = 0x2c < uVar2;
    if (uVar2 != 0x2d) {
      bVar8 = 8 < uVar2 - 0x30;
    }
    if (!bVar8 || (uVar2 == 0x2d || uVar2 - 0x30 == 9)) {
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
        saved_text_1 = (char *)__errno_location();
        *(undefined4 *)saved_text_1 = 0;
        lVar10 = strtoll(pcVar3,&local_34,10);
        if (*(int *)saved_text_1 == 0x22) {
          pcVar3 = DAT_0003cf60;
          if (-1 < lVar10) {
            pcVar3 = DAT_0003cf64;
          }
          error_set(error,lex,pcVar3);
          return lex->token;
        }
        if (local_34 == pcVar3 + (lex->saved_text).length) {
          (lex->value).integer = lVar10;
          lex->token = 0x101;
          return 0x101;
        }
                    /* WARNING: Subroutine does not return */
        __assert_fail(DAT_0003d0b4,DAT_0003d0a4,0x206,DAT_0003d0b8);
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
      iVar4 = jsonp_strtod(strbuff,&value);
      if (iVar4 == 0) {
        lex->token = 0x102;
        (lex->value).real = value;
        return 0x102;
      }
      error_set(error,lex,DAT_0003d0bc);
      return lex->token;
    }
    if ((uVar2 & 0xffffffdf) - 0x41 < 0x1a) {
      do {
        uVar2 = lex_get_save(lex,error);
      } while ((uVar2 & 0xffffffdf) - 0x41 < 0x1a);
      lex_unget_unsave(lex,uVar2);
      pcVar3 = strbuffer_value(strbuff);
      saved_text = (char *)strcmp(pcVar3,DAT_0003cf48);
      if (saved_text == (char *)0x0) {
        lex->token = 0x103;
        return 0x103;
      }
      iVar4 = strcmp(pcVar3,DAT_0003cf4c);
      if (iVar4 == 0) {
        lex->token = 0x104;
        return 0x104;
      }
      iVar4 = strcmp(pcVar3,DAT_0003cf50);
      if (iVar4 == 0) {
        lex->token = 0x105;
        return 0x105;
      }
    }
    else {
      byte = (lex->stream).buffer[(lex->stream).buffer_pos];
      while (byte != '\0') {
        strbuffer_append_byte(strbuff,byte);
        sVar6 = (lex->stream).buffer_pos;
        byte = (lex->stream).buffer[sVar6 + 1];
        (lex->stream).buffer_pos = sVar6 + 1;
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
    bVar1 = *pbVar7;
    if (bVar1 == 0x22) {
      *__dest = 0;
      lex->token = 0x100;
      return 0x100;
    }
    if (bVar1 == 0x5c) break;
    pbVar7 = pbVar7 + 1;
    *__dest = bVar1;
    __dest = __dest + 1;
  }
  bVar1 = pbVar7[1];
  if (bVar1 == 0x75) {
    codepoint = decode_unicode_escape((char *)(pbVar7 + 1));
    if (codepoint - 0xd800U < 0x400) {
      if ((pbVar7[6] != 0x5c) || (pbVar7[7] != 0x75)) {
LAB_0003d044:
        error_set(error,lex,DAT_0003d0b0,codepoint);
        goto out;
      }
      str = pbVar7 + 7;
      pbVar7 = pbVar7 + 0xc;
      iVar5 = decode_unicode_escape((char *)str);
      if (0x3ff < iVar5 - 0xdc00U) {
        error_set(error,lex,DAT_0003d0ac,codepoint,iVar5);
        goto out;
      }
      codepoint = (iVar5 - 0xdc00U) + (codepoint - 0xd800U) * 0x400 + 0x10000;
    }
    else {
      if (codepoint - 0xdc00U < 0x400) goto LAB_0003d044;
      if (codepoint == 0) {
        error_set(error,lex,DAT_0003d0c0);
        goto out;
      }
      pbVar7 = pbVar7 + 6;
    }
    iVar4 = utf8_encode(codepoint,buffer,&length);
    if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail(DAT_0003d0a0,DAT_0003d0a4,0x1ae,DAT_0003d0a8);
    }
    memcpy(__dest,buffer,length);
    __dest = __dest + length;
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
        __assert_fail(DAT_0003cf6c,DAT_0003cf70,0x1bc,DAT_0003cf74);
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
  pbVar7 = pbVar7 + 2;
  goto LAB_0003cee2;
}


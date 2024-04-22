
void lex_scan_string(lex_t *lex,json_error_t *error)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  byte *str;
  json_error_t *error_local;
  lex_t *lex_local;
  size_t length;
  int32_t value2;
  int32_t value;
  int i;
  char *t;
  char *p;
  int c;
  
  (lex->value).string.val = (char *)0x0;
  lex->token = -1;
  c = lex_get_save(lex,error);
  while (c != 0x22) {
    if (c == -2) goto out;
    if (c == -1) {
      error_set(error,lex,"premature end of input");
      goto out;
    }
    if ((-1 < c) && (c < 0x20)) {
      lex_unget_unsave(lex,c);
      if (c == 10) {
        error_set(error,lex,"unexpected newline",10);
      }
      else {
        error_set(error,lex,"control character 0x%x",c);
      }
      goto out;
    }
    if (c == 0x5c) {
      c = lex_get_save(lex,error);
      if (c == 0x75) {
        c = lex_get_save(lex,error);
        for (i = 0; i < 4; i = i + 1) {
          if ((((c < 0x30) || (0x39 < c)) && ((c < 0x41 || (0x46 < c)))) &&
             ((c < 0x61 || (0x66 < c)))) {
            error_set(error,lex,"invalid escape");
            goto out;
          }
          c = lex_get_save(lex,error);
        }
      }
      else {
        if (((((c != 0x22) && (c != 0x5c)) && (c != 0x2f)) && ((c != 0x62 && (c != 0x66)))) &&
           ((c != 0x6e && ((c != 0x72 && (c != 0x74)))))) {
          error_set(error,lex,"invalid escape");
          goto out;
        }
        c = lex_get_save(lex,error);
      }
    }
    else {
      c = lex_get_save(lex,error);
    }
  }
  t = (char *)jsonp_malloc((lex->saved_text).length + 1);
  if (t == (char *)0x0) {
out:
    lex_free_string(lex);
  }
  else {
    (lex->value).string.val = t;
    pcVar2 = strbuffer_value(&lex->saved_text);
    p = pcVar2 + 1;
    while (*p != '\"') {
      if (*p == '\\') {
        str = (byte *)(p + 1);
        if (*str == 0x75) {
          p = (char *)str;
          value = decode_unicode_escape((char *)str);
          if (value < 0) {
            error_set(error,lex,"invalid Unicode escape \'%.6s\'",p + -1);
            goto out;
          }
          pcVar2 = p + 5;
          if ((value < 0xd800) || (0xdbff < value)) {
            p = pcVar2;
            if ((0xdbff < value) && (value < 0xe000)) {
              error_set(error,lex,"invalid Unicode \'\\u%04X\'",value);
              goto out;
            }
          }
          else {
            if ((*pcVar2 != '\\') || (p[6] != 'u')) {
              p = pcVar2;
              error_set(error,lex,"invalid Unicode \'\\u%04X\'",value);
              goto out;
            }
            p = p + 6;
            value2 = decode_unicode_escape(p);
            if (value2 < 0) {
              error_set(error,lex,"invalid Unicode escape \'%.6s\'",p + -1);
              goto out;
            }
            p = p + 5;
            if ((value2 < 0xdc00) || (0xdfff < value2)) {
              error_set(error,lex,"invalid Unicode \'\\u%04X\\u%04X\'",value,value2);
              goto out;
            }
            value = (value + -0xd800) * 0x400 + value2 + 0x2400;
          }
          iVar3 = utf8_encode(value,t,&length);
          if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("0","compat/jansson-2.9/src/load.c",0x1db,"lex_scan_string");
          }
          t = t + length;
        }
        else {
          bVar1 = *str;
          if (bVar1 == 0x66) {
            *t = '\f';
          }
          else if (bVar1 < 0x67) {
            if (bVar1 != 0x5c) {
              if (0x5c < bVar1) {
                if (bVar1 != 0x62) goto LAB_00066b46;
                *t = '\b';
                goto LAB_00066b66;
              }
              if ((bVar1 != 0x22) && (bVar1 != 0x2f)) {
LAB_00066b46:
                p = (char *)str;
                    /* WARNING: Subroutine does not return */
                __assert_fail("0","compat/jansson-2.9/src/load.c",0x1f7,"lex_scan_string");
              }
            }
            *t = *str;
          }
          else if (bVar1 == 0x72) {
            *t = '\r';
          }
          else if (bVar1 == 0x74) {
            *t = '\t';
          }
          else {
            if (bVar1 != 0x6e) goto LAB_00066b46;
            *t = '\n';
          }
LAB_00066b66:
          t = t + 1;
          p = p + 2;
        }
      }
      else {
        *t = *p;
        t = t + 1;
        p = p + 1;
      }
    }
    *t = '\0';
    (lex->value).string.len = (int)t - (int)(lex->value).string.val;
    lex->token = 0x100;
  }
  return;
}


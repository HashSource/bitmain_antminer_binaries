
int lex_scan_number(lex_t *lex,int c,json_error_t *error)

{
  int *piVar1;
  int iVar2;
  json_error_t *error_local;
  int c_local;
  lex_t *lex_local;
  double doubleval;
  char *end;
  json_int_t intval;
  char *saved_text;
  
  lex->token = -1;
  c_local = c;
  if (c == 0x2d) {
    c_local = lex_get_save(lex,error);
  }
  if (c_local == 0x30) {
    c_local = lex_get_save(lex,error);
    if ((0x2f < c_local) && (c_local < 0x3a)) {
      lex_unget_unsave(lex,c_local);
      return -1;
    }
  }
  else {
    if ((c_local < 0x30) || (0x39 < c_local)) {
      lex_unget_unsave(lex,c_local);
      return -1;
    }
    do {
      c_local = lex_get_save(lex,error);
      if (c_local < 0x30) break;
    } while (c_local < 0x3a);
  }
  if (((((lex->flags & 8) == 0) && (c_local != 0x2e)) && (c_local != 0x45)) && (c_local != 0x65)) {
    lex_unget_unsave(lex,c_local);
    saved_text = strbuffer_value(&lex->saved_text);
    piVar1 = __errno_location();
    *piVar1 = 0;
    intval = strtoll(saved_text,&end,10);
    piVar1 = __errno_location();
    if (*piVar1 != 0x22) {
      if (saved_text + (lex->saved_text).length != end) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("end == saved_text + lex->saved_text.length","compat/jansson-2.9/src/load.c",
                      0x249,"lex_scan_number");
      }
      lex->token = 0x101;
      (lex->value).string.val = (char *)intval;
      (lex->value).string.len = intval._4_4_;
      return 0;
    }
    if (intval < 0) {
      error_set(error,lex,"too big negative integer");
    }
    else {
      error_set(error,lex,"too big integer");
    }
  }
  else {
    if (c_local == 0x2e) {
      iVar2 = lex_get(lex,error);
      if ((iVar2 < 0x30) || (0x39 < iVar2)) {
        lex_unget(lex,iVar2);
        return -1;
      }
      lex_save(lex,iVar2);
      do {
        c_local = lex_get_save(lex,error);
        if (c_local < 0x30) break;
      } while (c_local < 0x3a);
    }
    if ((c_local == 0x45) || (c_local == 0x65)) {
      c_local = lex_get_save(lex,error);
      if ((c_local == 0x2b) || (c_local == 0x2d)) {
        c_local = lex_get_save(lex,error);
      }
      if ((c_local < 0x30) || (0x39 < c_local)) {
        lex_unget_unsave(lex,c_local);
        return -1;
      }
      do {
        c_local = lex_get_save(lex,error);
        if (c_local < 0x30) break;
      } while (c_local < 0x3a);
    }
    lex_unget_unsave(lex,c_local);
    iVar2 = jsonp_strtod(&lex->saved_text,&doubleval);
    if (iVar2 == 0) {
      lex->token = 0x102;
      (lex->value).string.val = doubleval._0_4_;
      (lex->value).string.len = doubleval._4_4_;
      return 0;
    }
    error_set(error,lex,"real number overflow");
  }
  return -1;
}


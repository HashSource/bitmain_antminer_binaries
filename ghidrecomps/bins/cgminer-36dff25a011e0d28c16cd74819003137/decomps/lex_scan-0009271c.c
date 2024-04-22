
int lex_scan(lex_t *lex,json_error_t *error)

{
  int iVar1;
  char *__s1;
  json_error_t *error_local;
  lex_t *lex_local;
  char *saved_text;
  int c;
  
  strbuffer_clear(&lex->saved_text);
  if (lex->token == 0x100) {
    lex_free_string(lex);
  }
  do {
    do {
      iVar1 = lex_get(lex,error);
    } while (iVar1 == 0x20);
  } while (((iVar1 == 9) || (iVar1 == 10)) || (iVar1 == 0xd));
  if (iVar1 == -1) {
    lex->token = 0;
  }
  else if (iVar1 == -2) {
    lex->token = -1;
  }
  else {
    lex_save(lex,iVar1);
    if ((((iVar1 == 0x7b) || (iVar1 == 0x7d)) ||
        ((iVar1 == 0x5b || ((iVar1 == 0x5d || (iVar1 == 0x3a)))))) || (iVar1 == 0x2c)) {
      lex->token = iVar1;
    }
    else if (iVar1 == 0x22) {
      lex_scan_string(lex,error);
    }
    else if (((iVar1 < 0x30) || (0x39 < iVar1)) && (iVar1 != 0x2d)) {
      if (((0x40 < iVar1) && (iVar1 < 0x5b)) || ((0x60 < iVar1 && (iVar1 < 0x7b)))) {
LAB_000928c0:
        do {
          iVar1 = lex_get_save(lex,error);
          if (0x40 < iVar1) {
            if (iVar1 < 0x5b) goto LAB_000928c0;
          }
          if ((iVar1 < 0x61) || (0x7a < iVar1)) goto LAB_00092900;
        } while( true );
      }
      lex_save_cached(lex);
      lex->token = -1;
    }
    else {
      lex_scan_number(lex,iVar1,error);
    }
  }
out:
  return lex->token;
LAB_00092900:
  lex_unget_unsave(lex,iVar1);
  __s1 = strbuffer_value(&lex->saved_text);
  iVar1 = strcmp(__s1,"true");
  if (iVar1 == 0) {
    lex->token = 0x103;
  }
  else {
    iVar1 = strcmp(__s1,"false");
    if (iVar1 == 0) {
      lex->token = 0x104;
    }
    else {
      iVar1 = strcmp(__s1,"null");
      if (iVar1 == 0) {
        lex->token = 0x105;
      }
      else {
        lex->token = -1;
      }
    }
  }
  goto out;
}


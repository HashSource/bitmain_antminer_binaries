
/* WARNING: Variable defined which should be unmapped: error-local */

json_t * parse_value(lex_t *lex,size_t flags,json_error_t *error)

{
  void *pvVar1;
  int iVar2;
  char *value_00;
  size_t n;
  undefined4 uStack_28;
  json_error_t *error_local;
  size_t flags_local;
  lex_t *lex_local;
  size_t len;
  char *value;
  json_t *json;
  
  lex->depth = lex->depth + 1;
  if (0x800 < lex->depth) {
    error_set(error,lex,"maximum parsing depth reached");
    return (json_t *)0x0;
  }
  iVar2 = lex->token;
  if (iVar2 == 0x101) {
    json = json_integer(CONCAT44(error,uStack_28));
  }
  else if (iVar2 < 0x102) {
    if (iVar2 == 0x5b) {
      json = parse_array(lex,flags,error);
    }
    else {
      if (iVar2 < 0x5c) {
        if (iVar2 == -1) {
          error_set(error,lex,"invalid token");
          return (json_t *)0x0;
        }
LAB_000930b4:
        error_set(error,lex,"unexpected token");
        return (json_t *)0x0;
      }
      if (iVar2 == 0x7b) {
        json = parse_object(lex,flags,error);
      }
      else {
        if (iVar2 != 0x100) goto LAB_000930b4;
        value_00 = (lex->value).string.val;
        n = (lex->value).string.len;
        if (((flags & 0x10) == 0) && (pvVar1 = rpl_memchr(value_00,0,n), pvVar1 != (void *)0x0)) {
          error_set(error,lex,"\\u0000 is not allowed without JSON_ALLOW_NUL");
          return (json_t *)0x0;
        }
        json = jsonp_stringn_nocheck_own(value_00,n);
        if (json != (json_t *)0x0) {
          (lex->value).string.val = (char *)0x0;
          (lex->value).string.len = 0;
        }
      }
    }
  }
  else if (iVar2 == 0x103) {
    json = json_true();
  }
  else if (iVar2 < 0x103) {
    json = json_real((double)CONCAT44(error,uStack_28));
  }
  else if (iVar2 == 0x104) {
    json = json_false();
  }
  else {
    if (iVar2 != 0x105) goto LAB_000930b4;
    json = json_null();
  }
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    lex->depth = lex->depth - 1;
  }
  return json;
}


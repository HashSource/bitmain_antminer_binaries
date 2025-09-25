
/* WARNING: Unknown calling convention */

json_t * parse_value(lex_t *lex,size_t flags,json_error_t *error)

{
  bool bVar1;
  void *pvVar2;
  json_t *pjVar3;
  json_t *json;
  size_t __n;
  uint uVar4;
  int iVar5;
  size_t *psVar6;
  size_t sVar7;
  char *key;
  char *pcVar8;
  
  uVar4 = lex->depth + 1;
  lex->depth = uVar4;
  if (0x800 < uVar4) {
    error_set(error,lex,json_error_stack_overflow,"maximum parsing depth reached");
    return (json_t *)0x0;
  }
  iVar5 = lex->token;
  if (iVar5 == 0x101) {
    json = json_integer((lex->value).integer);
  }
  else if (iVar5 < 0x102) {
    if (iVar5 == 0x5b) {
      json = json_array();
      if (json == (json_t *)0x0) {
        return (json_t *)0x0;
      }
      lex_scan(lex,error);
      iVar5 = lex->token;
      if (iVar5 != 0x5d) {
        while (iVar5 != 0) {
          pjVar3 = parse_value(lex,flags,error);
          if ((pjVar3 == (json_t *)0x0) || (iVar5 = json_array_append_new(json,pjVar3), iVar5 != 0))
          goto LAB_000ce462;
          lex_scan(lex,error);
          if (lex->token != 0x2c) {
            if (lex->token == 0x5d) goto LAB_000ce2f4;
            break;
          }
          lex_scan(lex,error);
          iVar5 = lex->token;
        }
        error_set(error,lex,json_error_invalid_syntax,"\']\' expected");
LAB_000ce462:
        if (json->refcount == 0xffffffff) {
          return (json_t *)0x0;
        }
        psVar6 = &json->refcount;
        DataMemoryBarrier(0x1f);
        do {
          ExclusiveAccess(psVar6);
          sVar7 = *psVar6 - 1;
          bVar1 = (bool)hasExclusiveAccess(psVar6);
        } while (!bVar1);
        *psVar6 = sVar7;
LAB_000ce47e:
        if (sVar7 != 0) {
          return (json_t *)0x0;
        }
        json_delete(json);
        return (json_t *)0x0;
      }
    }
    else {
      if (iVar5 < 0x5c) {
        if (iVar5 == -1) {
          error_set(error,lex,json_error_invalid_syntax,"invalid token");
          return (json_t *)0x0;
        }
LAB_000ce2a2:
        error_set(error,lex,json_error_invalid_syntax,"unexpected token");
        return (json_t *)0x0;
      }
      if (iVar5 == 0x7b) {
        json = json_object();
        if (json == (json_t *)0x0) {
          return (json_t *)0x0;
        }
        lex_scan(lex,error);
        if (lex->token != 0x7d) {
          if (lex->token == 0x100) {
            pcVar8 = (lex->value).string.val;
            __n = (lex->value).string.len;
            (lex->value).string.val = (char *)0x0;
            (lex->value).string.len = 0;
            if (pcVar8 == (char *)0x0) {
              return (json_t *)0x0;
            }
            while( true ) {
              pvVar2 = memchr(pcVar8,0,__n);
              if (pvVar2 != (void *)0x0) {
                jsonp_free(pcVar8);
                error_set(error,lex,json_error_null_byte_in_key,
                          "NUL byte in object key not supported");
                goto LAB_000ce4da;
              }
              if (((flags & 1) != 0) &&
                 (pjVar3 = json_object_get(json,pcVar8), pjVar3 != (json_t *)0x0)) {
                jsonp_free(pcVar8);
                error_set(error,lex,json_error_duplicate_key,"duplicate object key");
                goto LAB_000ce4da;
              }
              lex_scan(lex,error);
              if (lex->token != 0x3a) {
                jsonp_free(pcVar8);
                error_set(error,lex,json_error_invalid_syntax,"\':\' expected");
                goto LAB_000ce4da;
              }
              lex_scan(lex,error);
              pjVar3 = parse_value(lex,flags,error);
              if (pjVar3 == (json_t *)0x0) {
                jsonp_free(pcVar8);
                goto LAB_000ce4da;
              }
              iVar5 = json_object_set_new_nocheck(json,pcVar8,pjVar3);
              if (iVar5 != 0) {
                jsonp_free(pcVar8);
                goto LAB_000ce4da;
              }
              jsonp_free(pcVar8);
              lex_scan(lex,error);
              if (lex->token != 0x2c) break;
              lex_scan(lex,error);
              if (lex->token != 0x100) goto LAB_000ce4ce;
              pcVar8 = (lex->value).string.val;
              __n = (lex->value).string.len;
              (lex->value).string.val = (char *)0x0;
              (lex->value).string.len = 0;
              if (pcVar8 == (char *)0x0) {
                return (json_t *)0x0;
              }
            }
            if (lex->token == 0x7d) goto LAB_000ce2f4;
            error_set(error,lex,json_error_invalid_syntax,"\'}\' expected");
          }
          else {
LAB_000ce4ce:
            error_set(error,lex,json_error_invalid_syntax,"string or \'}\' expected");
          }
LAB_000ce4da:
          if (json->refcount == 0xffffffff) {
            return (json_t *)0x0;
          }
          psVar6 = &json->refcount;
          DataMemoryBarrier(0x1f);
          do {
            ExclusiveAccess(psVar6);
            sVar7 = *psVar6 - 1;
            bVar1 = (bool)hasExclusiveAccess(psVar6);
          } while (!bVar1);
          *psVar6 = sVar7;
          goto LAB_000ce47e;
        }
      }
      else {
        if (iVar5 != 0x100) goto LAB_000ce2a2;
        pcVar8 = (lex->value).string.val;
        sVar7 = (lex->value).string.len;
        if (((flags & 0x10) == 0) && (pvVar2 = memchr(pcVar8,0,sVar7), pvVar2 != (void *)0x0)) {
          error_set(error,lex,json_error_null_character,
                    "\\u0000 is not allowed without JSON_ALLOW_NUL");
          return (json_t *)0x0;
        }
        json = jsonp_stringn_nocheck_own(pcVar8,sVar7);
        (lex->value).string.val = (char *)0x0;
        (lex->value).string.len = 0;
      }
    }
  }
  else if (iVar5 == 0x103) {
    json = json_true();
  }
  else if (iVar5 < 0x103) {
    json = json_real((lex->value).real);
  }
  else if (iVar5 == 0x104) {
    json = json_false();
  }
  else {
    if (iVar5 != 0x105) goto LAB_000ce2a2;
    json = json_null();
  }
LAB_000ce2f4:
  if (json != (json_t *)0x0) {
    lex->depth = lex->depth - 1;
    return json;
  }
  return (json_t *)0x0;
}



/* WARNING: Unknown calling convention */

json_t * parse_value(lex_t *lex,size_t flags,json_error_t *error)

{
  json_t *pjVar1;
  json_t *pjVar2;
  int iVar3;
  size_t sVar4;
  char *local_2c;
  double local_28;
  
  iVar3 = lex->token;
  if (iVar3 == 0x101) {
    if ((flags & 8) == 0) {
      pjVar2 = json_integer((lex->value).integer);
      return pjVar2;
    }
    iVar3 = jsonp_strtod(&lex->saved_text,&local_28);
    if (iVar3 != 0) {
      error_set(error,lex,"real number overflow");
      return (json_t *)0x0;
    }
    pjVar2 = json_real(local_28);
    return pjVar2;
  }
  if (iVar3 < 0x102) {
    if (iVar3 == 0x5b) {
      pjVar2 = json_array();
      if (pjVar2 == (json_t *)0x0) {
        return (json_t *)0x0;
      }
      lex_scan(lex,error);
      iVar3 = lex->token;
      if (iVar3 == 0x5d) {
        return pjVar2;
      }
      while (iVar3 != 0) {
        pjVar1 = parse_value(lex,flags,error);
        if (pjVar1 == (json_t *)0x0) goto LAB_0003d292;
        if (pjVar1->refcount != 0xffffffff) {
          pjVar1->refcount = pjVar1->refcount + 1;
        }
        iVar3 = json_array_append_new(pjVar2,pjVar1);
        if (iVar3 != 0) {
          sVar4 = pjVar1->refcount;
          goto joined_r0x0003d2f6;
        }
        sVar4 = pjVar1->refcount - 1;
        if ((pjVar1->refcount != 0xffffffff) && (pjVar1->refcount = sVar4, sVar4 == 0)) {
          json_delete(pjVar1);
        }
        lex_scan(lex,error);
        if (lex->token != 0x2c) {
          if (lex->token == 0x5d) {
            return pjVar2;
          }
          break;
        }
        lex_scan(lex,error);
        iVar3 = lex->token;
      }
      error_set(error,lex,"\']\' expected");
LAB_0003d292:
      if ((pjVar2->refcount != 0xffffffff) &&
         (sVar4 = pjVar2->refcount - 1, pjVar2->refcount = sVar4, sVar4 == 0)) {
        json_delete(pjVar2);
        return (json_t *)0x0;
      }
      return (json_t *)0x0;
    }
    if (iVar3 < 0x5c) {
      if (iVar3 == -1) {
        error_set(error,lex,"invalid token");
        return (json_t *)0x0;
      }
    }
    else {
      if (iVar3 == 0x7b) {
        pjVar2 = json_object();
        if (pjVar2 == (json_t *)0x0) {
          return (json_t *)0x0;
        }
        lex_scan(lex,error);
        if (lex->token == 0x7d) {
          return pjVar2;
        }
        if (lex->token == 0x100) {
          local_2c = (lex->value).string;
          (lex->value).string = (char *)0x0;
          if (local_2c == (char *)0x0) {
            return (json_t *)0x0;
          }
          do {
            if (((flags & 1) != 0) &&
               (pjVar1 = json_object_get(pjVar2,local_2c), pjVar1 != (json_t *)0x0)) {
              _jsonp_free(&local_2c);
              error_set(error,lex,"duplicate object key");
              goto LAB_0003d292;
            }
            lex_scan(lex,error);
            if (lex->token != 0x3a) {
              _jsonp_free(&local_2c);
              error_set(error,lex,"\':\' expected");
              goto LAB_0003d292;
            }
            lex_scan(lex,error);
            pjVar1 = parse_value(lex,flags,error);
            if (pjVar1 == (json_t *)0x0) {
              _jsonp_free(&local_2c);
              goto LAB_0003d292;
            }
            if (pjVar1->refcount != 0xffffffff) {
              pjVar1->refcount = pjVar1->refcount + 1;
            }
            iVar3 = json_object_set_new_nocheck(pjVar2,local_2c,pjVar1);
            if (iVar3 != 0) {
              _jsonp_free(&local_2c);
              sVar4 = pjVar1->refcount;
joined_r0x0003d2f6:
              if ((sVar4 != 0xffffffff) && (pjVar1->refcount = sVar4 - 1, sVar4 - 1 == 0)) {
                json_delete(pjVar1);
              }
              goto LAB_0003d292;
            }
            if ((pjVar1->refcount != 0xffffffff) &&
               (sVar4 = pjVar1->refcount - 1, pjVar1->refcount = sVar4, sVar4 == 0)) {
              json_delete(pjVar1);
            }
            _jsonp_free(&local_2c);
            lex_scan(lex,error);
            if (lex->token != 0x2c) {
              if (lex->token == 0x7d) {
                return pjVar2;
              }
              error_set(error,lex,"\'}\' expected");
              goto LAB_0003d292;
            }
            lex_scan(lex,error);
            if (lex->token != 0x100) break;
            local_2c = (lex->value).string;
            (lex->value).string = (char *)0x0;
            if (local_2c == (char *)0x0) {
              return (json_t *)0x0;
            }
          } while( true );
        }
        error_set(error,lex,"string or \'}\' expected");
        goto LAB_0003d292;
      }
      if (iVar3 == 0x100) {
        pjVar2 = json_string_nocheck((lex->value).string);
        return pjVar2;
      }
    }
  }
  else {
    if (iVar3 == 0x103) {
      pjVar2 = json_true();
      return pjVar2;
    }
    if (iVar3 < 0x103) {
      pjVar2 = json_real((lex->value).real);
      return pjVar2;
    }
    if (iVar3 == 0x104) {
      pjVar2 = json_false();
      return pjVar2;
    }
    if (iVar3 == 0x105) {
      pjVar2 = json_null();
      return pjVar2;
    }
  }
  error_set(error,lex,"unexpected token");
  return (json_t *)0x0;
}


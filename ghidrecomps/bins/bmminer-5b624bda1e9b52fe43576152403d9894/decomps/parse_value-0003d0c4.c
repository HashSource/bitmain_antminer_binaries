
/* WARNING: Variable defined which should be unmapped: key */
/* WARNING: Unknown calling convention */

json_t * parse_value(lex_t *lex,size_t flags,json_error_t *error)

{
  json_t *json;
  json_t *object;
  json_t *pjVar1;
  json_t *value_1;
  json_t *array;
  json_t *elem;
  json_t *pjVar2;
  int iVar3;
  size_t sVar4;
  undefined4 uStack_30;
  char *key;
  double value;
  
  iVar3 = lex->token;
  if (iVar3 == 0x101) {
    if ((flags & 8) == 0) {
      pjVar2 = json_integer(CONCAT44(key,uStack_30));
      return pjVar2;
    }
    iVar3 = jsonp_strtod(&lex->saved_text,&value);
    if (iVar3 != 0) {
      error_set(error,lex,DAT_0003d368);
      return (json_t *)0x0;
    }
    pjVar2 = json_real((double)CONCAT44(key,uStack_30));
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
        if (pjVar1 == (json_t *)0x0) goto error;
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
      error_set(error,lex,DAT_0003d36c);
error:
      if ((pjVar2->refcount != 0xffffffff) &&
         (sVar4 = pjVar2->refcount - 1, pjVar2->refcount = sVar4, sVar4 == 0)) {
        json_delete(pjVar2);
        return (json_t *)0x0;
      }
      return (json_t *)0x0;
    }
    if (iVar3 < 0x5c) {
      if (iVar3 == -1) {
        error_set(error,lex,DAT_0003d364);
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
          key = (lex->value).string;
          (lex->value).string = (char *)0x0;
          if (key == (char *)0x0) {
            return (json_t *)0x0;
          }
          do {
            if (((flags & 1) != 0) &&
               (pjVar1 = json_object_get(pjVar2,key), pjVar1 != (json_t *)0x0)) {
              _jsonp_free(&key);
              error_set(error,lex,DAT_0003d390);
              goto error;
            }
            lex_scan(lex,error);
            if (lex->token != 0x3a) {
              _jsonp_free(&key);
              error_set(error,lex,DAT_0003d374);
              goto error;
            }
            lex_scan(lex,error);
            pjVar1 = parse_value(lex,flags,error);
            if (pjVar1 == (json_t *)0x0) {
              _jsonp_free(&key);
              goto error;
            }
            if (pjVar1->refcount != 0xffffffff) {
              pjVar1->refcount = pjVar1->refcount + 1;
            }
            iVar3 = json_object_set_new_nocheck(pjVar2,key,pjVar1);
            if (iVar3 != 0) {
              _jsonp_free(&key);
              sVar4 = pjVar1->refcount;
joined_r0x0003d2f6:
              if ((sVar4 != 0xffffffff) && (pjVar1->refcount = sVar4 - 1, sVar4 - 1 == 0)) {
                json_delete(pjVar1);
              }
              goto error;
            }
            if ((pjVar1->refcount != 0xffffffff) &&
               (sVar4 = pjVar1->refcount - 1, pjVar1->refcount = sVar4, sVar4 == 0)) {
              json_delete(pjVar1);
            }
            _jsonp_free(&key);
            lex_scan(lex,error);
            if (lex->token != 0x2c) {
              if (lex->token == 0x7d) {
                return pjVar2;
              }
              error_set(error,lex,DAT_0003d378);
              goto error;
            }
            lex_scan(lex,error);
            if (lex->token != 0x100) break;
            key = (lex->value).string;
            (lex->value).string = (char *)0x0;
            if (key == (char *)0x0) {
              return (json_t *)0x0;
            }
          } while( true );
        }
        error_set(error,lex,DAT_0003d370);
        goto error;
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
      pjVar2 = json_real((double)CONCAT44(key,uStack_30));
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
  error_set(error,lex,DAT_0003d360);
  return (json_t *)0x0;
}


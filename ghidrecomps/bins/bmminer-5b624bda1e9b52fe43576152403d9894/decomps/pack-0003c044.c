
/* WARNING: Variable defined which should be unmapped: str */
/* WARNING: Unknown calling convention */

json_t * pack(scanner_t *s,va_list *ap)

{
  char cVar1;
  json_t *pjVar2;
  json_t *pjVar3;
  json_t *value;
  int iVar4;
  json_t *value_1;
  json_t *result;
  size_t sVar5;
  json_t **ppjVar6;
  json_t *object;
  json_t *array;
  char *str;
  int ours_1;
  
  switch((s->token).token) {
  case 'I':
    ap->__ap = (void *)(((int)ap->__ap + 7U & 0xfffffff8) + 8);
    pjVar2 = json_integer(CONCAT44(ours_1,str));
    return pjVar2;
  default:
    set_error(s,DAT_0003c274,DAT_0003c278);
    return (json_t *)0x0;
  case 'O':
    ppjVar6 = (json_t **)ap->__ap;
    ap->__ap = ppjVar6 + 1;
    pjVar2 = *ppjVar6;
    if (pjVar2 == (json_t *)0x0) {
      return (json_t *)0x0;
    }
    if (pjVar2->refcount != 0xffffffff) {
      pjVar2->refcount = pjVar2->refcount + 1;
      return pjVar2;
    }
    return pjVar2;
  case '[':
    pjVar2 = json_array();
    do {
      next_token(s);
      cVar1 = (s->token).token;
      if (cVar1 == ']') {
        return pjVar2;
      }
      if (cVar1 == '\0') goto LAB_0003c19a;
      pjVar3 = pack(s,ap);
      if (pjVar3 == (json_t *)0x0) goto error;
      iVar4 = json_array_append_new(pjVar2,pjVar3);
    } while (iVar4 == 0);
    set_error(s,DAT_0003c284,DAT_0003c288);
    break;
  case 'b':
                    /* WARNING: Load size is inaccurate */
    iVar4 = *ap->__ap;
    ap->__ap = (int *)((int)ap->__ap + 4);
    if (iVar4 == 0) {
      pjVar2 = json_false();
      return pjVar2;
    }
    pjVar2 = json_true();
    return pjVar2;
  case 'f':
    ap->__ap = (void *)(((int)ap->__ap + 7U & 0xfffffff8) + 8);
    pjVar2 = json_real((double)CONCAT44(ours_1,str));
    return pjVar2;
  case 'i':
    ap->__ap = (void *)((int)ap->__ap + 4);
    pjVar2 = json_integer(CONCAT44(ours_1,str));
    return pjVar2;
  case 'n':
    pjVar2 = json_null();
    return pjVar2;
  case 'o':
    ppjVar6 = (json_t **)ap->__ap;
    ap->__ap = ppjVar6 + 1;
    return *ppjVar6;
  case 's':
    str = read_string(s,ap,DAT_0003c280,&ours_1);
    if (str == (char *)0x0) {
      return (json_t *)0x0;
    }
    pjVar2 = json_string_nocheck(str);
    if (ours_1 != 0) {
      _jsonp_free(&str);
      return pjVar2;
    }
    return pjVar2;
  case '{':
    pjVar2 = json_object();
    while( true ) {
      next_token(s);
      cVar1 = (s->token).token;
      if (cVar1 == '}') {
        return pjVar2;
      }
      if (cVar1 == '\0') goto LAB_0003c19a;
      if (cVar1 != 's') {
        set_error(s,DAT_0003c274,DAT_0003c28c);
        goto error;
      }
      str = read_string(s,ap,DAT_0003c270,&ours_1);
      if (str == (char *)0x0) goto error;
      next_token(s);
      pjVar3 = pack(s,ap);
      if (pjVar3 == (json_t *)0x0) goto error;
      iVar4 = json_object_set_new_nocheck(pjVar2,str,pjVar3);
      if (iVar4 != 0) break;
      if (ours_1 != 0) {
        _jsonp_free(&str);
      }
    }
    if (ours_1 != 0) {
      _jsonp_free(&str);
    }
    set_error(s,DAT_0003c284,DAT_0003c290,str);
  }
error:
  if (((pjVar2 != (json_t *)0x0) && (pjVar2->refcount != 0xffffffff)) &&
     (sVar5 = pjVar2->refcount - 1, pjVar2->refcount = sVar5, sVar5 == 0)) {
    json_delete(pjVar2);
  }
  return (json_t *)0x0;
LAB_0003c19a:
  set_error(s,DAT_0003c274,DAT_0003c27c);
  goto error;
}


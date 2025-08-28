
/* WARNING: Unknown calling convention */

json_t * pack(scanner_t *s,va_list *ap)

{
  char cVar1;
  json_int_t value;
  json_t *pjVar2;
  json_t *pjVar3;
  int iVar4;
  json_int_t *pjVar5;
  size_t sVar6;
  double *pdVar7;
  undefined4 *puVar8;
  double value_00;
  json_t *local_18;
  int local_14;
  
  switch((s->token).token) {
  case 'I':
    pjVar5 = (json_int_t *)((int)ap->__ap + 7U & 0xfffffff8);
    value = *pjVar5;
    ap->__ap = pjVar5 + 1;
    pjVar2 = json_integer(value);
    return pjVar2;
  default:
    set_error(s,"<format>","Unexpected format character \'%c\'");
    return (json_t *)0x0;
  case 'O':
    puVar8 = (undefined4 *)ap->__ap;
    ap->__ap = puVar8 + 1;
    pjVar2 = (json_t *)*puVar8;
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
      if (pjVar3 == (json_t *)0x0) goto LAB_0003c1a2;
      iVar4 = json_array_append_new(pjVar2,pjVar3);
    } while (iVar4 == 0);
    set_error(s,"<internal>","Unable to append to array");
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
    pdVar7 = (double *)((int)ap->__ap + 7U & 0xfffffff8);
    value_00 = *pdVar7;
    ap->__ap = pdVar7 + 1;
    pjVar2 = json_real(value_00);
    return pjVar2;
  case 'i':
                    /* WARNING: Load size is inaccurate */
    iVar4 = *ap->__ap;
    ap->__ap = (int *)((int)ap->__ap + 4);
    pjVar2 = json_integer((longlong)iVar4);
    return pjVar2;
  case 'n':
    pjVar2 = json_null();
    return pjVar2;
  case 'o':
    puVar8 = (undefined4 *)ap->__ap;
    ap->__ap = puVar8 + 1;
    return (json_t *)*puVar8;
  case 's':
    local_18 = (json_t *)read_string(s,ap,"string",&local_14);
    if (local_18 == (json_t *)0x0) {
      return (json_t *)0x0;
    }
    pjVar2 = json_string_nocheck((char *)local_18);
    if (local_14 != 0) {
      _jsonp_free(&local_18);
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
        set_error(s,"<format>","Expected format \'s\', got \'%c\'");
        goto LAB_0003c1a2;
      }
      local_18 = (json_t *)read_string(s,ap,"object key",&local_14);
      if (local_18 == (json_t *)0x0) goto LAB_0003c1a2;
      next_token(s);
      pjVar3 = pack(s,ap);
      if (pjVar3 == (json_t *)0x0) goto LAB_0003c1a2;
      iVar4 = json_object_set_new_nocheck(pjVar2,(char *)local_18,pjVar3);
      if (iVar4 != 0) break;
      if (local_14 != 0) {
        _jsonp_free(&local_18);
      }
    }
    if (local_14 != 0) {
      _jsonp_free(&local_18);
    }
    set_error(s,"<internal>","Unable to add key \"%s\"",local_18);
  }
LAB_0003c1a2:
  if (((pjVar2 != (json_t *)0x0) && (pjVar2->refcount != 0xffffffff)) &&
     (sVar6 = pjVar2->refcount - 1, pjVar2->refcount = sVar6, sVar6 == 0)) {
    json_delete(pjVar2);
  }
  return (json_t *)0x0;
LAB_0003c19a:
  set_error(s,"<format>","Unexpected end of format string");
  goto LAB_0003c1a2;
}


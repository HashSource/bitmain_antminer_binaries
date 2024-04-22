
/* WARNING: Variable defined which should be unmapped: ap-local */

json_t * pack(scanner_t *s,va_list *ap)

{
  int *piVar1;
  json_t **ppjVar2;
  json_t *pjVar3;
  bool bVar4;
  va_list *ap_local;
  scanner_t *s_local;
  json_t *json_1;
  int nullable_1;
  json_t *json;
  int nullable;
  
  switch((s->token).token) {
  case 'I':
    ap->__ap = (void *)(((int)ap->__ap + 7U & 0xfffffff8) + 8);
    pjVar3 = json_integer(CONCAT44(s,ap));
    break;
  default:
    set_error(s,"<format>","Unexpected format character \'%c\'",(uint)(byte)(s->token).token);
    pjVar3 = (json_t *)0x0;
    break;
  case 'O':
    next_token(s);
    bVar4 = (s->token).token != '?';
    if (bVar4) {
      prev_token(s);
    }
    ppjVar2 = (json_t **)ap->__ap;
    ap->__ap = ppjVar2 + 1;
    pjVar3 = *ppjVar2;
    if ((pjVar3 != (json_t *)0x0) || (bVar4)) {
      pjVar3 = json_incref(pjVar3);
    }
    else {
      pjVar3 = json_null();
    }
    break;
  case '[':
    pjVar3 = pack_array(s,ap);
    break;
  case 'b':
    piVar1 = (int *)ap->__ap;
    ap->__ap = piVar1 + 1;
    if (*piVar1 == 0) {
      pjVar3 = json_false();
    }
    else {
      pjVar3 = json_true();
    }
    break;
  case 'f':
    ap->__ap = (void *)(((int)ap->__ap + 7U & 0xfffffff8) + 8);
    pjVar3 = json_real((double)CONCAT44(s,ap));
    break;
  case 'i':
    ap->__ap = (void *)((int)ap->__ap + 4);
    pjVar3 = json_integer(CONCAT44(s,ap));
    break;
  case 'n':
    pjVar3 = json_null();
    break;
  case 'o':
    next_token(s);
    bVar4 = (s->token).token != '?';
    if (bVar4) {
      prev_token(s);
    }
    ppjVar2 = (json_t **)ap->__ap;
    ap->__ap = ppjVar2 + 1;
    pjVar3 = *ppjVar2;
    if ((pjVar3 == (json_t *)0x0) && (!bVar4)) {
      pjVar3 = json_null();
    }
    break;
  case 's':
    pjVar3 = pack_string(s,ap);
    break;
  case '{':
    pjVar3 = pack_object(s,ap);
  }
  return pjVar3;
}



json_t * pack(scanner_t *s,va_list *ap)

{
  int *piVar1;
  json_int_t *pjVar2;
  double *pdVar3;
  undefined4 *puVar4;
  json_t *pjVar5;
  bool bVar6;
  va_list *ap_local;
  scanner_t *s_local;
  json_t *json_1;
  int nullable_1;
  json_t *json;
  int nullable;
  
  switch((s->token).token) {
  case 'I':
    pjVar2 = (json_int_t *)((int)ap->__ap + 7U & 0xfffffff8);
    ap->__ap = pjVar2 + 1;
    pjVar5 = json_integer(*pjVar2);
    break;
  default:
    set_error(s,"<format>","Unexpected format character \'%c\'",(uint)(byte)(s->token).token);
    pjVar5 = (json_t *)0x0;
    break;
  case 'O':
    next_token(s);
    bVar6 = (s->token).token != '?';
    if (bVar6) {
      prev_token(s);
    }
    puVar4 = (undefined4 *)ap->__ap;
    ap->__ap = puVar4 + 1;
    pjVar5 = (json_t *)*puVar4;
    if ((pjVar5 != (json_t *)0x0) || (bVar6)) {
      pjVar5 = json_incref(pjVar5);
    }
    else {
      pjVar5 = json_null();
    }
    break;
  case '[':
    pjVar5 = pack_array(s,ap);
    break;
  case 'b':
    piVar1 = (int *)ap->__ap;
    ap->__ap = piVar1 + 1;
    if (*piVar1 == 0) {
      pjVar5 = json_false();
    }
    else {
      pjVar5 = json_true();
    }
    break;
  case 'f':
    pdVar3 = (double *)((int)ap->__ap + 7U & 0xfffffff8);
    ap->__ap = pdVar3 + 1;
    pjVar5 = json_real(*pdVar3);
    break;
  case 'i':
    piVar1 = (int *)ap->__ap;
    ap->__ap = piVar1 + 1;
    pjVar5 = json_integer((longlong)*piVar1);
    break;
  case 'n':
    pjVar5 = json_null();
    break;
  case 'o':
    next_token(s);
    bVar6 = (s->token).token != '?';
    if (bVar6) {
      prev_token(s);
    }
    puVar4 = (undefined4 *)ap->__ap;
    ap->__ap = puVar4 + 1;
    pjVar5 = (json_t *)*puVar4;
    if ((pjVar5 == (json_t *)0x0) && (!bVar6)) {
      pjVar5 = json_null();
    }
    break;
  case 's':
    pjVar5 = pack_string(s,ap);
    break;
  case '{':
    pjVar5 = pack_object(s,ap);
  }
  return pjVar5;
}


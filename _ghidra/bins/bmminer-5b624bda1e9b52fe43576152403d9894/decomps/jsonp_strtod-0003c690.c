
/* WARNING: Unknown calling convention */

int jsonp_strtod(strbuffer_t *strbuffer,double *out)

{
  char cVar1;
  lconv *plVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  char *__s;
  double dVar6;
  char *local_1c [2];
  
  plVar2 = localeconv();
  __s = strbuffer->value;
  cVar1 = *plVar2->decimal_point;
  if ((cVar1 != '.') && (pcVar3 = strchr(__s,0x2e), pcVar3 != (char *)0x0)) {
    *pcVar3 = cVar1;
    __s = strbuffer->value;
  }
  piVar4 = __errno_location();
  *piVar4 = 0;
  dVar6 = strtod(__s,local_1c);
  if (local_1c[0] == strbuffer->value + strbuffer->length) {
    if (((dVar6 <= 1.79769313486232e+308) &&
        (-1 < (int)((uint)(dVar6 < -1.79769313486232e+308) << 0x1f))) || (*piVar4 != 0x22)) {
      iVar5 = 0;
      *out = dVar6;
    }
    else {
      iVar5 = -1;
    }
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("end == strbuffer->value + strbuffer->length","compat/jansson-2.6/src/strconv.c",
                0x45,"jsonp_strtod");
}


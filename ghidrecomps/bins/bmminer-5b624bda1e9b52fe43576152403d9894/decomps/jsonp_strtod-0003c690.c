
/* WARNING: Unknown calling convention */

int jsonp_strtod(strbuffer_t *strbuffer,double *out)

{
  char cVar1;
  lconv *plVar2;
  char **point;
  char *pcVar3;
  char *pos;
  int *piVar4;
  int iVar5;
  char *__s;
  double dVar6;
  char *end;
  
  plVar2 = localeconv();
  __s = strbuffer->value;
  cVar1 = *plVar2->decimal_point;
  if ((cVar1 != '.') && (pcVar3 = strchr(__s,0x2e), pcVar3 != (char *)0x0)) {
    *pcVar3 = cVar1;
    __s = strbuffer->value;
  }
  piVar4 = __errno_location();
  *piVar4 = 0;
  dVar6 = strtod(__s,&end);
  if (end == strbuffer->value + strbuffer->length) {
    if (((dVar6 == DAT_0003c718 || dVar6 < DAT_0003c718 != (NAN(dVar6) || NAN(DAT_0003c718))) &&
        (-1 < (int)((uint)(dVar6 < DAT_0003c720) << 0x1f))) || (*piVar4 != 0x22)) {
      iVar5 = 0;
      *out = dVar6;
    }
    else {
      iVar5 = -1;
    }
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail(DAT_0003c728,DAT_0003c72c,0x45,DAT_0003c730);
}


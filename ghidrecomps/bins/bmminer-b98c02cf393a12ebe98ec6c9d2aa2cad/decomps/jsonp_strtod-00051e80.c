
undefined4 jsonp_strtod(char **param_1,double *param_2)

{
  char cVar1;
  lconv *plVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  char *__s;
  double dVar6;
  char *local_1c [2];
  
  plVar2 = localeconv();
  __s = *param_1;
  cVar1 = *plVar2->decimal_point;
  if ((cVar1 != '.') && (pcVar3 = strchr(__s,0x2e), pcVar3 != (char *)0x0)) {
    *pcVar3 = cVar1;
    __s = *param_1;
  }
  piVar4 = __errno_location();
  *piVar4 = 0;
  dVar6 = strtod(__s,local_1c);
  if (local_1c[0] == param_1[1] + (int)*param_1) {
    if (((dVar6 == DAT_00051f18 || dVar6 < DAT_00051f18 != (NAN(dVar6) || NAN(DAT_00051f18))) &&
        (-1 < (int)((uint)(dVar6 < DAT_00051f20) << 0x1f))) || (*piVar4 != 0x22)) {
      uVar5 = 0;
      *param_2 = dVar6;
    }
    else {
      uVar5 = 0xffffffff;
    }
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("end == strbuffer->value + strbuffer->length","compat/jansson-2.9/src/strconv.c",
                0x50,"jsonp_strtod");
}


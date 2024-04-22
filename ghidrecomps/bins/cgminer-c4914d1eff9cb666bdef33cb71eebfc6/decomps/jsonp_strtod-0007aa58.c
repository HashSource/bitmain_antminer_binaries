
int jsonp_strtod(strbuffer_t *strbuffer,double *out)

{
  int *piVar1;
  int iVar2;
  double *out_local;
  strbuffer_t *strbuffer_local;
  char *end;
  double value;
  
  to_locale(strbuffer);
  piVar1 = __errno_location();
  *piVar1 = 0;
  value = strtod(strbuffer->value,&end);
  if (strbuffer->value + strbuffer->length != end) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("end == strbuffer->value + strbuffer->length","compat/jansson-2.9/src/strconv.c",
                  0x50,"jsonp_strtod");
  }
  if (((value == DAT_0007ab00 || value < DAT_0007ab00 != (NAN(value) || NAN(DAT_0007ab00))) &&
      (-1 < (int)((uint)(value < DAT_0007ab08) << 0x1f))) ||
     (piVar1 = __errno_location(), *piVar1 != 0x22)) {
    *(undefined4 *)out = value._0_4_;
    *(undefined4 *)((int)out + 4) = value._4_4_;
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


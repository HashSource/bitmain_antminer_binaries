
undefined4 jsonp_strtod(char **param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  char *local_14;
  undefined8 local_10;
  
  to_locale(param_1);
  piVar1 = __errno_location();
  *piVar1 = 0;
  local_10 = strtod(*param_1,&local_14);
  if (*param_1 + (int)param_1[1] != local_14) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("end == strbuffer->value + strbuffer->length","3rdparty/jansson-2.6/src/strconv.c"
                  ,0x46,"jsonp_strtod");
  }
  piVar1 = __errno_location();
  if ((*piVar1 == 0x22) && (local_10 != 0.0)) {
    uVar2 = 0xffffffff;
  }
  else {
    *param_2 = (undefined4)local_10;
    param_2[1] = local_10._4_4_;
    uVar2 = 0;
  }
  return uVar2;
}


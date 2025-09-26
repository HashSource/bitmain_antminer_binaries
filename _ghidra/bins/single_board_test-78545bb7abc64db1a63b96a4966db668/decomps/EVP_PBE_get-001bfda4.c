
undefined4 EVP_PBE_get(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  if (0x1c < param_3) {
    return 0;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(&builtin_pbe + param_3 * 0x14);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(&DAT_0027f610 + param_3 * 0x14);
  }
  return 1;
}


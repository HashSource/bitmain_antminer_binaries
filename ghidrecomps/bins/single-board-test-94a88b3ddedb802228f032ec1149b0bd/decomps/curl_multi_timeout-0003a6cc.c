
undefined4 curl_multi_timeout(int *param_1,undefined4 *param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 0xbab1e)) {
    if (param_1[0x11] != 0) {
      multi_timeout_part_1();
      return 0;
    }
    *param_2 = 0xffffffff;
    return 0;
  }
  return 1;
}


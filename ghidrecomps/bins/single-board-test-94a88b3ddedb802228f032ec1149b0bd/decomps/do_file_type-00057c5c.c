
undefined4 do_file_type(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
     (iVar1 = Curl_raw_equal(param_1,DAT_00057ca4), iVar1 != 0)) {
    return 1;
  }
  iVar1 = Curl_raw_equal(param_1,DAT_00057ca8);
  if (iVar1 != 0) {
    return 2;
  }
  iVar1 = Curl_raw_equal(param_1,DAT_00057cac);
  if (iVar1 == 0) {
    iVar1 = Curl_raw_equal(param_1,DAT_00057cb0);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0x2b;
    }
    return uVar2;
  }
  return 0x2a;
}


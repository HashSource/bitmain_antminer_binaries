
undefined4 process_zlib_error(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(param_2 + 0x18) != 0) {
    Curl_failf(*param_1,DAT_0004cd80,*(int *)(param_2 + 0x18),param_4,param_4);
    return 0x3d;
  }
  Curl_failf(*param_1,DAT_0004cd84,0,param_4,param_4);
  return 0x3d;
}


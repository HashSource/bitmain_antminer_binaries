
void Curl_unencode_deflate_write(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  void *__s;
  
  if (*(int *)(param_2 + 0x90) == 0) {
    __s = (void *)(param_2 + 0x94);
    memset(__s,0,0x38);
    *(undefined4 *)(param_2 + 0xb4) = 0x4cd3d;
    *(undefined4 *)(param_2 + 0xb8) = 0x4cd51;
    iVar1 = inflateInit_(__s,"1.2.8",0x38);
    if (iVar1 != 0) {
      process_zlib_error(param_1,__s);
      return;
    }
    *(undefined4 *)(param_2 + 0x90) = 1;
  }
  *(undefined4 *)(param_2 + 0x98) = param_3;
  *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x5c);
  inflate_stream(param_1,param_2);
  return;
}


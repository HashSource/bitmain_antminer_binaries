
void Curl_unencode_deflate_write(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  void *__s;
  
  if (*(int *)(param_2 + 0x90) == 0) {
    __s = (void *)(param_2 + 0x94);
    memset(__s,0,0x38);
    uVar2 = DAT_0004cfec;
    uVar1 = DAT_0004cfe8;
    *(undefined4 *)(param_2 + 0xb4) = DAT_0004cff0;
    *(undefined4 *)(param_2 + 0xb8) = uVar1;
    iVar3 = inflateInit_(__s,uVar2,0x38);
    if (iVar3 != 0) {
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


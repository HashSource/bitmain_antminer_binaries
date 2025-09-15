
void PL_ERROR(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = **(int **)(*param_1 + 0x86e8);
  if (*(int *)(iVar1 + 0x10) != 0) {
    Curl_fileinfo_dtor(0);
  }
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  return;
}


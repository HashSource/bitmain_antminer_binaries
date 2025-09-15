
void Curl_unencode_cleanup(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0xe0) != 0) {
    inflateEnd(iVar1 + 0xe4);
    *(undefined4 *)(iVar1 + 0xe0) = 0;
  }
  return;
}


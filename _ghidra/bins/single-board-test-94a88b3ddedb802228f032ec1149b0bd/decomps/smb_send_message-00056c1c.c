
void smb_send_message(int *param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  int local_1c;
  
  iVar2 = param_4 + 0x24;
  smb_format_message(param_1,*param_1 + 0x459d,param_2);
  memcpy((void *)(*param_1 + 0x45c1),param_3,param_4);
  iVar1 = Curl_write(param_1,0,*param_1 + 0x459d,iVar2,&local_1c);
  if (iVar1 == 0) {
    if (iVar2 != local_1c) {
      param_1[0xfa] = local_1c;
    }
    if (iVar2 != local_1c) {
      param_1[0xf9] = iVar2;
    }
    param_1[0xf8] = 0;
  }
  return;
}


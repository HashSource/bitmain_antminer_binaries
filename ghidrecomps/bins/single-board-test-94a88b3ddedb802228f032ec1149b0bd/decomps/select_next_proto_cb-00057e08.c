
undefined4
select_next_proto_cb
          (undefined4 param_1,undefined4 *param_2,undefined1 *param_3,int param_4,uint param_5,
          undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  void *__s1;
  
  if (7 < param_5) {
    iVar2 = 0;
    do {
      __s1 = (void *)(param_4 + iVar2 + 1);
      iVar1 = memcmp(__s1,&DAT_0013ad70,8);
      if (iVar1 == 0) {
        *param_2 = __s1;
        *param_3 = *(undefined1 *)(param_4 + iVar2);
        Curl_infof(*param_6,"NPN, negotiated HTTP1.1\n");
        param_6[0x11d] = 2;
        return 0;
      }
      iVar2 = iVar2 + *(byte *)(param_4 + iVar2) + 1;
    } while (iVar2 + 8U <= param_5);
  }
  Curl_infof(*param_6,"NPN, no overlap, use HTTP1.1\n");
  *param_2 = &DAT_0013ad70;
  *param_3 = 8;
  param_6[0x11d] = 2;
  return 0;
}



undefined4
select_next_proto_cb
          (undefined4 param_1,void **param_2,undefined *param_3,int param_4,uint param_5,
          undefined4 *param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *__s1;
  
  if (7 < param_5) {
    iVar3 = 0;
    do {
      __s1 = (void *)(param_4 + iVar3 + 1);
      iVar2 = memcmp(__s1,DAT_00057e84,8);
      if (iVar2 == 0) {
        *param_2 = __s1;
        uVar1 = DAT_00057e88;
        *param_3 = *(undefined *)(param_4 + iVar3);
        Curl_infof(*param_6,uVar1);
        param_6[0x11d] = 2;
        return 0;
      }
      iVar3 = iVar3 + *(byte *)(param_4 + iVar3) + 1;
    } while (iVar3 + 8U <= param_5);
  }
  Curl_infof(*param_6,DAT_00057e8c);
  *param_2 = DAT_00057e84;
  *param_3 = 8;
  param_6[0x11d] = 2;
  return 0;
}


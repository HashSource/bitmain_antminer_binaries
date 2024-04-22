
undefined4
sasl_create_plain_message
          (undefined4 param_1,char *param_2,char *param_3,undefined4 *param_4,undefined4 *param_5)

{
  size_t __n;
  size_t __n_00;
  void *__dest;
  undefined4 uVar1;
  int iVar2;
  
  __n = strlen(param_2);
  __n_00 = strlen(param_3);
  iVar2 = __n_00 + 2 + __n * 2;
  __dest = (void *)(**DAT_000551bc)(iVar2);
  if (__dest == (void *)0x0) {
    uVar1 = 0x1b;
    *param_5 = 0;
    *param_4 = 0;
  }
  else {
    memcpy(__dest,param_2,__n);
    *(undefined *)((int)__dest + __n) = 0;
    memcpy((void *)((int)__dest + __n + 1),param_2,__n);
    *(undefined *)((int)__dest + __n * 2 + 1) = 0;
    memcpy((void *)((int)__dest + (__n + 1) * 2),param_3,__n_00);
    uVar1 = Curl_base64_encode(param_1,__dest,iVar2,param_4,param_5);
    (**DAT_000551c0)(__dest);
  }
  return uVar1;
}


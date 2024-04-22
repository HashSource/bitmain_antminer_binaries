
int Curl_ntlm_core_mk_ntlmv2_resp
              (undefined4 param_1,undefined4 *param_2,int param_3,void **param_4,size_t *param_5)

{
  longlong lVar1;
  time_t tVar2;
  undefined4 *__s;
  int iVar3;
  undefined4 uVar4;
  size_t __n;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  tVar2 = time((time_t *)0x0);
  __n = *(int *)(param_3 + 0x14) + 0x30;
  __s = (undefined4 *)(**DAT_0005fa88)(__n);
  if (__s == (undefined4 *)0x0) {
    iVar3 = 0x1b;
  }
  else {
    memset(__s,0,__n);
    curl_msnprintf(__s + 4,*(int *)(param_3 + 0x14) + 0x20,DAT_0005fa8c,0,0,0,0);
    lVar1 = (longlong)tVar2 * 10000000 + CONCAT44(DAT_0005fa84,DAT_0005fa80);
    Curl_write64_le((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),__s + 6);
    uVar4 = param_2[1];
    __s[8] = *param_2;
    __s[9] = uVar4;
    memcpy(__s + 0xb,*(void **)(param_3 + 0x10),*(size_t *)(param_3 + 0x14));
    uVar4 = *(undefined4 *)(param_3 + 0xc);
    __s[2] = *(undefined4 *)(param_3 + 8);
    __s[3] = uVar4;
    iVar3 = Curl_hmac_md5(param_1,0x10,__s + 2,*(int *)(param_3 + 0x14) + 0x28,&local_38);
    if (iVar3 == 0) {
      __s[3] = uStack_2c;
      *__s = local_38;
      __s[1] = uStack_34;
      __s[2] = uStack_30;
      *param_4 = __s;
      *param_5 = __n;
    }
    else {
      (**DAT_0005fa90)(__s);
    }
  }
  return iVar3;
}


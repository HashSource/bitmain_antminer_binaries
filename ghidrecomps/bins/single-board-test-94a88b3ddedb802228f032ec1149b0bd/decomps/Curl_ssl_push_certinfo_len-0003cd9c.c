
undefined4
Curl_ssl_push_certinfo_len(int param_1,int param_2,char *param_3,void *param_4,size_t param_5)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  
  pvVar5 = param_4;
  sVar1 = strlen(param_3);
  iVar4 = sVar1 + param_5 + 2;
  iVar2 = (**DAT_0003ce24)(iVar4);
  if (iVar2 != 0) {
    curl_msnprintf(iVar2,iVar4,DAT_0003ce28,param_3,pvVar5);
    memcpy((void *)(iVar2 + sVar1 + 1),param_4,param_5);
    *(undefined *)(iVar2 + sVar1 + param_5 + 1) = 0;
    iVar4 = Curl_slist_append_nodup(*(undefined4 *)(*(int *)(param_1 + 0x8790) + param_2 * 4),iVar2)
    ;
    uVar3 = 0;
    if (iVar4 == 0) {
      (**DAT_0003ce2c)(iVar2);
      curl_slist_free_all(*(undefined4 *)(*(int *)(param_1 + 0x8790) + param_2 * 4));
      uVar3 = 0x1b;
    }
    *(int *)(*(int *)(param_1 + 0x8790) + param_2 * 4) = iVar4;
    return uVar3;
  }
  return 0x1b;
}


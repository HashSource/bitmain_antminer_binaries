
int pop3_perform_apop_part_11(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined local_4c [16];
  undefined auStack_3c [36];
  
  iVar2 = Curl_MD5_init(DAT_00051408);
  iVar3 = 0x1b;
  if (iVar2 != 0) {
    pcVar5 = *(char **)(param_1 + 0x428);
    iVar3 = 0;
    strlen(pcVar5);
    uVar4 = curlx_uztoui();
    Curl_MD5_update(iVar2,pcVar5,uVar4);
    pcVar5 = *(char **)(param_1 + 0x124);
    strlen(pcVar5);
    uVar4 = curlx_uztoui();
    Curl_MD5_update(iVar2,pcVar5,uVar4);
    Curl_MD5_final(iVar2,local_4c);
    do {
      iVar2 = iVar3 * 2;
      puVar1 = local_4c + iVar3;
      iVar3 = iVar3 + 1;
      curl_msnprintf(auStack_3c + iVar2,3,DAT_0005140c,*puVar1);
    } while (iVar3 != 0x10);
    iVar3 = Curl_pp_sendf(param_1 + 0x3c0,DAT_00051410,*(undefined4 *)(param_1 + 0x120),auStack_3c);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x3f8) = 6;
    }
  }
  return iVar3;
}


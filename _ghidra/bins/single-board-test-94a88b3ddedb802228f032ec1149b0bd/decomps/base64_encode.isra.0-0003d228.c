
undefined4
base64_encode_isra_0(int param_1,byte *param_2,size_t param_3,undefined4 *param_4,size_t *param_5)

{
  char *pcVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *__s;
  uint uVar7;
  byte local_2c [8];
  
  *param_4 = 0;
  *param_5 = 0;
  if (param_3 == 0) {
    param_3 = strlen((char *)param_2);
    pcVar1 = (char *)(*Curl_cmalloc)((param_3 * 4) / 3 + 4,param_3 * -0x55555554);
    __s = pcVar1;
    if (pcVar1 != (char *)0x0) goto joined_r0x0003d35c;
  }
  else {
    pcVar1 = (char *)(*Curl_cmalloc)((param_3 << 2) / 3 + 4);
    __s = pcVar1;
    if (pcVar1 != (char *)0x0) {
      do {
        iVar5 = 0;
        iVar4 = 0;
        do {
          if (param_3 == 0) {
            local_2c[iVar5] = 0;
          }
          else {
            iVar4 = iVar4 + 1;
            param_3 = param_3 - 1;
            local_2c[iVar5] = *param_2;
            param_2 = param_2 + 1;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != 3);
        uVar3 = (uint)(local_2c[1] >> 4) | (local_2c[0] & 3) << 4;
        uVar6 = (uint)(local_2c[0] >> 2);
        uVar7 = (uint)(local_2c[2] >> 6) | (local_2c[1] & 0xf) << 2;
        if (iVar4 == 1) {
          curl_msnprintf(pcVar1,5,"%c%c==",*(undefined1 *)(param_1 + uVar6),
                         *(undefined1 *)(param_1 + uVar3));
        }
        else if (iVar4 == 2) {
          curl_msnprintf(pcVar1,5,"%c%c%c=",*(undefined1 *)(param_1 + uVar6),
                         *(undefined1 *)(param_1 + uVar3),*(undefined1 *)(param_1 + uVar7));
        }
        else {
          curl_msnprintf(pcVar1,5,"%c%c%c%c",*(undefined1 *)(param_1 + uVar6),
                         *(undefined1 *)(param_1 + uVar3),*(undefined1 *)(param_1 + uVar7),
                         *(undefined1 *)(param_1 + (local_2c[2] & 0x3f)));
        }
        pcVar1 = pcVar1 + 4;
joined_r0x0003d35c:
      } while (param_3 != 0);
      *pcVar1 = '\0';
      *param_4 = __s;
      (*Curl_cfree)(0);
      sVar2 = strlen(__s);
      *param_5 = sVar2;
      return 0;
    }
  }
  return 0x1b;
}


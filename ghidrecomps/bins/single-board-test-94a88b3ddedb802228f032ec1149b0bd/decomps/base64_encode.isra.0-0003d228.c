
undefined4
base64_encode_isra_0(int param_1,byte *param_2,size_t param_3,char **param_4,size_t *param_5)

{
  code **ppcVar1;
  char *pcVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *__s;
  uint uVar8;
  byte local_2c [8];
  
  *param_4 = (char *)0x0;
  *param_5 = 0;
  if (param_3 == 0) {
    param_3 = strlen((char *)param_2);
    pcVar2 = (char *)(**DAT_0003d368)((param_3 * 4) / 3 + 4,param_3 * -0x55555554);
    __s = pcVar2;
    ppcVar1 = DAT_0003d370;
    if (pcVar2 != (char *)0x0) goto joined_r0x0003d35c;
  }
  else {
    pcVar2 = (char *)(**DAT_0003d368)((param_3 << 2) / 3 + 4);
    __s = pcVar2;
    if (pcVar2 != (char *)0x0) {
      do {
        iVar6 = 0;
        iVar5 = 0;
        do {
          if (param_3 == 0) {
            local_2c[iVar6] = 0;
          }
          else {
            iVar5 = iVar5 + 1;
            param_3 = param_3 - 1;
            local_2c[iVar6] = *param_2;
            param_2 = param_2 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 3);
        uVar4 = (uint)(local_2c[1] >> 4) | (local_2c[0] & 3) << 4;
        uVar7 = (uint)(local_2c[0] >> 2);
        uVar8 = (uint)(local_2c[2] >> 6) | (local_2c[1] & 0xf) << 2;
        if (iVar5 == 1) {
          curl_msnprintf(pcVar2,5,DAT_0003d378,*(undefined *)(param_1 + uVar7),
                         *(undefined *)(param_1 + uVar4));
        }
        else if (iVar5 == 2) {
          curl_msnprintf(pcVar2,5,DAT_0003d374,*(undefined *)(param_1 + uVar7),
                         *(undefined *)(param_1 + uVar4),*(undefined *)(param_1 + uVar8));
        }
        else {
          curl_msnprintf(pcVar2,5,DAT_0003d36c,*(undefined *)(param_1 + uVar7),
                         *(undefined *)(param_1 + uVar4),*(undefined *)(param_1 + uVar8),
                         *(undefined *)(param_1 + (local_2c[2] & 0x3f)));
        }
        pcVar2 = pcVar2 + 4;
        ppcVar1 = DAT_0003d370;
joined_r0x0003d35c:
        DAT_0003d370 = ppcVar1;
      } while (param_3 != 0);
      *pcVar2 = '\0';
      *param_4 = __s;
      (**ppcVar1)(0);
      sVar3 = strlen(__s);
      *param_5 = sVar3;
      return 0;
    }
  }
  return 0x1b;
}


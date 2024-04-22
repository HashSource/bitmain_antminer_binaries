
undefined4 check_noproxy(char *param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  size_t sVar7;
  
  if (param_2 != (char *)0x0) {
    if (*param_2 == '\0') {
      return 0;
    }
    iVar1 = Curl_raw_equal(DAT_00043920);
    if (iVar1 != 0) {
      return 1;
    }
    sVar2 = strlen(param_2);
    pcVar3 = strchr(param_1,0x3a);
    if (pcVar3 == (char *)0x0) {
      sVar7 = strlen(param_1);
    }
    else {
      sVar7 = (int)pcVar3 - (int)param_1;
    }
    if (sVar2 != 0) {
      sVar4 = 0;
      if (sVar2 != 0) goto LAB_000438c2;
LAB_0004389a:
      uVar5 = sVar4;
      if (sVar2 != sVar4) {
        do {
          do {
            if (param_2[sVar4] == '.') {
              sVar4 = sVar4 + 1;
            }
            uVar6 = uVar5 - sVar4;
            if (uVar6 <= sVar7) {
              iVar1 = Curl_raw_nequal(param_2 + sVar4,param_1 + (sVar7 - uVar5) + sVar4,uVar6);
              if (iVar1 != 0) {
                if (uVar6 == sVar7) {
                  return 1;
                }
                if ((param_1 + (sVar7 - uVar5) + sVar4)[-1] == '.') {
                  return 1;
                }
              }
            }
            sVar4 = uVar5 + 1;
            if (sVar2 <= sVar4) {
              return 0;
            }
LAB_000438c2:
            while (pcVar3 = strchr(DAT_00043924,(uint)(byte)param_2[sVar4]), pcVar3 != (char *)0x0)
            {
              sVar4 = sVar4 + 1;
              if (sVar2 <= sVar4) goto LAB_0004389a;
            }
            if (sVar2 == sVar4) {
              return 0;
            }
            uVar5 = sVar4;
          } while (sVar2 <= sVar4);
          do {
            pcVar3 = strchr(DAT_00043924,(uint)(byte)param_2[uVar5]);
            if (pcVar3 != (char *)0x0) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < sVar2);
        } while( true );
      }
    }
  }
  return 0;
}


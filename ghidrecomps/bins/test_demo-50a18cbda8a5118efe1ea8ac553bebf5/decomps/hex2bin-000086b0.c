
uint hex2bin(int param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  long lVar5;
  uint uVar6;
  undefined *puVar7;
  char local_20;
  char local_1f;
  undefined local_1e;
  char *local_1c [2];
  
  local_1e = 0;
  if (*param_2 == '\0') {
    uVar6 = (uint)(param_3 == 0);
  }
  else if (param_3 == 0) {
LAB_0000870c:
    uVar6 = 1;
  }
  else {
    if (param_2[1] != '\0') {
      puVar7 = (undefined *)(param_1 + -1);
      cVar3 = *param_2;
      cVar4 = param_2[1];
      do {
        local_1f = cVar4;
        local_20 = cVar3;
        param_3 = param_3 - 1;
        lVar5 = strtol(&local_20,local_1c,0x10);
        puVar7 = puVar7 + 1;
        *puVar7 = (char)lVar5;
        if (*local_1c[0] != '\0') {
          printf(DAT_0000872c,&local_20);
          return 0;
        }
        pcVar1 = param_2 + 2;
        if (*pcVar1 == '\0') {
          if (param_3 < 2) {
            return 1 - param_3;
          }
          return 0;
        }
        if (param_3 == 0) goto LAB_0000870c;
        pcVar2 = param_2 + 3;
        param_2 = param_2 + 2;
        cVar3 = *pcVar1;
        cVar4 = *pcVar2;
      } while (*pcVar2 != '\0');
    }
    printf(DAT_00008730);
    uVar6 = 0;
  }
  return uVar6;
}


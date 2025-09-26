
uint UI_set_result_ex(int param_1,uint *param_2,byte *param_3,size_t param_4)

{
  char *pcVar1;
  undefined1 extraout_r2;
  undefined1 uVar2;
  uint uVar3;
  int line;
  uint uVar4;
  char *__s;
  char *__s_00;
  char acStack_40 [16];
  char acStack_30 [16];
  
  uVar3 = *param_2;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  if (uVar3 == 0) {
LAB_001cf598:
    uVar3 = 0;
  }
  else {
    if (uVar3 < 3) {
      BIO_snprintf(acStack_40,0xd,"%d",param_2[5]);
      BIO_snprintf(acStack_30,0xd,"%d",param_2[6]);
      if ((int)param_4 < (int)param_2[5]) {
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 1;
        ERR_put_error(0x28,0x78,0x65,"crypto/ui/ui_lib.c",0x389);
        ERR_add_error_data(5,"You must type in ",acStack_40,&DAT_00246b34,acStack_30," characters");
      }
      else {
        if ((int)param_4 <= (int)param_2[6]) {
          if ((void *)param_2[3] != (void *)0x0) {
            memcpy((void *)param_2[3],param_3,param_4);
            uVar4 = param_2[6];
            uVar2 = extraout_r2;
            uVar3 = uVar4;
            if ((int)param_4 <= (int)uVar4) {
              uVar3 = param_2[3];
              uVar2 = 0;
            }
            if ((int)param_4 <= (int)uVar4) {
              *(undefined1 *)(uVar3 + param_4) = uVar2;
            }
            param_2[4] = param_4;
            return 0;
          }
          line = 0x398;
          goto LAB_001cf68c;
        }
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 1;
        ERR_put_error(0x28,0x78,100,"crypto/ui/ui_lib.c",0x390);
        ERR_add_error_data(5,"You must type in ",acStack_40,&DAT_00246b34,acStack_30," characters");
      }
    }
    else {
      if (uVar3 != 3) goto LAB_001cf598;
      if ((undefined1 *)param_2[3] != (undefined1 *)0x0) {
        *(undefined1 *)param_2[3] = 0;
        uVar3 = (uint)*param_3;
        if (uVar3 != 0) {
          __s_00 = (char *)param_2[6];
          do {
            pcVar1 = strchr(__s_00,uVar3);
            if (pcVar1 != (char *)0x0) {
              *(char *)param_2[3] = *__s_00;
              return 0;
            }
            __s = (char *)param_2[7];
            pcVar1 = strchr(__s,(uint)*param_3);
            if (pcVar1 != (char *)0x0) {
              *(char *)param_2[3] = *__s;
              return 0;
            }
            param_3 = param_3 + 1;
            uVar3 = (uint)*param_3;
          } while (uVar3 != 0);
        }
        return uVar3;
      }
      line = 0x3a6;
LAB_001cf68c:
      ERR_put_error(0x28,0x78,0x69,"crypto/ui/ui_lib.c",line);
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


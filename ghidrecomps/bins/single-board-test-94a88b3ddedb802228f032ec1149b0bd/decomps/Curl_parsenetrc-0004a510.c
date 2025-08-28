
undefined4 Curl_parsenetrc(undefined4 param_1,int *param_2,int *param_3,char *param_4)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  __uid_t __uid;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  int local_454;
  FILE *local_44c;
  passwd *local_448;
  passwd pStack_444;
  char acStack_428 [1028];
  
  pbVar5 = (byte *)*param_2;
  if ((pbVar5 != (byte *)0x0) && (pbVar5 = (byte *)(uint)*pbVar5, pbVar5 != (byte *)0x0)) {
    pbVar5 = (byte *)0x1;
  }
  if (param_4 == (char *)0x0) {
    iVar7 = curl_getenv(&DAT_001377cc);
    if (iVar7 == 0) {
      __uid = geteuid();
      iVar7 = getpwuid_r(__uid,&pStack_444,acStack_428,0x400,&local_448);
      if (iVar7 != 0) {
        return 1;
      }
      if (local_448 == (passwd *)0x0) {
        return 1;
      }
      iVar7 = (*Curl_cstrdup)(pStack_444.pw_dir);
      if (iVar7 == 0) {
        return 0x1b;
      }
    }
    pcVar2 = (char *)curl_maprintf("%s%s%s",iVar7,&DAT_00135588,".netrc");
    (*Curl_cfree)(iVar7);
    if (pcVar2 == (char *)0x0) {
      return 0xffffffff;
    }
    local_44c = fopen64(pcVar2,"r");
    (*Curl_cfree)(pcVar2);
  }
  else {
    local_44c = fopen64(param_4,"r");
  }
  if (local_44c == (FILE *)0x0) {
    return 1;
  }
  uVar8 = 1;
  bVar9 = false;
  iVar7 = 0;
  local_454 = 0;
  bVar1 = false;
  do {
    pcVar2 = fgets(acStack_428,0x100,local_44c);
    if (pcVar2 == (char *)0x0) {
LAB_0004a636:
      fclose(local_44c);
      return uVar8;
    }
    pcVar2 = __strtok_r(acStack_428," \t\n",(char **)&local_448);
    while (pcVar2 != (char *)0x0) {
      pcVar3 = (char *)*param_2;
      if ((((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) && ((char *)*param_3 != (char *)0x0)) &&
         (*(char *)*param_3 != '\0')) goto LAB_0004a636;
      if (iVar7 == 1) {
        iVar7 = Curl_raw_equal(param_1,pcVar2);
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          uVar8 = 0;
          iVar7 = 2;
        }
      }
      else if (iVar7 == 0) {
        iVar4 = Curl_raw_equal("machine",pcVar2);
        if (iVar4 == 0) {
          iVar4 = Curl_raw_equal("default",pcVar2);
          if (iVar4 != 0) {
            iVar7 = 2;
            uVar8 = 0;
          }
        }
        else {
          iVar7 = 1;
        }
      }
      else if (iVar7 == 2) {
        if (bVar9) {
          if (pbVar5 == (byte *)0x0) {
            (*Curl_cfree)();
            iVar4 = (*Curl_cstrdup)(pcVar2);
            *param_2 = iVar4;
            if (iVar4 == 0) {
              uVar8 = 0xffffffff;
              goto LAB_0004a636;
            }
          }
          else {
            local_454 = Curl_raw_equal(pcVar3,pcVar2);
          }
          bVar9 = false;
        }
        else if (bVar1) {
          uVar6 = ((uint)pbVar5 ^ 1) & 1;
          if (local_454 != 0) {
            uVar6 = 1;
          }
          if (uVar6 == 0) {
            local_454 = 0;
          }
          else {
            (*Curl_cfree)(*param_3);
            iVar4 = (*Curl_cstrdup)(pcVar2);
            *param_3 = iVar4;
            if (iVar4 == 0) {
              uVar8 = 0xffffffff;
              goto LAB_0004a636;
            }
          }
          bVar1 = false;
        }
        else {
          iVar4 = Curl_raw_equal("login",pcVar2);
          if (iVar4 == 0) {
            iVar4 = Curl_raw_equal("password",pcVar2);
            if (iVar4 == 0) {
              iVar7 = Curl_raw_equal("machine",pcVar2);
              if (iVar7 == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                local_454 = 0;
              }
            }
            else {
              bVar1 = true;
            }
          }
          else {
            bVar9 = true;
          }
        }
      }
      pcVar2 = __strtok_r((char *)0x0," \t\n",(char **)&local_448);
    }
  } while( true );
}


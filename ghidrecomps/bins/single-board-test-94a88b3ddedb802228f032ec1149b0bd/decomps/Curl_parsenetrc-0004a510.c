
undefined4 Curl_parsenetrc(undefined4 param_1,byte **param_2,char **param_3,char *param_4)

{
  bool bVar1;
  code **ppcVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  __uid_t __uid;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  int local_454;
  FILE *local_44c;
  passwd *local_448;
  passwd pStack_444;
  char acStack_428 [1028];
  
  pbVar6 = *param_2;
  if ((pbVar6 != (byte *)0x0) && (pbVar6 = (byte *)(uint)*pbVar6, pbVar6 != (byte *)0x0)) {
    pbVar6 = (byte *)0x1;
  }
  if (param_4 == (char *)0x0) {
    iVar8 = curl_getenv(DAT_0004a734);
    if (iVar8 == 0) {
      __uid = geteuid();
      iVar8 = getpwuid_r(__uid,&pStack_444,acStack_428,0x400,&local_448);
      if (iVar8 != 0) {
        return 1;
      }
      if (local_448 == (passwd *)0x0) {
        return 1;
      }
      iVar8 = (**DAT_0004a748)(pStack_444.pw_dir);
      if (iVar8 == 0) {
        return 0x1b;
      }
    }
    ppcVar2 = DAT_0004a738;
    pcVar3 = (char *)curl_maprintf(DAT_0004a740,iVar8,DAT_0004a744,DAT_0004a73c);
    (**ppcVar2)(iVar8);
    if (pcVar3 == (char *)0x0) {
      return 0xffffffff;
    }
    local_44c = fopen64(pcVar3,DAT_0004a71c);
    (**ppcVar2)(pcVar3);
  }
  else {
    local_44c = fopen64(param_4,DAT_0004a71c);
  }
  if (local_44c == (FILE *)0x0) {
    return 1;
  }
  uVar9 = 1;
  bVar10 = false;
  iVar8 = 0;
  local_454 = 0;
  bVar1 = false;
  do {
    pcVar3 = fgets(acStack_428,0x100,local_44c);
    if (pcVar3 == (char *)0x0) {
LAB_0004a636:
      fclose(local_44c);
      return uVar9;
    }
    pcVar3 = __strtok_r(acStack_428,DAT_0004a720,(char **)&local_448);
    while (pcVar3 != (char *)0x0) {
      pbVar4 = *param_2;
      if ((((pbVar4 != (byte *)0x0) && (*pbVar4 != 0)) && (*param_3 != (char *)0x0)) &&
         (**param_3 != '\0')) goto LAB_0004a636;
      if (iVar8 == 1) {
        iVar8 = Curl_raw_equal(param_1,pcVar3);
        if (iVar8 == 0) {
          iVar8 = 0;
        }
        else {
          uVar9 = 0;
          iVar8 = 2;
        }
      }
      else if (iVar8 == 0) {
        iVar5 = Curl_raw_equal(DAT_0004a724,pcVar3);
        if (iVar5 == 0) {
          iVar5 = Curl_raw_equal(DAT_0004a728,pcVar3);
          if (iVar5 != 0) {
            iVar8 = 2;
            uVar9 = 0;
          }
        }
        else {
          iVar8 = 1;
        }
      }
      else if (iVar8 == 2) {
        if (bVar10) {
          if (pbVar6 == (byte *)0x0) {
            (*Curl_cfree)();
            pbVar4 = (byte *)(*Curl_cstrdup)(pcVar3);
            *param_2 = pbVar4;
            if (pbVar4 == (byte *)0x0) {
              uVar9 = 0xffffffff;
              goto LAB_0004a636;
            }
          }
          else {
            local_454 = Curl_raw_equal(pbVar4,pcVar3);
          }
          bVar10 = false;
        }
        else if (bVar1) {
          uVar7 = ((uint)pbVar6 ^ 1) & 1;
          if (local_454 != 0) {
            uVar7 = 1;
          }
          if (uVar7 == 0) {
            local_454 = 0;
          }
          else {
            (*Curl_cfree)(*param_3);
            pcVar3 = (char *)(*Curl_cstrdup)(pcVar3);
            *param_3 = pcVar3;
            if (pcVar3 == (char *)0x0) {
              uVar9 = 0xffffffff;
              goto LAB_0004a636;
            }
          }
          bVar1 = false;
        }
        else {
          iVar5 = Curl_raw_equal(DAT_0004a72c,pcVar3);
          if (iVar5 == 0) {
            iVar5 = Curl_raw_equal(DAT_0004a730,pcVar3);
            if (iVar5 == 0) {
              iVar8 = Curl_raw_equal(DAT_0004a724,pcVar3);
              if (iVar8 == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                local_454 = 0;
              }
            }
            else {
              bVar1 = true;
            }
          }
          else {
            bVar10 = true;
          }
        }
      }
      pcVar3 = __strtok_r((char *)0x0,DAT_0004a720,(char **)&local_448);
    }
  } while( true );
}


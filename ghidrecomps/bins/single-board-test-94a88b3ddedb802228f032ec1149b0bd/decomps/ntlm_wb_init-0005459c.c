
undefined4 ntlm_wb_init(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  code **ppcVar2;
  byte *pbVar3;
  __uid_t __uid;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  __pid_t _Var7;
  byte *pbVar8;
  uint uVar9;
  code *pcVar10;
  undefined4 uVar11;
  passwd *local_440;
  int local_43c;
  int local_438;
  passwd local_434;
  char acStack_418 [1024];
  
  if ((param_1[0xa9] != -1) || (param_1[0xaa] != 0)) {
    return 0;
  }
  if (((((param_2 == (byte *)0x0) || (uVar9 = (uint)*param_2, pbVar3 = param_2, uVar9 == 0)) &&
       ((pbVar3 = (byte *)getenv(DAT_000547f4), pbVar3 == (byte *)0x0 ||
        (uVar9 = (uint)*pbVar3, uVar9 == 0)))) &&
      ((pbVar3 = (byte *)getenv(DAT_000547f8), pbVar3 == (byte *)0x0 ||
       (uVar9 = (uint)*pbVar3, uVar9 == 0)))) &&
     ((pbVar3 = (byte *)getenv(DAT_000547fc), pbVar3 == (byte *)0x0 ||
      (uVar9 = (uint)*pbVar3, uVar9 == 0)))) {
    __uid = geteuid();
    iVar4 = getpwuid_r(__uid,&local_434,acStack_418,0x400,&local_440);
    if ((iVar4 == 0) && (local_440 != (passwd *)0x0)) {
      pbVar3 = (byte *)local_434.pw_name;
    }
    if (((pbVar3 == (byte *)0x0) || (uVar9 = (uint)*pbVar3, uVar9 == 0)) &&
       (uVar9 = (uint)*param_2, pbVar3 = param_2, uVar9 == 0)) goto LAB_00054624;
  }
  pbVar8 = pbVar3;
  if ((uVar9 != 0x5c) && (uVar9 != 0x2f)) {
    do {
      pbVar8 = pbVar8 + 1;
      bVar1 = *pbVar8;
      if (bVar1 == 0) {
        uVar9 = 0;
        goto LAB_00054624;
      }
    } while ((bVar1 != 0x5c) && (bVar1 != 0x2f));
  }
  uVar9 = (**DAT_0005480c)(pbVar3);
  if (uVar9 == 0) {
    return 0x1b;
  }
  pbVar8[uVar9 - (int)pbVar3] = 0;
  pbVar3 = pbVar3 + (int)(pbVar8 + (1 - (int)pbVar3));
LAB_00054624:
  iVar4 = access(DAT_00054800,1);
  if (iVar4 == 0) {
    iVar4 = socketpair(1,1,0,&local_43c);
    if (iVar4 == 0) {
      _Var7 = fork();
      if (_Var7 != -1) {
        if (_Var7 != 0) {
          close(local_438);
          ppcVar2 = DAT_00054808;
          param_1[0xaa] = _Var7;
          pcVar10 = *ppcVar2;
          param_1[0xa9] = local_43c;
          (*pcVar10)(uVar9);
          (**ppcVar2)(0);
          return 0;
        }
        close(local_43c);
        iVar4 = dup2(local_438,0);
        if (iVar4 != -1) {
          iVar4 = dup2(local_438,1);
          if (iVar4 != -1) {
            if (uVar9 == 0) {
              execl(DAT_00054800,DAT_00054800,DAT_00054820,DAT_00054824,DAT_0005481c,DAT_00054814,
                    pbVar3,0);
            }
            else {
              execl(DAT_00054800,DAT_00054800,DAT_00054820,DAT_00054824,DAT_0005481c,DAT_00054814,
                    pbVar3,DAT_00054818,uVar9,0);
            }
            piVar5 = __errno_location();
            iVar4 = *piVar5;
            close(local_438);
            uVar11 = *param_1;
            uVar6 = Curl_strerror(param_1,iVar4);
            Curl_failf(uVar11,DAT_00054828,iVar4,uVar6);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          piVar5 = __errno_location();
          iVar4 = *piVar5;
          uVar11 = *param_1;
          uVar6 = Curl_strerror(param_1,iVar4);
          Curl_failf(uVar11,DAT_00054830,iVar4,uVar6);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        piVar5 = __errno_location();
        iVar4 = *piVar5;
        uVar11 = *param_1;
        uVar6 = Curl_strerror(param_1,iVar4);
        Curl_failf(uVar11,DAT_00054834,iVar4,uVar6);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      piVar5 = __errno_location();
      iVar4 = *piVar5;
      close(local_43c);
      close(local_438);
      uVar11 = *param_1;
      uVar6 = Curl_strerror(param_1,iVar4);
      Curl_failf(uVar11,DAT_0005482c,iVar4,uVar6);
    }
    else {
      piVar5 = __errno_location();
      iVar4 = *piVar5;
      uVar11 = *param_1;
      uVar6 = Curl_strerror(param_1,iVar4);
      Curl_failf(uVar11,DAT_00054810,iVar4,uVar6);
    }
  }
  else {
    piVar5 = __errno_location();
    iVar4 = *piVar5;
    uVar11 = *param_1;
    uVar6 = Curl_strerror(param_1,iVar4);
    Curl_failf(uVar11,DAT_00054804,DAT_00054800,iVar4,uVar6);
  }
  ppcVar2 = DAT_00054808;
  (**DAT_00054808)(uVar9);
  (**ppcVar2)(0);
  return 9;
}


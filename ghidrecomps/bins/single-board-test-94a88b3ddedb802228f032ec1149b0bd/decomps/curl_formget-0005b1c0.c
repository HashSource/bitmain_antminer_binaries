
int curl_formget(undefined4 param_1,undefined4 param_2,code *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *local_203c;
  undefined auStack_2038 [8];
  int *local_2030;
  undefined4 uStack_202c;
  FILE *local_2028;
  undefined4 local_2024;
  undefined auStack_2020 [8196];
  
  iVar1 = Curl_getformdata(0,&local_203c,param_1,0,auStack_2038);
  if (iVar1 == 0) {
    if (local_203c != (int *)0x0) {
      piVar5 = local_203c;
      do {
        if (piVar5[1] - 2U < 2) {
          uStack_202c = 0;
          local_2028 = (FILE *)0x0;
          local_2024 = 0;
          local_2030 = piVar5;
          do {
            uVar3 = readfromfile(&local_2030,auStack_2020,0x2000);
            if ((0x2000 < uVar3) || (uVar2 = (*param_3)(param_2,auStack_2020,uVar3), uVar2 != uVar3)
               ) {
              if (local_2028 != (FILE *)0x0) {
                fclose(local_2028);
              }
              goto LAB_0005b262;
            }
          } while (uVar2 != 0);
        }
        else {
          iVar4 = piVar5[3];
          iVar1 = (*param_3)(param_2,piVar5[2],iVar4);
          if (iVar4 != iVar1) {
LAB_0005b262:
            Curl_formclean(&local_203c);
            return -1;
          }
        }
        piVar5 = (int *)*piVar5;
      } while (piVar5 != (int *)0x0);
    }
    Curl_formclean(&local_203c);
    iVar1 = 0;
  }
  return iVar1;
}


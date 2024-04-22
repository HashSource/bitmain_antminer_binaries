
int ocsp_match_issuerid(undefined4 param_1,int param_2,_STACK *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int local_34;
  int local_30;
  
  if (param_2 != 0) {
    iVar1 = ocsp_match_issuerid_part_4();
    return iVar1;
  }
  local_34 = 0;
  do {
    iVar1 = sk_num(param_3);
    if (iVar1 <= local_34) {
      return 1;
    }
    piVar2 = (int *)sk_value(param_3,local_34);
    if (*piVar2 == 0) {
      for (local_30 = 0; iVar1 = sk_num((_STACK *)0x0), local_30 < iVar1; local_30 = local_30 + 1) {
        piVar2 = (int *)sk_value((_STACK *)0x0,local_30);
        if (*piVar2 == 0) {
          iVar3 = sk_num((_STACK *)0x0);
          iVar1 = 0;
          if (0 < iVar3) {
            do {
              piVar2 = (int *)sk_value((_STACK *)0x0,iVar1);
              if (*piVar2 == 0) {
                for (iVar3 = 0; iVar4 = sk_num((_STACK *)0x0), iVar3 < iVar4; iVar3 = iVar3 + 1) {
                  piVar2 = (int *)sk_value((_STACK *)0x0,iVar3);
                  if (*piVar2 == 0) {
                    for (iVar4 = 0; iVar5 = sk_num((_STACK *)0x0), iVar4 < iVar5; iVar4 = iVar4 + 1)
                    {
                      piVar2 = (int *)sk_value((_STACK *)0x0,iVar4);
                      if (*piVar2 == 0) {
                        for (iVar5 = 0; iVar6 = sk_num((_STACK *)0x0), iVar5 < iVar6;
                            iVar5 = iVar5 + 1) {
                          piVar2 = (int *)sk_value((_STACK *)0x0,iVar5);
                          if (*piVar2 == 0) {
                            for (iVar6 = 0; iVar7 = sk_num((_STACK *)0x0), iVar6 < iVar7;
                                iVar6 = iVar6 + 1) {
                              piVar2 = (int *)sk_value((_STACK *)0x0,iVar6);
                              if (*piVar2 == 0) {
                                for (iVar7 = 0; iVar8 = sk_num((_STACK *)0x0), iVar7 < iVar8;
                                    iVar7 = iVar7 + 1) {
                                  piVar2 = (int *)sk_value((_STACK *)0x0,iVar7);
                                  if (*piVar2 == 0) {
                                    iVar8 = 0;
                                    while( true ) {
                                      iVar10 = sk_num((_STACK *)0x0);
                                      if (iVar10 <= iVar8) break;
                                      puVar9 = (undefined4 *)sk_value((_STACK *)0x0,iVar8);
                                      iVar10 = ocsp_match_issuerid(param_1,*puVar9,0);
                                      iVar8 = iVar8 + 1;
                                      if (iVar10 < 1) {
                                        return iVar10;
                                      }
                                    }
                                  }
                                  else {
                                    iVar8 = ocsp_match_issuerid_part_4(param_1);
                                    if (iVar8 < 1) {
                                      return iVar8;
                                    }
                                  }
                                }
                              }
                              else {
                                iVar7 = ocsp_match_issuerid_part_4(param_1);
                                if (iVar7 < 1) {
                                  return iVar7;
                                }
                              }
                            }
                          }
                          else {
                            iVar6 = ocsp_match_issuerid_part_4(param_1);
                            if (iVar6 < 1) {
                              return iVar6;
                            }
                          }
                        }
                      }
                      else {
                        iVar5 = ocsp_match_issuerid_part_4(param_1);
                        if (iVar5 < 1) {
                          return iVar5;
                        }
                      }
                    }
                  }
                  else {
                    iVar4 = ocsp_match_issuerid_part_4(param_1);
                    if (iVar4 < 1) {
                      return iVar4;
                    }
                  }
                }
              }
              else {
                iVar3 = ocsp_match_issuerid_part_4(param_1);
                if (iVar3 < 1) {
                  return iVar3;
                }
              }
              iVar1 = iVar1 + 1;
              iVar3 = sk_num((_STACK *)0x0);
            } while (iVar1 < iVar3);
          }
        }
        else {
          iVar1 = ocsp_match_issuerid_part_4(param_1);
          if (iVar1 < 1) {
            return iVar1;
          }
        }
      }
    }
    else {
      iVar1 = ocsp_match_issuerid_part_4(param_1);
      if (iVar1 < 1) {
        return iVar1;
      }
    }
    local_34 = local_34 + 1;
  } while( true );
}


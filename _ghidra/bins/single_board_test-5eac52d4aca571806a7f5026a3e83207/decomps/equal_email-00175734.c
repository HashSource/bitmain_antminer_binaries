
bool equal_email(void *param_1,size_t param_2,void *param_3,size_t param_4)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  size_t sVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  
  if (param_2 != param_4) {
    return false;
  }
  if (param_2 != 0) {
    sVar5 = param_2 - 1;
    uVar4 = (uint)*(byte *)((int)param_1 + sVar5);
    pbVar8 = (byte *)((int)param_1 + sVar5);
    if (uVar4 == 0x40) {
LAB_00175794:
      iVar7 = param_2 - sVar5;
      pbVar3 = (byte *)((int)param_3 + sVar5);
      if (iVar7 != 0) {
        uVar2 = (uint)*(byte *)((int)param_3 + sVar5);
        uVar4 = 0x40;
LAB_001757a4:
        pbVar6 = pbVar8 + iVar7;
        do {
          pbVar8 = pbVar8 + 1;
          if (uVar2 != uVar4) {
            if ((uVar4 - 0x41 & 0xff) < 0x1a) {
              uVar4 = uVar4 + 0x20 & 0xff;
              if (uVar2 - 0x41 < 0x1a) goto LAB_001757ee;
            }
            else {
              if (0x19 < uVar2 - 0x41) {
                return false;
              }
LAB_001757ee:
              uVar2 = uVar2 + 0x20 & 0xff;
            }
            if (uVar4 != uVar2) {
              return false;
            }
          }
          if (pbVar8 == pbVar6) break;
          uVar4 = (uint)*pbVar8;
          pbVar3 = pbVar3 + 1;
          uVar2 = (uint)*pbVar3;
          if (uVar4 == 0) {
            return false;
          }
        } while( true );
      }
    }
    else {
      pbVar3 = (byte *)((int)param_3 + sVar5);
      if (*(char *)((int)param_3 + sVar5) != '@') {
        pbVar6 = (byte *)((int)param_3 + (param_2 - 2));
        pbVar1 = (byte *)((param_2 - 2) + (int)param_1);
        do {
          pbVar8 = pbVar1;
          pbVar3 = pbVar6;
          if (sVar5 == 0) goto LAB_00175782;
          uVar4 = (uint)*pbVar8;
          sVar5 = sVar5 - 1;
          if (uVar4 == 0x40) goto LAB_00175794;
          pbVar6 = pbVar3 + -1;
          pbVar1 = pbVar8 + -1;
        } while (*pbVar3 != 0x40);
      }
      iVar7 = param_2 - sVar5;
      if (iVar7 != 0) {
        if (uVar4 == 0) {
          return false;
        }
        uVar2 = 0x40;
        goto LAB_001757a4;
      }
    }
    if (sVar5 != 0) {
      param_2 = sVar5;
    }
  }
LAB_00175782:
  iVar7 = memcmp(param_1,param_3,param_2);
  return iVar7 == 0;
}


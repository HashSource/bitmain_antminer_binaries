
byte * escape_string(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  size_t sVar3;
  byte *pbVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  char acStack_818 [2048];
  
  bVar1 = *param_1;
  if (bVar1 != 0) {
    iVar8 = 0;
    pbVar4 = param_1;
    bVar5 = bVar1;
LAB_00014f9a:
    do {
      if (bVar5 == 0x3d) {
LAB_00014fa8:
        if (param_2 != 0) {
LAB_00014fac:
          pbVar4 = pbVar4 + 1;
          bVar5 = *pbVar4;
          if (bVar5 == 0) break;
          goto LAB_00014f9a;
        }
LAB_00014f92:
        iVar8 = iVar8 + 1;
      }
      else {
        if (0x3d < bVar5) {
          if (bVar5 != 0x5c) {
            if (bVar5 != 0x7c) goto LAB_00014f94;
            goto LAB_00014fa8;
          }
          goto LAB_00014f92;
        }
        if (bVar5 == 0x22) {
          if (param_2 != 0) goto LAB_00014f92;
        }
        else if (bVar5 == 0x2c) {
          if (param_2 == 0) goto LAB_00014f92;
          goto LAB_00014fac;
        }
      }
LAB_00014f94:
      pbVar4 = pbVar4 + 1;
      bVar5 = *pbVar4;
    } while (bVar5 != 0);
    if (iVar8 != 0) {
      sVar3 = strlen((char *)param_1);
      sVar3 = iVar8 + 1 + sVar3;
      pbVar4 = (byte *)malloc(sVar3);
      if (pbVar4 == (byte *)0x0) {
        snprintf(acStack_818,0x800,"Failed to malloc escape buf %d in %s %s():%d",sVar3,"api.c",
                 "escape_string",0x34b);
        _applog(3,acStack_818,1);
        _quit(1);
        bVar1 = *param_1;
      }
      pbVar2 = param_1 + 1;
      pbVar6 = pbVar4;
      do {
        if (bVar1 == 0) {
          *pbVar6 = 0;
          return pbVar4;
        }
        if (bVar1 == 0x3d) {
LAB_00015024:
          if (param_2 == 0) {
            *pbVar6 = 0x5c;
            pbVar6 = pbVar6 + 1;
          }
LAB_0001502a:
          *pbVar6 = bVar1;
          pbVar7 = pbVar6 + 1;
        }
        else if (bVar1 < 0x3e) {
          if (bVar1 != 0x22) {
            if (bVar1 == 0x2c) goto LAB_00015024;
            goto LAB_0001502a;
          }
          if (param_2 != 0) {
            *pbVar6 = 0x5c;
            pbVar6 = pbVar6 + 1;
          }
          *pbVar6 = 0x22;
          pbVar7 = pbVar6 + 1;
        }
        else {
          if (bVar1 != 0x5c) {
            if (bVar1 != 0x7c) goto LAB_0001502a;
            goto LAB_00015024;
          }
          pbVar7 = pbVar6 + 2;
          *pbVar6 = 0x5c;
          pbVar6[1] = 0x5c;
        }
        bVar1 = *pbVar2;
        pbVar2 = pbVar2 + 1;
        pbVar6 = pbVar7;
      } while( true );
    }
  }
  return param_1;
}


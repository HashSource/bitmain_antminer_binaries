
/* WARNING: Unknown calling convention */

char * escape_string(char *str,_Bool isjson)

{
  char *ptr;
  size_t sVar1;
  byte *pbVar2;
  char *buf;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar7;
  int iVar8;
  char tmp42 [2048];
  byte *pbVar6;
  
  bVar7 = *str;
  pbVar2 = (byte *)str;
  if (bVar7 != 0) {
    iVar8 = 0;
    pbVar3 = (byte *)str;
    bVar4 = bVar7;
    do {
      while (bVar4 != 0x3d) {
        if (bVar4 < 0x3e) {
          if (bVar4 == 0x22) {
            if (isjson) goto LAB_00018220;
          }
          else if (bVar4 == 0x2c) break;
          goto LAB_00018208;
        }
        if (bVar4 != 0x5c) {
          if (bVar4 != 0x7c) goto LAB_00018208;
          break;
        }
LAB_00018220:
        pbVar3 = pbVar3 + 1;
        bVar4 = *pbVar3;
        iVar8 = iVar8 + 1;
        if (bVar4 == 0) goto LAB_0001822a;
      }
      if (!isjson) goto LAB_00018220;
LAB_00018208:
      pbVar3 = pbVar3 + 1;
      bVar4 = *pbVar3;
    } while (bVar4 != 0);
LAB_0001822a:
    if (iVar8 != 0) {
      sVar1 = strlen(str);
      sVar1 = iVar8 + 1 + sVar1;
      pbVar2 = (byte *)malloc(sVar1);
      if (pbVar2 == (byte *)0x0) {
        snprintf(tmp42,0x800,DAT_000182dc,sVar1,DAT_000182d4,DAT_000182d8,0x348);
        _applog(3,tmp42,true);
        _quit(1);
        bVar7 = *str;
      }
      pbVar3 = (byte *)(str + 1);
      pbVar6 = pbVar2;
      while (bVar7 != 0) {
        if (bVar7 == 0x3d) {
LAB_00018282:
          if (!isjson) {
LAB_00018286:
            *pbVar6 = 0x5c;
            bVar7 = pbVar3[-1];
            pbVar6 = pbVar6 + 1;
          }
LAB_00018268:
          pbVar5 = pbVar6 + 1;
          *pbVar6 = bVar7;
        }
        else {
          if (bVar7 < 0x3e) {
            if (bVar7 == 0x22) {
              if (isjson) goto LAB_00018286;
            }
            else if (bVar7 == 0x2c) goto LAB_00018282;
            goto LAB_00018268;
          }
          if (bVar7 != 0x5c) {
            if (bVar7 != 0x7c) goto LAB_00018268;
            goto LAB_00018282;
          }
          *pbVar6 = 0x5c;
          pbVar6[1] = pbVar3[-1];
          pbVar5 = pbVar6 + 2;
        }
        bVar7 = *pbVar3;
        pbVar3 = pbVar3 + 1;
        pbVar6 = pbVar5;
      }
      *pbVar6 = 0;
    }
  }
  return (char *)pbVar2;
}


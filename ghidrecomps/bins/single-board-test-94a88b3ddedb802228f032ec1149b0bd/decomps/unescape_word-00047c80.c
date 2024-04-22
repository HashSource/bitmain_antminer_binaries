
int unescape_word(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte bVar5;
  bool bVar6;
  int local_14;
  
  pbVar1 = (byte *)curl_easy_unescape(param_1,param_2,0,&local_14);
  if (pbVar1 == (byte *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (**DAT_00047cf8)(local_14 * 2 + 1);
    if (iVar2 != 0) {
      bVar5 = *pbVar1;
      if (bVar5 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        pbVar3 = pbVar1;
        do {
          while( true ) {
            bVar6 = 0x7e < bVar5;
            if (bVar5 != 0x7f) {
              bVar6 = 0x1f < bVar5;
            }
            if (((bVar6 && (bVar5 != 0x7f && bVar5 != 0x20)) && (bVar5 != 0x27 && bVar5 != 0x22)) &&
               (bVar5 != 0x5c)) break;
            *(undefined *)(iVar2 + iVar4) = 0x5c;
            *(byte *)(iVar2 + iVar4 + 1) = bVar5;
            iVar4 = iVar4 + 2;
            pbVar3 = pbVar3 + 1;
            bVar5 = *pbVar3;
            if (bVar5 == 0) goto LAB_00047cdc;
          }
          *(byte *)(iVar2 + iVar4) = bVar5;
          iVar4 = iVar4 + 1;
          pbVar3 = pbVar3 + 1;
          bVar5 = *pbVar3;
        } while (bVar5 != 0);
      }
LAB_00047cdc:
      *(undefined *)(iVar2 + iVar4) = 0;
    }
    (**DAT_00047cfc)(pbVar1);
  }
  return iVar2;
}


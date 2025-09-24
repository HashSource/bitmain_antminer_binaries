
int CONF_parse_list(char *list,int sep,int nospc,list_cb *list_cb,void *arg)

{
  byte *pbVar1;
  ushort **ppuVar2;
  byte *pbVar3;
  int iVar4;
  size_t sVar5;
  uint uVar6;
  byte *pbVar7;
  
  if (list == (char *)0x0) {
    ERR_put_error(0xe,0x77,0x73,"crypto/conf/conf_mod.c",0x209);
    return 0;
  }
  do {
    if (nospc == 0) {
LAB_00113d36:
      pbVar3 = (byte *)strchr(list,sep);
      if (((byte *)list == pbVar3) || (*list == 0)) goto LAB_00113d94;
      pbVar7 = pbVar3 + -1;
      if (pbVar3 == (byte *)0x0) {
        sVar5 = strlen(list);
        pbVar7 = (byte *)list + (sVar5 - 1);
      }
      if (nospc != 0) {
        ppuVar2 = __ctype_b_loc();
        pbVar1 = pbVar7;
        do {
          pbVar7 = pbVar1;
          pbVar1 = pbVar7 + -1;
        } while ((int)((uint)(*ppuVar2)[*pbVar7] << 0x12) < 0);
      }
      iVar4 = (*list_cb)(list,(int)(pbVar7 + (1 - (int)list)),arg);
    }
    else {
      uVar6 = (uint)(byte)*list;
      if (uVar6 != 0) {
        ppuVar2 = __ctype_b_loc();
        do {
          if (-1 < (int)((uint)(*ppuVar2)[uVar6] << 0x12)) goto LAB_00113d36;
          list = (char *)((byte *)list + 1);
          uVar6 = (uint)(byte)*list;
        } while (uVar6 != 0);
      }
      pbVar3 = (byte *)strchr(list,sep);
LAB_00113d94:
      iVar4 = (*list_cb)((char *)0x0,0,arg);
    }
    if (iVar4 < 1) {
      return iVar4;
    }
    if (pbVar3 == (byte *)0x0) {
      return 1;
    }
    list = (char *)(pbVar3 + 1);
  } while( true );
}


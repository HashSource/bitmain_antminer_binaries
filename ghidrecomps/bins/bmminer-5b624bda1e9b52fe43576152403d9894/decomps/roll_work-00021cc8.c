
/* WARNING: Unknown calling convention */

void roll_work(work *work)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *hexstr;
  uint *be32;
  char tmp42 [2048];
  
  piVar2 = DAT_00021d5c;
  uVar3 = *(uint *)(work->data + 0x44);
  iVar4 = work->rolls;
  iVar5 = *DAT_00021d5c;
  cVar1 = *DAT_00021d60;
  uVar3 = (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18
          ) + 1;
  *(uint *)(work->data + 0x44) =
       uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18
  ;
  work->rolls = iVar4 + 1;
  work->nonce = 0;
  *piVar2 = iVar5 + 1;
  if ((cVar1 != '\0') &&
     (((*DAT_00021d64 != '\0' || (*DAT_00021d68 != '\0')) || (6 < *DAT_00021d70)))) {
    tmp42._0_4_ = *DAT_00021d6c;
    tmp42._4_4_ = DAT_00021d6c[1];
    tmp42._8_4_ = DAT_00021d6c[2];
    tmp42._12_4_ = DAT_00021d6c[3];
    tmp42._16_4_ = DAT_00021d6c[4];
    tmp42._20_4_ = DAT_00021d6c[5];
    tmp42[24] = (char)DAT_00021d6c[6];
    _applog(7,tmp42,false);
  }
  hexstr = work->ntime;
  if (hexstr != (char *)0x0) {
    hex2bin((uchar *)tmp42,hexstr,4);
    uVar3 = (tmp42._0_4_ << 0x18 | ((uint)tmp42._0_4_ >> 8 & 0xff) << 0x10 |
             ((uint)tmp42._0_4_ >> 0x10 & 0xff) << 8 | (uint)tmp42._0_4_ >> 0x18) + 1;
    tmp42._0_4_ = uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18;
    __bin2hex(hexstr,(uchar *)tmp42,4);
  }
  uVar3 = total_work_inc();
  work->id = uVar3;
  return;
}


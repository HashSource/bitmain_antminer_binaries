
/* WARNING: Unknown calling convention */

void pic_heart_beat_each_chain(uchar chain)

{
  uint uVar1;
  
  uVar1 = (uint)chain;
  if (fpga_version < 0xe) {
    chain = chain / 3;
    if (uVar1 % 3 == 0) goto LAB_0002d11c;
  }
  else if (uVar1 - 1 < 3) {
LAB_0002d11c:
    dsPIC33EP16GS202_pic_heart_beat(chain);
    return;
  }
  return;
}


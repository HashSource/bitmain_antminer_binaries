
bool pic_heart_beat_each_chain(void)

{
  int iVar1;
  
  iVar1 = dsPIC33EP16GS202_pic_heart_beat();
  return iVar1 == 1;
}


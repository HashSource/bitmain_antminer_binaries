
void ERR_add_error_data(int num,...)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  ERR_add_error_vdata(num,&uStack_c);
  return;
}


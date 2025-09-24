
undefined4 dtls1_write_bytes(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (param_4 < 0x4001) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    uVar1 = do_dtls1_write();
  }
  else {
    ossl_statem_fatal(param_1,0x50,0x221,0x44,"ssl/record/rec_layer_d1.c",0x318);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


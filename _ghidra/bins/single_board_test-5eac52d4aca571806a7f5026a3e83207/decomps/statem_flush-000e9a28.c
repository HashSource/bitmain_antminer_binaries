
void statem_flush(int param_1)

{
  long lVar1;
  
  *(undefined4 *)(param_1 + 0x14) = 2;
  lVar1 = BIO_ctrl(*(BIO **)(param_1 + 0xc),0xb,0,(void *)0x0);
  if (0 < lVar1) {
    *(uint *)(param_1 + 0x14) = (uint)(0 < lVar1);
  }
  return;
}


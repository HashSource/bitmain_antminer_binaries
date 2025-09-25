
void RECORD_LAYER_init(int *param_1,int param_2)

{
  *param_1 = param_2;
  *(undefined4 *)(param_2 + 0xf30) = 1;
  SSL3_RECORD_clear(param_1 + 0xaa,0x20);
  return;
}


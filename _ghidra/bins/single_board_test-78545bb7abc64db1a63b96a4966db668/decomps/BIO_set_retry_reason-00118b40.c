
void BIO_set_retry_reason(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}



void Curl_sasl_cleanup(int param_1,int param_2)

{
  if (param_2 != 0x40) {
    return;
  }
  (**DAT_00055e98)(*(undefined4 *)(param_1 + 0x284));
  *(undefined4 *)(param_1 + 0x284) = 0;
  *(undefined4 *)(param_1 + 0x288) = 0;
  return;
}


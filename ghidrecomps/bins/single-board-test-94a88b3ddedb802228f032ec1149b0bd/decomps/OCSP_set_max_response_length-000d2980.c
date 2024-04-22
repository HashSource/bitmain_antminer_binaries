
void OCSP_set_max_response_length(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_2 = 0x19000;
  }
  *(int *)(param_1 + 0x18) = param_2;
  return;
}


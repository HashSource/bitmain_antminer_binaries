
int Curl_pipeline_wanted(int param_1,uint param_2)

{
  if (param_1 != 0) {
    if ((param_2 & *(uint *)(param_1 + 0x60)) == 0) {
      param_1 = 0;
    }
    else {
      param_1 = 1;
    }
  }
  return param_1;
}



bool Curl_pp_moredata(int *param_1)

{
  if (param_1[6] != 0) {
    return false;
  }
  if (*param_1 == 0) {
    return false;
  }
  return (uint)param_1[2] < (uint)param_1[1];
}

